#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>
#include <iostream>



template <class Key>
struct GenericAvlNode
{
    typedef GenericAvlNode *Node;
    Key key;
    GenericAvlNode *left_son;
    GenericAvlNode *right_son;
    GenericAvlNode *parent;
    int height;
    int subTree_size;
    const int returnBlanceFactor() const { return (getHeight(left_son) - getHeight(right_son)); }
    GenericAvlNode(const Key &key, GenericAvlNode *parent = nullptr) 
                    : key(key), left_son(nullptr), right_son(nullptr), parent(parent), height(0),subTree_size(1){};
    GenericAvlNode(const GenericAvlNode &node) = default;
    virtual ~GenericAvlNode() = default;

    GenericAvlNode &operator=(const GenericAvlNode &node) = default;

    //=======================================================================
    // Getters & Setters.
    //=======================================================================
    void calculateHeight()
    {
        const int left_height = getHeight(left_son);
        const int right_height = getHeight(right_son);
        height = (left_height > right_height ? left_height : right_height) + 1;
    }
    void calculateSize()
    {
        const int left_size = left_son->getSize();
        const int right_size = right_son->getSize();
        subTree_size = left_size + right_size + 1;
    }
    static const int getHeight(const Node node) { return (!node) ? -1 : node->height; }
    const int getSize() { return (this == nullptr) ? 0 : subTree_size; }
    /// we assumed T has assign operator
    static void swapData(Node &node_a, Node &node_b)
    {
        const Key temp_key = node_a->key;
        node_a->key = node_b->key;

        node_b->key = temp_key;
    }
};
template <class Key>
std::ostream &operator<<(std::ostream &os, const GenericAvlNode<Key> &node)
{

    os << "(" << node.key << ")" << node.subTree_size;

    return os;
}


template <class Key>
class AVLtree
{
    typedef GenericAvlNode<Key>* Node;

private:
    Node root;
    
    void rotateRight(Node root);
    void rotateLeft(Node root);
    void rotate(Node root,Node new_root,Node* new_root_son,Node* root_son);
    Node get_next_in_order(Node root) const;
    void fixAscendRoute(Node iterator, const bool is_insert = true);


    template <class ApplyFunctor>
    void searchInOrder(const Node root, ApplyFunctor functor);

    template <class ApplyFunctor>
    void searchPreOrder(const Node root, ApplyFunctor functor);

    template <class ApplyFunctor>
    void searchPostOrder(Node root, ApplyFunctor functor);

    // Functors to apply on trees on a given order


    class Delete
    {
    public:
        void operator()(const Node node)
        {
            delete (node);
        }
    };

    class Print
    {
    public:
        void operator()(const Node node)
        {
            std::cout << node->key;
        }
    };


public:
    unsigned int num_of_nodes;
        AVLtree() : root(nullptr) , num_of_nodes(0){};
    ~AVLtree() { searchPostOrder(Delete()); }

    template <class ApplyFunctor = Print>
    void searchInOrder(ApplyFunctor functor = Print());

    template <class ApplyFunctor = Print>
    void searchPreOrder(ApplyFunctor functor = Print());

    template <class ApplyFunctor = Print>
    void searchPostOrder(ApplyFunctor functor = Print());

    Node find(const Key &key) const;

    void insert(const Key &new_key); // Not const, might change root
    void remove(const Key &key);
    Node getRoot() const { return root; };
};
template <class Key>
void AVLtree<Key>::rotate(Node root,Node new_root,Node* new_root_son,Node* root_son)
{
    //Node new_root = root->left_son; // A
    Node orig_parent = root->parent;

    (*(root_son)) = *new_root_son; // set B
    if (*new_root_son)
    {
        (*new_root_son)->parent = root;
    }
    root->calculateSize();
    root->calculateHeight(); // Update height and size of B
    root->parent = new_root;
    *new_root_son = root;
    new_root->calculateSize();
    new_root->calculateHeight();

    if (!orig_parent)
    {
        this->root = new_root;
    }
    else
    {
        Node* to_change = &(orig_parent->right_son == root ? orig_parent->right_son : orig_parent->left_son );
        (*to_change) = new_root;
    }
    new_root->parent = orig_parent;

}

    template <class Key>
void AVLtree<Key>::rotateRight(Node root)
{
    Node new_root = root->left_son;
    rotate(root,new_root,&(new_root->right_son),&(root->left_son));
    
}
    template <class Key>
void AVLtree<Key>::rotateLeft(Node root)
{
        Node new_root = root->right_son;
    rotate(root,new_root,&(new_root->left_son),&(root->right_son));
    
    
}

    template <class Key>
void AVLtree<Key>::remove(const Key &key)
{
    Node to_remove = find(key);
    if (!to_remove)
    {
        throw nodeNotExists();
    }

    if (to_remove->left_son && to_remove->right_son)
    {
        Node next_node = get_next_in_order(to_remove);
        GenericAvlNode<Key>::swapData(to_remove, next_node); 
        to_remove = next_node;
    }
    Node parent = to_remove->parent;
    bool is_root = (parent == nullptr);
    Node* parent_son_to_change_ptr = is_root ? nullptr :
                    &(parent->left_son == to_remove ? parent->left_son :parent->right_son );
    
    
    if (!to_remove->left_son && !to_remove->right_son)
    {
        // to_remove is leaf
        if (is_root)
        {
            this->root = nullptr;
        }
        else
        {
            (*parent_son_to_change_ptr)=nullptr;     
        }
        
        
    }
    else
    {
        // to_remove has exaclty one son
        Node *sole_son_ptr = &(to_remove->right_son ? to_remove->right_son : to_remove->left_son); // Default value, so if root is empty - set it
        if (is_root)
        {
            this->root = *sole_son_ptr;
        }
        else 
        {
            (*parent_son_to_change_ptr) = *sole_son_ptr;
        }
            
        (*(sole_son_ptr))->parent = parent;
    }
    delete to_remove;
    num_of_nodes--;
    // Update heights of parents

    Node ascending_iterator = parent;
    while (ascending_iterator != nullptr)
    {
        ascending_iterator->calculateSize();
        ascending_iterator->calculateHeight();
        ascending_iterator = ascending_iterator->parent;
    }
    fixAscendRoute(parent, false);
}
    template <class Key>
void AVLtree<Key>::insert(const Key &new_key)
{

    if (find(new_key) != nullptr)
    { // can't add the node, it exists
        throw nodeExists();
    }

    Node iterator = this->root;         // we know that this node can be added
    Node *new_node_ptr = &(this->root); // Default value, so if root is empty - set it
    Node parent_node = nullptr;         // If root doesn't exist, parent will be null

    // Find the correct node to insert the son to
    while (iterator)
    {
        parent_node = iterator;
        iterator->subTree_size +=1;
        if (iterator->key < new_key)
        {
            new_node_ptr = &(iterator->right_son);
            iterator = iterator->right_son;
        }
        else if (iterator->key > new_key)
        {
            new_node_ptr = &(iterator->left_son);
            iterator = iterator->left_son;
        }
    }

    try
    {
            *new_node_ptr = new GenericAvlNode<Key>(new_key, parent_node);
    }
    catch(const std::bad_alloc &e)
    {
        while (parent_node)
        {
                parent_node->subTree_size -=1;
            parent_node = parent_node->parent;
        }
        
        throw e;
    }

    // Assumes there is a < operator in T type
    num_of_nodes++;
    fixAscendRoute(parent_node);
}
    template <class Key>
void AVLtree<Key>::fixAscendRoute(Node iterator, const bool is_insert)
{
    bool fixed_once = false;
    while (iterator && (!is_insert || !fixed_once))
    {
        iterator->calculateHeight();
        int balanceFactor = iterator->returnBlanceFactor();

        if (balanceFactor > 1) // left son carry
        {
            fixed_once = true;
            if (iterator->left_son->returnBlanceFactor() < 0)
            {
                rotateLeft(iterator->left_son); // this is LR
            }
            rotateRight(iterator);
        }
        else if (balanceFactor < -1) // right son carry
        {
            fixed_once = true;
            if (iterator->right_son->returnBlanceFactor() > 0)
            {
                rotateRight(iterator->right_son); // this is RL
            }
            rotateLeft(iterator);
        }
        iterator = iterator->parent;
    }
}

    template <class Key>
GenericAvlNode<Key> *AVLtree<Key>::find(const Key &key) const
{
    Node iterator = this->root;
    while (iterator != nullptr && iterator->key != key)
    {
        iterator = iterator->key < key ? iterator->right_son : iterator->left_son;
    }
    return iterator;
}
    template <class Key>
GenericAvlNode<Key> *AVLtree<Key>::get_next_in_order(Node root) const
{
    Node iterator = root->right_son;
    while (iterator->left_son)
    {
        iterator = iterator->left_son;
    }
    return iterator;
}
    
template <class Key>
template <class ApplyFunctor>
void AVLtree<Key>::searchInOrder(ApplyFunctor functor)
{
    searchInOrder(this->root, functor);
}
    template <class Key>
template <class ApplyFunctor>
void AVLtree<Key>::searchPostOrder(ApplyFunctor functor)
{
    searchPostOrder(this->root, functor);
}
    template <class Key>
template <class ApplyFunctor>
void AVLtree<Key>::searchPreOrder(ApplyFunctor functor)
{
    searchPreOrder(this->root, functor);
}
    template <class Key>
template <class ApplyFunctor>
void AVLtree<Key>::searchInOrder(const Node root, ApplyFunctor functor)
{
    if (!root)
    {
        return;
    }
    searchInOrder(root->left_son, functor);
    functor(root);
    searchInOrder(root->right_son, functor);
}
    template <class Key>
template <class ApplyFunctor>
void AVLtree<Key>::searchPreOrder(const Node root, ApplyFunctor functor)
{
    if (!root)
    {
        return;
    }
    functor(root);
    searchPreOrder(root->left_son, functor);
    searchPreOrder(root->right_son, functor);
}

    template <class Key>
template <class ApplyFunctor>
void AVLtree<Key>::searchPostOrder(Node root, ApplyFunctor functor)
{
    if (!root)
    {
        return;
    }
    searchPostOrder(root->left_son, functor);
    searchPostOrder(root->right_son, functor);
    functor(root);
}


#endif //AVL_TREE_H