#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Größe eingeben:\n");
	int size;
	scanf("%d",&size);
//	if(size < 1) return 0;
	printf("%d Zahlen (doubles) eingeben und mit [ret] trennen\n",size);
	double* array = malloc(size*sizeof(double));
	double xquer=0;
	for(int i=0;i<size;++i){
		scanf("%lf",&array[i]);
		xquer +=array[i];
		printf("%dte Zahl ist %g\n",i,array[i]);
	}
	xquer *= (double)1/size;
	printf("aritmetisches Mittel = %g\n",xquer);
	double s = 0;
	for(int i=0;i<size;++i){
		s += (array[i] - xquer)*(array[i] - xquer);
	}
	s /= (size - 1);
	printf("Stichprobenvarianz = %g\n",s);
	free(array);
}
