#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    int stack[high - low + 1];

    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        int pi = partition(arr, low, high);

        if (pi - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high)
        {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

int main()
{
    int i, n;
    clock_t start, end;
    double time_used;

    n = 50000;
    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr1[i] = i;
        arr2[i] = i;
    }

    start = clock();
    mergeSort(arr1, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("升序数据（数据量：%d）\n归并排序 耗时：%f秒\n", n, time_used);

    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序 耗时：%f秒\n\n", time_used);

    free(arr1);
    free(arr2);

    n = 50000;
    arr1 = (int *)malloc(n * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr1[i] = n - i - 1;
        arr2[i] = n - i - 1;
    }

    start = clock();
    mergeSort(arr1, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("降序数据（数据量：%d）\n归并排序 耗时：%f秒\n", n, time_used);

    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序 耗时：%f秒\n\n", time_used);

    free(arr1);
    free(arr2);

    n = 50000;
    arr1 = (int *)malloc(n * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr1[i] = rand() % n;
        arr2[i] = arr1[i];
    }

    start = clock();
    mergeSort(arr1, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("无序数据（数据量：%d）\n归并排序 耗时：%f秒\n", n, time_used);

    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序 耗时：%f秒\n\n", time_used);

    free(arr1);
    free(arr2);

    n = 100000;
    int *arr4 = (int *)malloc(n * sizeof(int));
    int *arr5 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr4[i] = rand() % n;
        arr5[i] = arr4[i];
    }

    start = clock();
    mergeSort(arr4, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("大量数据（数据量：%d）\n归并排序 耗时：%f秒\n", n, time_used);

    start = clock();
    quickSort(arr5, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序 耗时：%f秒\n\n", time_used);

    free(arr4);
    free(arr5);

    n = 60000;
    int *arr6 = (int *)malloc(n * sizeof(int));
    int *arr7 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr6[i] = rand() % n;
        arr7[i] = arr6[i];
    }

    start = clock();
    mergeSort(arr6, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("中量数据（数据量：%d）\n归并排序 耗时：%f秒\n", n, time_used);

    start = clock();
    quickSort(arr7, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序 耗时：%f秒\n\n", time_used);

    free(arr6);
    free(arr7);

    n = 10000;
    int *arr8 = (int *)malloc(n * sizeof(int));
    int *arr9 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr8[i] = rand() % n;
        arr9[i] = arr8[i];
    }

    start = clock();
    mergeSort(arr8, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("少量数据（数据量：%d）\n归并排序 耗时：%f秒\n", n, time_used);

    start = clock();
    quickSort(arr9, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序 耗时：%f秒\n\n", time_used);

    free(arr8);
    free(arr9);

    return 0;
}