#pragma once
//! \brief Structure for a stack.
struct Stack
{
    int BufferSize;     
    int* Buffer;       
    int Top;            
};

//! \brief Creates and initializes a stack.
//! \return Pointer to the created stack.
Stack* CreateStack();

//! \brief Adds an element to the top of the stack.
//! param stack Pointer to the stack where the element will be added.
//! param data The value to be added to the stack.
void Push(Stack* stack, int data);

//! \brief Removes and returns the top element from the stack.
//! param stack Pointer to the stack from which the element will be removed.
//! \return Value of the removed element.
int Pop(Stack* stack);

//! \brief Checks if the stack is full.
//! param stack Pointer to the stack that needs to be checked.
//! \return True if the stack is full, false otherwise.
bool IsFull(Stack* stack);

//! \brief Checks if the stack is empty.
//! param stack Pointer to the stack that needs to be checked.
//! \return True if the stack is empty, false otherwise.
bool IsEmpty(Stack* stack);

//! \brief Resizes the stack to a new size.
//! param stack Pointer to the stack that needs to be resized.
//! param newSize The new size for the stack.
void Resize(Stack* stack, int newSize);

//! \brief Frees the memory occupied by the stack.
//! param stack Pointer to the stack that needs to be deleted.
void Delete(Stack* stack);