/******************************************************************************/
//@File      binary_tree.cc
//@Brief     Binary tree implemention
//@Author    Shulei Wang, shulwang2g@gmail.com
//@License   The code is free for all purposes without any express guarantee 
//@*******   it works.(Public Domain)
/******************************************************************************/

#include "binary_tree.h" 

template <typename Type> Type*
BinaryTree<Type>::Search(Node<Type> *p, const Type &element) const
{
    while (p != 0) 
    {
        if (element < p->element_) 
            p = p->left_;
        else if (element > p->element_)
            p = p->right_;
        else 
            return &p->element_;
    }

    return 0;
}

template <typename Type> 
void BinaryTree<Type>::Insert(const Type &element)
{
    Node<Type> *p = root_; 
    Node<Type> *prev = 0; 

    if (root_ == 0) {
        root_ = new Node<Type>(element);
        return;
    }

    while (p != 0)
    {
        prev = p;
        if (element < p->element_)
            p = p->left_;
        else
            p = p->right_;
    }

    if (element < prev->element_)
        prev->left_ = new Node<Type>(element);
    else
        prev->right_ = new Node<Type>(element);
}

template <typename Type>
void BinaryTree<Type>::BreadthFirst(void)
{

}

