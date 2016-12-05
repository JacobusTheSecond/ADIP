c,d,e=1,f;P(n){for(;e<n;g(e,n)<2?++f:0)++e;}g(a,b){while(1)return b>0?g(b,a%b):a;}main(){scanf("%d %d",&c,&d);P(c);printf("%d %d",g(c,d),f);}
