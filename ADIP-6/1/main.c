#include <stdio.h>
#include <stdlib.h>

typedef struct DynArray{
	int max;
	int current;
	void ** array;
} DynArray;

void addItem_pluseins(DynArray* Array ,void* a){
	if(Array->current == Array->max){
		Array->array = realloc(Array->array,sizeof(void*)*(Array->max+1));
		++Array->max;
	}
	Array->array[Array->current]=a;
	++Array->current;
}

void addItem_malzwei(DynArray* Array ,void* a){
	if(Array->current == Array->max){
		Array->array = realloc(Array->array,sizeof(void*)*2*Array->max);
		Array->max *= 2;
	}
	Array->array[Array->current]=a;
	++Array->current;
}

void print(DynArray* Array){
	for(int i = 0;i<Array->current;++i){
		printf("%d\n",*((int*)Array->array[i]));
	}
}

int main(){
	DynArray* array = calloc(1,sizeof(DynArray));
	array->max = 1;
	array->array = calloc(1,sizeof(void*));
	int p = 1;
	int * a = &p;

	for(int i = 0;i<10;++i)
		addItem_malzwei(array,a);

	print(array);
	printf("%d\n",array->max);

	for(int i=0;i<10;++i){
		addItem_pluseins(array,a);
	}
	
	print(array);
	printf("%d\n",array->max);

	free(array->array);
	free(array);
}
