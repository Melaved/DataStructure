#include <stdexcept>
#include "..\header files\Stack.h"
#include "..\header files\QueueByStacks.h"


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
    }
    if (IsEmpty(queue->OutStack))
    {  
        return 0;
    }
    else 
    {
        return Pop(queue->OutStack);
    }
}

void ClearQueue(QueueByStacks* queue) 
{
    if (queue != nullptr)
    {
        if (queue->InStack != nullptr) 
        {
            Delete(queue->InStack);
            queue->InStack = nullptr;
        }
        if (queue->OutStack != nullptr) 
        {
            Delete(queue->OutStack);
            queue->OutStack = nullptr;
        }
        delete queue;
    }
}

