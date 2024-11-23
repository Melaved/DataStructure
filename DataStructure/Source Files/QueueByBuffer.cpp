#include "..\header files\CircularBuffer.h";
#include "..\header files\QueueByBuffer.h";

QueueByBuffer* CreateQueueByBuffer()
{
    QueueByBuffer* queue = new QueueByBuffer;
    queue->Buffer = CreateCircularBuffer();
    return queue;
}

void Enqueue(QueueByBuffer* queue, int data)
{
    AddElement(queue->Buffer, data);
}

int Dequeue(QueueByBuffer* queue) 
{
    return GetElement(queue->Buffer);
}

//void ResizeQueue(QueueByBuffer* queue, int newSize)
//{
//    ResizeBuffer(&queue->Buffer, newSize);
//}

void DeleteQueue(QueueByBuffer* queue)
{
    Delete(queue->Buffer);
}
