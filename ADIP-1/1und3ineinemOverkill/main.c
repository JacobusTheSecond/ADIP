#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//clock_t start, end; double cpu_time_used; start = clock(); DOWORK end = clock; cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
#define FILENAME "/home/jacobus/C/primes/.primelist.txt"

//arraystruct to pass multiple primes
typedef struct array {
		 void* a;
		int length;
		} array;

//the amount of primes saved in FILENAME
int currsize;

//modify array, to hold either the needed or the available amount of primes
void getPrimesFromFile(int amount, array* primes)
{
	//if we already have the needed amount of primes, we wont have to read anything
	if(primes->length >= amount)
	{
		return;
	}

	//init file
	FILE* fp = fopen(FILENAME,"a+");
	char line[1024];

	//very bad check wether FILENAME is empty or not
	//checks wether or not the first char is a number or not
	char c;
	fread(&c,1,1,fp);
	if(!(c - '0' >=0 && c - '0' <=9)){

		//if FILENAME is empty, return hardcoded array of primes from
		//2 to 5
		primes->a = malloc(3*sizeof(long long));
		((long long*)primes->a)[0] = 2;
		((long long*)primes->a)[1] = 3;
		((long long*)primes->a)[2] = 5;
		primes->length = 3;

		//returning
		fclose(fp);
		return;
	}
	rewind(fp);
	clock_t start,end;
	double cpu_time_used;
	start=clock();
	//begin reading the file, by reading the amount of primes saved
	//in the first line
	fgets(line,1024,fp);

	//save it for repurposing later, as well as currsize, for checks in 
	//writePrimesToFile()
	int length =atoi(line);
	currsize = length;

	//creating array
	primes->a = malloc(amount*sizeof(long long));
	//inits for loop
	long long value;
	int i = 0;

	//loop to read the file until we either reach either
	// 1. EOF, or
	// 2. the amount of stored primes, or
	// 3. the length or array
	while(fgets(line,1024,fp) && i < length && i < amount)
	{
		//printf("%s",line);
		sscanf(line,"%lli",&value);
		//printf("%lli\n",value);
		((long long*) primes->a)[i] = value;
		++i;
	}

	//saving the actual amount of recieved primes in array length
	primes->length = i;
	end = clock();
	cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("%f Sekunden gebraucht um Primzahlen auszulesen\n", cpu_time_used);
	//returning
	fclose(fp);
	return;
}

//writes all primes into FILENAME
int writePrimesToFile(array* primes)
{
	//if we have more primes stored in the file than in the array, then
	//there is no need to overwrite anything
	//printf("%d &d",currsize,primes->length);
	if(currsize >= primes->length){return 0;}

	//output information, in case this takes long
	printf("writing into file...\n");
	//has to be in overwrite mode, incase the length of the first line
	//changes.
	FILE* fp = fopen(FILENAME,"w+");

	//first write amount of primes into first line of FILENAME
	char buff[1024];
	sprintf(buff,"%d",primes->length);
	fputs(buff,fp);
	fputs("\n",fp);

	//write array with 1 entry per line into FILENAME
	for(int i=0; i<primes->length;++i){
		sprintf(buff,"%lli",((long long*)primes->a)[i]);
		fputs(buff,fp);
		fputs("\n",fp);
	}

	//returning
	fclose(fp);
	return EXIT_SUCCESS;
}

int main()
{
	array primearray = {a:(void*)0,length:0};
	array* primes = &primearray;
	//loop, so user doesnt have to restart programm
	int cont = 1;
	while(cont == 1){

		//get long long from User
		long long n;
		printf("ganze Zahl eingeben:\n");
		scanf("%lli",&n);
		if(n<0){
			printf("%lli ist negativ. es wird mit %lli fortgefahren.\n", n, -1*n);
			n *=-1;
		}
		printf("----------------------------------------------\n");
		//calculates the upperbound of primes up to sqrt(n). this upper bound
		//will be needed, to not retrieve too many primes from FILENAME, to
		//save runtime. It also serves as the size the array has to be
		//reallocated to, incase FILENAME does not have enough primes stored
		long long sqrn = sqrt(n) + 1;
		double upperbound = sqrn/log(sqrn)*(1+1.2762f/log(sqrn)) + 1;

		//safeguard in case upperbound goes negative. if this ever happens the programm will mostlikey die
		if(upperbound<0)
		{
			upperbound = sqrn;
		}

		//fill array with primes, if we need more
		getPrimesFromFile( (int)floor(upperbound) , primes );

		//if there are not enough primes, calculate needed amount of primes
		if(((long long*)primes->a)[primes->length - 1]<=((long long)sqrt(n)))
		{
			clock_t start,end;
			double cpu_time_used;
			start = clock();
			//reallocates array to the upperbound of primes needed to check
			//if n is prime or not
			primes->a = realloc(primes->a,(int)floor(upperbound) * sizeof(long long));

			//starts calculating needed amount of primes
			printf("%d Primzahlen werden generiert\n",(int)floor(upperbound));

			//init of additional variables for loop
			int i = primes->length;
			int risprime;

			//highest known prime sofar + 1
			long long r = ((long long*)primes->a)[primes->length-1] +1;

			//calculate primes, until upperbound of primes needed is reached
			while(i<(int)floor(upperbound))
			{

				//output every 10000 new primes, that something is happening
				if(i%10000==0){printf("\r %d Primzahlen bis jetzt generiert",i);}

				//checks if r is prime or not, but looking, if any primenumber
				//p from the primearray divides r, where p² <= r
				risprime=1;
				for(int j = 0; ((long long*)primes->a)[j] < sqrt(r)+1 && j<i; ++j)
				{
					if(r%((long long*)primes->a)[j] == 0){
						risprime = 0;
						break;
					}
				}

				//if r is a prime, we add it to the primearray, and increase the amount
				//of primes found sofar by one
				if(risprime==1)
				{
					((long long*)primes->a)[i] = r;
					++i;
				}

				//increase r. This is inefficient, because we know, that primes can only occur 
				//on odd numbers, for r>2, however the programm ran into weird issues, when
				//implementing it with r+=2
				++r;
			}
			end = clock();
			cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
			//when all upperbound primes have been calculated, resize array
			primes->length = i;

			//and output
			printf("Primzahlen bis %lli wurden generiert\n", ((long long*)primes->a)[primes->length - 1]);
			printf("Primzahlen berechnen hat %f Sekunden gedauert\n",cpu_time_used);
		}

		//attempt to write primes into FILENAME
		writePrimesToFile(primes);

		//array for saving the primdividors of n
		array primedividors = {a:malloc((int)(1.443f*log(n)*(sizeof(long long)+1))),length:0};
		array* PTs = &primedividors;
		//finally check, if n is prime, and output accordingly
		int prime = 1;
		long long outputn = n;
		int i=0;
		clock_t start,end;
		double cpu_time_used;
		start=clock();
		while(((long long*)primes->a)[i] < sqrt(n)+1)
		{
			if(n!=((long long*)primes->a)[i] && n%((long long*)primes->a)[i]==0)
			{
				n/=((long long*)primes->a)[i];
				((long long*)PTs->a)[PTs->length]=((long long*)primes->a)[i];
				++(PTs->length);
				prime = 0;
			}else{
				i++;
			}
		}
		end = clock();
		cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
		printf("%lli auf Primzahl überprüfen hat %f Sekunden gedauert\n",outputn,cpu_time_used);
		printf("----------------------------------------------\n");
		if(prime== 1)
		{
			printf("%lli ist eine Primzahl\n",outputn);
		}
		else
		{
			printf("%lli ist keine Primzahl. %lli = 1 * ",outputn,outputn);
			for(int i=0;i<(PTs->length);++i)
			{
				printf("%lli * ",((long long*)PTs->a)[i]);
			}
			printf("%lli\n",n);
		}
		free(PTs->a);
		//repeat process, until User is tired
		printf("Noch eine? [ℝ \\{0}=Ja, 0=Nein]\n");
		scanf("%d",&cont);
		if(cont != 0 && cont != 1){
			cont = 1;
		}
	}

	//if we are done, free array
	free(primes->a);
	return EXIT_SUCCESS;
}

