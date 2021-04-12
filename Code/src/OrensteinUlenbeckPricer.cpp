/*
 * OrensteinUlenbeckPricer.cpp
 *
 *  Created on: 13 mars 2019
 *      Author: othmane
 */

#include <math.h>
#include <armadillo>
#include <random>
#include <iostream>

using namespace std;
using namespace arma;

double OrensteinUlenbeckPricer(double s_ini,double strike, double sigma_ini,double m_ini , double risk_free_rate, double maturity_date,
		double alpha, double k ,double m0,double alpha0, double k0,double rho,int nbr_paths,int nbr_time_disc){


	auto payoffcall = [](double str, double sousjacent) { // the vector of the maximum values of between the components of x and y with the same size
			return max(sousjacent-str,0.0);};


	vec timeinc = linspace<vec>(0, maturity_date, nbr_time_disc);
	double ss=1;
	vec sousjacent = ones<vec>(nbr_time_disc);


	sousjacent(0)=s_ini;
	double sigma=sigma_ini;
	double m = m_ini;
	double price=0;


	for(int q=0;q<nbr_paths;q++){
		for(int j=1;j<=nbr_time_disc-2;j++){

			vec eps_k = randn<vec>(3);
//			random_device rd;
//			mt19937 gen(rd());
//			normal_distribution<> dis(0, 1.0);


			double norm1 = eps_k(0);
			double norm2 = eps_k(1);
			double norm3 = eps_k(2);

			sousjacent(j)=sousjacent(j-1)+sousjacent(j-1)*risk_free_rate*(timeinc(j)-timeinc(j-1))+sousjacent(j-1)*(sigma)*sqrt((timeinc(j)-timeinc(j-1)))*norm1;
			sigma=sigma-alpha*(sigma-m)*(timeinc(j+1)-timeinc(j))+k*(rho*sqrt((timeinc(j)-timeinc(j-1)))*norm1+sqrt(1-pow(rho,2))*sqrt((timeinc(j)-timeinc(j-1)))*norm2);
			m=m-alpha0*(m-m0)*(timeinc(j+1)-timeinc(j))+k0*sqrt((timeinc(j)-timeinc(j-1)))*norm3;


			ss=sousjacent(j);

				}
		m=m_ini;
		sigma=sigma_ini;

		price=price+payoffcall(strike,ss);
//		cout<<"payoffcall(strike,sousjacent(nbr_time_disc-1))="<<price<<endl;
		}



	return exp(-risk_free_rate*maturity_date)*(1.0/nbr_paths)*price;
}




