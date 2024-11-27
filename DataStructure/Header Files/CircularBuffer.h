#pragma once

//! \brief Circular buffer structure.
struct CircularBuffer
{
	int* Buffer;
	int Tail;
	int Head;
	int BufferSize;
	int Count;
};

//! \brief initial circular buffer size.
const int INITIAL_BUFFER_SIZE = 4;

//! \brief Creates and initializes a circular buffer.
//! \return Pointer to the created circular buffer.
CircularBuffer* CreateCircularBuffer();

//! \brief Adds an element to the circular buffer.
//! param buffer Pointer to the circular buffer where the element will be added.
//! param data The value to be added to the buffer.
void AddElement(CircularBuffer* buffer, int data);

//! \brief Retrieves an element from the circular buffer.
//! param buffer Pointer to the circular buffer from which the element will be retrieved.
//! \return Value of the retrieved element.
int GetElement(CircularBuffer* buffer);

//! \brief Returns the number of free spaces in the circular buffer.
//! param buffer Pointer to the circular buffer for which the number of free spaces is needed.
//! \return Number of free spaces in the buffer.
int FreeSpace(CircularBuffer* buffer);

//! \brief Returns the number of occupied spaces in the circular buffer.
//! param buffer Pointer to the circular buffer for which the number of occupied spaces is needed.
//! \return Number of occupied spaces in the buffer.
int OccupiedSpace(CircularBuffer* buffer);

//! \brief Frees the memory occupied by the circular buffer.
//! param buffer Pointer to the circular buffer that needs to be deleted.
void Delete(CircularBuffer* buffer);

