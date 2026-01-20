#include "LinkList.h"
#include <iostream>
using namespace std;

int main()
{
	auto list = LinkList<int>();
	list.AddNode(1);
	auto node2 = list.AddNode(2);
	list.AddNode(3);
	auto node4 = list.AddNode(4);
	bool result = list.HasCycle();
	cout << "Has cycle: " << (result ? "true" : "false") << endl;
	node4->next = node2;
	result = list.HasCycle();
	cout << "Has cycle: " << (result ? "true" : "false") << endl;
	list.~LinkList();
	return 0;
}