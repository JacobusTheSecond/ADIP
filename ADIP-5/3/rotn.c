#include <stdio.h>
#include <stdlib.h>

char encryptChar(char c, int n){
	if(c>='A'&&c<='Z'){
		c = ((c - 'A')+n)%('Z'-'A'+1)+'A';
	}

	if(c>='a'&&c<='z'){
		c = ((c-'a')+n)%('z'-'a'+1)+'a';
	}
	return c;
}

int encrypt(char* a, int n){
	for(int i=0;a[i];++i){
		a[i]=encryptChar(a[i],n);
	}
	return EXIT_SUCCESS;
}

int decrypt(char* a, int n){
	encrypt(a,26-n);
	return EXIT_SUCCESS;
}

int main(){
	char* s = malloc(256);
	int n;
	scanf("%s %d",s,&n);
	encrypt(s,n);
	printf("%s\n",s);

}
