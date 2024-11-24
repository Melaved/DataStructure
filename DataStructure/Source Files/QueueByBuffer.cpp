#include "..\header files\CircularBuffer.h";
#include "..\header files\QueueByBuffer.h";
#include <stdexcept>;

QueueByBuffer* CreateQueueByBuffer()
{
    QueueByBuffer* queue = new QueueByBuffer;
    queue->Buffer = CreateCircularBuffer();
    return queue;
}

void Enqueue(QueueByBuffer* queue, int data)
{
    if (FreeSpace(queue->Buffer) != 0) 
    {
        AddElement(queue->Buffer, data);
    }
    else 
    {
        return;
    }
}

int Dequeue(QueueByBuffer* queue) 
{
    return GetElement(queue->Buffer);
}

void DeleteQueue(QueueByBuffer* queue)
{
    Delete(queue->Buffer);
}
