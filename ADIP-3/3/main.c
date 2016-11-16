#include <stdio.h>

int main(){
	char* enden[4] = {"zehn","zig","ßig","hundert"};
	char* ziffern[9] = {"ein","zwei","drei","vier","fünf","sechs","sieben","acht","neun"};
	char* extras[6] = {"eins","elf","zwölf","eine","zwan","sieb"};
	int teiler[4] = {1000000000,1000000,1000,1};
	char* teilerzahl[4] = {"milliarden","millionen","tausend",""};
	printf("Ganze Zahl eingeben:\n");
	int input;
	scanf(" %d",&input);
	if(input < 0){
		printf("minus ");
		input *= -1;
	}
	if(input < 0){
		printf("\b\b\b\b\b\b\bHast du gut kaputt gemacht\n");
		return 0;
	}
//	printf("%d\n",input);
	if(input == 0){
		printf("null\n");
		return 0;
	}
	for(int i=0;i<4;++i){
		int currentthousand = input / teiler[i] % 1000;
//		printf("%d : %d %s\n",i,currentthousand,teilerzahl[i]);
		if(currentthousand != 0){
			int hunderter = currentthousand / 100 % 10;
			//printf("%d\n",hunderter);
			if(hunderter != 0)printf("%s%s",ziffern[hunderter-1],enden[3]);
			int zehner = currentthousand / 10 % 10;
			int einer = currentthousand % 10;
			//printf("%d %d %d\n",hunderter,zehner,einer);
			switch(zehner){
				case 2 ... 9:
//					printf("1\n");
					printf("%s%s%s%s%s",(hunderter != 0)?"und":"",(einer != 0)?ziffern[einer-1]:"",(einer != 0)?"und":"",(zehner == 2)?extras[4]:(zehner==7)?extras[5]:ziffern[zehner-1],enden[(zehner == 3)?2:1]);
					break;
				case 1:
//					printf("2\n");
					printf("%s%s%s",(hunderter!=0)?"und":"",(einer>2||einer==0)?ziffern[einer-1]:extras[einer],(einer>2||einer==0)?enden[0]:"");
					break;
				case 0:
//					printf("3\n");
					printf("%s%s",(hunderter!=0&&einer!=0)?"und":"",((einer>1)?ziffern[einer-1]:((einer==1)?((i==3)?extras[0]:(i<2)?extras[3]:ziffern[0]):"")));
			}
			printf("%s",teilerzahl[i]);
		}
	}
	printf("\n");
	return 0;
}
