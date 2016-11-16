#include <stdio.h>

int main()
{
	int n;
	printf("Geben sie eine natürliche Zahl ein\n");
	scanf("%d",&n);
	int summe = n*(n+1)/2;
	long long qsumme = (long long)n*((long long)n+1)*(2*(long long)n+1)/6;
	printf("Summe der Zahlen von 1 bis %d ist %d\n",n,summe);
	printf("Summe der Quadratzahlen von 1 bis %d ist %lli\n",n,qsumme);
}
