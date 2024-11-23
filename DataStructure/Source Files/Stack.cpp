#include "..\header files\Stack.h"

#include <stdexcept>

Stack* CreateStack()
{
    Stack* stack = new Stack();
    stack->BufferSize = 5;
    stack->Buffer = new int[stack->BufferSize];
    stack->Top = -1;
    return stack;
}

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
        throw std::runtime_error("Stack is empty");
    }

    return stack->Buffer[stack->Top--];
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
