#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

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
    for (int i : arr)
    {
        mp[i]++;
    }
    for (pair<int, int> p: mp)
    {
        cout << p.first << " " << p.second << endl; // key - value: number - appearance.
        res += comb(p.second);
    }
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