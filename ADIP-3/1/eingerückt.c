b,c,k,i=1;
a(h,n){
	c=0;
	while(!h&c<17|i){
		k=rand()%9+2;
		c+=k;
		printf("%s zieht %d\n",n,k);
		if(c>20)return;
		if(h)printf("[1]: next\n[0]: quit\n"),scanf(" %d",&i);
	}
}

main(){
	srand(time(0));
	a(1,"Spieler"),b=c;
	printf("%s gewinnt\n",(b>21)?"Dealer":(a(0,"Dealer"),(c<21&c>b)?"Dealer":"Spieler"));
}
