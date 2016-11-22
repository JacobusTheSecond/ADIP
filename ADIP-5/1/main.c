#include <stdio.h>

void cbR(int *x){
	printf("Ergebnis 1: %d\n",*x);
	(*x)+=12;	
	printf("Ergebnis 2: %d\n",*x);
}

void cbV(int x){
	printf("Ergebnis 4: %d\n",x);
	(x)+=12;	
	printf("Ergebnis 5: %d\n",x);
}

int main(){
	int a = 10;
	cbR(&a);
	printf("Ergebnis 3: %d\n",a);

	cbV(a);
	printf("Ergebnis 6: %d\n",a);
}
