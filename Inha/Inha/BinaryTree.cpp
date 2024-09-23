#include "BinaryTree.h"

Node* BinaryTree::Search(Node* node, const int data) const noexcept
{
    if (node == nullptr)
        std::cout << "�˻��ϴ� �����Ͱ� �������� �ʽ��ϴ�.\n";
    else if (node->data.number == data)
        return node;
    else if (node->data.number < data)
        return Search(node->right, data);
    else
        return Search(node->left, data);
}


Node* BinaryTree::Search(const int data) const noexcept
{
    if (root == nullptr)
    {
        std::cout << "����� �����Ͱ� �����ϴ�.\n";
        return nullptr;
    }

    return Search(root, data);
}

Node* BinaryTree::Add(Node* node, const Student* data)
{
    if ( node == nullptr )
    {
        node = new Node();
        node->data = *data;
        return node;
    }
    if (node->data.number == data->number)
        std::cout << "�̹� ��ϵ� �л� ��ȣ�Դϴ�.\n";
    else if (node->data.number < data->number)
        node->right = Add(node->right, data);
    else
        node->left = Add(node->left, data);

    return node;
}

Node* BinaryTree::Add(const Student* data)
{
    if (root == nullptr)
    {
        root = new Node();
        root->data = *data;
        return root;
    }

    Node* p = Add(root, data);
    return p;
}

bool BinaryTree::Remove(Node* node, const int data)
{
    Node** p = &node;
    Node* temp, * next;
    Node **left;

    while (1)
    {
        if (*p == nullptr)
        {
            std::cout << "[����] �ش� �����Ͱ� �������� �ʽ��ϴ�.\n";
            return false;
        }

        else if ((*p)->data.number == data)
            break;
        else if ((*p)->data.number < data)
            p = &(*p)->right;
        else
            p = &(*p)->left;
    }

    // �� ���� ��
    if ((*p)->left != nullptr && (*p)->right != nullptr)
    {
        left = &(*p)->left;
        while ((*left)->right != nullptr)
            left = &(*left)->right;
        next = *left;
        //left = &(*left)->left;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }

    // �� ���� ��
    else
    {
        if ((*p)->left != nullptr) 
            next = (*p)->left;
        else next = (*p)->right;
    }

    temp = *p;
    if (*p == this->root)
        this->root = next;
    *p = next;
    delete temp;
    std::cout << "���������� �����Ǿ����ϴ�.\n";

    return true;
}

bool BinaryTree::Remove(const int data)
{
    if (root == nullptr)
    {
        std::cout << "�˻� �����Ͱ� �����ϴ�.\n";
        return false;
    }
    return Remove(root, data);
}

void BinaryTree::PrintTree(Node* node) const noexcept
{
    if (node->left != nullptr)
        PrintTree(node->left);
    
    std::cout << "[�̸�]: " << node->data.name << ", [��ȣ]: " << node->data.number << "\n";

    if (node->right != nullptr)
        PrintTree(node->right);
}

void BinaryTree::PrintTree() const noexcept
{
    PrintTree(root);
}