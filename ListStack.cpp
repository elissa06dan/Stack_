#include "ListStack.h"
#include <stdexcept>

ListStack::ListStack() : _top(nullptr), _size(0) {}

ListStack::~ListStack() 
{
	while (_top != nullptr) 
	{
		Node* temp = _top;
		_top = _top->next;
		delete temp;
	}
}

ListStack::ListStack(const ListStack& other) : _top(nullptr), _size(0) 
{
	Node* current = other._top;
	Node* prevCopied = nullptr;
	while (current != nullptr) 
	{
		
		Node* newNode = new Node(current->data);
		
		if (prevCopied == nullptr) 
		{
			_top = newNode;	
		} 
		
		else 
		{
			prevCopied->next = newNode;
		}
		
		prevCopied = newNode;
		current = current->next;
		_size++;
    }
}

ListStack& ListStack::operator=(const ListStack& other) 
{
	if (this != &other) 
	{
		while (_top != nullptr) 
		{
			Node* temp = _top;
			_top = _top->next;
			delete temp;
		}
		_size = 0;
        
		Node* current = other._top;
		Node* prevCopied = nullptr;
		
		while (current != nullptr) 
		{	
			Node* newNode = new Node(current->data);
			
			if (prevCopied == nullptr) 
			{
				_top = newNode;
			} 
			
			else 
			{
				prevCopied->next = newNode;
			}
			
			prevCopied = newNode;
			current = current->next;
			_size++;
		}
	}
	return *this;
}

void ListStack::push(const ValueType& value) 
{
	_top = new Node(value, _top); 
	_size++;
}

void ListStack::pop() 
{
	if (isEmpty()) 
	{
		throw std::out_of_range("Cannot pop from empty stack");
	}
    
	Node* temp = _top;
	_top = _top->next;
	delete temp;
	_size--;
}

const ValueType& ListStack::top() const 
{
	if (isEmpty()) 
	{
		throw std::out_of_range("Stack is empty");
	}
	return _top->data;
}

bool ListStack::isEmpty() const 
{
	return _size == 0;
}

size_t ListStack::size() const 
{
	return _size;
}
