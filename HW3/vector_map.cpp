#include <iostream>
#include <vector>

using namespace std;

// Kt: key type; Vt: value type.
template <typename Kt, typename Vt>
class Map
{
private:
    vector<pair<Kt, Vt>> arr;         // Key - value pair.
    int size;                         // map's size
    int binary_search(const Kt &key); // might need a Comparator if Kt is complex 🫠

public:
    Map();
    void put(const pair<Kt, Vt> &p); // put entry to map
    void remove(const Kt &key);      // remove entry from map (by key)
    bool find(const Kt &key);        // find if an entry is in map
    Vt &operator[](const Kt &key);
    int getSize(); // return map's size
    void print();  // print out map
};

// search for the index where the key is or where it can fit in : O(log(n))
template <>
int Map<int, int>::binary_search(const int &key)
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
            if (arr[mid].first < key)
            {
                start = mid + 1;
            }
            else if (key < arr[mid].first)
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        if (key > arr[start].first)
        {
            return start + 1;
        }
        return start;
    }
}

// Initialize size = 0;
template <>
Map<int, int>::Map()
{
    size = 0;
}

// Find out if key k is in map or not. O(log(n))
template <>
bool Map<int, int>::find(const int &k)
{
    int index = binary_search(k);
    if (arr[binary_search(k)].first == k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <>
void Map<int, int>::put(const pair<int, int> &p) // Avg case: O(n)
{
    if (size == 0)
    {
        arr.push_back(p);
    }
    else
    {
        int key = p.first;
        int val = p.second;
        int index = binary_search(key);
        if (arr[index].first == key)
        {
            cout << "Entry's key (" << key << ") has already been taken" << endl;
            return;
        }
        else
        {
            if (index >= size)
            {
                arr.push_back(p);
            }
            else
            {
                arr.insert(arr.begin() + index, p);
            }
        }
    }
    size += 1;
    return;
}

template <>
void Map<int, int>::remove(const int &k)
{
    int index = binary_search(k);
    if (arr[binary_search(k)].first == k)
    {
        arr.erase(arr.begin() + index);
        size -= 1;
    }
    else
    {
        cout << "Key is not found in map" << endl;
        return;
    }
}

// return value of entry through it's key.
template <>
int &Map<int, int>::operator[](const int &key)
{
    int index = binary_search(key);
    if (arr[index].first == key)
    {
        return arr[index].second;
    }
}

template <>
int Map<int, int>::getSize()
{
    return size;
}

template <>
void Map<int, int>::print()
{
    if (size == 0)
    {
        cout << "Empty map" << endl;
        return;
    }
    for (pair<int, int> p : arr)
    {
        cout << "{" << p.first << ":"
             << p.second << "} ";
    }
    cout << endl;
}

int main()
{
    Map<int, int> mp;
    // putting (i, i * 2) to map where i in (0, 10);
    cout << "Putting (i, i * 2) to map where i in (0, 10) (in reverse order):" << endl;
    for (int i = 10; i > 0; i--)
    {
        pair<int, int> p = {i, i * 2};
        mp.put(p);
    }
    mp.print();
    cout << endl;

    cout << "Trying to put {4, 2} to map: \n";
    mp.put(pair<int, int>{4, 2});
    cout << endl;

    cout << "After removing all entries in map:\n";
    for (int i = 1; i < 11; i++)
    {
        mp.remove(i);
    }
    mp.print();
    return 0;
}