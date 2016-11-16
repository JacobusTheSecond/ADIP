#include <stdio.h>
#include "uglyoutput.h"
#include <math.h>

int main() 
{

	//eingabenerkennung
	int breakpoints = 1;
	long long n;
	printf("mit oder ohne breakpoints am Flußdiagram? (1 = Ja, 0 = Nein,aber mit print, 2 = Nein, ohne print)?\n");
	scanf("%d",&breakpoints);
	if(!(breakpoints == 2  || breakpoints == 1 || breakpoints == 0))breakpoints=1,printf("Also Ja\n");
	printf("ganze positive Zahl eingeben:\n");
	scanf("%lli",&n);
	getchar(); //damit der den Enter-press nicht für das nächste getchar() hällt

	//banter für dumme eingaben
	if (n < 1) 
	{
		printf("Du ignorierst also Anweisungen? Sehr cool. deine Zahl sei 42\n");
		n = 42;
	}
	if (n == 1) 
	{
		printf("Als ob du das nicht im Kopf hinbekommen würdest. Natürlich ist die Primzahlzerlegung von 1 = 1\n");
	}
	else 
	{

		//actual code
		long long outputn = n;
		long long* PT = malloc( (((int)floor(1.443f/*log(e)/log(2)*/*log((double)n)))+1) * sizeof(long long) );
		int length = 0;
		long long p = 2;
		print1
		while (p<=sqrt(n)) 
		{
			print2
			if (n%p == 0) 
			{
				print3
				PT[length] = p;
				length += 1;
				n /= p;
			}
			else 
			{
				print4
				p += 1;
			}
		}
		//output
		print2
		print4
		print5
		PT[length] = n;
		++length;
		printf("1 * ");
		for (int i = 0; i < length; ++i) {
			printf("%lli * ",PT[i]);
		}
		printf("\b\b= %lli\n", outputn);
		free(PT);
	}
	return 0;

}



/*
Diagramm das in uglyoutput.h geschrieben wird
 +-------+
 | p = 2 |
 +-------+
	  |
	  +--------+
	  |        |
	  V        |
 +-----------+ |
 | n%p=0?1:2 | |
 | 1: p P-T  | |
 |    n /= p |-+
 | 2: p+=1   | |
 | p<n?3:4   | |
 | 3:        |-+
 | 4:        |
 +-----------+
	   |
	   V
 +------------+
 | output P-T |
 +------------+
*/



