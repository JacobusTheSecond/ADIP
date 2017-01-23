#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void max_heapify(int * arr, size_t n, size_t i)
{
	int mem;
	size_t x;
	if(2*i + 1 <= n)
	{
		max_heapify(arr, n, 2*i);
		max_heapify(arr, n, 2*i + 1);
		x = (arr[2*i] > arr[2*i+1]) ? 2*i : 2*i + 1;
		if(arr[i] < arr[x])
		{
			mem = arr[x];
			arr[x] = arr[i];
			arr[i] = mem;
			max_heapify(arr, n, x);
		}
	}
	else if(2*i <= n)
	{
		max_heapify(arr, n, 2*i);
		if(arr[i] < arr[2*i])
		{
			mem = arr[2*i];
			arr[2*i] = arr[i];
			arr[i] = mem;
			max_heapify(arr, n, 2*i);
		}
	}
}

void max_heap_do_insert(int * arr, size_t n, size_t i)
{
	int mem;
	if(i == 1) return;
	if(arr[i] > arr[i/2])
	{
		mem = arr[i];
		arr[i] = arr[i/2];
		arr[i/2] = mem;
		max_heap_do_insert(arr, n, i/2);
	}
}

void max_heap_insert(int ** arr, size_t * n, size_t * dyn_size, int elem)
{
	(*n)++;
	if(*n >= *dyn_size)
	{
		if(!((*arr) = realloc(*arr, *dyn_size * 2 * sizeof(int)))) abort();
	}
	(*arr)[*n] = elem;
	max_heap_do_insert(*arr, *n, *n);
}

void max_heap_remove_max(int * arr, size_t * n)
{
	size_t i = 1, x;
	int mem;
	arr[1] = arr[(*n)--];
	while(1)
	{
		if(2*i+1 <= *n)
		{
			x = (arr[2*i] > arr[2*i+1]) ? 2*i : 2*i + 1;
			if(arr[x] > arr[i])
			{
				mem = arr[i];
				arr[i] = arr[x];
				arr[x] = mem;
				i = x;
				continue;
			}
		}
		else if(2*i <= *n)
		{
			x = 2*i;
			if(arr[x] > arr[i])
			{
				mem = arr[i];
				arr[i] = arr[x];
				arr[x] = mem;
				i = x;
				continue;
			}
		}
		else break;
	}
}

int main()
{
	int arr_pre[] = {-1,2,5,10,3,7,9,22,1,5,8};//-1 als leeres element, damit index bei 1 anfaengt
	size_t n = sizeof(arr_pre)/sizeof(int) - 1;
	size_t dyn_size = n + 1;
	int * arr = malloc(sizeof(arr_pre));
	if(!arr) abort();
	memcpy(arr, arr_pre, sizeof(arr_pre));
	
	max_heapify(arr, n, 1);
	max_heap_insert(&arr, &n, &dyn_size, 99);
	max_heap_insert(&arr, &n, &dyn_size, 3);
	max_heap_remove_max(arr, &n);
	
	printf("(");
	for(size_t i = 1; i <= n; i++)
	{
		printf("%i ", arr[i]);
	}
	printf(")\n");
	return EXIT_SUCCESS;
}