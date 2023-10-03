#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int value;
    Node *next;

    Node()
    {
        next = nullptr;
    }
    Node(int _value)
    {
        value = _value;
        next = nullptr;
    }
};

struct Set
{
private:
    Node *head; // Assign no value for the sentinel node.

public:
    Set()
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
    void insert(int val)
    {
        Node *n = new Node;
        n->value = val;
        n->next = nullptr;
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
                    if (it->next->value > val)
                    {
                        Node *temp = it->next;
                        n->next = temp;
                        it->next = n;
                        return;
                    }
                    else if (it->next->value == val)
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

    void remove(int value)
    {
        Node *it = head;
        while (it->next != nullptr)
        {
            if (it->next->value == value)
            {
                Node *temp = it->next->next;
                delete it->next;
                it->next = temp;
                return;
            }
            else
            {
                it = it->next;
            }
        }
        cout << "Value is not in set." << endl;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Empty set" << endl;
            return;
        }
        Node *it = head->next;
        cout << "Set: ";
        while (it != nullptr)
        {
            cout << it->value << " ";
            it = it->next;
        }
        cout << endl;
    }

    Set *Union(Set *otherSet)
    {
        Set *result = new Set();
        Node *rIt = result->head;
        Node *tIt = this->head->next;
        Node *oIt = otherSet->head->next;
        while (tIt != nullptr && oIt != nullptr)
        {
            if (tIt->value < oIt->value)
            {
                Node *n = new Node(tIt->value);
                rIt->next = n;
                tIt = tIt->next;
            }
            else if (tIt->value > oIt->value)
            {
                Node *n = new Node(oIt->value);
                rIt->next = n;
                oIt = oIt->next;
            }
            else
            {
                Node *n = new Node(oIt->value);
                rIt->next = n;
                oIt = oIt->next;
                tIt = tIt->next;
            }
            rIt = rIt->next;
        }
        while (tIt != nullptr)
        {
            Node *n = new Node(tIt->value);
            rIt->next = n;
            tIt = tIt->next;
            rIt = rIt->next;
        }
        while (oIt != nullptr)
        {
            Node *n = new Node(oIt->value);
            rIt->next = n;
            oIt = oIt->next;
            rIt = rIt->next;
        }
        return result;
    }
    Set *Intersection(Set *otherSet)
    {
        Set *result = new Set();
        Node *rIt = result->head;
        Node *tIt = this->head->next;
        Node *oIt = otherSet->head->next;
        while (tIt != nullptr && oIt != nullptr)
        {
            if (tIt->value < oIt->value)
            {
                tIt = tIt->next;
            }
            else if (tIt->value > oIt->value)
            {
                oIt = oIt->next;
            }
            else
            {
                Node *n = new Node(oIt->value);
                rIt->next = n;
                oIt = oIt->next;
                tIt = tIt->next;
                rIt = rIt->next;
            }
        }
        return result;
    }

    Set *Difference(Set *otherSet)
    {
        Set *result = new Set();
        Node *rIt = result->head;
        Node *tIt = this->head->next;
        Node *oIt = otherSet->head->next;
        while (tIt != nullptr && oIt != nullptr)
        {
            if (tIt->value < oIt->value)
            {
                Node *n = new Node(tIt->value);
                rIt->next = n;
                tIt = tIt->next;
                rIt = rIt->next;
            }
            else if (tIt->value > oIt->value)
            {
                oIt = oIt->next;
            }
            else
            {
                oIt = oIt->next;
                tIt = tIt->next;
            }
        }
        while (tIt != nullptr)
        {
            Node *n = new Node(tIt->value);
            rIt->next = n;
            tIt = tIt->next;
            rIt = rIt->next;
        }
        return result;
    }
};

int main()
{
    vector<int> values1 = {3, 1, 5, 2, 6, 4, 3, 4, 9, 7, 8};
    Set *mySet1 = new Set();
    for (int i : values1)
    {
        // cout << "Insert value: " << i << endl;
        mySet1->insert(i);
        // mySet1->print();
        // cout << endl;
    }
    mySet1->print();

    vector<int> values2 = {1, 1, 6, 2, -7, 9, -7, 1, 13, 5, 8, -2};
    Set *mySet2 = new Set();
    for (int i : values2)
    {
        mySet2->insert(i);
    }
    mySet2->print();

    Set *mySet3 = mySet1->Difference(mySet2);
    mySet3->print();
    return 0;
}
