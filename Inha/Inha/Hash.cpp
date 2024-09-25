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
    delete[] table;
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

    while (p != nullptr)
    {
        if (p->data.num == data->num)
        {
            cout << "[오류] 같은 학생 번호가 이미 존재합니다.\n";
            return false;
        }

        p = p->next;
    }
    Node* temp = new Node();
    temp->data = *data;
    temp->next = table[key];
    table[key] = temp;

    cout << "[성공] 정상적으로 학생 정보를 저장했습니다.\n";

    return false;
}

bool Hash::Remove(const int number)
{
    int key = number % size;
    Node* p = table[key];
    Node** pp = &table[key];

    while (p != nullptr)
    {
        if (p->data.num == number)
        {
            *pp = p->next;
            p = nullptr;
            delete p;
            cout << "[완료] 해당 정보를 삭제하였습니다.\n";
            return true;
        }
        pp = &p->next;
        p = p->next;
    }

    cout << "[오류] 해당하는 정보가 존재하지 않습니다.\n";
    return false;
}

Node* Hash::Search(const int number)
{
    int key = number % size;
    Node* p = table[key];

    while (p != nullptr)
    {
        if (p->data.num == number)
        {
            cout << "[결과] 이름: " << p->data.name << ", 번호: " << p->data.num << "\n";
            return p;
        }
        p = p->next;
    }

    cout << "[오류] 해당하는 번호가 존재하지 않습니다.\n";
    return nullptr;
}

void Hash::Dump()
{
    cout << "\n[학생 정보 전체 출력]\n";
    for (int i = 0; i < size; i++)
    {
        cout << "key: " << i << "\n";
        Node* p = table[i];
        while (p != nullptr)
        {
            cout << "이름: " << p->data.name << ", 번호: " << p->data.num << "\n";
            p = p->next;
        }
    }
    cout << "\n\n";
}

void Hash::Clear()
{
    for (int i = 0; i < size; i++)
    {
        Node* p = table[i];
        while (p != nullptr)
        {
            Node* next = p->next;
            delete p;
            p = next;
        }
    }
}
