#include <stdio.h>

long long pre(long long n){
	return --n;
}

long long succ(long long n){
	return ++n;
}

long long add(long long a, long long b){
	if(b>0){
		return add(succ(a),pre(b));
	}else if(b<0){
		return add(pre(a),succ(b));
	}else if(b == 0){
		return a;
	}
}

long long sub(long long a, long long b){
	if(b>0){
		return sub(pre(a),pre(b));
	}else if(b<0){
		return sub(succ(a),succ(b));
	}else{
		return a;
	}
}

long long mult(long long a, long long b){
	if(b>0){
		return add(mult(a,pre(b)),a);
	}else if(b<0){
		return sub(mult(a,succ(b)),a);
	}else{
		return 0;
	}
}

int main(){
	long long a,b;
	printf("a eingeben:\n");
	scanf("%lli",&a);
	printf("b eingeben:\n");
	scanf("%lli",&b);
	//if(b>0){
		printf("%lli + %lli = %lli\n%lli - %lli = %lli\n%lli * %lli = %lli\n",a,b,add(a,b),a,b,sub(a,b),a,b,mult(a,b));
	//}else{
	//	printf("a>0!!\n");
	////}
	return 0;
}
