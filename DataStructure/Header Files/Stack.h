struct Stack
{
	int* Buffer;
	int BufferSize;
	int Top;
	Stack(int size)
	{
		BufferSize = size;
		Top = -1;
		Buffer = new int[BufferSize];
	}
};

void Push(Stack* stack, int data);
int Pop(Stack* stack);
bool IsFull(Stack* stack);
bool IsEmpty(Stack* stack);
void Resize(Stack* stack, int newSize);
void Delete(Stack* stack);