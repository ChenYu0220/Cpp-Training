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
struct KNode
{
	T data;
	KNode<T>* next; // pointer to the next node
	KNode<T>* prev;	// pointer to the previous node
	KNode(T data) : data(data), next(nullptr), prev(nullptr) {};
};

template<typename T>
class KCustomList
{
public:
	KCustomList()
	{
		cout << "Construct" << endl;
		pHead = nullptr;
		pTail = nullptr;
		_size = 0;
	};

	~KCustomList()
	{
		cout << "Destruct" << endl;
		popAll();
	}

	void popAll()
	{
		KNode<T>* temp = pHead;
		while (temp != nullptr)
		{
			KNode<T>* next = temp->next;
			delete temp;
			temp = next;
		}
		pHead = nullptr;
		pTail = nullptr;
		_size = 0;
	}

	KNode<T>* push(T data)
	{
		KNode<T>* pNode = new KNode<T>(data);
		if (pHead == nullptr)
		{
			pHead = pTail = pNode;
			_size++;
			return pNode;
		};
		pTail->next = pNode;
		pNode->prev = pTail;
		pTail = pNode;
		_size++;
		return pNode;
	}

	KNode<T>* insert(KNode<T>* node, T data)
	{
		if(node == nullptr || node->next == nullptr)
		{
			return push(data);
		};
		KNode<T>* pNode = new KNode<T>(data);
		pNode->prev = node;
		pNode->next = node->next;
		if (node->next != nullptr) {
			node->next->prev = pNode;
			node->next = pNode;
		}
		_size++;
		return pNode;
	}

	KNode<T>* find(T targetData)
	{
		KNode<T>* current = pHead;  // 从链表头开始
		while (current != nullptr)  // 遍历直到链表尾部
		{
			if (current->data == targetData)
			{
				return current;  // 找到目标节点
			}
			current = current->next;  // 移动到下一个节点
		}
		return nullptr;  // 未找到
	}

	void remove(KNode<T>* node)
	{
		if (node == nullptr) return;  // 空指针检查

		// 1. 如果要删除的是头节点
		if (node == pHead)
		{
			pHead = node->next;
			if (pHead != nullptr)  // 如果删除后链表不为空
				pHead->prev = nullptr;
			else                    // 如果删除后链表为空
				pTail = nullptr;
		}
		// 2. 如果要删除的是尾节点
		else if (node == pTail)
		{
			pTail = node->prev;
			if (pTail != nullptr)
				pTail->next = nullptr;
			else
				pHead = nullptr;
		}
		// 3. 普通中间节点
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}

		delete node;
		_size--;
	}

	void display()
	{
		KNode<T>* temp = pHead;
		while (temp)
		{
			cout << temp->data << ",";
			temp = temp->next;
		}
		cout << endl;
	}

private:
	KNode<T>* pHead;
	KNode<T>* pTail;
	size_t _size = 0;
};







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