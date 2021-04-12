/*
 * Newton.h
*  Created on: May 25, 2018
*
*******************************************************************************
* brief:     This function encodes the newton algorithm to determine a zero of a function
*
* return:    a double
*
* input:     ObjectiveFunction f  : ObjectiveFunction is a template type and f is supposed to be the objective function of the optimisation algorithm
*            int max_iteration : the maximum number of iteration
*            const vec x_0 : initial point of the optimization algorithm
*            long double tolerance : the tolerance
*
*
* output:   x such that f(x)=0
*
*******************************************************************************
*/

#ifndef NEWTON_H_
#define NEWTON_H_

#include <cmath>
#include <iostream>

using namespace std;

#define EPSILON 1e-4

template <typename Function>
double Newton(
		Function f,
		const double x_0,
        int max_iteration,
        long double tolerance
		) {

	int k = 0;
	double x_k_plus_one = x_0;
	double x_k;
	double f_derivative;

	/*LOOP OF THE NEWTON METHOD*/
	do {
		x_k = x_k_plus_one;

		if (abs(x_k) <  numeric_limits<double>::epsilon() ) {
			f_derivative = ( (f(x_k + EPSILON)-f(x_k - EPSILON)) / (2 * EPSILON) );


		} else {
			f_derivative = ( (f(x_k * (1 + pow(EPSILON,1/3))) - f(x_k * (1 - pow(EPSILON,1/3)))) / (2 * x_k * pow(EPSILON, 1/3)) );

		}
		x_k_plus_one = x_k - f(x_k)/f_derivative;

		k++;
	} while((abs(x_k_plus_one - x_k) > tolerance) && (k < max_iteration));

	return x_k_plus_one;
};

#endif /* NEWTON_H_ */
