#pragma once

template<typename T>
struct Node
{
	T data;
	Node<T>* next; // Ensure this is Node<T>*, not T*
	Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkList
{
private:
	Node<T>* head;
public:
	LinkList() 
	{
		head = nullptr;
	};

	~LinkList() 
	{
		if (HasCycle())
		{
			BreakCycle();
		};

		auto current = head;
		while (current != nullptr)
		{
			auto temp = current->next;
			delete current;
			current = temp;
		}
		head = nullptr;
	};

	Node<T>* AddNode(T value) 
	{
		auto newNode = new Node<T>(value);
		if (head == nullptr) 
		{
			head = newNode;
			return head;
		}
		else
		{
			auto current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
			return newNode;
		}

	};

	Node<T>* GetHead() 
	{
		return head; 
	}

	bool HasCycle()
	{
		auto fast = head;
		auto slow = fast;
		bool result = false;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				result = true;
				break;
			}
		}
		return result;
	}

	void BreakCycle()
	{
		if (!HasCycle())
		{
			return;
		};

		auto slow = head;
		auto fast = head;

		// 找到相遇点
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
			{
				break;
			}
		}

		// 找到环的入口并断开
		slow = head;
		Node<T>* prev = nullptr;

		while (slow != fast)
		{
			prev = fast;
			slow = slow->next;
			fast = fast->next;
		}

		// prev现在是环中最后一个节点，断开它
		if (prev)
		{
			prev->next = nullptr;
		}
	}
};