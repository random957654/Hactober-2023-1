#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void mergeArrays(vector<int>& arr1, const vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> merged(n1 + n2);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    cout << "Merged Array: ";
    for (int i = 0; i < n1 + n2; i++)
        cout << merged[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    cout << "Array 1: ";
    for (int num : arr1)
        cout << num << " ";
    cout << endl;

    cout << "Array 2: ";
    for (int num : arr2)
        cout << num << " ";
    cout << endl;

    mergeArrays(arr1, arr2);

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int arrSize = arr.size();

    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
