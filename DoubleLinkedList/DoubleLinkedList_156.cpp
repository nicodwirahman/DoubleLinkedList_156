#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string naem;
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
	void revtraverse();
	void hapus();
	void searchData();
};