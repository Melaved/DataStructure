
#include <stdexcept>
#include "..\header files\Stack.h"
struct QueueByStacks
{
    Stack* InStack;
    Stack* OutStack;
};

QueueByStacks* CreateQueueByStacks()
{
    QueueByStacks* queue = new QueueByStacks();
    queue->InStack = CreateStack();
    queue->OutStack = CreateStack();
    return queue;
}

void Enqueue(QueueByStacks* queue, int data)
{
    Push(queue->InStack, data);
}

int Dequeue(QueueByStacks* queue)
{
    if (IsEmpty(queue->OutStack))
    {
        while (!IsEmpty(queue->InStack))
        {
            Push(queue->OutStack, Pop(queue->InStack));
        }

        if (IsEmpty(queue->OutStack))
        {
            throw std::runtime_error("Queue is empty.");
        }
    }

    return Pop(queue->OutStack);
}

//bool IsEmptyQueue(QueueByStacks* queue)
//{
//    return IsEmpty(queue->InStack) && IsEmpty(queue->OutStack);
//}

void ClearQueue(QueueByStacks* queue)
{
    delete queue->InStack;
    delete queue->OutStack;
    queue->InStack = nullptr;
    queue->OutStack = nullptr;
}
