#include "..\header files\CircularBuffer.h";

struct Queue {
    CircularBuffer Buffer; 
};


void Enqueue(Queue* queue, int data) {
    AddElement(&queue->Buffer, data);
}

int Dequeue(Queue* queue) {
    return GetElement(&queue->Buffer);
}

void DeleteQueue(Queue* queue) {
    Delete(&queue->Buffer);
}
