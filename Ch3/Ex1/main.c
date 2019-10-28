#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch_better(int x, int v[], int n);

int main() {
	int sorted_array[] = {0,1,2,3,4,5,6,7,8,9};

	clock_t start, end;
	start = clock();
	int bin1res = binsearch(4,sorted_array,10);
	end = clock();
	double time_taken = (double)(start - end) / CLOCKS_PER_SEC;
	printf("Result is %d, took %f sec to execute.\n", bin1res, time_taken);

	start = clock();
	int bin2res = binsearch_better(6,sorted_array,10);
	end = clock();
	time_taken = (double)(start - end) / CLOCKS_PER_SEC;
	printf("Result is %d, took %f sec to execute\n", bin2res, time_taken);

	return 0;
}


// Binary search but better
int binsearch_better(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n -1;
	mid = (low + high)/2;
	while(low <= high) {
		if(x < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	if(x == v[mid]) {
		return mid;
	} else 
		return -1;
}


// Binary search: Find x in v[0] <= v1 <= .... v[n-1]
int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;

	while(low <= high) {
		mid = (low + high)/2;
		if(x < v[mid]) {
			high = mid + 1;
		} else if(x > v[mid]) {
			low = mid + 1;
		} else 
			return mid;
	}

	return -1;
}