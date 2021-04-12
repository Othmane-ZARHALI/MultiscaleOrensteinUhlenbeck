/*
 * OrensteinUlenbeckPricer.h
 *
 *  Created on: 13 mars 2019
 *      Author: othmane
 */
#ifndef ORENSTEINULENBECKPRICER_H_
#define ORENSTEINULENBECKPRICER_H_


#include <math.h>
#include <armadillo>
#include <iostream>

using namespace std;
using namespace arma;

double OrensteinUlenbeckPricer(double s_ini,double strike, double sigma_ini,double m_ini , double risk_free_rate, double maturity_date,
		double alpha, double k ,double m0,double alpha0, double k0,double rho,int nbr_paths,int nbr_time_disc);

#endif /* ORENSTEINULENBECKPRICER_H_ */
