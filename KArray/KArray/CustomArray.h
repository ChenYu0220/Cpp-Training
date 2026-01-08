#pragma once
#include <iostream>
using namespace std;

/*
Implement the array and the below api.
auto arr = new CustomArray();
arr.reserve(4);
arr.push(1);
arr.push(2);
arr.insert(1, 3);
arr.remove(1);
arr.pop();
arr.clear();
int index = arr.findIndex(1);
*/

template<typename T>
class KCustomArray {
public: 
	KCustomArray() 
	{
		_size = 0;
		_capacity = 0;
		_data = nullptr;
	};

	~KCustomArray()
	{
		_size = 0;
		_capacity = 0;
		delete[] _data;
	};

	// 分配内存
	void reverse(size_t newSize)
	{
		if (newSize <= _capacity)
		{
			return;
		}
		T* tempData = new T[newSize];
		for (size_t i = 0; i < _size; i++)
		{
			tempData[i] = _data[i];
		}
		delete[] _data;
		_capacity = newSize;
		_data = tempData;
	}

	void decreaseMemory()
	{
		if (_size <= _capacity / 2)
		{
			reverse(_capacity / 2);
		};
	}

	void push(const T target)
	{
		if (_size >= _capacity)
		{
			// 超出容量
			reverse(_capacity == 0 ? 1 : _capacity * 2);
		}
		_data[_size++] = target;
	}

	void insert(size_t index, const T target)
	{
		if (index > _size)
		{
			throw std::out_of_range("Index out of range");
		}
		if (_size >= _capacity)
		{
			// 超出容量
			reverse(_capacity == 0 ? 1 : _capacity * 2);
		}
		// size = max index + 1
		for (size_t i = _size; i > index; i--)
		{
			_data[i] = _data[i - 1];
		}
		_data[index] = target;
		_size++;
	}

	void remove(size_t index)
	{
		if (index >= _size)
		{
			return;
		}
		for (size_t i = index; i < _size - 1; i++)
		{
			_data[i] = _data[i + 1];
		}
		_size--;
		decreaseMemory();
	}

	T pop()
	{
		if (_size <= 0)
		{
			throw out_of_range("Array is empty");
		}
		T value = _data[_size - 1];
		_size--;
		decreaseMemory();
		return value;
	}

	// 只清空元素，不释放内存
	void clear()
	{
		_size = 0;
	}

	int findIndex(const T target)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_data[i] == target)
			{
				return i;
			}
		}
		return -1;
	}

	friend ostream& operator<<(ostream& out, KCustomArray& arr) {
		for (int i = 0; i < arr._size; i++)
		{
			out << arr._data[i] << " ";
		}
		return out;
	}

private:
	T* _data;
	size_t _size = 0;
	size_t _capacity = 0;
};

template<typename T>
class CustomArray {
public:
	CustomArray() 
	{
		_size = 0;
		_capacity = 0;
		_data = nullptr;
	};

	~CustomArray()
	{
		_size = 0;
		_capacity = 0;
		delete[] _data;
	};

	void reserve(const size_t size)
	{
		if (size <= _capacity)
		{
			return;
		};
		T* tempData = new T[size];
		for (size_t i = 0; i < _size; i++)
		{
			tempData[i] = _data[i];
		};
		delete[] _data;
		_capacity = size;
		_data = tempData;
	};

	void push(const T target)
	{
		if (_size >= _capacity) 
		{
			// above the capacity
			reserve(_capacity == 0 ? 1 : _capacity*2);
		}
		_data[_size++] = target;
	};

	void insert(const size_t index, const T target)
	{
		if(index >= _size)
		{
			reserve(_capacity == 0 ? 1 : _capacity * 2);
		}
		for (size_t i = _size; i > index; i--)
		{
			_data[i] = _data[i - 1];
		}
		_data[index] = target;
		_size++;
	};
	
	void remove(const size_t index)
	{
		if ((index >= _size) || (index < 0))
		{
			return;
		};
		for (size_t i = index; i < _size - 1; i++)
		{
			_data[i] = _data[i + 1];
		};
		_size--;
		decreaceMemory();
	};
	
	void pop()
	{
		if (_size <= 0)
		{
			return;
		};
		_size--;
		decreaceMemory();
	};

	void clear()
	{
		// clear() will keep the capacity of the container, so that it would not allocate memory frequently
		_size = 0;
	};

	// if the number of size <= capacity/2, we need to decreace the capacity of the array
	void decreaceMemory()
	{
		if (_size <= _capacity / 2)
		{
			reserve(_capacity / 2);
		};
	};

	int findIndex(const T target)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_data[i] == target)
			{
				return i;
			};
		};
		return -1;
	};

	friend ostream& operator<<(ostream& out, CustomArray& arr) {
		for (int i = 0; i < arr._size; i++) 
		{
			out << arr._data[i] << " ";
		};
		return out;
	};

private:
	size_t _size;
	size_t _capacity;
	T* _data;
};