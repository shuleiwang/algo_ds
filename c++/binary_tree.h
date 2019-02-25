/******************************************************************************/
//@File      binary_tree.h
//@Brief     Binary tree implemention
//@Author    Shulei Wang, shulwang2g@gmail.com
//@License   The code is free for all purposes without any express guarantee 
//@*******   it works.(Public Domain)
/******************************************************************************/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H 

template <typename Type> class BinaryTree;

template <typename Type>
class Node
{
    friend class BinaryTree<Type>;
public:
    Node(): left_(0), right_(0) {} 
    Node(const Type &element, 
            const Node<Type> *left = 0, 
            const Node<Type> *right = 0): element_(element), 
            left_(left), right_(right) {}

private:
    Type element_;
    Node *left_;
    Node *right_;
};

template <typename Type>
class BinaryTree 
{
public:
    BinaryTree();
    BinaryTree(const BinaryTree &src);
    BinaryTree& operator=(const BinaryTree &src);
    ~BinaryTree();

public:
    Type* Search(Node<Type>* p, const Type &element) const;
    void Insert(const Type &element);

    void BreadthFirst(void);

private:
    Node<Type> *root_;
};

#endif /* BINARY_TREE_H */

