/*
 * BlackScholesPricer.cpp
 *
 *  Created on: 13 mars 2019
 *      Author: othmane
 */

#include <math.h>
#include "BlackScholesPricerCall.h"       /* erf */
#include <iostream>

using namespace std;


double BlackScholesPricerCall(double s0, double risk_free_rate, double maturity_date, double strike, double volatility){
	double d1 = (log(s0/strike) + (risk_free_rate + 0.5 * pow(volatility, 2)) * maturity_date) / (volatility * sqrt(maturity_date));
	double d2 = d1 - volatility * sqrt(maturity_date);

	double price = s0 *  (1 + erf (d1/sqrt(2))) / 2 - strike * exp(-risk_free_rate * maturity_date) * (1 + erf(d2/sqrt(2))) / 2;
	return price;
}




