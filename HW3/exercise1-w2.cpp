#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Assignment 2: exercise 1:
    Given a list A of n integer numbers,
    your task is to write a program to count
    the number of pairs (i,j) that A[i]=A[j].
    Input:
        The first line contains an integer number n
        The second line contains n integer numbers separated by spaces
*/

int comb(int a)
{
    if (a < 2)
    {
        return 0;
    }
    else
    {
        return a * (a - 1) / 2;
    }
}

int sol(const vector<int> &arr)
{
    unordered_map<int, int> mp;
    int res = 0;

    // in unordered map, if we access a key that is not already appeared, it will be initialized with 0.
    for (int i : arr)
    {
        mp[i]++;
    }

    // Now we have the # of appearance of each element in the array.
    // Number of pairs of the same value = (Appearance)C2.
    for (pair<int, int> p : mp)
    {
        res += comb(p.second);
    }

    // Bucket stats
    // int n = mp.bucket_count();
    // cout << "mp has " << n << " buckets." << endl;
    // for (unsigned i = 0; i < n; ++i)
    // {
    //     cout << "bucket #" << i << " contains: ";
    //     for (auto it = mp.begin(i); it != mp.end(i); ++it)
    //         cout << "[" << it->first << ":" << it->second << "] ";
    //     cout << endl;
    // }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sol(arr);
    return 0;
}