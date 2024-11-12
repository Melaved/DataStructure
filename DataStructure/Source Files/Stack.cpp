struct Stack 
{
	int* Buffer;
	int BufferSize;
	int Top;
    Stack(int size) : BufferSize(size), Top(-1) 
    {
        Buffer = new int[BufferSize];
    }

    ~Stack() 
    {
        delete[] Buffer;
    }
};

void Push(Stack* stack, int data) 
{
    //Stack overflow check
    if (stack->Top == stack->BufferSize - 1) 
    {
        return;
    }
    stack->Buffer[++stack->Top] = data;
}

void Push(Stack* stack, int data)
{
    if (stack->Top == stack->BufferSize - 1)
    {
        return;
    }
    stack->Buffer[++stack->Top] = data;
}

int Pop(Stack* stack)
{
    if (stack->Top == -1)
    {
        
        return -1; // ћожно вернуть специальное значение
    }
    return stack->Buffer[stack->Top--];
}

bool IsEmpty(Stack* stack) 
{
    return stack->Top == -1;
}

void Delete(Stack* stack)
{
    delete[] stack->Buffer;
    delete stack;
}