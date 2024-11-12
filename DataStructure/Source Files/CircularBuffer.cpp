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

int FreeSpace(CircularBuffer* cb) 
{
    return cb->capacity - cb->size;
}

int UsedSpace(CircularBuffer* cb)
{
    return cb->size;
}

void AddToBuffer(CircularBuffer* cb, int data)
{
    if (cb->size == cb->capacity) 
    {
        //std::cout << "Buffer overflown";
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % cb->capacity;
    cb->size++;
}

int RemoveFromBuffer(CircularBuffer* cb) 
{
    if (cb->size == 0) 
    {
        //std::cout << "Buffer underflown";
        return -1; // ћожно вернуть специальное значение
    }
    int data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % cb->capacity;
    cb->size--;
    return data;
}