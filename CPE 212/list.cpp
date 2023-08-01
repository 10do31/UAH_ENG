//list.cpp for project 4
//Dan Otieno.

#include <iostream>

#include <new>

#include "list.h"


  List::List()
  {
  	num = 0;
  	
  	head = NULL;
  }              
  // Description of List()
  // Constructor sets state of list to empty

  List::~List()
  {
  	Node* temp, *temp2;
  	
    temp = head;
    temp2 = NULL;
    
    while(temp != NULL)
	{
      temp2 = temp;
      temp = temp -> next;
      delete temp2; 
    }
    
    delete temp;
  } 
  // Description of ~List()             
  // Destructor must deallocate all list nodes


  /***** Transformer Methods *****/
  void List::Append(string newword)
  {
  	Node* temp = head;
  	
    Node* someNode = new Node;  
    
	someNode -> next = NULL;  
    
	someNode -> word = newword;
    
	if(head == NULL)
	{  
      head = someNode;
      num++;
        
      return;
    }
	  
    while (temp -> next != NULL)
	{  
      temp = temp -> next;
    }
    
    temp -> next = someNode;
    
    num++;	
  }                   
  // Description of Append(...)
  // Appends newword to the end of the current phrase 
  // Error Handling: If list is full, throw ListFull object.

  void List::InsertAt(int pos, string newword)
  {
  	Node* temp, *temp2;
    
    temp = head;
    temp2 = NULL;
    
    if(pos > num || pos < 0)
	{
      throw ListBadPosition();
    }
    
    
    else
	{
      for(int i=0;i<pos;i++)
	  {
        temp2 = temp;
        temp = temp -> next;
      }
      
      Node* someNode = new Node;
      someNode -> word = newword;
      someNode -> next = temp;
      
      if(temp2 == NULL)
	  { 
        head = someNode;
      }
      
      else
	  { 
        temp2 -> next = someNode;
      }
      
      num++;
    
    }
    
  }
  // Description of InsertAt(...)
  // Inserts newword at position pos.
  // Positions numbered starting with zero (0 <= pos <= num).
  // Hint: pos == num ==> append
  // Word previously at pos should now be at position pos+1
  // Error Handling: If list is full, throws ListFull object
  //                 If pos out of range, throws ListBadPosition object

  void List::Delete(string someword)
  {
  	Node* temp, *temp2;
	
	temp = head;
    temp2 = NULL;
    
    while(temp != NULL)
	{
      if(temp -> word == someword)
	  { 
        if(temp2 == NULL)
		{
          head = temp -> next;
                
        }
        else
		{
          temp2 -> next = temp -> next;
        }
        
        delete temp;
        num--;
        
        return;
      }
    
    temp2 = temp;
    temp = temp -> next;

    } 
    
    throw ListNotFound();
	
  }
  // Description of Delete(...)
  // Deletes the first instance of someword if it is present.  
  // Error Handling: If someword is not in list, throws ListNotFound object

  void List::Replace(string oldword, string newword)
  {
  	Node* temp;
	  
	temp = head;
	
  	
    while(temp != NULL)
	{
      if(temp -> word == oldword)
	  {
        temp -> word = newword;
        
        return;
      }
      
      temp = temp -> next;
    }
    
    throw ListNotFound();
  }
  // Description of Replace(...)
  // Replaces the first instance of oldword with newword.  
  // Error Handling: If oldword not found, throws ListNotFound object
  

  /***** Observer Methods *****/
  int List::Length() const
  {
  	return num;	 
  }
  // Description of Length()
  // Returns number of words in the list
  // Error Handling: none

  bool List::Find(string someword) const
  {
  	Node* temp;
  	
  	temp = head;
  	
  	while(temp != NULL)
	{
      if(temp -> word == someword)
	  {
        return true;
      }
      
      temp = temp -> next;
    }
    
    return false;
  }
  // Description of Find(...)
  // Returns true if someword is in list, false otherwise
  // Error Handling: none

