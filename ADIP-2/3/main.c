#include <stdio.h>

int main(){
	int youwontescape = 1;
	while(youwontescape){
		int input = 0;
		printf("Eingabe:\n");
		scanf("%d",&input);
		int sum = 0;
		for(int i=1;i<input;++i){
		        if(input   %   i == 0){
		                sum = sum + i;
		        }
		}
		if(input == sum){
		        printf("%d ist vollkommen\n",input);
		}else if(input > sum){
		        printf("%d ist defizient\n",input);
		}else{
			printf("%d ist weder noch\n",input);
		}
		printf("Nochmal? [Y=1,N=0]\n");
		scanf("%d",&youwontescape);
	}
}

