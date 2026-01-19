#include "MiddleNode.h"
#include <iostream>
using namespace std;

IntList::IntList(int val)
{
	head = new Node(val);
}

IntList::~IntList()
{
	while (head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void IntList::AddItem(int val)
{
	Node* newNode = new Node(val);
	Node* current = head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = newNode;
}

void IntList::PrintList()
{
	Node* current = head;
	while (current)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

Node* IntList::FindMiddleNode()
{
	Node* slowPtr = head;
	Node* fastPtr = head;
	while (fastPtr != nullptr && fastPtr->next != nullptr)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		
	};
	cout << slowPtr->value << endl;
	return slowPtr;
}