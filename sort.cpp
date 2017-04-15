#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> InitArr(int size) {
    srand((int) time(0));
    vector<int> arr;
    for (int i = 0; i < size; ++i) {
        arr.push_back(rand() % size);
    }
    return arr;
}

void PrintArr(vector<int> arr) {
    for (auto i : arr)
        cout << i << "\t";
    cout << endl;
    return;
}


//选择排序
void SelectSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

//冒泡排序（交换排序）
void BubbleSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

//插入排序
void InsertSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int next = arr[i];                     // 右手抓到一张扑克牌
        int j = i - 1;                      // 拿在左手上的牌总是排序好的
        while (j >= 0 && arr[j] > next)    // 将抓到的牌与手牌从右向左进行比较
        {
            arr[j + 1] = arr[j];            // 如果该手牌比抓到的牌大,就将其右移
            j--;
        }
        arr[j + 1] = next;
    }
}

//归并排序

void Merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> a1;
    vector<int> a2;
    int i, j;
//    注意这个循环终止条件....
    for (i = left; i <= mid; ++i) {
        a1.push_back(arr[i]);
    }
    for (j = mid + 1; j <= right; j++) {
        a2.push_back(arr[j]);
    }
    a1.push_back(INT32_MAX);
    a2.push_back(INT32_MAX);

    i = 0;
    j = 0;
    for (int k = left; k <= right; ++k) {
        if (a1[i] > a2[j]) {
            arr[k] = a2[j];
            ++j;
        } else {
            arr[k] = a1[i];
            ++i;
        }
    }
}

void MergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
    return;
}

//快速排序
void swap(vector<int> &arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

//每一趟选一个基准数，找出比它大的和比它小的个数，就能确定它的位置！
int partition(vector<int> &arr, int low, int high) {
//    if (low >= high) return
    int base = arr[high];
    int tail = low - 1;
    for (int i = low; i < high; i++)       // 遍历基准以外的其他元素
    {
        if (arr[i] <= base)                   // 把小于等于基准的元素放到前一个子数组中
        {
            tail++;
            if (tail == i) continue;
            else swap(arr, tail, i);
        }
    }
    swap(arr, tail + 1, high);
    return tail + 1;
}

void QuickSort(vector<int> &arr, int low, int high) {
    if (high < low) return;
    int Index = partition(arr, low, high);  //将表一分为二
    QuickSort(arr, low, Index - 1);          //递归对低子表递归排序
    QuickSort(arr, Index + 1, high);
}


//堆排序
void HeapSortbystl(vector<int> &arr) {
    make_heap(arr.begin(), arr.end());
    sort_heap(arr.begin(), arr.end());
}

int main() {

    vector<int> arr = InitArr(20);
    PrintArr(arr);
//    InsertSort(arr);
//    SelectSort(arr);
//    BubbleSort(arr);
//    MergeSort(arr, 0, arr.size());
   // QuickSort(arr, 0, arr.size() - 1);
   HeapSortbystl(arr);
    PrintArr(arr);
    return 0;
}