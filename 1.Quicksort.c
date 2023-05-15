#include <stdio.h>

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j = low;j<=high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quickSort(int arr[],int low, int high)
{
    if (low<high)
    {
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

void main()
{
    int arr[] = {8,7,3,7,9,4,3,2};
    int size = 8;
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nSorted Array - \n");
    quickSort(arr,0,size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
