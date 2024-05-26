#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size_of_array;
    cin >> size_of_array;

    int arr[size_of_array];
    for (int i = 0; i < size_of_array; i++)
    {
        cin >> arr[i];
    }

    // initialize hash table
    int hash[13] = {0};
    for (int i = 0; i < size_of_array; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;

        // fetch
        cout << hash[number];
    }

    return 0;
}