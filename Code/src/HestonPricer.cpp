/*
 * HestonPricer.cpp
 *
 *  Created on: 10 août 2018
*******************************************************************************
* brief:     This function prices a call option i the heston model
*
* return:     Price of a call option on S&P500
*
* input:     - s0 = initial value of the S&P500
*
*            - v0 = first value of the instantenous variance V
*
*            - K = strike
*
*            - time_sequence = the sequence of time discretization from 0 to maturity date
*
*            - rho = correlation between S&P500 and V_t
*
*            - maturity_date = the maturity date of the option
*
*            - N = number of simulations of Monte Carlo
*
* output:     a double Call_0(v0, z0, K, T)
*******************************************************************************
**/
#include <cmath>
#include <armadillo>
#include <random>
#include <iostream>

//#define risk_free_rate 0.0189

using namespace std;
using namespace arma;



double HestonPricer(double s0, double v0,double K, double kappa, double theta, double vvol, double rho, double maturity_date, int N,double risk_free_rate ){



		// Extract number of observations

	    vec time_sequence = linspace<vec>(0,maturity_date,100);
	    double delta=time_sequence(2)-time_sequence(1);
		int H = time_sequence.size();

		// Simulate a Markov chain that starts by z0
		vec S_T_MC_sample;
		for(int i = 0; i < N; i++){


			/* simulation of the S&P500
			 *  at maturity date T denoted S_T, given that:
			 *  V = Instantaneous variance,
			 *  Z = Markov chain starting by z0
			 *  S_0 = s0
			 * */
			vec V = {v0};
			vec S = {s0};

			for (int k = 1; k < H; k++) {
				vec eps_k = randn<vec>(2);

				vec v_k = {kappa * theta* delta +
						(1 - kappa* delta) * V(k - 1) +
						vvol * sqrt(delta * V(k - 1)) * eps_k(0)};
				vec s_k = {S(k - 1) * (1 + risk_free_rate * delta + sqrt(delta * V(k - 1)) * (rho * eps_k(1) + sqrt(1 - pow(rho,2)) * eps_k(1)))};
				V = join_cols(V, v_k);
				S = join_cols(S, s_k);
			}

			if(all(S.tail(1) > 0)) {
				S_T_MC_sample = join_cols(S_T_MC_sample, S.tail(1));
			}
		}

		return(exp(-risk_free_rate * maturity_date) / N * sum(max(zeros<vec>(S_T_MC_sample.size()), S_T_MC_sample - K)));


}








