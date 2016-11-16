#include <stdio.h>
/*
Also EEEEEEEEEEEERSTMAL ist dieses "verfahren" nicht iterativ, sondern rekursiv, da von a_n auf a_m mit m<n verwiesen wird. dies ist vergleich bar mit vollständiger induktion oder >>REKURSION<<. 

Zweitens: man kann Rekursionsschritte nicht "zählen" ohne zu sagen WAS man gezählt haben möchte. Wenn wir die rekursionscalls als Baum zeichnen erhalten wir einen Baum mit O(n) vielen Knoten, und O(log(n)) Baumtiefe. Wenn mit dieser Aufgabe gezeigt werden sollte, dass dieses "iterative" Verfahren O(log(n)) Laufzeit braucht, dann sollte man Baumtiefe zählen. Zu entscheiden wie sinnvoll dieses Zählverfahren ist,ist dem Leser überlassen. Tip: NICHT. Außerdem hat dieser Baum O(n) Blätter, die "return a" oder "return 1" machen. Allerdings kann man doppelte Äste nur einmal berechnen, und somit wieder O(log(n)) Laufzeit erhalten

Drittens: Bei dem Iterativen Verfahren sind mindestens n Multiplikationen enthalten. sogesehen ist das zweite verfahren sogar schlechter. undzwar IMMER.
*/
int iterations_schritte = 0;
double it_pow(double a, int n){
	++iterations_schritte;
	if(n==0){
		return 1;
	}else if(n == 1){
		return a;
	}else if(n%2==0){
		double itpow2 = it_pow(a,n/2);
		return itpow2*itpow2;
	}else if(n%2==1){
		double itpow2 = it_pow(a,(n-1)/2);
		return a*itpow2*itpow2;
	}
	
}
int main(){
	printf("Eingabe a:\n");
	double a;
	scanf("%lf",&a);
	int n;
	printf("Eingabe n:\n");
	scanf("%d",&n);
	double an = 1;
	int i;
	for(i=0; i<n; ++i){
		an *= a;
	}
	printf("%f mit %d Schritten, iterativ\n",an,i);
	an = it_pow(a,n);
	printf("%f mit %d Schritten, rekursiv mit Knotenzahl (siehe Bild) als 'Schritte'\n",an,iterations_schritte);
	int j = 0;
	//rekursiver Algorithmus interpretiert als iterativ, allerdings ist dies offensichtlich nicht richtig
	if(n == 0){
		an = 1;
	}else{
		an = a;
		for(i=n; i>1; ++j){
			if(i%2==0){
				an *=an;
				i/=2;
			}else{
				an *= a;
				--i;
			}
		}
	}
	printf("%f mit %d Schritten, iterativ mit 2tem Algorithmus. offensichtlich falsch\n",an,j);
}
