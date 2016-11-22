d=-1,g;
main(a){
	srand(time(0));
	for(a=rand()%100000;d<0;d<0?printf("nice try\n"):0)printf("pay %d:\n",a),scanf("%d",&g),d=g-a;
	for(g=50;g;printf("%d %d-coins\n",a,g),g=g>49?20:g/2)a=d/g,d=d%g;
}
