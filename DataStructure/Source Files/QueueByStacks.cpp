#include "Stack.cpp"
struct TwoStacksQueue 
{
    Stack* stack1;
    Stack* stack2;

    TwoStacksQueue(int size)
    {
        stack1 = new Stack(size);
        stack2 = new Stack(size);
    }

    ~TwoStacksQueue()
    {
        Delete(stack1);
        Delete(stack2);
    }
};

void Enqueue(TwoStacksQueue* queue, int data) 
{
    Push(queue->stack1, data);
}

int Dequeue(TwoStacksQueue* queue) 
{
    if (IsEmpty(queue->stack2)) 
    {
        while (!IsEmpty(queue->stack1)) 
        {
            Push(queue->stack2, Pop(queue->stack1));
        }
    }

    if (IsEmpty(queue->stack2)) 
    {
        //std::cout << "Queue underflown";
        return -1; // ћожно вернуть специальное значение
    }

    return Pop(queue->stack2);
}
