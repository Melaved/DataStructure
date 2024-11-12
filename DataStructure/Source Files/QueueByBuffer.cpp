#include "CircularBuffer.cpp"

struct Queue
{
    CircularBuffer* buffer;

    Queue(int size) 
    {
        buffer = new CircularBuffer(size);
    }

    ~Queue()
    {
        delete buffer;
    }
};

void Enqueue(Queue* queue, int data) 
{
    AddToBuffer(queue->buffer, data);
}

int Dequeue(Queue* queue) 
{
    return RemoveFromBuffer(queue->buffer);
}

void DeleteQueue(Queue* queue) 
{
    delete queue; // Удаляем очередь, освобождая память
}
