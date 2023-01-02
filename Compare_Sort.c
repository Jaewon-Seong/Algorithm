#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void selectionSort(double arrSelect[], int size);
void bubbleSort(double arrBubble[], int size);
void insertSort(double arrInsert[], int size);
void mergeSort(double arrMerge[], int left, int right);
void merge(double arrMerge[], int left, int mid, int right);
void quickSort(double arrQuick[], int size);
void heapSort(double arrHeap[], int size);
void buildHeap(double arrHeap[], int size);
void heapify(double arrHeap[], int parent, int size);

double* arrSelect;
double* arrBubble;
double* arrInsert;
double* arrMerge;
double* arrQuick;
double* arrHeap;

double* sortedMerge;
double tmp;

int main()
{
	srand((unsigned int)time(NULL));
	clock_t start, end;

	for (int n = 1000; n <= 20000; n += 1000)
	{
		arrSelect = (double*)malloc(sizeof(double) * n);
		arrBubble = (double*)malloc(sizeof(double) * n);
		arrInsert = (double*)malloc(sizeof(double) * n);
		arrMerge = (double*)malloc(sizeof(double) * n);
		arrQuick = (double*)malloc(sizeof(double) * n);
		arrHeap = (double*)malloc(sizeof(double) * n);
		sortedMerge = (double*)malloc(sizeof(double) * n);

		for (int i = 0; i < n; i++)
		{
			double random = (double)(rand() % 200) * 0.01f - 1;
			arrSelect[i] = random;
			arrBubble[i] = random;
			arrInsert[i] = random;
			arrMerge[i] = random;
			arrQuick[i] = random;
			arrHeap[i] = random;
		}
		
		printf("\n Selection n = %d\n", n);
		start = clock();
		selectionSort(arrSelect, n);
		end = clock();
		printf("Time : %lfms\n", 1000 * ((double)(end)-(double)start) / CLOCKS_PER_SEC);

		printf("\n Bubble n = %d\n", n);
		start = clock();
		bubbleSort(arrBubble, n);
		end = clock();
		printf("Time : %lfms\n", 1000 * ((double)(end)-(double)start) / CLOCKS_PER_SEC);
		
		printf("\n Insertion n = %d\n", n);
		start = clock();
		insertSort(arrInsert, n);
		end = clock();
		printf("Time : %lfms\n", 1000 * ((double)(end)-(double)start) / CLOCKS_PER_SEC);
		
		printf("\n Merge n = %d\n", n);
		start = clock();
		mergeSort(arrMerge, 0, n - 1);
		end = clock();
		printf("Time : %lfms\n", 1000 * ((double)(end)-(double)start) / CLOCKS_PER_SEC);
		
		printf("\n Quick n = %d\n", n);
		start = clock();
		quickSort(arrQuick, n);
		end = clock();
		printf("Time : %lfms\n", 1000 * ((double)(end)-(double)start) / CLOCKS_PER_SEC);
		
		printf("\n Heap n = %d\n", n);
		start = clock();
		heapSort(arrHeap, n);
		end = clock();
		printf("Time : %lfms\n", 1000 * ((double)(end)-(double)start) / CLOCKS_PER_SEC);
		
		free(arrSelect);
		free(arrBubble);
		free(arrInsert);
		free(arrMerge);
		free(arrQuick);
		free(arrHeap);
		free(sortedMerge);
	}
	return 0;
}

void selectionSort(double arrSelect[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arrSelect[i] > arrSelect[j])		//Exchange by comparing the value of the index with the value located behind it
			{
				tmp = arrSelect[i];
				arrSelect[i] = arrSelect[j];
				arrSelect[j] = tmp;
			}
		}
	}
}

void bubbleSort(double arrBubble[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arrBubble[j] > arrBubble[j + 1])		//Exchange by comparing the value in the array with the value located behind it
			{
				tmp = arrBubble[j];
				arrBubble[j] = arrBubble[j + 1];
				arrBubble[j + 1] = tmp;
			}
		}
	}
}

void insertSort(double arrInsert[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;

		while (arrInsert[j] > arrInsert[j + 1] && j >= 0)		//Compare the values in the array with the values in front of it and insert them into your location
		{
			tmp = arrInsert[j];
			arrInsert[j] = arrInsert[j + 1];
			arrInsert[j + 1] = tmp;
			j--;
		}
	}
}
void mergeSort(double arrMerge[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;		//Define location index for dividing an array in half
		mergeSort(arrMerge, left, mid);		//Front of array divided by half
		mergeSort(arrMerge, mid + 1, right);		//After of array divided by half
		merge(arrMerge, left, mid, right);		//Sort and merge arrays by dividing them
	}
}

void merge(double arrMerge[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;		//병합할 배열의 index

	while (i <= mid && j <= right)
	{
		if (arrMerge[i] < arrMerge[j])		//If the value after an array is larger, store the value before it in the array to be sorted
		{
			sortedMerge[k++] = arrMerge[i++];
		}
		else		//If the value after an array is smaller, store the value before it in the array to be sorted
		{
			sortedMerge[k++] = arrMerge[j++];
		}
	}
}

void quickSort(double arrQuick[], int size)
{
	int left = 0, right = size, pivot = 0;

	if (size <= 1)		//Condition for terminating a function call when there are no more values to compare
		return;

	while (1)
	{
		while (arrQuick[++left] < arrQuick[pivot])	//Move left index to the right, ensuring that there is a value greater than the value of the pivot position from the left of the array
			;
		while (arrQuick[--right] > arrQuick[pivot])	//Move right index to the right, ensuring that there is a value greater than the value of the pivot position from the right of the array
			;

		if (left < right)		//Process of ascending sort  on a pivot basis
		{
			tmp = arrQuick[left];
			arrQuick[left] = arrQuick[right];
			arrQuick[right] = tmp;
		}
		else
			break;
	}

	tmp = arrQuick[pivot];
	arrQuick[pivot] = arrQuick[right];
	arrQuick[right] = tmp;

	quickSort(arrQuick, right);		//Recursive function call from the first to the right
	quickSort(arrQuick + left, size - left);		//Recursive function call from the right to the end
}

void heapSort(double arrHeap[], int size)
{
	int length = size;

	buildHeap(arrHeap, size);		//Create an array into heap structures

	while (length > 1)
	{		//Reduce the range of trees to explore
		tmp = arrHeap[0];
		arrHeap[0] = arrHeap[length - 1];
		arrHeap[length - 1] = tmp;
				
		length--;
		heapify(arrHeap, 0, length);		//Recursive run until the root has the lowest value
	}
}

void buildHeap(double arrHeap[], int size)
{
	int parent = (size - 1) / 2;

	for (int i = parent; i >= 0; i--)
		heapify(arrHeap, i, size);		//Maintaining the structure of the heap
}

void heapify(double arrHeap[], int parent, int size)		//The process of raising the largest value up
{
	int root = parent;
	int leftChild = parent * 2 + 1;
	int rightChild = parent * 2 + 2;
	int largest = root;

	if (leftChild < size && arrHeap[leftChild] > arrHeap[largest])		//Replace the largest index with the index of the left child node if the value f the left child is greater than the value of the parent
		largest = leftChild;
	if (rightChild < size && arrHeap[rightChild] > arrHeap[largest])
		largest = rightChild;

	if (largest != parent)		//If the value of the largest index has been replaced by the index of the child node, replace the value of the parent with the valude of the child
	{
		tmp = arrHeap[largest];
		arrHeap[largest] = arrHeap[parent];
		arrHeap[parent] = tmp;
		heapify(arrHeap, largest, size);
	}
}
