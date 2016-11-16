#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(0));
	int price = rand()%100000;
	printf("%d sind zu zahlen:\n",price);
	int gezahlt;
	int done = 1;
	while(done){
		scanf("%d",&gezahlt);
		if(gezahlt < price){
			printf("nice try\n%d sind zu zahlen\n",price);
		}else{
			done = 0;
		}
	}
	gezahlt -= price;
	int munzen[6]={50,20,10,5,2,1};
	for(int i=0;i<6;++i){
		int amount = 0;
		while(gezahlt - munzen[i] >= 0){
			gezahlt -= munzen[i];
			amount ++;
		}
		printf("%d %d-Münzen\n",amount,munzen[i]);
	}
	return 0;
}
