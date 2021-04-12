/*
 * ImpliedVolSurface.h
 *
 *  Created on: 13 mars 2019
 *      Author: othmane
 */

#ifndef IMPLIEDVOLATILITYSURFACE_H_
#define IMPLIEDVOLATILITYSURFACE_H_


#include <math.h>
#include <armadillo>
#include <iostream>

#include "Newton.h"
#include "BlackScholesPricerCall.h"
#include "OrensteinUlenbeckPricer.h"

using namespace std;
using namespace arma;

double ImpliedVolatilitySurface(vec param, double strike,double maturity_date);

#endif /* IMPLIEDVOLATILITYSURFACE_H_ */
