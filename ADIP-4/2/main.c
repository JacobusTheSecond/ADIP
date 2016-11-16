#include <stdio.h>

long long succ(long long n){
	return --n;
}

long long inc(long long n){
	return ++n;
}

long long add(long long a, long long b){
	if(b>0){
		return add(inc(a),succ(b));
	}else{
		return a;
	}
}

long long sub(long long a, long long b){
	if(b>0){
		return sub(succ(a),succ(b));
	}else{
		return a;
	}
}

long long mult(long long a, long long b){
	if(b>0){
		return add(mult(a,succ(b)),a);
	}else{
		return 0;
	}
}

int main(){
	long long a,b;
	printf("a (>0) eingeben:\n");
	scanf("%lli",&a);
	printf("b eingeben:\n");
	scanf("%lli",&b);
	if(b>0){
		printf("%lli + %lli = %lli\n%lli - %lli = %lli\n%lli * %lli = %lli\n",a,b,add(a,b),a,b,sub(a,b),a,b,mult(a,b));
	}else{
		printf("a>0!!\n");
	}
	return 0;
}
