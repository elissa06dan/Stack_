#pragma once
#include "StackImplementation.h"

class ListStack : public IStackImplementation 
{
	private:
		struct Node 
		{
			ValueType data;
			Node* next;
			
			Node(const ValueType& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
		};
		
		Node* _top;     
		size_t _size;   

	public:
		ListStack();
		ListStack(const ListStack&);
		ListStack& operator=(const ListStack&);
		~ListStack() override;
    		
		void push(const ValueType& value) override;
		void pop() override;
		const ValueType& top() const override;
		bool isEmpty() const override;
		size_t size() const override;
    
};
