/**************************************************************************/
//@file      link_list.h
//@author    wangshul
//@version   0.0.0
//@date	     2017-04-09	
//@license
//@brief
//@attention
/**************************************************************************/

#ifndef LINKLIST_H
#define LINKLIST_H

template <typename ElementType> class LinkList;

template <typename Element>
class ListNode
{
     friend class LinkList<Element>;
 private:
     ListNode(const Element &kValue):value_(kValue), next_(0) { } 
     Element  value_; //Node data
     ListNode  *next_; //Point to next node
};

template <typename ElementType>
class LinkList
{
 public:
     //@brief  Constructs an empty LinkList
     LinkList();

     //@brief  Initialize this LinkList with
     //******  a pair of iterator-marked sequences
     template <typename Iterator>
     LinkList(Iterator begin, Iterator end);

     //Copy control : copy constructor, assignment, destructor
     LinkList(const LinkList &kOldLinkList);
     LinkList& operator=(const LinkList &kRightLinkList);
     ~LinkList(); 

     //@brief  Adds a node to before the first node of the LinkList
     void PushFront(const ElementType &kNewElement);

     //@brief  Adds a node to after the last node of the LinkList
     void PushBack(const ElementType &kNewElement);

     //@brief  Insert a new node to after a given value
     void Insert(const ElementType &kGivenEle, const ElementType &kNode);

     //@brief  Delets a node from the head of the LinkList  
     void Pop();

     //@brief  Gets the element value_ of the first node
     ElementType& Front();
     const ElementType& Front() const;

     //@brief  Walks LinkList and return a pionter points to given node
     ListNode<ElementType>* Search(const ElementType &kFindedValue) const;

     //@brief  Determines if the LinkList is empty
     bool Empty() const;

     //@brief  Gets the number of node in the LinkList
     unsigned int Size() const;

     //@brief  Assign a LinkList to a sequence of elements that
     //******  are tagged with a pair of iterators
     template <typename Iterator>
     void Assign(Iterator begin, Iterator end);
 private:
     //Used by copy constructor, assignment, and destructor
     //@brief  Copys elements from right LinkList 
     void CopyElements(const LinkList &kRightLinkList);

     //@brief  Deletes the memory by the LinkList
     void Destroy();

     //@brief  Copys elements from a pair of iterators
     template <typename Iterator>
     void CopyElements(Iterator begin, Iterator end);

     ListNode<ElementType>  *head_; //Point to the first node in
                                    //the LinkList
     ListNode<ElementType>  *tail_; //Point to the last node in the LinkList
};

#include "linklist.cc" 

#endif



