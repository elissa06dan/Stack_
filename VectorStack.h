#pragma once
#include "StackImplementation.h"

class VectorStack : public IStackImplementation 
{
	public:
		VectorStack();
		~VectorStack() override;
		VectorStack(const VectorStack& other);
		VectorStack& operator=(const VectorStack& other);
		
		void push(const ValueType& value) override;
		void pop() override;
		const ValueType& top() const override;
		bool isEmpty() const override;
		size_t size() const override;
    
	private:
		ValueType* _data;        
		size_t _capacity;
		size_t _size;            
		
		void resize(size_t newCapacity); 
}; 
