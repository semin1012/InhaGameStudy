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
            cout << "[����] ���� �л� ��ȣ�� �̹� �����մϴ�.\n";
            return false;
        }

        p = p->next;
    }
    Node* temp = new Node();
    temp->data = *data;
    temp->next = table[key];
    table[key] = temp;

    cout << "[����] ���������� �л� ������ �����߽��ϴ�.\n";

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
            cout << "[�Ϸ�] �ش� ������ �����Ͽ����ϴ�.\n";
            return true;
        }
        pp = &p->next;
        p = p->next;
    }

    cout << "[����] �ش��ϴ� ������ �������� �ʽ��ϴ�.\n";
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
            cout << "[���] �̸�: " << p->data.name << ", ��ȣ: " << p->data.num << "\n";
            return p;
        }
        p = p->next;
    }

    cout << "[����] �ش��ϴ� ��ȣ�� �������� �ʽ��ϴ�.\n";
    return nullptr;
}

void Hash::Dump()
{
    cout << "\n[�л� ���� ��ü ���]\n";
    for (int i = 0; i < size; i++)
    {
        cout << "key: " << i << "\n";
        Node* p = table[i];
        while (p != nullptr)
        {
            cout << "�̸�: " << p->data.name << ", ��ȣ: " << p->data.num << "\n";
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
