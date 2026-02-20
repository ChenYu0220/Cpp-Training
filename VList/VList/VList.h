#pragma once

#include <iostream>
#include <vector>
#include <string>

// 模拟数据模型
class Model
{
public: 
	int totalItems() const 
	{
		return 1000000;  // 假设有100万项
	}

	std::string dataForItem(int index) const
	{
		return "Item" + std::to_string(index);
	}
};

// VList组件
class VirtualList
{
	const Model* model;
	int itemHeight;	// 每项高度
	int viewportHeight;	// 可视区域高度
	int scrollOffset;	// 当前滚动偏移

	public:
		VirtualList(const Model* m, int itemH, int viewH): model(m), itemHeight(itemH), viewportHeight(viewH), scrollOffset(0) {}

	// 设置滚动偏移
	void scrollTo(int offset)
	{
		scrollOffset = offset;
		updateVisibleItems();
	}

	// 计算当前可见项并渲染（此处用打印省略）
	void updateVisibleItems()
	{
		int firstVisible = scrollOffset / itemHeight;
		int lastVisible = (scrollOffset + viewportHeight - 1) / itemHeight;

		// 确保不越界
		if (firstVisible < 0) firstVisible = 0;
		if (lastVisible > model->totalItems()) lastVisible = model->totalItems() - 1;

		std::cout << "Visible items: " << firstVisible << "-" << lastVisible << "\n";

		for (int i = firstVisible; i <= lastVisible; ++i)
		{
			std::cout << "Rendering: " << model->dataForItem(i) << "\n";
		}
	}

	// 模拟鼠标滚轮
	void onScrolling(int delta)
	{
		int maxOffset = model->totalItems() * itemHeight - viewportHeight;
		int newOffset = scrollOffset + delta; // 向下为正
		if (newOffset < 0) newOffset = 0;
		if (newOffset > maxOffset) newOffset = maxOffset;
		scrollTo(newOffset);
	}
};