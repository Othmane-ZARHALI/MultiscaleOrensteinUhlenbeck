//============================================================================
// Name        : BACRY.cpp
// Author      : Othmane ZARHALI
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <armadillo>

#include "BlackScholesPricerCall.h"
#include "OrensteinUlenbeckPricer.h"
#include "ImpliedVolSurface.h"
#include "HestonPricer.h"

using namespace std;
using namespace arma;

int main() {
//	cout << "!!!Hello World!!!"<<ones<vec>(5) << endl; // prints !!!Hello World!!!
//	cout<<"blackscholes test pricing = " <<BlackScholesPricerCall(5, 0.5, 0.6, 6, 0.7)<<endl;
//
//	random_device rd;
//				mt19937 gen(rd());
//				normal_distribution<> dis(0, 1.0);
//
//	cout<<dis(gen)<<" " <<dis(gen)<<"  "<<endl;

//	double s_ini,double strike, double sigma_ini,double m_ini , double risk_free_rate, double maturity_date,
//			double alpha, double k ,double m0,double alpha0, double k0,double rho,int nbr_paths,int nbr_time_disc

	double prix= OrensteinUlenbeckPricer(257.0289,155, 0.35,0.7, 0.22, 0.263,
			0.1,0.002 ,0.18,0.0013, 0.00012,-0.64,100,100);
	cout<<"orenstein ulenbeck test pricing = " <<prix<<endl;
////
//	double prixHeston= HestonPricer(257.0289, 0.35,257, 0.00012,0.7, 0.02, -0.64, 0.263, 100,0.22);
//		cout<<"prixHeston = " <<prixHeston<<endl;


//	double implied_vol_test= ImpliedVolatilitySurface({257.0289,190, 0.35,0.5, 0.22, 0.236,
//				0.1,0.002 ,0.18,0.0013, 0.00012,-0.4,100,100},190,0.236);
//		cout<<"implied_vol_test  = " <<implied_vol_test<<endl;

		vec strikess = {125,155,190,192,195,200,220,235,245};
		for (unsigned int i=0;i<strikess.size();i++){
			double implied_vol_test= ImpliedVolatilitySurface({257.0289,strikess(i), 0.35,0.5, 0.22, 0.236,
							0.1,0.002 ,0.18,0.0013, 0.00012,-0.4,100,100},strikess(i),0.236);
					cout<<"implied_vol_test  = " <<implied_vol_test<<endl;
		}



	return 0;
}

