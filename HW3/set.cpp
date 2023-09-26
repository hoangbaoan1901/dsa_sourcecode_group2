#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class Set
{
private:
    vector<T> arr;                    // vector<T> arr;
    int size;                         // Set's size
    int binary_search(const T &elem); // might need a Comparator if Kt is complex 🫠

public:
    Set();
    void add(const T &elem);    // add entry to Set
    void remove(const T &elem); // remove entry from Set (by key)
    bool find(const T &elem);   // find if an entry is in Set
    int getSize();              // return Set's size
    void print();               // print out Set
    Set<T> Union(const Set<T> &other_set);
    Set<T> Intersection(const Set<T> &other_set);
    Set<T> Difference(const Set<T> &other_set);
};

// search for the index where the key is or where it can fit in : O(log(n))
template <>
int Set<int>::binary_search(const int &key)
{
    if (size == 0)
    {
        return 0;
    }
    else
    {
        int start = 0;
        int end = size - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] < key)
            {
                start = mid + 1;
            }
            else if (key < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        if (key > arr[start])
        {
            return start + 1;
        }
        return start;
    }
}

// Initialize size = 0;
template <>
Set<int>::Set()
{
    size = 0;
}

// Find out if key k is in Set or not. O(log(n))
template <>
bool Set<int>::find(const int &k)
{
    int index = binary_search(k);
    if (arr[binary_search(k)] == k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <>
void Set<int>::add(const int &n) // Avg case: O(n)
{
    if (size == 0)
    {
        arr.push_back(n);
    }
    else
    {
        int index = binary_search(n);
        if (arr[index] == n)
        {
            cout << "Entry's key has already been taken" << endl;
            return;
        }
        else
        {
            if (index >= size)
            {
                arr.push_back(n);
            }
            else
            {
                arr.insert(arr.begin() + index, n);
            }
        }
    }
    size += 1;
    return;
}

template <>
void Set<int>::remove(const int &n)
{
    int index = binary_search(n);
    if (arr[binary_search(n)] == n)
    {
        arr.erase(arr.begin() + index);
        size -= 1;
    }
    else
    {
        cout << "Key is not found in Set" << endl;
        return;
    }
}

template <>
int Set<int>::getSize()
{
    return size;
}

template <>
void Set<int>::print()
{
    if (size == 0)
    {
        cout << "Empty set" << endl;
    }
    for (int p : arr)
    {
        cout << p << " ";
    }
    cout << endl;
}

template <>
Set<int> Set<int>::Intersection(const Set<int> &other_set)
{
    Set<int> res;
    vector<int> res_arr;
    int it1 = 0;
    int it2 = 0;
    while (it1 < this->getSize() && it2 < other_set.size)
    {
        if (this->arr[it1] < other_set.arr[it2])
        {
            it1++;
        }
        else if (this->arr[it1] > other_set.arr[it2])
        {
            it2++;
        }
        else
        {
            res_arr.push_back(this->arr[it1]);
            it1++;
            it2++;
        }
    }
    res.arr = res_arr;
    res.size = res_arr.size();
    return res;
}

template <>
Set<int> Set<int>::Difference(const Set<int> &other_set)
{
    Set<int> res;
    vector<int> res_arr;
    int it1 = 0;
    int it2 = 0;
    while (it1 < this->getSize() && it2 < other_set.size)
    {
        if (this->arr[it1] < other_set.arr[it2])
        {
            res_arr.push_back(this->arr[it1]);
            it1++;
        }
        else if (this->arr[it1] > other_set.arr[it2])
        {
            it2++;
        }
        else
        {
            it1++;
            it2++;
        }
    }
    res.arr = res_arr;
    res.size = res_arr.size();
    return res;
}

template <>
Set<int> Set<int>::Union(const Set<int> &other_set)
{
    Set<int> res;
    vector<int> res_arr;
    int it1 = 0;
    int it2 = 0;
    while (it1 < this->getSize() && it2 < other_set.size)
    {
        if (this->arr[it1] < other_set.arr[it2])
        {
            res_arr.push_back(this->arr[it1]);
            it1++;
        }
        else if (this->arr[it1] > other_set.arr[it2])
        {
            res_arr.push_back(other_set.arr[it2]);
            it2++;
        }
        else
        {
            res_arr.push_back(this->arr[it1]);
            it1++;
            it2++;
        }
    }
    res.arr = res_arr;
    res.size = res_arr.size();
    return res;
}

int main()
{
    Set<int> mySet1;
    for (int i = 30; i > 0; i--)
    {
        if (i % 6 == 0)
        {
            mySet1.add(i);
        }
    }

    Set<int> mySet2;
    for (int i = 30; i > 3; i--)
    {
        if (i % 3 == 0)
        {
            mySet2.add(i);
        }
    }

    Set<int> mySet3;
    for (int i = 30; i > 3; i--)
    {
        if (i % 5 == 0)
        {
            mySet3.add(i);
        }
    }

    Set<int> res1 = mySet1.Intersection(mySet2);
    res1.print();

    Set<int> res2 = mySet2.Difference(mySet1);
    res2.print();

    Set<int> res3 = mySet1.Union(mySet3);
    res3.print();
    return 0;
}