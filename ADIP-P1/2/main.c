n,a,b,j;
long long M=1;
unsigned long long S=4;
c(k){
	for(int j=1;j<sqrt(k)+1;++j)if(j^k&k%j==0)a=1;
}
long long g(n){
	return (1<<n)-1;
}
l(){
	for(int i=1;i<32;++i){
		c(i);
		S=4;
		for(int w = 2;a&w<i;++w){
			S=(S*S-2)%g(i);
		}
		if(S==0|i==2)printf("%d\n",i);
	}
}
main(){
	scanf("%d",&n);
	printf("%lli %d\n",g(n));
	l();
}
