#include "VList.h"

int main()
{
	Model model;
	VirtualList list(&model, 20, 100);  // 每项20像素，可视区域100像素

	list.scrollTo(0);    // 初始位置
	list.onScrolling(500);  // 向下滚动40像素
	return 0;
}