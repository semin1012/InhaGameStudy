#include "Hash.h"
using namespace std;

Hash::Hash()
{
    table = new Node*[10];
    if (table == nullptr)
        return;
    size = 10;
    for (int i = 0; i < size; i++)
        table[i] = nullptr;
}

Hash::~Hash()
{
}

bool Hash::Initialize(int size)
{
    if (table)
        delete[] table;

    table = new Node*[size];
    if (table == nullptr)
        return false;

    this->size = size;
    for (int i = 0; i < size; i++)
        table[i] = nullptr;
    return true;
}

bool Hash::Add(const Student* data)
{
    int key = data->num % size;
    Node* p = table[key];

    p->data = *data;
    p->next = nullptr;
    return false;
}

bool Hash::Remove(const int number)
{
    return false;
}

Node* Hash::Search(const int number)
{
    return nullptr;
}

void Hash::Dump()
{
}

void Hash::Clear()
{
}
