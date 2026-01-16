#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
public:
	T data;
	Node* next;
	Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {

private:
	Node<T>* head;

public:
	LinkedList() : head(nullptr) {}
	
	void Add(T Val) 
	{
		Node<T>* NewNode = new Node<T>(Val);
		if (!head) 
		{
			head = NewNode;
		} else 
		{
			Node<T>* temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = NewNode;
		}
	}

	// Reverses the linked list in place
	void Reverse() 
	{
		Node<T>* prev = nullptr;
		Node<T>* current = head;
		Node<T>* next = nullptr;
		while (current) 
		{
			next = current->next;	// 保存下一个元素
			current->next = prev;	// 当前节点的 next 元素指向前一个节点
			prev = current;	// 令当前节点作为前置节点
			current = next;	// 处理下一个元素
		}
		head = prev;
	}

	void PrintList() 
	{
		Node<T>* temp = head;
		while (temp) 
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
};