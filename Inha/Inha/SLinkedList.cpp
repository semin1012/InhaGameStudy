#include "SLinkedList.h"

void SLinkedList::Initialize()
{
    head = new Node();
    head->next = nullptr;
}

void SLinkedList::Search(std::string name)
{
    Node* ptr = head->next;
    while (ptr != nullptr)
    {
        if (ptr->data.name == name)
        {
            std::cout << ptr->data.number << "��: " << ptr->data.name << std::endl;
            std::cout << "\n";
            return;
        }
        ptr = ptr->next;
    }
    std::cout << "�ش��ϴ� �л��� �����Ͱ� �������� �ʽ��ϴ�.\n";
}

void SLinkedList::Search(int num)
{
    Node* ptr = head->next;
    while (ptr != nullptr)
    {
        if (ptr->data.number == num)
        {
            std::cout << ptr->data.number << "��: " << ptr->data.name << std::endl;
            std::cout << "\n";
            return;
        }
        ptr = ptr->next;
    }
    std::cout << "�ش��ϴ� �л��� �����Ͱ� �������� �ʽ��ϴ�.\n";
}

void SLinkedList::InsertRear(const Student* st)
{
    Node* ptr = head;

    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }

    Node* node = new Node();
    node->data = *st;
    node->next = nullptr;
    ptr->next = node;
}

void SLinkedList::Remove(std::string name)
{
    Node* ptr = head->next;
    Node* pre = ptr;

    while (ptr != nullptr)
    {
        if (ptr->data.name == name)
        {
            if (ptr == head->next)
            {
                head->next = ptr->next;
                delete ptr;
            }

            else
            {
                pre->next = ptr->next;
                delete ptr;
            }

            std::cout << "�ش��ϴ� �����͸� �����߽��ϴ�.\n";
            return;
        }
        pre = ptr;
        ptr = ptr->next;
    }
    std::cout << "�ش��ϴ� �л��� �����Ͱ� �������� �ʽ��ϴ�.\n";
}

void SLinkedList::Remove(int num)
{
    Node* ptr = head->next;
    Node* pre = ptr;

    while (ptr != nullptr)
    {
        if (ptr->data.number == num)
        {
            if (ptr == head->next)
            {
                head->next = ptr->next;
                delete ptr;
            }

            else
            {
                pre->next = ptr->next;
                delete ptr;
            }

            std::cout << "�ش��ϴ� �����͸� �����߽��ϴ�.\n";
            return;
        }
        pre = ptr;
        ptr = ptr->next;
    }
    std::cout << "�ش��ϴ� �л��� �����Ͱ� �������� �ʽ��ϴ�.\n";
}

void SLinkedList::Print()
{
    Node* ptr = head->next;
    while (ptr != nullptr)
    {
        std::cout << ptr->data.number << "��: " << ptr->data.name << std::endl;
        ptr = ptr->next;
    }
    std::cout << "\n";
}
