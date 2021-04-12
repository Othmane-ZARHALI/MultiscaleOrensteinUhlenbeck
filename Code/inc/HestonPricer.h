/*
 * HestonPricer.h
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

#ifndef HESTONPRICER_H_
#define HESTONPRICER_H_

#include <math.h>
#include <armadillo>
#include <random>
#include <iostream>


//#define risk_free_rate 0.0189

using namespace std;
using namespace arma;

double HestonPricer(double s0, double v0,double K, double kappa, double theta, double vvol, double rho, double maturity_date, int N,double risk_free_rate );


#endif /* HESTONPRICER_H_ */
