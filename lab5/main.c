#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int *generate_random_array(int *arr, int n)
{
 for(int i=0; i<n; i++)
 {
 arr[i] = rand() % n;
 }
 return arr;
}
void print_array(int arr[], int n)
{
 for(int i=0; i<n; i++)
 {
 printf("%d, ", arr[i]);
 }
 printf("\n");
}
void selection_sort(int arr[], int n)
{
 for(int i=0; i<n-1; i++)
 {
 int min_idx = i;
 for(int j=i+1; j<n; j++)
 {
 if(arr[j]<arr[min_idx])
 min_idx = j;
 if(min_idx != i)
 {
 int temp = arr[min_idx];
 arr[min_idx] = arr[i];
 arr[i] = temp;
 }
 }
 }
}
void insertion_sort(int arr[], int n)
{
 int i, key, j;
 for (i = 1; i < n; i++)
 {
 key = arr[i];
 j = i - 1;
 while (j >= 0 && arr[j] > key)
 {
 arr[j + 1] = arr[j];
 j = j - 1;
 }
 arr[j + 1] = key;
 }
}
void bubble_sort(int arr[], int n)
{
 for(int i=0; i<n; i++)
 {
 for(int j=0; j<n; j++)
 {
 if(arr[i] < arr[j])
 {
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 }
 }
 }
}
void merge(int arr[], int l, int m, int r)
{
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 /* create temp arrays */
 int L[n1], R[n2];
 /* Copy data to temp arrays L[] and R[] */
 for (i = 0; i < n1; i++)
 L[i] = arr[l + i];
 for (j = 0; j < n2; j++)
 R[j] = arr[m + 1 + j];
 /* Merge the temp arrays back into arr[l..r]*/
 i = 0; // Initial index of first subarray
 j = 0; // Initial index of second subarray
 k = l; // Initial index of merged subarray
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k] = L[i];
 i++;
 }
 else {
 arr[k] = R[j];
 j++;
 }
 k++;
 }
 /* Copy the remaining elements of L[], if there
 are any */
 while (i < n1) {
 arr[k] = L[i];
 i++;
 k++;
 }
 /* Copy the remaining elements of R[], if there
 are any */
 while (j < n2) {
 arr[k] = R[j];
 j++;
 k++;
 }
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r)
{
 if (l < r) {
 // Same as (l+r)/2, but avoids overflow for
 // large l and h
 int m = l + (r - l) / 2;
 // Sort first and second halves
 merge_sort(arr, l, m);
 merge_sort(arr, m + 1, r);
 merge(arr, l, m, r);
 }
}
int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = (low - 1);
 for (int j = low; j <= high - 1; j++) {
 if (arr[j] < pivot) {
 i++;
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 }
 }
 int temp = arr[i+1];
 arr[i+1] = arr[high];
 arr[high] = temp;
 return (i + 1);
}
 void quickSort(int arr[], int low, int high) {
 if (low < high) {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
void heapify(int arr[], int N, int i)
{
 int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < N && arr[left] > arr[largest])
 largest = left;
 if (right < N && arr[right] > arr[largest])
 largest = right;
 if (largest != i) {
 int temp = arr[i];
 arr[i] = arr[largest];
 arr[largest] = temp;
 heapify(arr, N, largest);
 }
}
void heapSort(int arr[], int N)
{
 for (int i = N / 2 - 1; i >= 0; i--)
 heapify(arr, N, i);
 for (int i = N - 1; i >= 0; i--) {
 int temp = arr[0];
 arr[0] = arr[i];
 arr[i] = arr[0];
 heapify(arr, i, 0);
 }
}
void show_menu();
int main()
{
 system("COLOR A");
 int n;
 show_menu();
 scanf("%d", &n);
 int *arr, size;
 do
 {
 switch(n)
 {
 case 1:
 {
 int elem;
 printf("Numarul de elemente:\n");
 printf("1)100\n2)1000\n3)10000\n4)100000\n");
 scanf("%d", &elem);
 if(elem == 1)
 size = 100;
 else if(elem == 2)
 size = 1000;
 else if(elem == 3)
 size = 10000;
 else if(elem == 4)
 size = 100000;
 arr = (int*)malloc(size*sizeof(int));
 arr = generate_random_array(arr, size);
 break;
 }
 case 2:
 {
 print_array(arr, size);
 break;
 }
 case 3:
 {
 free(arr);
 printf("Memoria a fost eliberata");
 break;
 }
 case 4:
 {
 double time_selection_sort = 0.0;
 clock_t begin = clock();
 selection_sort(arr, size);
 clock_t end = clock();
 time_selection_sort += (double)(end - begin) / CLOCKS_PER_SEC;
 printf("The elapsed time is %f seconds\n", time_selection_sort);
 break;
 }
 case 5:
 {
 double time_insertion_sort = 0.0;
 clock_t begin = clock();
 insertion_sort(arr, size);
 clock_t end = clock();
 time_insertion_sort += (double)(end - begin) / CLOCKS_PER_SEC;
 printf("The elapsed time is %f seconds\n", time_insertion_sort);
 break;
 }
 case 6:
 {
 double time_bubble_sort = 0.0;
 clock_t begin = clock();
 bubble_sort(arr, size);
 clock_t end = clock();
 time_bubble_sort += (double)(end - begin) / CLOCKS_PER_SEC;
 printf("The elapsed time is %f seconds\n", time_bubble_sort);
 break;
 }
 case 7:
 {
 double time_merge_sort = 0.0;
 clock_t begin = clock();
 merge_sort(arr, 0, size - 1);
 clock_t end = clock();
 time_merge_sort += (double)(end - begin) / CLOCKS_PER_SEC;
 printf("The elapsed time is %f seconds\n", time_merge_sort);
 break;
 }
 case 8:
 {
 double time_quickSort = 0.0;
 clock_t begin = clock();
 quickSort(arr, 0, size - 1);
 clock_t end = clock();
 time_quickSort += (double)(end - begin) / CLOCKS_PER_SEC;
 printf("The elapsed time is %f seconds\n", time_quickSort);
 break;
 }
 case 9:
 {
 double time_heapSort = 0.0;
 clock_t begin = clock();
 heapSort(arr, size);
 clock_t end = clock();
 time_heapSort += (double)(end - begin) / CLOCKS_PER_SEC;
 printf("The elapsed time is %f seconds\n", time_heapSort);
 break;
 }
 case 10:
 {
 printf("-------------------------------------------------------------\n");
 printf("| N | 100 | 1000 | 10000 | 100000 |\n");
 printf("-------------------------------------------------------------\n");
 printf("|selection sort | 0.006000 | 0.031000 | 0.487000 | 35.941000|\n");
 printf("-------------------------------------------------------------\n");
 printf("|insertion sort | 0.000000 | 0.026000 | 0.270000 | 7.907000 |\n");
 printf("-------------------------------------------------------------\n");
 printf("|bubble sort | 0.000000 | 0.032000 | 0.530000 | 31.458000|\n");
 printf("-------------------------------------------------------------\n");
 printf("|merge sort | 0.000000 | 0.000000 | 0.003000 | 0.016000 |\n");
 printf("-------------------------------------------------------------\n");
 printf("|quick sort | 0.000000 | 0.000000 | 0.015000 | 0.016000 |\n");
 printf("-------------------------------------------------------------\n");
 printf("|heap sort | 0.000000 | 0.000000 | 0.000000 | 0.032000 |\n");
 printf("-------------------------------------------------------------\n");
 }
 }
 show_menu();
 scanf("%d", &n);
 }
 while(n>=1 && n <=9);
 free(arr);
 return 0;
}
void show_menu()
{
 printf("------------------------------------------------------\n");
 printf("|1)Initializarea tabloului cu numere aleatorii |\n");
 printf("------------------------------------------------------\n");
 printf("|2)Afisarea tabloului |\n");
 printf("------------------------------------------------------\n");
 printf("|3)Eliberarea memoriei tabloului |\n");
 printf("------------------------------------------------------\n");
 printf("|4)Sortarea tabloului utilizand metoda selection sort|\n");
 printf("------------------------------------------------------\n");
 printf("|5)Sortarea tabloului utilizand metoda insertion sort|\n");
 printf("------------------------------------------------------\n");
 printf("|6)Sortarea tabloului utilizand metoda bubble sort |\n");
 printf("------------------------------------------------------\n");
 printf("|7)Sortarea tabloului utilizand metoda merge sort |\n");
 printf("------------------------------------------------------\n");
 printf("|8)Sortarea tabloului utilizand metoda quick sort |\n");
 printf("------------------------------------------------------\n");
 printf("|9)Sortarea tabloului utilizand metoda heap sort |\n");
 printf("------------------------------------------------------\n");
 printf("|10)Printarea tabloului cu timpul de sortare |\n");
 printf("------------------------------------------------------\n");
 printf("|0) Exit |\n");
 printf("------------------------------------------------------\n");
}

