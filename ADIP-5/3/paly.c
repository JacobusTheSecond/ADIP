#include <stdio.h>
#include <stdlib.h>
typedef enum {false, true} bool;

int isPalindrome(char* s){
	int l;
	for(l=0;s[l];++l);
	for(int i=0;i<l;++i){
		if(s[i]!=s[l-i-1]){
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int printfBackwards(char* s){
	int l;
	for(l=0;s[l];++l);
	for(int i=0;i<l;++i){
		printf("%c",s[l-i-1]);
	}
	printf("\n");
	return EXIT_SUCCESS;	
}

int main(){
	char* s = malloc(256);
	scanf("%s",s);
	printf("%d\n",isPalindrome(s));
	printfBackwards(s);
}
