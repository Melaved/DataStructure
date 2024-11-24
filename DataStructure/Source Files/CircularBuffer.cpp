#include <stdexcept>
#include "..\header files\CircularBuffer.h";

CircularBuffer* CreateCircularBuffer()
{
    CircularBuffer* buffer = new CircularBuffer();
    buffer->BufferSize = INITIAL_BUFFER_SIZE;
    buffer->Buffer = new int[buffer->BufferSize];
    buffer->Head = 0;
    buffer->Tail = 0;
    buffer->Count = 0; 
    return buffer;
}

void AddElement(CircularBuffer* buffer, int data) 
{
    if (buffer->Count == buffer->BufferSize)
    {
        buffer->Head = (buffer->Head + 1) % buffer->BufferSize; 
    }
    else 
    {
        buffer->Count++;
    }

    buffer->Buffer[buffer->Tail] = data;
    buffer->Tail = (buffer->Tail + 1) % buffer->BufferSize; 
}

int GetElement(CircularBuffer* buffer) 
{
    if (buffer->Count == 0) {
        throw std::out_of_range("Buffer is empty");
    }

    int result = buffer->Buffer[buffer->Head];
    buffer->Head = (buffer->Head + 1) % buffer->BufferSize;
    buffer->Count--;
    return result;
}

int FreeSpace(CircularBuffer* buffer) {
    return buffer->BufferSize - buffer->Count;
}

int OccupiedSpace(CircularBuffer* buffer) {
    return buffer->Count; 
}

void Delete(CircularBuffer* buffer) {
    delete[] buffer->Buffer;
    delete buffer;
}


//void ResizeBuffer(CircularBuffer* buffer, int newSize)
//{
//	if (newSize == buffer->BufferSize || newSize <= 0)
//	{
//		return;
//	}
//
//	int* newBuffer = new int[newSize];
//
//	int currentIndex = buffer->Head;
//	for (int i = 0; i < buffer->BufferSize; ++i)
//	{
//		newBuffer[i] = buffer->Buffer[currentIndex];
//		currentIndex = (currentIndex + 1) % buffer->BufferSize;
//	}
//
//	delete[] buffer->Buffer;
//	buffer->Buffer = newBuffer;
//	buffer->BufferSize = newSize;
//	buffer->Head = 0;
//	buffer->Tail = buffer->BufferSize - 1;
//
//}