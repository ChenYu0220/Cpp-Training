#include "CustomArray.h"
#include "CustomList.h"
#include <iostream>
using namespace std;

// test
int main()
{
	cout << "----------CustomArray----------" << endl;
	auto arr = CustomArray<int>();
	arr.reserve(4);
	arr.push(1);
	arr.push(2);
	arr.insert(1, 3);
	arr.remove(1);
	cout << arr << endl;// 1
	arr.pop();
	arr.clear();
	int index = arr.findIndex(1);
	cout << index << endl; // -1

	cout << "----------CustomList----------" << endl;
	auto list1 = CustomList<int>(); // Construct
	auto node1 = list1.push(1);
	auto node2 = list1.push(2);
	auto node3 = list1.insert(node2, 3);
	auto ret = list1.find(2);
	cout << ret->data << endl;// 2
	list1.remove(node2);
	list1.display(); // 1,3
	list1.popAll();
	return 0; // Destruct
}