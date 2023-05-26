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

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}

bool DoubleLinkedList::ListEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (ListEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (ListEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecords in a]descending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (ListEmpty()) {
		cout << "list is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number" << rollNo << " deleted" << endl;
}
void DoubleLinkedList::searchData() {
	if (ListEmpty() == true) {
		cout << "\nList is Empty" << endl;
	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number" << endl;
		cout << "\nName: " << curr->name << endl;
	}
}
	int main() {
		DoubleLinkedList obj;
		while (true) {
			try {
				cout << "\nMenu" << endl;
				cout << "1. Add a record to the list" << endl;
				cout << "2. Delete a record from the list" << endl;
				cout << "3. View all records in the ascending order of roll numbers" << endl;
				cout << "4. View all records in the descending order of roll numbers" << endl;
				cout << "5. Search for a record in the list" << endl;
				cout << "6. Exit" << endl;
				cout << "\nEnter your choice (1-6): ";
				char ch;
				cin >> ch;
			