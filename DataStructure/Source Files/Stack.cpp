#include "..\header files\Stack.h";
#include <stdexcept>

void Push(Stack* stack, int data)
{
	if (IsFull(stack))
	{
		Resize(stack, stack->BufferSize * 2);
	}

	stack->Buffer[++stack->Top] = data;
}
int Pop(Stack* stack) 
{
	if (IsEmpty(stack)) 
	{
		throw ("Stack is empty");
	}

	return stack->Buffer[stack->Top--];

	//??????????????уменьшение размера???????????????????????????
	//int poppedValue = stack->Buffer[stack->Top--];

	//
	//if (stack->Top < stack->BufferSize / 4 && stack->BufferSize > 10) {
	//	ResizeStack(stack, stack->BufferSize / 2);
	//}

	//return poppedValue;
}

bool IsEmpty(Stack* stack) 
{
	return stack->Top == -1;
}

bool IsFull(Stack* stack) 
{
	return stack->Top == stack->BufferSize - 1;
}

void Resize(Stack* stack, int newSize)
{
	if (newSize <= 0) 
	{
		return;
	}

	int* newBuffer = new int[newSize];
	
	for (int i = 0; i <= stack->Top && i < newSize; ++i) 
	{
		newBuffer[i] = stack->Buffer[i];
	}

	delete[] stack->Buffer;
	stack->Buffer = newBuffer;
	stack->BufferSize = newSize;
}

void Delete(Stack* stack) 
{
	delete[] stack->Buffer;
	stack->Buffer = nullptr;
}
