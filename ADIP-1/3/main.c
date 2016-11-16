#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	printf("Ganze Zahl eingeben:\n");
	scanf("%d",&n);
	if(n < 0)
	{
		printf("Diese Zahl ist negativ\n");
	}
	else
	{
		int p = 2;
		while(p<sqrt(n)){
			if(n%p == 0)
			{
				printf("%d ist keine Primzahl\n", n);
				return 0;
			}
			else
			{
				p++;
			}
		}
		printf("%d ist eine Primzahl\n",n);
		return 0;
	}
		
}
