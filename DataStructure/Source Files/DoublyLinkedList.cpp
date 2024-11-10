#include <iostream>
using namespace std;

struct Node 
{
	int Data;

	Node* Next;

	Node* Prev;

	Node(int data) : Data(data), Next(nullptr), Prev(nullptr) {}
};

struct List 
{
	Node* Head;

	Node* Tail;

	List() : Head(nullptr), Tail(nullptr) {}
};

void ValidateList(List* list, int index) 
{
	if (list == nullptr || index < 0) 
	{
		return;
	}
}

void InsertNode(List* list, Node* newNode, Node* prevNode, Node* nextNode)
{
	newNode->Prev = prevNode;
	newNode->Next = nextNode;

	if (prevNode != nullptr) 
	{
		prevNode->Next = newNode;
	}
	else
	{
		list->Head = newNode;
	}

	if (nextNode != nullptr) 
	{
		nextNode->Prev = newNode;
	}
	else 
	{
		list->Tail = newNode;
	}
}


void InsertAtBeginning(List* list, int data)
{
	Node* newNode = new Node(data);
	InsertNode(list, newNode, nullptr, list->Head);

	if (list->Head != nullptr) {
		list->Head->Prev = newNode;
	}
}

void InsertAtEnd(List* list, int data) 
{
	Node* newNode = new Node(data);
	InsertNode(list, newNode, list->Tail, nullptr);

	if (list->Tail != nullptr) 
	{
		list->Tail->Next = newNode;
	}
}

void InsertBefore(List* list ,int index, int data) 
{
	ValidateList(list, index);

	if (index == 0)
	{
		InsertAtBeginning(list, data);
		return;
	}

	Node* current = list->Head;
	int currentIndex = 0;

	while (current != nullptr && currentIndex < index) 
	{
		current = current->Next;
		currentIndex++;
	}

	if (current == nullptr) 
	{ 
		return;
	}

	Node* newNode = new Node(data);
	InsertNode(list, newNode, current->Prev, current);

	current->Prev = newNode;
}

void InsertAfter(List* list,int index, int data)
{
	ValidateList(list, index);

	Node* current = list->Head;
	int currentIndex = 0;

	while (current != nullptr && currentIndex < index)
	{
		current = current->Next;
		currentIndex++;
	}

	if (current == nullptr)
	{
		return;
	}

	Node* newNode = new Node(data);
	InsertNode(list, newNode, current, current->Next);

	current->Next = newNode;
}


void RemoveNode(List* list, Node* nodeToRemove) 
{
	if (nodeToRemove->Prev)
	{
		nodeToRemove->Prev->Next = nodeToRemove->Next;
	}
	else 
	{
		list->Head = nodeToRemove->Next; 
	}

	if (nodeToRemove->Next)
	{
		nodeToRemove->Next->Prev = nodeToRemove->Prev;
	}
	else 
	{
		list->Tail = nodeToRemove->Prev;
	}

	delete nodeToRemove;
}

void RemoveAtIndex(List* list, int index) 
{
	ValidateList(list, index);

	Node* current = list->Head;
	int currentIndex = 0;

	while (current != nullptr && currentIndex < index)
	{
		current = current->Next;
		currentIndex++;
	}

	if (current == nullptr)
	{
		return;
	}

	RemoveNode(list, current);
}

void RemoveAtValue(List* list, int data)
{
	Node* current = list->Head;

	while (current != nullptr)
	{
		if (current->Data == data) 
		{
			RemoveNode(list, current);
			return;
		}
		current = current->Next;
	}
}

bool LinearSearch(List* list, int data) 
{
	if (list == nullptr) 
	{
		return false;
	}
	
	Node* current = list->Head;
	while(current != nullptr)
	{
		if (current->Data == data)
		{
			return true;
		}
		current = current->Next;
	}
	return false;
}

Node* Split(Node* head)
{
	if (head == nullptr) 
	{
		return 0;
	}
	Node* slow = head;
	Node* fast = head->Next;

	while (fast && fast->Next) 
	{
		slow = slow->Next;
		fast = fast->Next->Next;
	}
	Node* secondPart = slow->Next;
	slow->Next = nullptr;
	if (secondPart != nullptr)
	{
		secondPart->Prev = nullptr;
	}
	return secondPart;
}

Node* Merge(Node* first, Node* second) 
{
	if (first == nullptr) {
		return second;
	}

	if (second == nullptr) {
		return first;
	}

	if (first->Data < second->Data) 
	{
		first->Next = Merge(first->Next, second);

		if (first->Next != nullptr) 
		{
			first->Next->Prev = first;
		}

		first->Prev = nullptr;
		return first;
	}
	else 
	{
		second->Next = Merge(first, second->Next);
		if (second->Next != nullptr) {
			second->Next->Prev = second;
		}
		second->Prev = nullptr;
		return second;
	}
	
}

Node* MergeSort(Node* head)
{
	if (head == nullptr || head->Next == nullptr) 
	{
		return head;
	}
	
	Node* second = Split(head);

	head = MergeSort(head);
	second = MergeSort(second);

	return Merge(head, second);
}

void SortList(List* list)
{
	list->Head = MergeSort(list->Head);

	Node* current = list->Head;
	while (current && current->Next)
	{
		current = current->Next;
	}
	list->Tail = current;
}

void ClearList(List* list) 
{
	while (list->Head != nullptr) 
	{
		Node* temp = list->Head;
		list->Head = list->Head->Next;
		delete temp;
	}
}