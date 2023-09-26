#include <iostream>
#include <vector>

using namespace std;


// Implemented with vector.
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
    void remove(const T &elem); // remove entry from Set (by elem)
    bool find(const T &elem);   // find if an entry is in Set
    int getSize();              // return Set's size
    void print();               // print out Set
    Set<T> Union(const Set<T> &other_set);
    Set<T> Intersection(const Set<T> &other_set);
    Set<T> Difference(const Set<T> &other_set);
};

// search for the index where the elem is or where it can fit in : O(log(n))
template <>
int Set<int>::binary_search(const int &elem)
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
            if (arr[mid] < elem)
            {
                start = mid + 1;
            }
            else if (elem < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        if (elem > arr[start])
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

// Find out if elem k is in Set or not. O(log(n))
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

// Time complexity: O(n)
template <>
void Set<int>::add(const int &n)
{
    if (size == 0)
    {
        arr.push_back(n);
    }
    else
    {
        // Finding an index where entry can fit into vector. O(log(n))
        int index = binary_search(n);
        if (arr[index] == n)
        {
            cout << "Entry's elem has already been taken" << endl;
            return;
        }
        else
        {
            // Insert an entry to vector O(n). (Cost of copy, move and reallocation)
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

// Remove an entry from the set's vector (if exists) O(n)
template <>
void Set<int>::remove(const int &n)
{
    // Find index. O(log(n)).
    int index = binary_search(n);
    if (arr[binary_search(n)] == n)
    {
        // std::vector::erase: O(n)
        arr.erase(arr.begin() + index);
        size -= 1;
    }
    else
    {
        cout << "Elem is not found in Set" << endl;
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

/**
 * Complexity: O(min(m, n)) where m, n are size of each set.
 */
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

/**
 *  Complexity: O(n) where n is the size of "this" set.
 */
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

    while (it1 < this->getSize())
    {
        res_arr.push_back(this->arr[it1]);
        it1++;
    }
    res.arr = res_arr;
    res.size = res_arr.size();
    return res;
}

/**
 * Complexity: O(m + n) where m, n are the sizes of two sets.
 */
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
    while (it1 < this->getSize())
    {
        res_arr.push_back(this->arr[it1]);
        it1++;
    }
    while (it2 < other_set.size)
    {
        res_arr.push_back(other_set.arr[it2]);
        it2++;
    }
    res.arr = res_arr;
    res.size = res_arr.size();
    return res;
}

int main()
{
    Set<int> mySet1;
    vector<int> arr1 = {4, 9, 3, 2, 1, 6, 6};
    for (int i : arr1)
    {
        mySet1.add(i);
    }

    Set<int> mySet2;
    vector<int> arr2 = {9, 2, 8, 6, 7, 13, 10};
    for (int i : arr2)
    {
        mySet2.add(i);
    }

    cout << "mySet1 = ";
    mySet1.print();

    cout << "mySet2 = ";
    mySet2.print();

    cout << "mySet1 intersect mySet2 = ";
    Set<int> res1 = mySet1.Intersection(mySet2);
    res1.print();

    cout << "mySet2 intersect mySet1 = ";
    Set<int> res_1 = mySet2.Intersection(mySet1);
    res_1.print();

    cout << "mySet1 difference mySet2 = ";
    Set<int> res2 = mySet1.Difference(mySet2);
    res2.print();

    cout << "mySet2 difference mySet1 = ";
    Set<int> res_2 = mySet2.Difference(mySet1);
    res_2.print();

    cout << "mySet2 union mySet1 = ";
    Set<int> res3 = mySet2.Union(mySet1);
    res3.print();

    cout << "mySet1 union mySet2 = ";
    Set<int> res4 = mySet1.Union(mySet2);
    res3.print();
    return 0;
}