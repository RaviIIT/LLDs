#include <bits/stdc++.h>
#define INF 10000000000
#define ll long long int
#define pb push_back
#define mp make_pair
#define FOR(i, n) for (long long int i = 0; i < n; i++)
#define FORR(i, a, b) for (int i = a; i < b; i++)
// think about a question calmly, don't get panic to solve A fast
// if after 10 mins you are unable to think anything see dashboard
using namespace std;

class DLL
{
public:
    DLL *next;
    DLL *prev;
    int _value;
    int _key;

    DLL(int _key, int _value)
    {
        this->_key = _key;
        this->_value = _value;
        next = NULL;
        prev = NULL;
    }
};

class LRU
{
public:
    DLL *head;
    DLL *tail;
    int capacity;
    map<int, DLL *> location;

    LRU(int capacity)
    {
        this->capacity = capacity;
        head = new DLL(-1, -1);
        tail = new DLL(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(int key)
    {
        DLL *cur = location[key];
        DLL *prev_node = cur->prev;
        DLL *next_node = cur->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
        location.erase(key);
    }

    void addNode(int key, int value)
    {
        DLL *new_node = new DLL(key, value);
        DLL *next_node = head->next;

        head->next = new_node;
        new_node->prev = head;
        new_node->next = next_node;
        next_node->prev = new_node;
        location[key] = new_node;
    }

    void putInCache(int key, int value)
    {
        // value is not already in cache
        if (location.find(key) == location.end())
        {
            addNode(key, value);
            if (location.size() > capacity)
            {
                deleteNode(tail->prev->_key);
            }
        }
        else
        {
            deleteNode(key);
            addNode(key, value);
        }
    }

    int getData(int key)
    {
        if (location.find(key) != location.end())
        {
            int val = location[key]->_value;
            deleteNode(key);
            addNode(key, val);
            return val;
        }
        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}