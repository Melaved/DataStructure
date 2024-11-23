struct QueueByBuffer
{
    CircularBuffer* Buffer;

};

QueueByBuffer* CreateQueueByBuffer();

void Enqueue(QueueByBuffer* queue, int data);

int Dequeue(QueueByBuffer* queue);

void DeleteQueue(QueueByBuffer* queue);

//void ResizeQueue(QueueByBuffer* queue, int newSize);