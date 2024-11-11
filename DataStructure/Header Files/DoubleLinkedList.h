//! brief Represents a node in a doubly linked list.
struct Node
{
    //! brief The data stored in the node.
    int Data;

    //! brief Pointer to the next node in the list.
    Node* Next;  

    //!< Pointer to the previous node in the list.
    Node* Prev;

    //! brief Constructs a new node with the given data.
    //! param data The data to be stored in the node.
    Node(int data) : Data(data), Next(nullptr), Prev(nullptr) {}
};

//! brief Represents a doubly linked list.
struct List
{
    //! brief Pointer to the first node in the list.
    Node* Head;

    //! brief Pointer to the last node in the list.
    Node* Tail;   

    //! brief Constructs a new empty list.
    List() : Head(nullptr), Tail(nullptr) {}
};

//! brief Inserts a new node at the beginning of the list.
//! param list Pointer to the list where the node will be inserted.
//! param data The data to be stored in the new node.
void InsertAtBeginning(List* list, int data);

//! brief Inserts a new node at the end of the list.
//! param list Pointer to the list where the node will be inserted.
//! param data The data to be stored in the new node.
void InsertAtEnd(List* list, int data);

//! brief Inserts a new node before the specified index in the list.
//! param list Pointer to the list where the node will be inserted.
//! param index The index before which the new node will be inserted.
//! param data The data to be stored in the new node.
void InsertBefore(List* list, int index, int data);

//! brief Inserts a new node after the specified index in the list.
//! param list Pointer to the list where the node will be inserted.
//! param index The index after which the new node will be inserted.
//! param data The data to be stored in the new node.
void InsertAfter(List* list, int index, int data);

//! brief Removes a node at a specified index from the list.
//! param list Pointer to the list from which the node will be removed.
//! param index The index of the node to be removed.
void RemoveAtIndex(List* list, int index);

//! brief Removes the first node with the specified value from the list.
//! param list Pointer to the list from which the node will be removed.
//! param data The value of the node to be removed.
void RemoveAtValue(List* list, int data);

//! brief Performs a linear search for a specified value in the list.
//! param list Pointer to the list to search in.
//! param data The value to search for.
//! return True if the value is found, otherwise false.
bool LinearSearch(List* list, int data);

//! brief Clears all nodes from the list and frees memory.
//! param list Pointer to the list to be cleared.
void ClearList(List* list);

//! brief Splits a given linked list into two halves.
//! param head Pointer to the head of the list to be split.
//! return Pointer to the head of the second half of the split list.
Node* Split(Node* head);

//! brief Merges two sorted lists into one sorted list.
//! param first Pointer to the head of the first sorted list.
//! param second Pointer to the head of the second sorted list.
//! return Pointer to the head of the merged sorted list.
Node* Merge(Node* first, Node* second);

//! brief Sorts a linked list using merge sort algorithm.
//! param head Pointer to the head of the list to be sorted.
//! return Pointer to the head of the sorted list.
Node* MergeSort(Node* head);

//! brief Sorts a doubly linked list.
//! param list Pointer to the list to be sorted.
void SortList(List* list);

//! brief Validates integrity of the linked list at a specific index.
//! param list Pointer to the list to validate.
//! param index The index to check for integrity.
void ValidateList(List* list, int index);

//! brief Inserts a new node into the list given its surrounding nodes.
//! param list Pointer to the target list for insertion.
//! param newNode Pointer to the new node to be inserted.
//! param prevNode Pointer to the previous node (can be nullptr).
//! param nextNode Pointer to the next node (can be nullptr).
void InsertNode(List* list, Node* newNode, Node* prevNode, Node* nextNode);

//! brief Removes a specified node from the list.
//! param list Pointer to the target list for removal.
//! param nodeToRemove Pointer to the node that should be removed.
void RemoveNode(List* list, Node* nodeToRemove);
