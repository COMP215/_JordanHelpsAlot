#include<iostream>
#include"b.cpp"
#include"c.h"
using namespace std;

void SelectionSort(int* array, int array_size) {
	
	int min_index;
	for (int i = 0; i < array_size; i++){
		min_index = i; //Our proxy for i
		//Find the min in the balance of the array
		for (int j = i; j < array_size; j++){
			if (array[min_index] > array[j]){
				min_index = j;
			}
		}
		
		//swap the minimum element with the current array position;
		swap(array[i], array[min_index]);
	}

}

void BubbleSort(int* array, int array_size) {
	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < array_size - 1; i++){
			if (array[i] > array[i+1]) {
				swap(array[i], array[i+1]);
				swapped = true;
			}
		}
	}

}

//#include <conio.h>
void int_merge(int *,int, int , int );
void int_mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        int_mergesort(a,low,mid);
        int_mergesort(a,mid+1,high);
        int_merge(a,low,high,mid);
    }
    return;
}
void int_merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

/*
int* divide(int* array, int *array_size) {
	int mid = *array_size;
	if (mid % 2 != 0){
	    mid--;
	}
	mid = mid/2;
	*array_size = mid;
	int* sub_array = array + mid;
	return sub_array;
	}

int* divide(int* array, int *array_size) {
	int mid = *array_size;
	if (mid % 2 != 0){
	    mid--;
	}
	mid = mid/2;
	
	int sub_list_A[*array_size];
	
	for (short i=0; i<(*array_size-mid); i++){
	    sub_list_A[i] = array[i];
	}
	*array_size = mid;
	int* sub_list_B = array + mid;

	return sub_list_B;
	
}

void divide(int* array, int parent_size) {
	static int level = 0;
	level++;
	int mid = parent_size;
	int sizeA = 0, sizeB = 0;
	if (mid % 2 != 0){
	    mid--;
	}
	mid = mid/2;
	sizeA = parent_size - mid;
	sizeB = mid;
	
	int subarray_A[sizeA];
	for (short i=0; i<sizeA; i++){
	    subarray_A[i] = array[i];
	}
	int* subarray_B = array + mid;
	
	//A Sort
	cout << "LV:"<< level << " A:" << sizeA << " Value:";
	for (short i=0; i<sizeA; i++){
	    cout << subarray_A[i] << ", ";
	}
	cout << endl;
	if (sizeA > 2){divide(subarray_A, sizeA);}
	else if (sizeA > 1){
	    if (subarray_A[0] > subarray_A[1]){swap(subarray_A[0], subarray_A[1]);}
	}
	cout << "UPDATE A: ";
	for (short i=0; i<sizeA; i++){
	    cout << subarray_A[i] << ", ";
	}
	cout << endl;
	
	//B Sort
	cout << "LV:"<< level << " B:" << sizeB << " Value:";
	for (short i=0; i<sizeB; i++){
	    cout << subarray_B[i] << ", ";
	}
	cout << endl;
	if (sizeB > 2){divide(subarray_B, sizeB);}
	else if (sizeB > 1){
	    if (subarray_B[0] > subarray_B[1]){swap(subarray_B[0], subarray_B[1]);}
	}
	cout << "UPDATE B: ";
	for (short i=0; i<sizeB; i++){
	    cout << subarray_B[i] << ", ";
	}
	cout << endl;
	
	
	level--;
	return;
	
}
*/

int** divide(int* array, int array_size) {
    int** pair_array = new int*[array_size];
    int j = 0;
    for (short i=0; i<array_size; i++){
        pair_array[i] = new int[2];
    }
    for (short i=0; i<array_size; i++){
		pair_array[j][0] = array[i];
		i++;
		pair_array[j][1] = array[i];
        j++;
    }
	return pair_array;
	
}

void first_sort(int** pair_array, int pair_array_size){
	for (short i=0; i<pair_array_size; i++){
		if (pair_array[i][0] > pair_array[i][1]){
			swap(pair_array[i][0], pair_array[i][1]);
			cout << "SWAP:" << pair_array[i][0] << " | " << pair_array[i][1] << endl;
		}
	}
	return;
}

/*
int* merge(int* subarray_A, int sizeA, int* subarray_B, int sizeB){
	int* windowA = &subarray_A[0];
	int* windowB = &subarray_B[0];
	int* combined = new int[sizeA + sizeB];
	for (short i=0; i<(sizeA + sizeB); i++){
		if (*windowA < *windowB){
			combined[i] = *windowA;
			windowA++;
		}
		else{
			combined[i] = *windowB;
			windowB++;
		}
	}
	return combined;

}
*/

int* merge(int* subarray_A, int sizeA, int* subarray_B, int sizeB){
	int windowA = subarray_A[0];
	if (windowA == 0){return subarray_B;}
	int windowB = subarray_B[0];
	if (windowB == 0){return subarray_A;}
	int indexA = 0;
	int indexB = 0;
	int* combined = new int[sizeA + sizeB];
	for (short i=0; i<(sizeA + sizeB); i++){
		//cout << "Round: " << i << endl;
		//cout << "\tWinA: " << windowA << " | WinB: " << windowB << endl;
		if (indexA < (sizeA) && indexB < (sizeB)){
			windowA = subarray_A[indexA];
			windowB = subarray_B[indexB];
			if (windowA < windowB){
				combined[i] = windowA;
				indexA++;
				//windowA = subarray_A[indexA];
			}
			else{
				combined[i] = windowB;
				indexB++;
				//windowB = subarray_B[indexB];
			}
		}
		else if (indexA >= (sizeA)){
			cout << "Streaming: " << windowB << endl;
			combined[i] = windowB;
			indexB++;
			windowB = subarray_B[indexB];
		}
		else if (indexB >= (sizeB)){
			cout << "Streaming: " << windowA << endl;
			combined[i] = windowA;
			indexA++;
			windowA = subarray_A[indexA];
		}
	}
	cout << "COMB: ";
	for (short i=0; i<4; i++){
		cout << combined[i] << ", ";
	}
	cout << endl << endl;
	return combined;

}

void MergeSort(int* array, int array_size) {
	//int* array_sZ = &array_size;
	static int original_size = array_size;
	int** pair_array;
	int** quad_array = new int*[100];
	int extra_value = 0;
	pair_array = divide(array, array_size);
	int pair_array_size = array_size;

	if (pair_array_size % 2 != 0){
	    pair_array_size--;
	    pair_array_size = pair_array_size/2;
	    extra_value = pair_array[pair_array_size][0];
	}
	else{
		pair_array_size = pair_array_size/2;
	}
	cout << "EXTRA: " << extra_value << endl;
	first_sort(pair_array, pair_array_size);
	
	int* test;
	//test = merge(pair_array[0], 2, pair_array[1], 2);
	//cout << test[0] << ", " << test[1] << ", " << test[2] << ", " << test[3] << endl;
	//int part1[6] = {12, 31, 33, 49, 56, 81};
	//int part2[0];
	//test = merge(part1, 6, part2, 3);
	//for (short i = 0; i < 9; i++){
	//	cout << test[i] << ", ";
	//}
	//cout << endl;
	int j=0;
	if (pair_array_size % 2 != 0){
		for (short i=0; i<pair_array_size-1; i++){
			//quad_array[j] = new int[4];
			quad_array[j] = merge(pair_array[i], 2, pair_array[i+1], 2);
			i++;
			j++;
		}
		cout << "J:" << j << endl;
	}
	
	
	for (short i = 0; i < 4; i++){
		cout << quad_array[0][i] << ", ";
	}
	cout << endl;
	
	cout << "Pairs:" << endl;
	for (short i=0; i<pair_array_size; i++){
		cout << endl;
		for (short j=0; j<2; j++){
			cout << pair_array[i][j] << endl;
		}
    }
	cout << "array size: " << array_size << ", " << array_size << endl;
	/*
	for ( int i = 0; i < array_size; i++) {
		cout << sub_array[i] << endl << endl;
	}
	*/
	
}

int main(){
	int numbers[] = { 81, 4, 90, 72, 17, 80, 5, 12, 114, 38, 56 };
	
	//SelectionSort(numbers, 7);
	//BubbleSort(numbers, 7);
	int_mergesort(numbers, 0, 10);	//From internet
	//MergeSort(numbers, 11);	Not finished
	
	for ( int i = 0; i < 11; i++) {
		cout << numbers[i] << endl;
	}
	return 0;
	
	}
	
