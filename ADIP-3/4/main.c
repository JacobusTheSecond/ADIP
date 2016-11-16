#include <stdio.h>

float fsum(float* x){
	float S = 0;
	float D = 0;
	float Salt;
	for(int i=0;i<5;++i){
		Salt = S;
		S += x[i];
		D += (x[i] - (S - Salt));
	}
	S += D;
	return S;
	
}

double dsum(double* x){
	double S = 0;
	double D = 0;
	double Salt;
	for(int i=0;i<5;++i){
		Salt = S;
		S += x[i];
		D += (x[i] - (S - Salt));
	}
	S += D;
	return S;
	
}

float fumsum(float* x){
	float S = 0;
	for(int i=0;i<5;++i){
		S += x[i];
	}
	return S;
}

double dumsum(double* x){
	double S = 0;
	for(int i=0;i<5;++i){
		S += x[i];
	}
	return S;
}

int main(){
	float x[5] = {10000.0, -1.0e-3/9.0, 25.0e2, 1.0e-3 / 7.0, -12.5e3};
	double y[5] ={10000.0, -1.0e-3/9.0, 25.0e2, 1.0e-3 / 7.0, -12.5e3};
	printf("floats : fancy sum = %.30f vs dum sum = %.30f\n",fsum(x), fumsum(x));
	printf("doubles: fancy sum = %.30f vs dum sum = %.30f\n",dsum(y), dumsum(y));
}
