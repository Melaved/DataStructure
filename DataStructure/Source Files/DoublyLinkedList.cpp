struct Node 
{
	int Data;

	Node* Next = nullptr;

	Node* Prev = nullptr;
};

struct List 
{
	Node* Head = nullptr;

	Node* Tail = nullptr;
};

void initList(List* list) {
	list->Head = nullptr;
	list->Tail = nullptr;
}

bool isEmpty(const List* list) {
	return list->Head == nullptr;
}