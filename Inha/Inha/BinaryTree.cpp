#include "BinaryTree.h"

Node* BinaryTree::Search(Node* node, const int data) const noexcept
{
    if (node == nullptr)
        std::cout << "검색하는 데이터가 존재하지 않습니다.\n";
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
        std::cout << "저장된 데이터가 없습니다.\n";
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
        std::cout << "이미 등록된 학생 번호입니다.\n";
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
            std::cout << "[오류] 해당 데이터가 존재하지 않습니다.\n";
            return false;
        }

        else if ((*p)->data.number == data)
            break;
        else if ((*p)->data.number < data)
            p = &(*p)->right;
        else
            p = &(*p)->left;
    }

    // 두 개일 때
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

    // 한 개일 때
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
    std::cout << "정상적으로 삭제되었습니다.\n";

    return true;
}

bool BinaryTree::Remove(const int data)
{
    if (root == nullptr)
    {
        std::cout << "검색 데이터가 없습니다.\n";
        return false;
    }
    return Remove(root, data);
}

void BinaryTree::PrintTree(Node* node) const noexcept
{
    if (node->left != nullptr)
        PrintTree(node->left);
    
    std::cout << "[이름]: " << node->data.name << ", [번호]: " << node->data.number << "\n";

    if (node->right != nullptr)
        PrintTree(node->right);
}

void BinaryTree::PrintTree() const noexcept
{
    PrintTree(root);
}