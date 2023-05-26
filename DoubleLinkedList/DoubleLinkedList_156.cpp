#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool ListEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student:";
	cin >> nim;
	cout << "\nEnter the name of the student:";
	cin >> nm;
	Node* newNode = new Node();
	newNode->noMhs = nim;
	newNode->name = nm;

	/*insert a node in the begining of a doubly - linked list*/
	if (START == NULL || nim <= START -> noMhs) {
		if (START != NULL && nim == START -> noMhs){
			cout << "\nDuplicated number not allowed" << endl;
		return;
	}
	newNode->next = START;
	if (START != NULL)
		START->prev = newNode;
	newNode->prev = NULL;
	START = newNode;
	return;
}

/*inserting a Node Between Two Nodes in the list*/
Node* current = START; // step 1.a
Node* previous = NULL; // step 1.b
while (current->next != NULL && current->next->noMhs < nim) // step 1.c
	{
		previous = current; // step 1.d
		current = current->next; // step 1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}


newNode->next = current->next; // step 4
newNode->prev = current; // step 5
if (current->next != NULL)
current->next->prev = newNode; //step 6
current->next = newNode; // step 7
 }

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START; //stepp 1.a
	*current = START; // step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {//Step 1.c
		*previous = *current; //step 1.d
		*current = (*current)->next; //step1.e
	}
	return (*current != NULL);
}