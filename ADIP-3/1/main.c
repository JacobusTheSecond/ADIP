#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int draw(char* name,int hooman){
	int sum = 0,k;
	char input = 'n';
	while(!hooman && sum <= 16  || input == 'n'){
		k =  (rand()/(RAND_MAX/9))+2;
		sum += k;
		printf("%s drew %d, %s got %d\n",name,k,name,sum);
		if(sum >= 21)return sum;
		if(hooman)printf("[n]ext card\n[q]uit\n"),scanf(" %c",&input);

	}
	return sum;
}
int main(){
	srand(time(NULL));
	int deins = draw("You",1);
	if(deins > 21 ){printf("busted, you lost\n");return 0;}
	int dealer = draw("Dealer",0);
	if(dealer > 21 ){printf("dealer busted. you won\n");return 0;}
	(dealer >deins)?printf("you lost\n"):((dealer == deins)?printf("draw\n"):printf("you won\n"));
	return 0;
}
