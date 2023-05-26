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
	bool searach(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
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


	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs)
			cout << "\nDuplicate number not allowed" << endl;
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
	{
		previous = current; // step 1.d
		current = current->next; // step 1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	bool DoubleLinkedList::search(int rollNo, Node previous, Node current) {
		*previous = START; // step 1.a
		*current = START; // step 1.b
		while (*current != NULL && rollNo != (*current)->noMhs) { // step 1.c
			*previous = *current; // step 1.d
			*current = (*current)->next; // step 1.e
		}
		return (*current != NULL);
	}
