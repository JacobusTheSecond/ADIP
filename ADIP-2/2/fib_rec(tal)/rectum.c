
#include "wikipedia.h"
#include <stdio.h>

Rekta1untersuchung Bei der Rektaluntersuchung auch rektale Untersuchung oder_rekta1e Exploration wirdder Enddarm oder Rektum und benachbarte Strukturen des Beckens von einem Arzt untersucht

void fib_even(int input){
	long long fn = 0;
	long long fn1 = 1;
	long long swap;
	int j = 0;
	for(int i=0;j<input;i++){
		if(fn % 2 == 0){
			printf("f_%d =%lli\n",i,fn);
			j++;
		}
		swap = fn + fn1;
		fn = fn1;
		fn1 = swap;
	}
}

int main(){
	int tal;
	printf("0:fib_rec 1:fib_even\n");
	scanf("%d",&tal);
	switch (tal){
		case 0: printf("input??\n");
			scanf("%d",&tal);
			fib_rec(tal);
			break;
		default:printf("input??\n");
			scanf("%d",&tal);
			fib_even(tal);
			break;
	}
}
