#pragma once
#include <iostream>	

struct Student
{
	std::string name;
	int			number;

	bool operator==(const Student& other)
	{
		return this->number == other.number;
	}
};

struct Node
{
	Student data;
	Node*	left	= nullptr;
	Node*	right	= nullptr;
};

class BinaryTree
{
private:
	Node* root{ nullptr };

public:
	Node*	Search(const int data) const noexcept;
	Node*	Search(Node* node, const int data) const noexcept;
	Node*	Add(const Student* data);
	Node*	Add(Node* node, const Student* data);
	bool	Remove(Node* node, const int data);
	bool	Remove(const int data);
	void	PrintTree(Node* node) const noexcept;
	void	PrintTree() const noexcept;
};


template <typename T>
class Node2
{
private:
	T data;
	std::unique_ptr<Node<T>> left{ nullptr };
	std::unique_ptr<Node<T>> right{ nullptr };

public:
	explicit Node2(const T& data) noexcept;
};

template<typename T>
inline Node2<T>::Node2(const T& data) noexcept : data{ data }
{

}



template<typename T>
class BinaryTree2
{
private:
	std::unique_ptr<Node2<T>> root;

private:
	Node* Search(Node2<T>* node, const int data) const noexcept;


public:
	Node* Search(const int data) const noexcept;
	Node* Add(const T& data);
	Node* Add(Node2<T>, const T& data);
	bool	Remove(Node2<T>, const int data);
	bool	Remove(const int data);
	void	PrintTree(Node2<T>* node) const noexcept;
};

template<typename T>
inline Node* BinaryTree2<T>::Search(Node2<T>* node, const int data) const noexcept
{
	if (node == nullptr)
	{
		std::cout << "해당하는 정보가 없습니다.\n";
		return nullptr;
	}

	if (node == data)
		return node;
	else if (node < data)
		Search(node, data);
	else
		Search(node, data);

	return nullptr;
}

template<typename T>
inline Node* BinaryTree2<T>::Search(const int data) const noexcept
{
	if (root == nullptr)
	{
		return nullptr;
	}

	return Search(root, data);
}

template<typename T>
inline Node* BinaryTree2<T>::Add(const T& data)
{
	return nullptr;
}

template<typename T>
inline Node* BinaryTree2<T>::Add(Node2<T>, const T& data)
{
	return nullptr;
}

template<typename T>
inline bool BinaryTree2<T>::Remove(Node2<T>, const int data)
{
	return false;
}

template<typename T>
inline bool BinaryTree2<T>::Remove(const int data)
{
	return false;
}

template<typename T>
inline void BinaryTree2<T>::PrintTree(Node2<T>* node) const noexcept
{
}
