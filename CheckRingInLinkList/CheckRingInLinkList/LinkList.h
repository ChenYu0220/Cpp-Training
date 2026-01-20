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

/*
* 第一次相遇慢指针走了 L+X ,快指针走了 2(L+X);快指针比慢指针多走n圈所以 快指针走了 L+X+nC
* 所以 L+X+nC = 2(L+X)
* 所以 L+X = nC
* L = nC - X
* L = (n-1)C + (C - X)
* 这意味着从头节点出发到环起点的距离 L 等于从相遇点出发沿环走 (n-1) 圈再加上从相遇点到环起点的距离 (C - X)
* 当 n-1 = 0 时
* 【寻找链表中环的起点 | 链表面试题】https://www.bilibili.com/video/BV1gJbnzwEqr?vd_source=c08e421cbc7550697c2e21c0ded8ee0b
*/