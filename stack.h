#pragma once
#ifndef STACK_H
#define STACK_H
#include"list.h"

// Stack ADT using linked list as primary data structure.
// 
template<typename Type>
class Stack {
public:

	Stack();

	// Basic stack operations
	void	push(Type item);
	void	pop();
	Type	peek() const;

	// Check to see if there is anything on the stack
	bool	isEmpty() const;

	// Use to see what is in the stack for debugging
	void	printStack() const;

private:
	List<Type> m_list;
};

// Stack Implementation
//
//  Since Stack is a template class, which is not an actual 
//  class yet, not until we actually instantiate the Stack, 
//  we need to keep the class implementation together with 
//  the definition.  There are ways to simulate having 
//  separate "implementation/definition" with templates, 
//  but they aren't necessary and can be confusing.
//

// 1. Stack() Default constrcutor:
//		Call the defualt constructor for its List.
//		Already implemented. Nothing to do here.
template<typename Type>
Stack<Type>::Stack() :m_list() {}

// 2. push():
//		Add item to the stack in a manor appropriate for
//		Stack behavoir.
//
template<typename Type>
void Stack<Type>::push(Type item) {

	m_list.addToRear(item);

}

// 3. pop():
//		Remove the item on the "top" of the stack.
//
template<typename Type>
void Stack<Type>::pop() {

	m_list.deleteRear();

}

// 4. isEmpty():
//		return true if there are no items in the stack
//		otherwise return false.
//
template<typename Type>
bool Stack<Type>::isEmpty() const {

	if (m_list.isEmpty())
		return true;
	else
		return false;
}

// 5. peek():
//		Look at the "top" of the stack without changing the
//		Stack itself.
//
template<typename Type>
Type Stack<Type>::peek() const {

	return m_list.getRear();

	Type dumbyVariableSoCodeCompiles_DontActuallyUseThis;
	return dumbyVariableSoCodeCompiles_DontActuallyUseThis;
}

// 6. printStack()
//		Print to console the elements of the stack.
//		Used for debugging.
//
template<typename Type>
void Stack<Type>::printStack() const {

	m_list.printItems();

}
#endif//STACK_H