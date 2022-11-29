#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int partition(int arr[], int left, int right)
{
    int leftCounter = left - 1;
    int rightCounter = right;
    int pivotValue = arr[right];

    while (true)
    {
        while (arr[++leftCounter] < pivotValue)
        {
        }

        while (arr[--rightCounter] > pivotValue && rightCounter >= left)
        {
        }
        
        if (rightCounter < leftCounter)
        {
            break;
        }
        else
        {
            swap(arr[leftCounter], arr[rightCounter]);
        }
    }

    swap(arr[leftCounter], arr[rightCounter]);

    return leftCounter;
}

void quickSort(int arr[], int left, int right){
    if(right - left < 0){
        return;
    }else{
        int partitionIndex = partition(arr, left, right);
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}

int main()
{
    const int SIZE = 8;
    int data[SIZE] = {42, 15, 72, 58, 61, 68, 37, 49};

    printArray(data, SIZE);
    quickSort(data, 0, SIZE -1);
    printArray(data, SIZE);

    return 0;
}