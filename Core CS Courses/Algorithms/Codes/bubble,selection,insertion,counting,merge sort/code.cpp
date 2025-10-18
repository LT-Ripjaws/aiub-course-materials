#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
    flag =0;
    for (j = 0; j < n - i - 1; j++)
    {
    if (arr[j] > arr[j + 1])
    {
    swap(arr[j], arr[j + 1]);
    flag = 1;
    }
    }
    if (flag == 0)
    break;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
    int k = arr[i];
    int j;
    for (j = i - 1; j >= 0 && arr[j] > k; --j) {
    arr[j + 1] = arr[j];
    }
    arr[j + 1] = k;
    }
}

void selectionSort(int arr[], int n)
    {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
    min_idx = i;
    for (j = i+1; j < n; j++)
    {
    if (arr[j] < arr[min_idx])
    min_idx = j;
    }
    if (min_idx!=i)
    swap(arr[min_idx], arr[i]);
    }
}

void merge(int arr[], int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;
        int leftArray[n1];
        int rightArray[n2];
            for (int i = 0; i < n1; i++) {
            leftArray[i] = arr[left + i];
            }
            for (int i = 0; i < n2; i++) {
            rightArray[i] = arr[middle + 1 + i];
            }
        int i = 0;
        int j = 0;
        int k = left;
          while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
            }
            k++;
            }
           while (i < n1) {
            arr[k] = leftArray[i];
            i++;
            k++;
            }
           while (j < n2) {
            arr[k] = rightArray[j];
            j++;
            k++;
            }
}

void mergeSort(int arr[], int low, int high) {
        if (low < high) {
        int middle = low + (high - low) / 2;
        mergeSort(arr, low, high);
        mergeSort(arr, low + 1, high);
        merge(arr, low, middle, high);
        }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}


void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void countingSort(int arr[], int n)
{
    int max = arr[0];
        for (int i = 1; i < n; i++)
            {
                if (arr[i] > max)
                    {
                        max = arr[i];
                    }
            }
        int count[max + 1] = {0};
        int output[n];
        for (int i = 0; i < n; i++)
            {
            count[arr[i]]++;
            }
        for (int i = 1; i <= max; i++)
            {
            count[i] += count[i - 1];
            }
        for (int i = n - 1; i >= 0; i--)
            {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
            }
        for (int i = 0; i < n; i++)
            {
            arr[i] = output[i];
            }
 }


int main() {
    int arrSize;
    cout << "Enter the number of elements: ";
    cin >> arrSize;
    int arr[arrSize];
    cout << "Enter the elements: ";
    for (int i = 0; i < arrSize; i++) {
    cin >> arr[i];
    }
    cout << "Original array: ";
    for (int i = 0; i < arrSize; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;

bubbleSort(arr, arrSize);
insertionSort(arr, arrSize);
selectionSort(arr, arrSize);
mergeSort(arr, 0, arrSize - 1);
quicksort(arr, 0, arrSize - 1);
countingSort(arr, arrSize);

    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
