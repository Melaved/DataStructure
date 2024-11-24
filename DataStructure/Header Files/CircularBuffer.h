struct CircularBuffer
{
	int* Buffer;
	int Tail;
	int Head;
	int BufferSize;
	int Count;
};

const int INITIAL_BUFFER_SIZE = 8;
CircularBuffer* CreateCircularBuffer();
void AddElement(CircularBuffer* buffer, int data);
int GetElement(CircularBuffer* buffer);
int FreeSpace(CircularBuffer* buffer);
int OccupiedSpace(CircularBuffer* buffer);
void Delete(CircularBuffer* buffer);


//void ResizeBuffer(CircularBuffer* buffer, int newSize);