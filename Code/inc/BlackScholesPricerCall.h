/*
 * BlackScholesPricer.cpp
 *
 *  Created on: 13 mars 2019
 *      Author: othmane
 */
#ifndef BLACKSCHOLESPRICERCALL_H_
#define BLACKSCHOLESPRICERCALL_H_


#include <math.h>
     /* erf */
#include <iostream>

using namespace std;


using namespace std;

double BlackScholesPricerCall(double s0, double risk_free_rate, double maturity_date, double strike, double volatility);


#endif /* BLACKSCHOLESPRICERCALL_H_ */
