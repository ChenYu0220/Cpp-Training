#include "ReverseList.h"


int main() {
	auto list = LinkedList<int>();
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.PrintList();
	list.Reverse();
	list.PrintList();
	return 0;
}