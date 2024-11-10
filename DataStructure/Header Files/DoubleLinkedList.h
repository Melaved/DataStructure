struct Node {
    int Data;
    Node* Next;
    Node* Prev;

    Node(int data);
};

struct List {
    Node* Head;
    Node* Tail;

    List();
};


void InsertAtBeginning(List* list, int data);

void InsertAtEnd(List* list, int data);

void InsertBefore(List* list, int index, int data);

void InsertAfter(List* list, int index, int data);

void RemoveAtIndex(List* list, int index);

void RemoveAtValue(List* list, int data);

bool LinearSearch(List* list, int data);

void ClearList(List* list);

//service functions
void ValidateList(List* list, int index);
void InsertNode(List* list, Node* newNode, Node* prevNode, Node* nextNode);