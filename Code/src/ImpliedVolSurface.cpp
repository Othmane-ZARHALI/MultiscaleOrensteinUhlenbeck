/*
 * ImpliedVolSurface.cpp
 *
 *  Created on: 13 mars 2019
 *      Author: othmane
 */
#include <math.h>
#include <armadillo>
#include <iostream>

#include "Newton.h"
#include "BlackScholesPricerCall.h"
#include "OrensteinUlenbeckPricer.h"
#include "HestonPricer.h"


using namespace std;
using namespace arma;

double ImpliedVolatilitySurface(vec param, double strike,double maturity_date){

//	ordre des elements de param
//	double s_ini,double strike, double sigma_ini,double m_ini , double risk_free_rate, double maturity_date,
//	//			double alpha, double k ,double m0,double alpha0, double k0,double rho,int nbr_paths,int nbr_time_disc

//	auto objectiffunction = [&param](double impliedvol) { // the vector of the maximum values of between the components of x and y with the same size
//				return (OrensteinUlenbeckPricer(param(0),param(1), param(2),param(3), param(4),param(5),
//						param(6),param(7) ,param(8),param(9), param(10),param(11),param(12),param(13))-BlackScholesPricerCall(param(0), param(4), param(5), param(1), impliedvol));};

//	auto objectiffunction = [&param](double impliedvol) { // the vector of the maximum values of between the components of x and y with the same size
//					return (59.9-BlackScholesPricerCall(param(0), param(4), param(5), param(1), impliedvol));};



	auto objectiffunction = [&param](double impliedvol) { // the vector of the maximum values of between the components of x and y with the same size
					return (HestonPricer(param(0),param(2),param(1), param(7),param(3),0.07,-0.4, 0.236, 100,0.22)-BlackScholesPricerCall(param(0), param(4), param(5), param(1), impliedvol));};



	vec volatilities = linspace<vec>(0,1, 500);
	vec list_elem = ones<vec>( 100);

	for (int i=0;i<100;i++){
		list_elem(i)= abs(objectiffunction(volatilities(i)));
	}


//	cout<<"list elem = "<<list_elem<<endl;
	return  volatilities(list_elem.index_min()) ;

}




