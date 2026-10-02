#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;       // Number of elements currently in heap
    int total_size; // Maximum capacity

public:

    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert into the heap
    void insert(int val)
    {
        // Check if heap is full
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }

        // Insert at the end
        arr[size] = val;

        // Store index of newly inserted element
        int index = size;

        // Increase heap size
        size++;

        // Heapify Up
        while (index > 0 &&
               arr[index] > arr[(index - 1) / 2])
        {
            swap(arr[index], arr[(index - 1) / 2]);

            // Move to parent
            index = (index - 1) / 2;
        }

        cout << val << " is inserted into the heap\n";
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    MaxHeap h1(6);

    h1.insert(10);
    h1.insert(5);
    h1.insert(20);
    h1.insert(3);
    h1.insert(8);
    h1.insert(15);

    h1.print();

    return 0;
}