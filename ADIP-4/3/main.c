#include <stdio.h>
#include <math.h>

int fak(int n){

	if(n == 1 || n == 0){
		return 1;
	}else{
		return n*fak(n-1);
	}
}

double sin(double x){
	double result = 0;
	for(int n =0;n<6;++n){
		result += pow(-1,n)*pow(x,2*n+1)/fak(2*n+1);
	}
}


double cos(double x){
	double result = 0;
	for(int n =0;n<6;++n){
		result += pow(-1,n)*pow(x,2*n)/fak(2*n);
	}
}


double exp(double x){
	double result = 0;
	for(int n =0;n<11;++n){
		result += pow(x,n)/fak(n);
	}
}

int main(){
	printf("c eingeben:\n");
	double x;
	scanf("%lf",&x);
	printf("sin(%f) = %f\ncos(%f) = %f\n exp(%f) = %f\n",x,sin(x),x,cos(x),x,exp(x));
	return 0;
}
