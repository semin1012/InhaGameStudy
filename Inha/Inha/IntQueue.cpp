#include "IntQueue.h"
#include <stdio.h>
#include <stdlib.h>

int Initialize(IntQueue* q, int max)
{
    q->que = (int*)malloc(sizeof(int) * max);
    if (q->que == nullptr) return -1;
    q->max = max;
    q->num = 0;
    q->front = 0;
    q->rear = 1;
    return 0;
}

int Enque(IntQueue* q, int x)
{
    if (q->num == q->max)
        return -1;

    q->que[(q->rear)-1] = x;
    q->rear++;

    if (q->rear == q->max + 1)
        q->rear = 1;

    q->num++;


    return 0;
}

int Deque(IntQueue* q, int* x)
{
    if (q->num == 0)
        return -1;

    q->num--;
    if (q->front == q->max + 1)
        q->front = 0;

    *x = q->que[q->front++];
    return 0;
}

int Peek(const IntQueue* q, int* x)
{
    if (q->num > 0) {
        *x = q->que[q->front];
        return q->que[q->front];
    }
    return -1;
}

void Clear(IntQueue* q)
{
    q->front = 0;
    q->rear = 1;
    q->num = 0;
}

int Capacity(const IntQueue* q)
{
    return q->max;
}

int Size(const IntQueue* q)
{
    return q->num;
}

int IsEmpty(const IntQueue* q)
{
    if (q->num == 0)
        return 1;
    return -1;
}

int IsFull(const IntQueue* q)
{
    if (q->front == q->rear)
        return 1;
    return -1;
}

int Search(const IntQueue* q, int x)
{
    int temp = q->front;
    for (int i = 0; i < q->num; i++)
    {
        if (x == q->que[temp])
            return i;
        temp += 1;
        if (temp > q->max - 1) temp = 0;
    }
    return -1;
}

void Print(const IntQueue* q)
{
    int temp = q->front;
    for (int i = 0; i < q->num; i++)
    {
        if (temp > q->max - 1) temp = 0;
        printf("%d ", q->que[temp]);
        temp += 1;
    }
    printf("\n");
}

void Terminate(IntQueue* q)
{
    free(q->que);
    q->que = nullptr;
}
