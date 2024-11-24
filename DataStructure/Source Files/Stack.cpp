#include "..\header files\Stack.h"

#include <stdexcept>

//Stack* CreateStack()
//{
//    Stack* stack = new Stack();
//    stack->BufferSize = 5;
//    stack->Buffer = new int[stack->BufferSize];
//    stack->Top = -1;
//    return stack;
//}
//
//void Push(Stack* stack, int data)
//{
//    if (IsFull(stack))
//    {
//        Resize(stack, stack->BufferSize * 2);
//    }
//
//    stack->Buffer[++stack->Top] = data;
//}
//
//int Pop(Stack* stack)
//{
//    if (IsEmpty(stack))
//    {
//        throw std::runtime_error("Stack is empty");
//    }
//
//    int result = stack->Buffer[stack->Top]; // Сначала сохраняем значение
//    stack->Top--;
//    return result;
//}
//
//bool IsEmpty(Stack* stack)
//{
//    return stack->Top == -1;
//}
//
//bool IsFull(Stack* stack)
//{
//    return stack->Top == stack->BufferSize - 1;
//}
//
//void Resize(Stack* stack, int newSize)
//{
//    if (newSize <= 0)
//    {
//        return;
//    }
//
//    int* newBuffer = new int[newSize];
//
//    for (int i = 0; i <= stack->Top && i < newSize; ++i)
//    {
//        newBuffer[i] = stack->Buffer[i];
//    }
//
//    delete[] stack->Buffer;
//    stack->Buffer = newBuffer;
//    stack->BufferSize = newSize;
//}
//
//void Delete(Stack* stack)
//{
//    delete[] stack->Buffer;
//    stack->Buffer = nullptr;
//}
// Функция для создания нового стека
Stack* CreateStack() {
    Stack* stack = new Stack();
    stack->BufferSize = 5;
    stack->Buffer = new int[stack->BufferSize];
    stack->Top = -1;
    return stack;
}

// Функция для добавления элемента в стек
void Push(Stack* stack, int data) {
    if (IsFull(stack)) {
        Resize(stack, stack->BufferSize * 2);
    }
    stack->Buffer[++stack->Top] = data;
}

// Функция для извлечения элемента из стека
int Pop(Stack* stack) {
    if (IsEmpty(stack)) {
        throw std::runtime_error("Stack is empty");
    }
    return stack->Buffer[stack->Top--]; // Упрощенный возврат
}

// Функция для проверки, пуст ли стек
bool IsEmpty(Stack* stack) {
    return stack->Top == -1;
}

// Функция для проверки, полон ли стек
bool IsFull(Stack* stack) {
    return stack->Top == stack->BufferSize - 1;
}

// Функция для изменения размера стека
void Resize(Stack* stack, int newSize) {
    if (newSize <= 0) {
        return;
    }

    int* newBuffer = new int[newSize];
    for (int i = 0; i <= stack->Top && i < newSize; ++i) {
        newBuffer[i] = stack->Buffer[i];
    }

    delete[] stack->Buffer;
    stack->Buffer = newBuffer;
    stack->BufferSize = newSize;
}

// Функция для удаления стека
void Delete(Stack* stack) {
    delete[] stack->Buffer;
    delete stack; // Освобождаем память для самого стека
}
