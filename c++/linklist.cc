/**************************************************************************/
//@file      link_list.cc
//@author    wangshul
//@version   0.0.0
//@date	     2017-04-09	
//@license
//@brief
//@attention
/**************************************************************************/

template <typename ElementType>
LinkList<ElementType>::LinkList(): head_(0), tail_(0) { }

template <typename ElementType>
template <typename Iterator>
LinkList<ElementType>::LinkList(Iterator begin, Iterator end):
        head_(0), tail_(0)
{   CopyElements(begin,end);   } 

template <typename ElementType>
LinkList<ElementType>::LinkList(
        const LinkList &kOldLinkList): head_(0), tail_(0) 
{   CopyElements(kOldLinkList);   } 

template <typename ElementType>
LinkList<ElementType>& LinkList<ElementType>::operator=(
        const LinkList &kRightLinkList)
{
    if (this != &kRightLinkList)
    { 
        Destroy();
        CopyElements(kRightLinkList);
    }
    return *this;
}

template <typename ElementType>
LinkList<ElementType>::~LinkList()
{   Destroy();   } 

template <typename ElementType>
void LinkList<ElementType>::PushFront(const ElementType &kNewElement)
{ 
    ListNode<ElementType>  *point_to_node(
            new ListNode<ElementType>(kNewElement));
    if (Empty())
        tail_ = head_ = point_to_node;
    else
    {
        point_to_node->next_ = head_;
        head_ = point_to_node;
    }
}
        
template <typename ElementType>
void LinkList<ElementType>::PushBack(const ElementType &kNewElement)
{ 
    ListNode<ElementType>  *point_to_node(
            new ListNode<ElementType>(kNewElement));
    if (Empty())
        tail_ = head_ = point_to_node;
    else
    {
        tail_->next_ = point_to_node;
        tail_ = point_to_node;
    }
}

template <typename ElementType>
void LinkList<ElementType>::Pop()
{ 
    ListNode<ElementType>  *point_to_node(head_);
    head_ = head_->next_;
    delete point_to_node;
} 

template <typename ElementType>
ElementType& LinkList<ElementType>::Front()
{   return head_->value_;   }

template <typename ElementType>
const ElementType& LinkList<ElementType>::Front() const
{   return head_->value_;   }

template <typename ElementType>
unsigned int LinkList<ElementType>::Size() const
{ 
    ListNode<ElementType>  *point_to_node(head_); 
    unsigned int node_number(0);
    while (point_to_node)
    {
        ++node_number;
        point_to_node = point_to_node->next_;
    }
    return node_number;
} 

template <typename ElementType>
bool LinkList<ElementType>::Empty() const
{   return head_ == 0;   }

template <typename ElementType>
template <typename Iterator> 
void LinkList<ElementType>::Assign(Iterator begin, Iterator end)
{ 
    Destroy();
    CopyElements(begin,end);
} 

template <typename ElementType>
void LinkList<ElementType>::CopyElements(const LinkList &kRightLinkList)
{ 
    ListNode<ElementType>  *point_to_node(kRightLinkList.head_);
    while (point_to_node)
    {
        PushBack(point_to_node->value_);
        point_to_node = point_to_node->next_;
    }
} 

template <typename ElementType>
void LinkList<ElementType>::Destroy()
{ 
    while (!Empty())
    {   Pop();   }
}      

template <typename ElementType>
template <typename Iterator>
void LinkList<ElementType>::CopyElements(Iterator begin, Iterator end)
{ 
    while (begin != end)
    {  
        PushBack(*begin); 
        ++begin;
    }
} 

template <typename ElementType>
ListNode<ElementType>* LinkList<ElementType>::Search(
                                   const ElementType &kFindedValue) const
{ 
    ListNode<ElementType>*  return_pointer(tail_);
    ListNode<ElementType>*  walk_pointer(head_);
    while (walk_pointer != 0)
    { 
        if (walk_pointer->value_ == kFindedValue) 
        {
            return_pointer = walk_pointer;
            break;
        }
        walk_pointer = walk_pointer->next_;
    } 
    return return_pointer;
} 

template <typename ElementType>
void LinkList<ElementType>::Insert(const ElementType &kGivenEle, 
                                   const ElementType &kNode)
{
    ListNode<ElementType>*  pointer1(new ListNode<ElementType>(kNode));
    ListNode<ElementType>*  pointer2(Search(kGivenEle));
    pointer1->next_ = pointer2->next_;
    pointer2->next_ = pointer1;
}

