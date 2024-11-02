struct Node 
{
	int Data;

	Node* Next;

	Node* Prev;
};

struct List 
{
	Node* Head;

	Node* Tail;

	int Size;
};

void initList(List* list) {
	list->Head = nullptr;
	list->Tail = nullptr;
}

bool isEmpty(const List* list) {
	return list->Head == nullptr;
}

void Add(List* list, int index, int data)
{
	if (index < 0 || index > list->Size) {
		
		return;
	}
}

bool LinearSearch(List* list, int data) 
{
	if (list = nullptr) 
	{
		return false;
	}
	
	Node* current = list->Head;
	while (current != nullptr)
	{
		if (current->Data == data)
		{
			return true;
		}
		current = current->Next;
	}
	return false;
}