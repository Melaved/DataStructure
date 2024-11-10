
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



void InsertAtBeginning(List* list, int data);

void InsertAtEnd(List* list, int data);

void InsertBefore(List* list, int index, int data);

void InsertAfter(List* list, int index, int data);

void RemoveAtIndex(List* list, int index);

void RemoveAtValue(List* list, int data);

bool LinearSearch(List* list, int data);

void ClearList(List* list);

Node* Split(Node* head);

Node* Merge(Node* first, Node* second);

Node* MergeSort(Node* head);

void SortList(List* list);

void ClearList(List* list);

//service functions
void ValidateList(List* list, int index);
void InsertNode(List* list, Node* newNode, Node* prevNode, Node* nextNode);
void RemoveNode(List* list, Node* nodeToRemove);