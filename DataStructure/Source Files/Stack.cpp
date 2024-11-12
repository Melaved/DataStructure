struct stack 
{
	int* buffer;
	int buffersize;
	int top;
    stack(int size) : buffersize(size), top(-1) 
    {
        buffer = new int[buffersize];
    }

    ~stack() 
    {
        delete[] buffer;
    }
};

void push(stack* stack, int data) 
{
    //stack overflow check
    if (stack->top == stack->buffersize - 1) 
    {
        return;
    }
    stack->buffer[++stack->top] = data;
}

void push(stack* stack, int data)
{
    if (stack->top == stack->buffersize - 1)
    {
        return;
    }
    stack->buffer[++stack->top] = data;
}

int pop(stack* stack)
{
    if (stack->top == -1)
    {
        
        return -1; // можно вернуть специальное значение
    }
    return stack->buffer[stack->top--];
}

bool isempty(stack* stack) 
{
    return stack->top == -1;
}

void delete(stack* stack)
{
    delete[] stack->buffer;
    delete stack;
}