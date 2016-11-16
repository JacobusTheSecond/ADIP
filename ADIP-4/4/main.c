#include <stdio.h>

int main(){
	int max;
	printf("max(c) eingeben:\n");
	scanf("%d",&max);
	for(int c = 3;c<max;++c){
		for(int b = 2; b<c;++b){
			for(int a = 1; a<b;++a){
				if(a*a + b*b == c*c){
					printf("%7d² + %7d² = %7d²\n",a,b,c);
				}
			}
		}
	}
}


