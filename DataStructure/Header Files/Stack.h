#pragma once
struct Stack
{
    int BufferSize;
    int* Buffer;
    int Top;
};

Stack* CreateStack();
void Push(Stack* stack, int data);
int Pop(Stack* stack);
bool IsFull(Stack* stack);
bool IsEmpty(Stack* stack);
void Resize(Stack* stack, int newSize);
void Delete(Stack* stack);
