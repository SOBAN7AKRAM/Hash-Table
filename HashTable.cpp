#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int val)
    {
        val = val;
        next = nullptr;
    }
};
void hashTable(vector<int> &vec, int val)
{
    int index = val % 10;
    vec[index] = val;
}
void linearProbing(vector<int> &vec, int val)
{
    int index = val % 10;
    if (vec[index] != -1)
    {
        while (vec[index] != -1)
        {
            index++;
        }
    }
    vec[index] = val;
}
void quadraticProbing(vector<int> &vec, int val)
{
    int index = val % 10;
    if (vec[index] != -1)
    {
        while (vec[index] != -1)
        {
            index++;
            index = index * index;
        }
    }
    vec[index] = val;
}
class Chaining
{
private:
    int size;
    vector<list<int>> table;
public:
    Chaining()
    {
        size = 10;
        table = vector<list<int>> (size);
    }
    int getHash(int val)
    {
        return val % size;
    }
    void insertVal(int val)
    {
        int index = getHash(val);
        table[index].push_back(val);
    }
    void removeVal(int val)
    {
        int index = getHash(val);
        table[index].remove(val);
    }
};
int main()
{
    vector<int> vec(10, -1);
    // hashTable(vec, 10);
    // hashTable(vec, 29);
    // hashTable(vec, 38);
    // hashTable(vec, 17);
    // hashTable(vec, 16);
    // hashTable(vec, 11);
    // hashTable(vec, 22);
    // hashTable(vec, 23);
    // hashTable(vec, 34);
    // hashTable(vec, 15);

    // linearProbing(vec, 10);
    // linearProbing(vec, 29);
    // linearProbing(vec, 38);
    // linearProbing(vec, 17);
    // linearProbing(vec, 16);
    // linearProbing(vec, 20);
    // linearProbing(vec, 30);
    // linearProbing(vec, 23);
    // linearProbing(vec, 34);
    // linearProbing(vec, 15);

    quadraticProbing(vec, 10);
    quadraticProbing(vec, 30);
    quadraticProbing(vec, 40);

    for (int i = 0; i < 10; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}