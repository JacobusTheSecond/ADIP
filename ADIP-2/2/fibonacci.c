#include "LargeInt.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
typedef struct LargeInt LargeInt;

void fib_rec(int input){
	LargeInt * fn = NEW_LargeInt_from_str("0x00", 0);
	LargeInt * fn1 = NEW_LargeInt_from_str("0x01", 0);
	LargeInt * swap;
	for(int i=0; i<input;i++){
		swap = add(fn,fn1);
		destructor(fn);
		fn = fn1;
		fn1 = swap;
	}
	char * str = LargeIntToString_Dec(fn);
	printf("fn_%d = %s\n",input, str);
	free(str);
	destructor(fn);
	destructor(fn1);
	//destructor(swap);
}

void fib_even(int input, int dec){
	LargeInt * fn = NEW_LargeInt_from_str("0x00", 0);
	LargeInt * fn1 = NEW_LargeInt_from_str("0x01", 0);
	LargeInt * swap;
	char* str;
	int j = 0;
	//clock_t start,end;
	for(int i=0;j<input;i++){
		if((int)(fn->LInt[0]) % 2 == 0){
			//start = clock();
			if(dec == 1){
				str = LargeIntToString_Dec(fn);
			}else{
				str = LargeIntToString_Hex(fn);
			}
			printf("\n\nfn_%d = %s\n",i, str);
			free(str);
			j++;
			//end = clock();
			//printf("printtime = %g seconds\n",((double) (end-start)/(double)CLOCKS_PER_SEC));
		}
		//start = clock();
		swap = add(fn,fn1);
		destructor(fn);
		fn = fn1;
		fn1 = swap;
		//end = clock();
		//printf("calctime = %g seconds\n",((double) (end-start)/(double)CLOCKS_PER_SEC));
	}
	destructor(fn);
	destructor(fn1);
	//destructor(swap);
}

int main(){
	int input;
	printf("0:fib_rec\n1:fib_even in hexadecimal\n2:fib_even in decimal\n");
	assert(scanf("%d",&input));
	switch (input){
		case 0: printf("input??\n");
			assert(scanf("%d",&input));
			fib_rec(input);
			break;
		case 1: printf("input??\n");
			assert(scanf("%d",&input));
			fib_even(input,0);
			break;
		default:printf("input??\n");
			assert(scanf("%d",&input));
			fib_even(input,1);
			break;
	}
}
