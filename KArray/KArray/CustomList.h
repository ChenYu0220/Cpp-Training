#pragma once
#include <iostream>
using namespace std;
/*
Implement the linked list and the below api.
auto list1 = new CustomList();
auto node1 = list1.push(1);
auto node2 = list1.push(2);
auto node3 = list1.insert(node2, 3);
auto ret = list1.find(2);
list1.remove(node2);
list1.popAll();
*/
template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node(T data) : data(data), next(nullptr), prev(nullptr) {};
};

template<typename T>
class CustomList 
{
public:
	CustomList()
	{
		cout << "Construct" << endl;
		pHead = nullptr;
		pTail = nullptr;
		_size = 0;
	};

	~CustomList() 
	{
		cout << "Destruct" << endl;
		popAll();
	};

	Node<T>* push(T data)
	{
		Node<T>* pNode = new Node<T>(data);
		if (pHead == nullptr)
		{
			pHead = pTail = pNode;
		};
		pTail->next = pNode;
		pNode->prev = pTail;
		pTail = pNode;
		_size++;
		return pNode;
	};

	Node<T>* insert(Node<T>* node, T data)
	{
		if (node == nullptr || node->next == nullptr)
		{
			return push(data);
		};
		Node<T>* pNode = new Node<T>(data);
		pNode->prev = node;
		pNode->next = node->next;
		if (node->next != nullptr) {
			node->next->prev = pNode;
			node->next = pNode;
		}
		_size++;
		return pNode;
	};

	Node<T>* find(T targetData)
	{
		Node<T>* temp = pHead;
		while (temp != nullptr)
		{
			if (temp->data == targetData)
			{
				return temp;
			};
			temp = temp->next;
		};
		return nullptr;
	};

	void remove(Node<T>* node)
	{
		if (node == nullptr)
		{
			return;
		};
		node->prev->next = node->next;
		if (node->next != nullptr)
		{
			node->next->prev = node->prev;
		};
		if (node == pHead)
		{
			pHead = node->next;
		};
		if (node == pTail)
		{
			pTail = node->prev;
		};
		delete node;
		_size--;
	};

	void popAll() 
	{
		Node<T>* temp = pHead;
		while (temp != nullptr)
		{
			Node<T>* next = temp->next;
			delete temp;
			temp = next;
		}
		pHead = nullptr;
		pTail = nullptr;
	};

	void display()
	{
		Node<T>* temp = pHead;
		while (temp)
		{
			cout << temp->data << ",";
			temp = temp->next;
		}
		cout << endl;
	};
private:
	Node<T>* pHead;
	Node<T>* pTail;
	size_t _size;
};