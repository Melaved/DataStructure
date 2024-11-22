#include <stdexcept>
#include "..\header files\CircularBuffer.h";

void AddElement(CircularBuffer* buffer, int data) 
{
	if (FreeSpace(buffer) == 0) 
	{
		buffer->Tail = data;
		buffer->Tail = (buffer->Tail + 1) % buffer->BufferSize;
	}
	else
	{
		buffer->Head = data;
		buffer->Head = (buffer->Head + 1) % buffer->BufferSize;
	}
}

int GetElement(CircularBuffer* buffer)
{
	if (OccupiedSpace(buffer) == 0)
	{
		throw "Buffer is empty";
	}
	int result = buffer->Tail;
	buffer->Tail = (buffer->Tail + 1) % buffer->BufferSize;
	return result;
}

int FreeSpace(CircularBuffer* buffer)
{
	return (buffer->BufferSize + buffer->Head - buffer->Tail) % buffer->BufferSize;
}

int OccupiedSpace(CircularBuffer* buffer)
{
	return (buffer->Tail - buffer->Head + buffer->BufferSize) % buffer->BufferSize;
}


void Delete(CircularBuffer* buffer)
{
	delete[] buffer->Buffer;
	buffer->Buffer = nullptr;
}
