/*Stack.cpp file for project3

Dan Otieno - Fall 2020.*/

#include <iostream>
#include <new>
#include "stack.h"


  Stack::Stack(int n) 
  {
  	/*dynamically allocates an empty stack array.*/
  	
  	num = n;
    array = new int [n];
	top = -1;
  }                         

  Stack::~Stack() 
  {
  	/*deallocates all dynamically-allocated memory
	associated with the object.*/
	
  	delete [] array;	
  }
  
  void Stack::Resize(int n)
  {	
    /*Function attempts to resize array by doubling
    its capacity.Then moves content from old to new array and deletes
	old array to free up memory.*/
	
	int* temparray = new int[2*num];
	
	if(!temparray)
	{
	  throw StackFull();
	}
	
	else
	{
	  for(int i=0; i<num; i++)
	  {
	  temparray[i] = array[i];
	  }
	
	  temparray[num] = n;
	
	  top = num;
	
	  num = 2*num;  
	  
	  delete [] array;
	
	  array = temparray;
	}	
		
  }

  void Stack::Push(int n)
  {
  	/*Pushes integer n onto top of stack.*/
  	
  	if(IsFull())
  	{
  	  Resize(n); //Call Resize function.		
	}
	
	else
	{
	  top++;
  	  array[top] = n;
	}
  }     

  void Stack::Pop()
  {
  	/*Removes top integer from stack.
    If stack is empty,throws StackEmpty exception.*/
  	
  	if(IsEmpty())
  	{
  	  throw StackEmpty();	
	}
	else
	{
	  top --;
	}
  }

  bool Stack::IsEmpty() const
  {
  	// Returns true if stack is empty; false otherwise.
  	return (top == -1);
  }  
	
  bool Stack::IsFull() const
  {
  	// Returns true if stack is full; false otherwise
  	return (top == (num - 1));
  } 
	
  void Stack::MakeEmpty()
  {
  	/*Removes all items from stack leaving an empty,but usable stack 
	with capacity num. If stack is already empty, MakeEmpty() does nothing.*/
		
  	top = -1;
  } 
      
  int Stack::Top() const
  {
  	/*Returns value of top integer on stack without modifying the stack.
    If stack is empty, throws StackEmpty exception.*/
    
  	if(IsEmpty())
  	{
  	  throw StackEmpty();	
	}
	
	else
	{
	  return array[top];
	}
  }  

  int Stack::Size() const
  {
  	// Returns number of items on stack without modifying the stack.
  	return top + 1;
  }    

  int Stack::Max() const
  {
  	/* Returns value of largest integer on stack without modifying the stack.
    If stack is empty, throws StackEmpty.*/
    
  	if(IsEmpty())
  	{
  	  throw StackEmpty();	
	}
	
	else
	{
	  int max = 0, i;
	
	  for(i=0; i<Size(); i++)
	  {
	  	if(max < array[i])
	  	{
	  	  max = array[i];
		}
	  }
	  
	  return max;
	}
  } 

  int Stack::Min() const
  {
  	/*Returns value of smallest integer on stack without modifying the stack.
    If stack is empty, throws StackEmpty.*/
    
  	if(IsEmpty())
  	{
  	  throw StackEmpty();	
	}
	
	else
	{
	  int min = array[0], k;
	
	  for(k=0; k<Size(); k++)
	  {
	  	if(min > array[k])
	  	{
	  	  min = array[k];
		}
	  }
	  
	  return min;
	}
  } 

  int Stack::Peek(unsigned int n) const
  {
  	/*Returns stack value n levels down from top of stack.
	If position n does not exist, throws StackInvalidPeek.*/
	
  	if(top+1 <= n)
  	{
  	  throw StackInvalidPeek();
	}
	
	else
	{
	  return array[top-n];
	}
  } 
 	
  int Stack::Capacity() const
  {
  	// Returns total num of elements that maybe stored in stack array.
  	return num;
  }  

