#pragma once

struct Node
{
	int value;
	Node* next;
	Node(int val) : value(val), next(nullptr) {};
};

class IntList
{
public:
	IntList(int val);
	~IntList();

	void AddItem(int val);

	void PrintList();

	Node* FindMiddleNode();

private:
	Node* head = nullptr;
};