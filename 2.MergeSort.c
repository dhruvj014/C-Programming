#include <stdio.h>
#include <conio.h>

void merge(int a[100], int low, int mid, int high)
{
    int b[100];
    int i = low;
    int k = low;
    int j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int a[100], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int i, n, a[100];
    printf("Enter the number of elements:");
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        printf("Enter the value:");
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("After Sorting:\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
