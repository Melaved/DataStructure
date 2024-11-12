struct CircularBuffer
{
    int* buffer;
    int head;
    int tail;
    int capacity;
    int size;

    CircularBuffer(int size) : capacity(size), head(0), tail(0), size(0)
    {
        buffer = new int[capacity];
    }

    ~CircularBuffer() 
    {
        delete[] buffer;
    }
};

int FreeSpace(CircularBuffer* circularBuffer) 
{
    return circularBuffer->capacity - circularBuffer->size;
}

int UsedSpace(CircularBuffer* circularBuffer)
{
    return circularBuffer->size;
}

void AddToBuffer(CircularBuffer* circularBuffer, int data)
{
    if (circularBuffer->size == circularBuffer->capacity)
    {
        //std::cout << "Buffer overflown";
        return;
    }
    circularBuffer->buffer[circularBuffer->tail] = data;
    circularBuffer->tail = (circularBuffer->tail + 1) % circularBuffer->capacity;
    circularBuffer->size++;
}

int RemoveFromBuffer(CircularBuffer* circularBuffer)
{
    if (circularBuffer->size == 0)
    {
        //std::cout << "Buffer underflown";
        return -1; // ћожно вернуть специальное значение
    }
    int data = circularBuffer->buffer[circularBuffer->head];
    circularBuffer->head = (circularBuffer->head + 1) % circularBuffer->capacity;
    circularBuffer->size--;
    return data;
}