#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
	return 0.4*pow(x,5)+pow(x,3);
}

double integrate(double(*f)(double),double left, double right, double stepsize){
	double result;
	double curr = left;
	while(curr <= right){
		result += f(curr)*stepsize;
		curr += stepsize;
	}
	return result;
}

int main(){
	printf("Integral von Sinus [0,pi]:  %f\n",integrate(&sin,0,M_PI,0.0001));
	printf("Integral von Sinus [0,2pi]: %f\n",integrate(&sin,0,2*M_PI,0.0001));
	printf("Integral von f(x) = 0.4*x⁵ + x³ [0,3]: %f\n",integrate(&f,0,3,0.0001));
}
