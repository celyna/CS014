#ifndef _STACK_H_
#define _STACK_H_
#define MAX_SIZE 20
// #include <iostream>
// #include <stdexcept>

using namespace std;

template<typename T>
class stack 
{
private:
	T data[MAX_SIZE];
	int size;
public:
	stack() 
	{
		size = 0;
	};
	void push(T val)
	{
		if(size == MAX_SIZE)  
		{
			throw overflow_error("Called push on full stack.");
		}
		data[size++] = val;
	};

	void pop() 
	{
		// T value;
		if(size > 0) 
		{
			--size;
		}
		else 
		{
			throw underflow_error("Called pop on empty stack.");
		}
		return;
	};

	T top() 
	{
		T value;
		if(size > 0)
		{
			value = data[size-1];
		}
		else 
		{
			throw underflow_error("Called top on empty stack.");
		}
		return value;
	};

	bool empty() {
		if(size == 0) 
		{
			return true;
		}
		return false;
	};
};

#endif
