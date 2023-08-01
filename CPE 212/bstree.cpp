//bstree.cpp
//Dan Otieno


#include <iostream>

#include <new>

#include "bstree.h"


  template <typename SomeType>
  void BSTree<SomeType>::Delete(BSTreeNode<SomeType>*& treePtr, SomeType& item)
  {
  	if (item < treePtr->data)
    Delete(treePtr->leftPtr, item);
  
    else if (item > treePtr->data)
    Delete(treePtr->rightPtr, item);
  
    else
    DeleteNode(treePtr);
  }
  // Delete()
  // Recursive function that traverses the tree starting at treePtr to locate the data value to be removed
  // Once located, DeleteNode is invoked to remove the value from the tree
  // If tree is not empty and item is NOT present, throw NotFoundBSTree	
	
  template <typename SomeType>
  void BSTree<SomeType>::DeleteNode(BSTreeNode<SomeType>*& treePtr)
  {
  	if (treePtr->rightPtr == NULL && treePtr->leftPtr == NULL) 
    {
      delete treePtr;
      treePtr = NULL;
    } 
    else if (treePtr->leftPtr == NULL) 
    {
      BSTreeNode<SomeType> *tempPtr = treePtr;
      treePtr = treePtr->rightPtr;
      delete tempPtr;
    } 
  
    else if (treePtr->rightPtr == NULL) 
    {
      BSTreeNode<SomeType> *tempPtr = treePtr;
      treePtr = treePtr->leftPtr;
      delete tempPtr;
    } 
  
    else 
    {
      SomeType somedata = GetPredecessor(treePtr->leftPtr);
      
      treePtr->data = somedata;
      
      Delete(treePtr->leftPtr, somedata); // Delete predecessor node.
    }

  }
  // DeleteNode()
  // Removes the node pointed to by treePtr from the tree
  // Hint:  calls GetPredecessor and Delete

  template <typename SomeType>
  void BSTree<SomeType>::Insert(BSTreeNode<SomeType>*& ptr, SomeType item)
  {
  	if (ptr == NULL)
    {   // Insertion place found.
      ptr = new BSTreeNode<SomeType>;
      
      ptr->rightPtr = NULL;
      ptr->leftPtr = NULL;
      ptr->data = item;
    }
    else if (item < ptr->data)
    {
      Insert(ptr->leftPtr, item); // Insert in leftPtr subtree.
	}
	
    else if (item > ptr->data)
    {
      Insert(ptr->rightPtr, item);   // Insert in rightPtr subtree.
	} 
	
	else 
    {
      throw FoundInBSTree();
    }  
  }
  // Insert()
  // Recursive function that finds the correct position of item and adds it to the tree
  // Throws FoundInBSTree if item is already in the tree	

  template <typename SomeType>
  void BSTree<SomeType>::Destroy(BSTreeNode<SomeType>*& ptr)
  {
  	if(ptr != NULL)
  	{
  	  Destroy(ptr -> leftPtr);
  	  Destroy(ptr -> rightPtr);
  	  
  	  DeleteNode(ptr);
	}
  }
  // Destroy()
  // Recursively deallocates every node in the tree pointed to by ptr

  template <typename SomeType>
  void BSTree<SomeType>::CopyTree(BSTreeNode<SomeType>*& copy, const BSTreeNode<SomeType>* originalTree)
  {
  	if (originalTree == NULL)
  	{
  	  copy = NULL;
	}
	
    else
    {
      copy = new BSTreeNode<SomeType>;
      
      copy -> data = originalTree -> data;
      
      copy -> leftPtr = originalTree -> leftPtr;
      copy -> rightPtr = originalTree -> rightPtr;
      
      CopyTree(copy->leftPtr, originalTree->leftPtr);
      CopyTree(copy->rightPtr, originalTree->rightPtr);
    }

  }
  // CopyTree()
  // Recursively copies all data from original tree into copy
	
  template <typename SomeType>
  SomeType BSTree<SomeType>::GetPredecessor(BSTreeNode<SomeType>* treePtr) const
  {
  	BSTreeNode<SomeType>* tempPtr;
  	
  	tempPtr = treePtr;
	
	while(tempPtr -> rightPtr != NULL)
  	{
  	  tempPtr = tempPtr -> rightPtr;
	}
	
	return tempPtr -> data;
  }
  // GetPredecessor()
  // Finds the largest data value in the tree pointed to by treePtr and returns that data value
  // as the functions return value
	
  template <typename SomeType>
  int BSTree<SomeType>::CountNodes(BSTreeNode<SomeType>* treePtr) const
  {
  	if (treePtr->rightPtr == NULL && treePtr->leftPtr == NULL)
  	{
  	  return 1;
	}
    
    else if (treePtr->leftPtr == NULL)
    {
      return 1 + CountNodes(treePtr->rightPtr);
	}
    
    else if (treePtr->rightPtr == NULL)
    {
      return 1 + CountNodes(treePtr->leftPtr);
	}
    
	else
	{
	  return 1 + CountNodes(treePtr->leftPtr) + CountNodes(treePtr->rightPtr);
	}
  }
  // CountNodes()
  // Recursive function that counts every node in the tree pointed to by treePtr and returns the
  // count as the function return value
	
  template <typename SomeType>
  int BSTree<SomeType>::LevelCount(BSTreeNode<SomeType>* treePtr) const
  {
  	if (treePtr->rightPtr == NULL && treePtr->leftPtr == NULL)
  	{
  	  return 1;
	}

    else if (treePtr->rightPtr == NULL)
    {
      return 1 + LevelCount(treePtr->leftPtr);
	}
    
    if (treePtr->leftPtr == NULL)
    {
      return 1 + LevelCount(treePtr->rightPtr);
	}
    
    else
    {
      return 1 + max(LevelCount(treePtr->leftPtr), LevelCount(treePtr->rightPtr));
	}		
  }
  // LevelCount()
  // Recursive function that traverses the entire tree to determine the total number of levels in the tree

  template <typename SomeType>
  int BSTree<SomeType>::FindLevel(BSTreeNode<SomeType>* treePtr, SomeType item) const
  {
  	if (treePtr == NULL)
  	{
      throw NotFoundBSTree();
	}
   
    else if (treePtr->data == item)
    {
      return 0;
	}
    
    else if(treePtr->data < item)
    {
      return 1 + FindLevel(treePtr->rightPtr, item);
	}
    
    else
    {
       return 1 + FindLevel(treePtr->leftPtr, item);
	}
   	
  }
  // FindLevel()
  // Recursive function that traverses the tree looking for item and returns the level where
  // item was found


  /**************  End of Private Helper Functions You Must Implement ****************/
  

  /**************  Start of Public Interface Functions You Must Implement ****************/
	
  template <typename SomeType>
  BSTree<SomeType>::BSTree()
  {
  	rootPtr = NULL;
  }								
  // BSTree()
  // Default constructor initializes rootPtr pointer to NULL
  
  template <typename SomeType>	
  BSTree<SomeType>::BSTree(const BSTree<SomeType>& someTree)
  {
  	CopyTree(rootPtr, someTree.rootPtr);
  }
  // BSTree() 
  // Copy constructor for BSTree
  // Hint:  calls CopyTree
	
  template <typename SomeType>
  void BSTree<SomeType>::operator=(const BSTree<SomeType>& originalTree)
  {
  	if(&originalTree == this)
  	{
  	  return;
  	  
  	  Destroy(rootPtr);
	  CopyTree(rootPtr, originalTree.rootPtr);
	}
  }
  // operator=() 
  // Overloaded assignment operator for BSTree.
  // Hint:  calls CopyTree
  
  template <typename SomeType>
  BSTree<SomeType>::~BSTree()
  {
  	if(!IsEmpty())
	Destroy(rootPtr);
  }							
  // ~BSTree()
  // Destructor deallocates all tree nodes
  // Hint:  calls the private helper function Destroy
  
  template <typename SomeType>
  void BSTree<SomeType>::InsertItem(SomeType item)
  {
  	if(IsFull())
    throw FullBSTree();
    
    
    else
	Insert(rootPtr, item);
  }		
  // InsertItem()
  // Inserts item into BSTree;  if tree already full, throws FullBSTree exception
  // If item is already in BSTree, throw FoundInBSTree exception
  // Hint:  calls the private helper function Insert
  
  template <typename SomeType>
  SomeType BSTree<SomeType>::DeleteItem(SomeType item)
  {
  	BSTreeNode<SomeType>* treePtr;
	  
	if(IsEmpty())
    throw EmptyBSTree();
    
    else if(treePtr == NULL && !IsEmpty())
	throw NotFoundBSTree();

    else
	{
	  SomeType tempitem = item;

      Delete(rootPtr, item);

      return tempitem;
	}
  }		
  // DeleteItem()
  // Deletes item from BSTree if item is present AND returns object via function return value
  // If tree is empty, throw the EmptyBSTree exception
  // If tree is not empty and item is NOT present, throw NotFoundBSTree
  // Hint:  calls the private helper function Delete
  
  template <typename SomeType>
  void BSTree<SomeType>::MakeEmpty()
  {
  	if (!IsEmpty())
    Destroy(rootPtr);
  }						
  // MakeEmpty()
  // Deallocates all BSTree nodes and sets rootPtr pointer to NULL
  // Hint:  calls the private helper function Destroy
  
  template <typename SomeType>
  int BSTree<SomeType>::Size() const
  {
  	if(rootPtr==NULL)
  	return 0;
  	
  	else
  	return CountNodes(rootPtr);
  	
  }	
  // Size()
  // Returns total number of data values stored in tree
  
  template <typename SomeType>
  bool BSTree<SomeType>::IsFull() const
  {
  	BSTreeNode<SomeType>* location;
  	
  	try
  	{
  	  location = new BSTreeNode<SomeType>;
  	  
  	  delete location;
  	  
  	  return false;
	}
	
	catch(std::bad_alloc exception)
	{
	  return true;
	}
  }					
  // IsFull()
  // Returns true if BSTree is full; returns false otherwise
  
  template <typename SomeType>
  bool BSTree<SomeType>::IsEmpty() const
  {
  	return rootPtr == NULL;
  }					
  // IsEmpty()
  // Returns true if BSTree is empty; returns false otherwise
  	
  template <typename SomeType>
  SomeType BSTree<SomeType>::Min() const
  {
  	
	if (IsEmpty())
    throw EmptyBSTree();

    BSTreeNode<SomeType>* tempPtr = rootPtr;

    while (tempPtr->leftPtr != NULL)
    tempPtr = tempPtr->leftPtr;

    return tempPtr->data;
	
  }                 
  // Min()
  // Returns minimum value in tree; throws EmptyBSTree if tree is empty
	
  template <typename SomeType>
  SomeType BSTree<SomeType>::Max() const
  {
  	if (IsEmpty())
    throw EmptyBSTree();

    BSTreeNode<SomeType>* tempPtr = rootPtr;

    while (tempPtr->rightPtr != NULL)
    tempPtr = tempPtr->rightPtr;

    return tempPtr->data;
  }                 
  // Max()
  // Returns maximum value in tree; throws EmptyBSTree if tree is empty
  
  
  template <typename SomeType>	
  int BSTree<SomeType>::TotalLevels() const
  {
    BSTreeNode<SomeType>* treePtr;
	
	if(IsEmpty())
    {
      throw EmptyBSTree();
	}
    else
    {
      return LevelCount(rootPtr);
	}
  }              
  // TotalLevels()
  // Returns the maximum level value for current tree contents
  // Levels are numbered 0, 1, ..., N-1.  This function returns N
  // Throws EmptyBSTree if empty
  // Hint:  calls the private helper function LevelCount
  
  template <typename SomeType>
  int BSTree<SomeType>::Level(SomeType item) const
  {  
	BSTreeNode<SomeType>* treePtr;
	
	if(IsEmpty())
  	{
  	  throw EmptyBSTree(); 
	}
	
	else if(treePtr == NULL && !IsEmpty())
	{
	  throw NotFoundBSTree();
	}
	
	else
	{
	  return FindLevel(rootPtr, item);
	}  	    
  }       
  // Level()
  // Returns the level within the BSTree at which the value item is found
  // If tree is empty, throws EmptyBSTree
  // If tree is not empty and item is not found, throws NotFoundBSTree
  // Hint:  calls the private helper funtion FindLevel
