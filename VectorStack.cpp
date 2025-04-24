#include "VectorStack.h"
#include <stdexcept>
#include <algorithm> // для std::copy

VectorStack::VectorStack() : _data(nullptr), _capacity(0), _size(0) {}

VectorStack::~VectorStack() 
{
	delete[] _data;
}

VectorStack::VectorStack(const VectorStack& other) : _capacity(other._capacity), _size(other._size) 
{
	_data = new ValueType[_capacity];
	for (size_t i = 0; i < _size; ++i) {
		_data[i] = other._data[i];
	}
}

VectorStack& VectorStack::operator=(const VectorStack& other) 
{
	if (this != &other) 
	{
		delete[] _data; 
		
		_capacity = other._capacity;
		_size = other._size;
		_data = new ValueType[_capacity];
		
		for (size_t i = 0; i < _size; ++i) {
			_data[i] = other._data[i];
		}
	}
	return *this;
}

void VectorStack::push(const ValueType& value) 
{
	if (_size >= _capacity) 
	{
		resize(_capacity == 0 ? 8 : _capacity * 2);
	}
	_data[_size++] = value;
}

void VectorStack::pop() 
{
	if (isEmpty()) 
	{
		throw std::out_of_range("Cannot pop from empty stack");
	}
	_size--;
    
	if (_size > 0 && _size < _capacity / 4) {
		resize(_capacity / 2);
	}
}

const ValueType& VectorStack::top() const 
{
	if (isEmpty()) 
	{
		throw std::out_of_range("Stack is empty");
	}
	return _data[_size - 1];
}

bool VectorStack::isEmpty() const 
{
	return _size == 0;
}

size_t VectorStack::size() const 
{
	return _size;
}

void VectorStack::resize(size_t newCapacity) 
{
	if (newCapacity < _size) 
	{
		newCapacity = _size;
	}
	
	ValueType* newData = new ValueType[newCapacity];
	
	for (size_t i = 0; i < _size; ++i) 
	{
		newData[i] = _data[i];
	}
    
	delete[] _data;
	_data = newData;
	_capacity = newCapacity;
}
