struct CircularBuffer
{
	int* Buffer;
	int Tail;
	int Head;
	int BufferSize;
	CircularBuffer(int size)
	{
		BufferSize = size;
		Buffer = new int[size];
		Tail = 0;
		Head = 0;
	}

};

void AddElement(CircularBuffer* buffer, int data);
int GetElement(CircularBuffer* buffer);
int FreeSpace(CircularBuffer* buffer);
int OccupiedSpace(CircularBuffer* buffer);
void Delete(CircularBuffer* buffer);