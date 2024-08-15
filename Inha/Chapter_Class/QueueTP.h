#pragma once

template <class T>
class QueueTP
{
private:
	enum { MAX = 10 };
	int queueSize;
	int count;
	int front;
	int rear;
	T* items;

public:
	explicit QueueTP(int size = MAX);
	QueueTP(const QueueTP& q);
	~QueueTP() { delete[] items; }
	bool isEmpty() { return count == 0; }
	bool isFull() { return count == queueSize; }
	T getFront() { return items[front]; }
	T getRear() { return items[rear-1]; }
	bool push(const T item);
	bool pop();
};

template<class T>
inline QueueTP<T>::QueueTP(int size) : queueSize(size), count(0), front(0), rear(0)
{
	items = new T[queueSize];
}

template<class T>
inline QueueTP<T>::QueueTP(const QueueTP& q)
{
	queueSize = q.queueSize;
	front = q.front;
	rear = q.rear;
	count = q.count;
	items = new T[queueSize];
	for (int i = 0; i < count; i++)
		items[i] = q.items[i];
}

template<class T>
inline bool QueueTP<T>::push(const T item)
{
	if (count < queueSize - 1)
	{
		items[rear++] = item;
		count++;
	
		if (rear == queueSize)
			rear = 0;
		return true;
	}
	return false;
}

template<class T>
inline bool QueueTP<T>::pop()
{
	if (count > 0)
	{
		front++;
		count--;
		if (front == queueSize -1)
			front = 0;
		return true;
	}
	return false;
}