// Read the marks obtained by students in an online examination and find the maximum and minimum marks using
// a heap data structure. Analyze the algorithm.
// (Marks Sorting Algorithm)
#include <iostream>
using namespace std;
class Heap
{
    int n;
    int *minheap, *maxheap;

public:
    void get();
    void displayMin() { cout << "Minimum number is:" << maxheap[0] << endl; }
    void displayMax() { cout << "Maximum number is :" << minheap[0] << endl; }
    void upAdjust(bool, int);
};
void Heap::get()
{
    cout << "Enter the number of entries you want :\n"
         << endl;
    cin >> n;
    int k;
    minheap = new int[n];
    maxheap = new int[n];
    cout << "Enter number" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        minheap[i] = k;
        upAdjust(0, i);
        maxheap[i] = k;
        upAdjust(1, i);
    }
}
void Heap::upAdjust(bool m, int l)
{
    int s;
    if (!m)
    {
        while (minheap[(l - 1) / 2] < minheap[l])
        {
            s = minheap[l];
            minheap[l] = minheap[(l - 1) / 2];
            minheap[(l - 1) / 2] = s;
            l = (l - 1) / 2;
            if (l == -1)
                break;
        }
    }
    else
    {
        while (maxheap[(l - 1) / 2] > maxheap[l])
        {
            s = maxheap[l];
            maxheap[l] = maxheap[(l - 1) / 2];
            maxheap[(l - 1) / 2] = s;
            l = (l - 1) / 2;
            if (l == -1)
                break;
        }
    }
}
int main()
{
    int choice;
    cout << "1.MIN HEAP\n";
    cout << "2.MAX HEAP\n";
    cout << "Enter your choice:\n";
    cin >> choice;
    Heap H;
    switch (choice)
    {
    case 1:
        H.get();
        H.displayMin();
        break;
    case 2:
        H.get();
        H.displayMax();
        break;
    }
    return (0);
}
/*1.MIN HEAP
2.MAX HEAP
Enter your choice:
1
Enter the number of entries you want :
5
Enter number
20 30 40 50 60
Minimum number is:20
1.MIN HEAP
2.MAX HEAP
Enter your choice:
2
Enter the number of entries you want :
6
Enter number
56
12
09
45
47
83
Maximum number is :83
[Program finished]*/

// OR

// #include<iostream>
// using namespace std;

// void maxHeapify(int heap[], int i, int n) {

//     int left = 2 * i;
//     int right = (2 * i) + 1;
//     int largest = i;

//     if (left <= n && heap[i] < heap[left])
//         largest = left;

//     if (right <= n && heap[largest] < heap[right])
//         largest = right;

//     if (largest != i) {
//         swap(heap[largest], heap[i]);
//         maxHeapify(heap, largest, n);
//     }
// }

// void buildHeap(int heap[], int n) {

//     for (int i = n / 2; i >= 1; i--)
//         maxHeapify(heap, i, n);
// }

// int main() {
//     int n;
//     cout << "Enter Number of Students : ";
//     cin >> n;

//     int heap[n + 1];

//     cout << "Enter Marks : \n";
//     for (int i = 1; i <= n; i++)
//         cin >> heap[i];

//     buildHeap(heap, n);

//     int heapSize = n;
    
//     for (int i = n; i >= 2; i--) {
//         swap(heap[1], heap[i]);
//         --heapSize;
//         maxHeapify(heap, 1, heapSize);
//     }

//     cout << "\nAfter Sorting :: ";
//     for (int i = 1; i <= n; i++)
//         cout << heap[i] << " ";
//     cout << "\nMAXIMUM MARKS :" << heap[n] << endl;
//     cout << "MINIMUM MARKS :" << heap[1] << endl;
//     return 0;
// }