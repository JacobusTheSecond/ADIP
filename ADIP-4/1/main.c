#include <stdio.h>

long long fak(long long n){
	if(n>1){
		return n*fak(n-1);
	}else if(n == 1||n==0){
		return 1;
	}else if(n<0){
		return 0;
	}
}

long long over(long long n, long long k){
	if(0<k && k<=n)return fak(n)/(fak(k)*fak(n-k));
	return 0;
}

long long Lotto(long long n, long long k){
	if(0<k && k<=n)return fak(n)/fak(n-k);
	return 0;
}

int main(){
	long long n,k;
	printf("n eingeben\n");
	scanf("%lli",&n);
	printf("k eingeben\n");
	scanf("%lli",&k);
	printf("%lli! = %lli\n%lli over %lli = %lli\n(%lli over %lli)*%lli! = %lli\n",n,fak(n),n,k,over(n,k),n,k,k,Lotto(n,k));
}
