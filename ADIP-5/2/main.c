#include <stdio.h>
#include <stdlib.h>

typedef struct doubleMartix{
		int width;
		int height;
		double ** data;
	}doubleMatrix;

int matrixmult(doubleMatrix * A, doubleMatrix * B,doubleMatrix* R){
	if(A->width != B->height){
		return EXIT_FAILURE;	
	}
	R->data = (double**) malloc(sizeof(double*)*A->height);
	R->height = A->height;
	R->width = B->width;
	for(int Rh=0;Rh<R->height;++Rh){
		R->data[Rh] = (double*) calloc(sizeof(double),R->width);
		for(int Rw = 0;Rw<R->width;++Rw){
			for(int i = 0; i<A->width;++i){
				R->data[Rh][Rw]+=A->data[Rh][i]*B->data[i][Rw];
			}
		}
	}
	return EXIT_SUCCESS;
}

int readMatrix(doubleMatrix* MP, char* s){
	printf("%s einlesen:\n",s);
	printf("   Höhe eingeben:\n   ");
	scanf(" %d", &(MP->height));
	MP->data = (double**) malloc(sizeof(double*)*MP->height);
	printf("   Weite eingeben:\n   ");
	scanf(" %d",&(MP->width));
	for(int i=0;i<MP->height;++i){
		MP->data[i]=(double*) malloc(sizeof(double)*MP->width);
		for(int j=0;j<MP->width;++j){
			printf("   %s[%d][%d] eingeben:\n   ",s,i,j);
			scanf("%lf",&(MP->data[i][j]));
		}
	}
	return EXIT_SUCCESS;
}

int freeMatrix(doubleMatrix * A){
	for(int i = 0; i<A->height;++i){
		free(A->data[i]);
	}
	free(A->data);
	free(A);
	return EXIT_SUCCESS;
}

int printMatrix(doubleMatrix* M){
	for(int i=0;i<M->height;++i){
		printf("| ");
		for(int j=0;j<M->width;++j){
			printf("%5g ", M->data[i][j]);
		}
		printf("|\n");
	}
	return EXIT_SUCCESS;
}

int main(){
	doubleMatrix* A = malloc(sizeof(doubleMatrix));
	doubleMatrix* B = malloc(sizeof(doubleMatrix));
	readMatrix(A,"A");
	readMatrix(B,"B");
	doubleMatrix* R = malloc(sizeof(doubleMatrix));
	matrixmult(A,B,R);
	printMatrix(R);
	freeMatrix(A);
	freeMatrix(B);
	freeMatrix(R);
}
