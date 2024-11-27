#pragma once
#include "..\header files\QueueByBuffer.h"
#include "..\header files\QueueByStacks.h"
#include "..\header files\CircularBuffer_IO.h"


void ShowQueueMenu();

void PrintQueueByBuffer(QueueByBuffer* queue);

void PrintQueueByStacks(QueueByStacks* queue);

void QueueByBufferChoice(QueueByBuffer* queueByBuffer);

void QueueByStacksChoice(QueueByStacks* queue);
