#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    int value;
    Node *next;

    Node()
    {
        next = nullptr;
    }
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        next = nullptr;
    }
};

struct Map
{
private:
    Node *head; // Assign no key for the sentinel node.

public:
    Map()
    {
        head = new Node;
        head->next = nullptr;
    }
    bool isEmpty()
    {
        if (head->next == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void put(int key, int value)
    {
        Node *n = new Node(key, value);
        if (isEmpty())
        {
            head->next = n;
        }
        else
        {
            Node *it = head;
            while (true)
            {
                if (it->next != nullptr)
                {
                    if (it->next->key > key)
                    {
                        Node *temp = it->next;
                        n->next = temp;
                        it->next = n;
                        return;
                    }
                    else if (it->next->key == key)
                    {
                        // cout << "Value " << val << " is already in Set" << endl;
                        return;
                    }
                    else
                    {
                        it = it->next;
                    }
                }
                else
                {
                    it->next = n;
                    return;
                }
            }
        }
    }

    int remove(int key)
    {
        Node *it = head;
        while (it->next != nullptr)
        {
            if (it->next->key == key)
            {
                Node *temp = it->next->next;
                int value = it->next->value;
                delete it->next;
                it->next = temp;
                return value;
            }
            else
            {
                it = it->next;
            }
        }
        cout << "Key is not in map." << endl;
    }

    int &operator[](int _key)
    {
        Node *it = head->next;
        while (it != nullptr)
        {
            if (it->key == _key)
            {
                return it->value;
            }
            else
            {
                it = it->next;
            }
        }
        if (it == nullptr)
        {
            cout << "Key " << _key << " not found in map" << endl;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Empty map" << endl;
            return;
        }
        Node *it = head->next;
        cout << "Map: ";
        while (it != nullptr)
        {
            cout << "(" << it->key << ", " << it->value << ") ";
            it = it->next;
        }
        cout << endl;
    }
};

int main()
{
    Map *myMap = new Map();
    // Put key value pair of (i, 2i) into map.
    for (int i = 10; i >= -4; i--)
    {
        myMap->put(i, i * 2);
    }
    for (int i = 15; i <= 20; i++)
    {
        myMap->put(i, i * 2);
    }
    cout << (*myMap)[3] << endl;
    cout << (*myMap)[15] << endl;
    cout << myMap->remove(-4) << endl;
    myMap->print();
    cout << (*myMap)[13] << endl;
    return 0;
}
