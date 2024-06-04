// reverse an array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7};
    int temp;
    int start = 0;
    int end = (sizeof(arr) / sizeof(arr[0])) - 1;

    while (start <= end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


