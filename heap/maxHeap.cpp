#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> arr;

    void insert(int val)
    {
        // insert at the end
        arr.push_back(val);

        // start at the end
        int i = arr.size() - 1;

        // move the element accordingly
        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (arr[i] > arr[parent])
            {
                int temp = arr[i];
                arr[i] = arr[parent];
                arr[parent] = temp;
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    void print()
    {

        for (int x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap h1;

    h1.insert(10);
    h1.insert(5);
    h1.insert(20);
    h1.insert(3);
    h1.insert(8);
    h1.insert(15);

    h1.print();

    return 0;
}