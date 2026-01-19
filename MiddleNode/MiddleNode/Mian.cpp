#include "MiddleNode.h"

// 寻找链表的中间节点
// 寻找一个单向链表，找到它的中间节点并返回。如果有两个中间节点，则返回第二个中间节点。
int main()
{
	IntList myList(12);
	myList.AddItem(23);
	myList.AddItem(36);
	myList.AddItem(15);
	myList.AddItem(25);
	myList.AddItem(7);
	myList.AddItem(18);
	myList.PrintList();
	myList.FindMiddleNode();

	myList.~IntList();
	return 0;
}