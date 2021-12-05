/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//#define printf

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void QuickSort(int *arr, int begin, int end)
{
    if (begin >= end) {
        return;
    }
    printf("pivot: %d\n", arr[end]);
    int i = begin;
    int j = end - 1;
    while (i < j) {
        while (arr[i] < arr[end] && i < j) {
            i++;
        }
        while (arr[j] >= arr[end] && i < j) {
            j--;
        }
        if (arr[i] > arr[j] && i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    if (arr[i] > arr[end]) {
        swap(&arr[i], &arr[end]);
    }
    QuickSort(arr, begin, i);
    QuickSort(arr, i + 1, end);
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize){
    *returnSize = k;
    if (arrSize == 0 || k == 0) {
        return NULL;
    }

    int *returnArray = NULL;
    returnArray = (int*)malloc(k * sizeof(int));
    if (returnArray == NULL) {
        printf("malloc error\n");
        return NULL;
    }

    QuickSort(arr, 0, arrSize - 1);
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < k; ++i) {
        returnArray[i] = arr[i];
    }
 
    return returnArray;
}