#ifndef AVL_H_
#define AVL_H_

#include <ctime>
#include <iomanip>
#include <iostream>

// commit

template<typename T>
class AVLTree
{
public:
    class Node
    {
		public:
        //data, templated
        T data;
        Node *right_child;
        Node *left_child;
        Node *parent;
		//height from bottom of tree
        int height;
		// the size of the node's subtree, node included
		int subtree_size;

    	//default constructor
    	//Node();
		// Constructor initializing the data.
		Node(T t);
		//destructor
		virtual ~Node(); //not sure why this ruins things
		// Calculate the balance point.
		int getBalance();
		// Get the actual data.
		T getData();
		// Get the height.
		int getHeight();
		// Get the left subtree.
		Node *getLeftChild();
		// Get the node's parent.
		Node *getParent();
		// Get the right subtree.
		Node *getRightChild();
		// Remove the node's parent.
		void removeParent();
		// Set the left subtree.
		Node *setLeftChild(Node *newLeft);
		// Set the right subtree.
		Node *setRightChild(Node *newRight);
		// Set the node's height.
		int updateHeight();
		// increases node's subtree_size by 1
		void updateInsertSize();
		// decreases node's subtree_size by 1
		void updateRemoveSize();
		// updates node's subtree_size after rotation
		void updateRotationSize();

		// turns AVLTree to sorted array
		void AVLToArr(T arr[], int* index);

		// turns AVLTree to ranks tree (setting each node's subtree_size)
		void AVLToRank();	
		
		// returns the subtree_size of a node
		int getSubtreeSize();

		// returns the node with the given rank
		Node* select(int rank);
	};
public:
	//a pointer to the root
  	Node *root;
 	//a pointer to the node with the lowest value
  	Node* lowest;
  	//a pointer to the node with the highest value
  	Node* highest;

  	//default constructor for empty tree
  	AVLTree();
  	//parametrized constructor with one value t 
  	AVLTree(T t);
  	//destructot
  	~AVLTree();
  	//get height
  	int getHeight();
  	//std::exception insert(const T& t);
  	bool insert(const T& t);
  	//returns lowest value
  	T getLowestValue();
  	//returns highest value
  	T getHighestValue();
	// return pointer to node with lowest value
	// T getLowest();
  	//returns pointer to node with highest value
  	AVLTree<T>::Node* getHighest();
  	//std::exception remove(const T& t);
  	bool remove(const T& t);
	// returns a pointer to highest node
  	void print();
	//turns sorted array of <T> elements to a Nodes Tree
	static AVLTree<T>::Node* arrToNodesTree(T arr[], int start, int end);
	//setting the node's height
	static int setNodesHeight(AVLTree<T>::Node* node);
	//setting the node's parent
	static void setNodesParent(AVLTree<T>::Node* node);
	//setting the linked-node's Highest node
	void setHighestNode(AVLTree<T>::Node* node);
	//setting the linked-node's Lowest node
	void setLowestNode(AVLTree<T>::Node* node);
	//setting the linked-node's Root	 
	void setNodesRoot(AVLTree<T>::Node* node);
	//turns sorted array of <T> elements to an AVLTree
	static AVLTree<T>* arrToAVLTree(T arr[], int start, int end);
	static AVLTree<T>* mergeAVLTrees(AVLTree<T>* tree_1, AVLTree<T>* tree_2);

public:
  	// Balance the tree
	void balanceAtNode(Node *n);
	// returns a pointe to node containing the data.
	// nullptr if not in tree
	Node *findNode(const T& t);
	// Rotate the subtree left.
	void rotateLeft(Node *n);
	// Rotate the subtree right.
	void rotateRight(Node *n);
	// Set the root.
	void setRoot(Node *n);
	void printSubtree(Node *subtree, int depth,int offset, bool first);
	int spacing(int offset);
};


// paramterized Constructor.
template<typename T>
AVLTree<T>::Node::Node(T val) {
  data = val;
  height = 0;
  subtree_size = 1;
  parent = nullptr;
  left_child = nullptr;
  right_child = nullptr;
}

// paramterized dtor.
template<typename T>
AVLTree<T>::Node::~Node() {
//   std::cout << "node destroyed" << data << std::endl;
}


// Calculate the balance factoP: left.height-r.height
template<typename T>
int AVLTree<T>::Node::getBalance() {
  // If we don't have a left subtree, check the right.
  int result;
  if (left_child == nullptr){
	// If neither subtree exists, return zero.
	if (right_child == nullptr){
		result = 0;
	}
	// Otherwise, the right subtree exists so make
	// it's height negative and subtract one.
	else{
		result = -right_child->height-1;
	}
  // Otherwise, we have a left subtree so if we
  // don't have a right one, return the left's
  // height plus one.	  
  }

  else{
	  	if (right_child == nullptr){
		  result = left_child->height+1;
		}
		// Otherwise, both subtrees exist so subtract
		// them to return the difference.
		else{
			result = left_child->height-right_child->height;	 
		} 
  } 
  return result;
}

// Get the actual data, consider making const
template <typename T>
T AVLTree<T>::Node::getData() {
  return data;
} 

// Get the height.
template<typename T>
int AVLTree<T>::Node::getHeight() {
  return height;
}

// Get the left subtree.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::getLeftChild() {
  return left_child;
}

// Get the right subtree.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::getRightChild() {
  return right_child;
}

// Get the node's parent.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::getParent() {
  return parent;
}

// Remove the node's parent.
template<typename T>
void AVLTree<T>::Node::removeParent() {
	parent = nullptr;
}

// Set the left subtree.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::setLeftChild(Node *newLeft)
 {
  // If there is a left node, set it's parent to
  // be us. In any event, make it our left subtree
  // and update the height.
  if (newLeft != nullptr){
	  newLeft->parent = this;
  }
  left_child = newLeft;
  updateHeight();
  return left_child;
}

// Set the right subtree.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::setRightChild(Node *newRight) {
  // If there is a right node, set it's parent to
  // be us. In any event, make it our right subtree
  // and update the height.
  if (newRight != nullptr){
	  newRight->parent = this;
  }
  right_child = newRight;
  updateHeight();
  return right_child;
}

// update the node's height.
template<typename T>
int AVLTree<T>::Node::updateHeight() {
  // If we don't have a left subtree, check the
  // right.
  if (left_child == nullptr){
	// If we don't have either subtree, the height
	// is zero.
	if (right_child == nullptr){
		height = 0;
	}
	// Otherwise, we only have the right subtree so
	// our height is one more than it's height.
	else{
		height = right_child->height+1;
	}	  
  }
  // Otherwise, the left subtree exists so if we
  // don't have a right one, our height is one
  // more than it's height.
  else {
	  if (right_child == nullptr)
	  height = left_child->height+1;
	// Otherwise, we have both subtree's so if the
	// left's height is greater than the right, our
	// height is one more than it.

  	else{
			if (left_child->height > right_child->height)
			height = left_child->height+1;
			// Otherwise, the right subtree's height will be
			// used so our height is one more than it.
			else
			height = right_child->height+1;		  
	 	}
  }
  return height;
}

// update the node's subtree_size after inserting a node
template<typename T>
void AVLTree<T>::Node::updateInsertSize()
{
	// if the node has no childs
	if(this->right_child == nullptr && this->left_child == nullptr)
	{
		// the subtree only contains the node itself
		this->subtree_size = 1;
		return;
	}

	// else, we need to add one
	subtree_size+=1;
}

// update the node's subtree_size after removing a node
template<typename T>
void AVLTree<T>::Node::updateRemoveSize()
{
	// the size is 1 smaller since we removed a node
	subtree_size -= 1;
}

// update the node's subtree_size after rotating the tree
template<typename T>
void AVLTree<T>::Node::updateRotationSize()
{
	// if the node has no childs
	if (this->getLeftChild() == nullptr && this->getRightChild() == nullptr)
	{		  
		this->subtree_size = 1;
		return;
	}

	// if the node has only right child
	if (this->getLeftChild() == nullptr)
	{
		this->subtree_size = this->getRightChild()->subtree_size + 1;
		return;
	}

	// if the node has only left child
	if (this->getRightChild() == nullptr)
	{
		this->subtree_size = this->getLeftChild()->subtree_size + 1;
		return;
	}

	// the node has both childs
	this->subtree_size = this->getLeftChild()->subtree_size + this->getRightChild()->subtree_size + 1;
}

//empty tree constructor, must decide how to instantiate
template<typename T>
AVLTree<T>::AVLTree() {
  root = nullptr;
  lowest = nullptr;
  highest = nullptr;
}

// Constructor to populate the tree with one node, not used in HW
template<typename T>
AVLTree<T>::AVLTree(T t) {
  root = new Node(t);
  lowest = root;
  highest = root;
}

//destructor, maybe should be from highest?
template<typename T>
AVLTree<T>::~AVLTree(){
	while(root!=nullptr)
	{
		remove(root->getData());
	}
	// std::cout << "destroyed avl tree" <<std::endl;
}

// Balance the subtree. balancing the tree cannot change wich node is of highest or lowest value
//as such there is no need to update them
template<typename T>
void AVLTree<T>::balanceAtNode(Node *n) {

  // Get the current balance
  //determine which rotation is needed RR,LL,RL,LR
  int bal = n->getBalance();
  if (bal > 1) {
    //we are left heavy
    //determine if we are in LR case
	if (n->getLeftChild()->getBalance() < 0)
	  rotateLeft(n->getLeftChild());
	rotateRight(n);
    } 
  // Otherwise, we are right heavy
  // determine if we need RL or RR
  else if (bal < -1) {
	if (n->getRightChild()->getBalance() > 0)
	  rotateRight(n->getRightChild());
	rotateLeft(n);
  }
}

// Find the node containing the data.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::findNode(const T& data) {
  // While nodes remain, if we found the right
  // node, exit the loop. If the value we want
  // is less than the current, check the left
  // subtree, otherwise, the right.
  Node *temp = root;
  while (temp != nullptr) {
	if (data == temp->getData())
	  break;
	else{
		if (data < temp->getData())
	  		temp = temp->getLeftChild();
		else
	  		temp = temp->getRightChild();
	}
  }
  return temp;
}

// Get the tree's height.
template <typename T>
int AVLTree<T>::getHeight() {
  return root->getHeight();
}


// Insert the value into the tree.
template <typename T>
bool AVLTree<T>::insert(const T& t) {
  // If the tree is empty, add the new node as the root.
  if (root == nullptr){
	 root = new Node(t);
	 lowest = root;
	 highest = root; 
  }
  // Otherwise, we need to find the insertion point.
  else {
	// Starting at the tree root search for the
	// insertion point, until we have added the new node.
	Node *added_node = nullptr;
	Node *temp = root;
	while (temp != nullptr && added_node == nullptr) {
	  // If the value is less than the current
	  // node's value, go left. If there isn't a
	  // left subtree, insert the node, otherwise,
	  // it is next to check.
	  if (t < temp->getData()) {
		if (temp->getLeftChild() == nullptr) {
		  added_node = temp->setLeftChild(new Node(t));
		  if(lowest!=nullptr){
			if(t < lowest->getData())
		  		lowest = added_node;
		  }
		  else lowest = added_node;
		}
    	else
		  temp = temp->getLeftChild();
		}
	  // Otherwise, if the value is greater than
	  // the current node's value, go right. If
	  // there isn't a right subtree, insert the
	  // node, otherwise, it is next to check.
	  else if (t > temp->getData()) {
		if (temp->getRightChild() == nullptr) {
		  added_node = temp->setRightChild(new Node(t));
      // if we are the furthest right node
      // we are the largest valued node
		  if(highest != nullptr){
			  if(t > highest->getData())
			  	highest = added_node;
		  }
		  else highest = added_node;
		} 
    	else
		  temp = temp->getRightChild();
		}
		// Otherwise, the value is already in the
		// tree so abort.
    	else
		//should update to Std::exception
			return false;
	}

	// From the new node upwards to the root updated subtree_size
	temp = added_node;
	while(temp != nullptr) 
	{
		temp->updateInsertSize();
		temp = temp->getParent();
	}

	// From the new node upwards to the root:
	// updated the height and make sure the subtree is balanced.
	temp = added_node;
	while(temp != nullptr) {
	  temp->updateHeight();
	  balanceAtNode(temp);
	  temp = temp->getParent();
	} 
  }
  return true;
}

// Remove the value from the tree.
template <typename T>
bool AVLTree<T>::remove(const T& t) {
	// Find the node to delete and if none, exit.
	Node *toBeRemoved = findNode(t);
	if (toBeRemoved == nullptr){
		//should be std::exception
		return false;
	}
	// Get the parent and set the side the node is
	// on of the parent.
	enum {left, right} side;
	Node *p = toBeRemoved->getParent();
	//enum is right also if the node is a root
	if (p != nullptr && p->getLeftChild() == toBeRemoved)
		side = left;
	else
		side = right;
	// If the node to be removed doesn't have a left
	// subtree, check it's right subtree to figure
	// out our next move.
	if (toBeRemoved->getLeftChild() == nullptr)
	{
		// If we don't have any subtrees, we are the
		// leaf so our parent doesn't need us.
		if (toBeRemoved->getRightChild() == nullptr) 
		{
			// If we don't have a parent, the tree is now
			// empty so change the root to null and delete
			// our node.
			if (p == nullptr)
			{
				setRoot(nullptr);
				delete toBeRemoved;
      			toBeRemoved = nullptr;
				lowest = nullptr;
				highest = nullptr;
			}
			// Otherwise, change the parent so it doesn't
			// point to us, delete ourself, update the
			// parent's height, and rebalance the tree. 
			//if there is a node in the tree there is a lowest and highest value
			//in order to be the highest or lowest value we must be a leaf
			//check if we are the highest or lowest value
			//update as needed
			else 
			{
				if (side == left)
				{
					if(toBeRemoved->getData() == lowest->getData())
					{
						lowest = lowest->getParent();
					}
					p->setLeftChild(nullptr);
				}
				else
				{
					if(toBeRemoved->getData() == highest->getData())
					{
						highest = highest->getParent();
					}
					p->setRightChild(nullptr);
				}
				// update the subtree_size in the node's path
				Node* iter = toBeRemoved;
				while(iter->getParent())
				{
					iter->getParent()->updateRemoveSize();
					iter = iter->getParent();
				}
				delete toBeRemoved;
      			toBeRemoved = nullptr;
				p->updateHeight();
				balanceAtNode(p);
			} 
		}
		// Otherwise, there is a right subtree so use
		// it to replace ourself.
		else 
		{
			// If we don't have a parent, the tree is now
			// the right subtree and delete our node.
			if (p == nullptr) 
			{
				//deal with the case where the lowest value is the parent
				lowest = toBeRemoved->getRightChild();
				setRoot(toBeRemoved->getRightChild());
				delete toBeRemoved;
      			toBeRemoved = nullptr;
			}
			// Otherwise, change the parent so it doesn't
			// point to us, delete ourself, update the
			// parent's height, and rebalance the tree.
			else 
			{
				if (side == left)
				{
					// in this case, the lowest node is now our right son
					if(lowest == toBeRemoved)
					lowest = toBeRemoved->getRightChild();
					p->setLeftChild(toBeRemoved->getRightChild());
				}
				else
					p->setRightChild(toBeRemoved->getRightChild());
	
				Node* iter = toBeRemoved;
				while(iter->getParent())
				{
					iter->getParent()->updateRemoveSize();
					iter = iter->getParent();
				}
				delete toBeRemoved;
				p->updateHeight();
				balanceAtNode(p);
			} 
		} 
	}
  	// Otherwise, we have a left subtree so check the
	// right one of the node being removed to decide
	// what is next. If there isn't a right subtree,
	// the left one will replace ourself.
	else
	{ 
		if (toBeRemoved->getRightChild() ==nullptr) 
		{
			// If we don't have a parent, the tree is now
			// the left subtree and delete our node.
			if (p == nullptr) 
			{
				highest = toBeRemoved->getLeftChild();
				setRoot(toBeRemoved->getLeftChild());
				delete toBeRemoved;
        		toBeRemoved = nullptr;
			}
			// Otherwise, change the parent so it doesn't
			// point to us, delete ourself, update the
			// parent's height, and rebalance the tree.
			else 
			{
				if(side == left)
        		{
					p->setLeftChild(toBeRemoved->getLeftChild());
        		}
				else
				{
					// in this case our left son is now the highest
					if(highest == toBeRemoved)
						highest = toBeRemoved->getLeftChild();
					p->setRightChild(toBeRemoved->getLeftChild());
				}
				p->updateHeight();
				balanceAtNode(p);
			}
		}
		// Otherwise, the node to remove has both subtrees
		// so decide the best method to remove it.
		else 
		{
			// If the left side is deeper, modify it.
			// Check the balance to see which way to go.
			Node *replacement;
			Node *replacement_parent;
			Node *temp_node;
			int bal = toBeRemoved->getBalance();
			if (bal > 0) 
			{
				// If the right subtree of the node's
				// left subtree is empty, we can move the
				// node's right subtree there.
				if (toBeRemoved->getLeftChild()->getRightChild() == nullptr) 
				{
					replacement = toBeRemoved->getLeftChild();
					replacement->setRightChild(toBeRemoved->getRightChild());
					replacement->subtree_size += replacement->getRightChild()->getSubtreeSize();
					temp_node = replacement;
				}
				// Otherwise, find the most right child
				// of our node's left subtree and it's parent. 
				// This is our replacement. Make it's
				// parent point to it's left child instead
				// of itself. It is now free to replace the
				// deleted node. Copy both of the deleted
				// nodes subtrees into the replacement leaving
				// fixing up the parent below.
				else 
				{
					replacement = toBeRemoved->getLeftChild()->getRightChild();
					while (replacement->getRightChild() != nullptr)
						replacement = replacement->getRightChild();
					replacement_parent = replacement->getParent();
					replacement_parent->setRightChild(replacement->getLeftChild());

					Node* iterator = replacement_parent;
					while (iterator != toBeRemoved)
					{
						iterator->subtree_size -= 1;
						iterator = iterator->getParent();
					}
					
					temp_node = replacement_parent;
					replacement->setLeftChild(toBeRemoved->getLeftChild());
					replacement->setRightChild(toBeRemoved->getRightChild());
					replacement->subtree_size = toBeRemoved->getLeftChild()->getSubtreeSize() + toBeRemoved->getRightChild()->getSubtreeSize() + 1;
				}
			} 
			// Otherwise, we are going to modify the right side
			// if the left subtree of the node's right subtree
			// is empty, we can move the node's left subtree there.
			else if (toBeRemoved->getRightChild()->getLeftChild() == nullptr) 
			{
				replacement = toBeRemoved->getRightChild();
				replacement->setLeftChild(toBeRemoved->getLeftChild());
				replacement->subtree_size += toBeRemoved->getLeftChild()->getSubtreeSize();
				temp_node = replacement;
			}
			// Otherwise, find the left most empty subtree
			// of our node's right subtree and it's
			// parent. This is our replacement. Make it's
			// parent point to it's right child instead
			// of itself. It is now free to replace the
			// deleted node. Copy both of the deleted
			// nodes subtrees into the replacement leaving
			// fixing up the parent below.
			else 
			{
				replacement = toBeRemoved->getRightChild()->getLeftChild();
				while (replacement->getLeftChild() !=nullptr)
					replacement = replacement->getLeftChild();
				replacement_parent = replacement->getParent();
				replacement_parent->setLeftChild(replacement->getRightChild());

				Node* iterator = replacement_parent;
				while (iterator != toBeRemoved)
				{
					iterator->subtree_size -= 1;
					iterator = iterator->getParent();
				}

				temp_node = replacement_parent;
				replacement->setLeftChild(toBeRemoved->getLeftChild());
				replacement->setRightChild(toBeRemoved->getRightChild());
				replacement->subtree_size = toBeRemoved->getLeftChild()->getSubtreeSize() + toBeRemoved->getRightChild()->getSubtreeSize() +1;
			}
			// Fix the parent to point to the new root.
			// If there isn't a parent, update the actual
			// tree root. Otherwise, there is a parent so
			// if we were the left subtree, update it,
			// otherwise, the right. In all cases, delete
			// the node and rebalance the tree.
			if (p == nullptr)
				setRoot(replacement);
			else if (side == left)
					p->setLeftChild(replacement);
				else
					p->setRightChild(replacement);
			
			Node* iter = toBeRemoved;
			if (iter != nullptr)
			{
				while(iter->getParent())
				{
					iter->getParent()->updateRemoveSize();
					iter = iter->getParent();
				}
			}
			delete toBeRemoved;
    		toBeRemoved = nullptr;
			balanceAtNode(temp_node);
		}
	}
	return true;
}

// Rotate the subtree left.
template <typename T>
void AVLTree<T>::rotateLeft(Node *n) {
  // Get the node's parent and if it exists and the
  // node was it's left subtree, remember we are
  // processing the left, otherwise, the right.
  enum {left, right} side;
  Node *p = n->getParent();
  if (p != nullptr && p->getLeftChild() == n)
	side = left;
  else
	side = right;
  // Get the node's right subtree as the new root
  // and that subtree's left subtree. Make that
  // left subtree the node's new right. Put our
  // original node as the left subtree of our
  // new root.
  Node *temp = n->getRightChild();
  //setrightchild updates parent
  n->setRightChild(temp->getLeftChild());
  temp->setLeftChild(n);
  // Fix the original parent to point to the new
  // root. If there isn't a parent, update the
  // actual tree root. Otherwise, there is a
  // parent so if we were the left subtree, update
  // it, otherwise, the right.
  if (p == nullptr)
	setRoot(temp);
  else if (side == left)
		p->setLeftChild(temp);
  	else
		p->setRightChild(temp);
		
  // after the rotation, update node's subtree_size
  n->updateRotationSize();
  temp->updateRotationSize();
}

// Rotate the subtree right.
template <typename T>
void AVLTree<T>::rotateRight(Node *n) {
  // Get the node's parent and if it exists and the
  // node was it's left subtree, remember we are
  // processing the left, otherwise, the right.
  enum {left, right} side;
  Node *p = n->getParent();
  if (p != nullptr && p->getLeftChild() == n)
	side = left;
  else
	side = right;
  // Get the node's left subtree as the new root
  // and that subtree's right subtree. Make that
  // right subtree the node's new left. Put our
  // original node as the right subtree of our
  // new root.
  Node *temp = n->getLeftChild();
  n->setLeftChild(temp->getRightChild());
  temp->setRightChild(n);
  // Fix the original parent to point to the new
  // root. If there isn't a parent, update the
  // actual tree root. Otherwise, there is a
  // parent so if we were the left subtree, update
  // it, otherwise, the right.
  if (p == nullptr)
	setRoot(temp);
  else if (side == left)
		p->setLeftChild(temp);
  	else
		p->setRightChild(temp);

  // after the rotation, update node's subtree_size
  n->updateRotationSize();
  temp->updateRotationSize();
}

// Set the root. Change the tree root to the node
// and if it exists, remove it's parent.
template <typename T>
void AVLTree<T>::setRoot(Node *n) {
  root = n;
  if (root != nullptr)
	root->removeParent();
}



//return lowest value, can only be used on a non empty tree
template<typename T>
T AVLTree<T>::getLowestValue(){
	if(lowest!=nullptr)
		return lowest->getData();
}

//return highest value can only be used on a non empty tree
template<typename T>
T AVLTree<T>::getHighestValue(){
	if(highest!=nullptr)
		return highest->getData();
}

// returns a pointer to the node woth the highest value
template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::getHighest(){
	return highest;
}

//print the tree
template <typename T>
void AVLTree<T>::print() {

  // If the tree is empty, say so.
  if (root == nullptr)
	std::cout << "Tree is empty!" <<std::endl;

  // Otherwise, if the tree has a height more than 4
  // (5 rows), it is too wide.
  else if (root->getHeight() > 4)
	std::cout << "Not currently supported!" <<std::endl;

  // Otherwise, set up to display the tree. Get
  // the maximum depth and for each possible
  // level, output that level's elements and
  // finish off the line.
  else {
	int max = root->getHeight();
	for (int depth = 0; depth <= max; depth++) {
	  printSubtree(root, depth, max-depth+1, true);
	  std::cout << std::endl;
	} // for
  } 
} // print

// --------------------------------------------------
// Print the subtree.  The leftmost branch will have
// first true. The level counts up from the bottom
// for the line we are doing. The depth is how
// many layers to skip over.
template <typename T>
void AVLTree<T>::printSubtree(Node *subtree, int depth,
	int level, bool first) {

  // If we need to go deeper in the subtree, do so.
  // If the subtree is empty, pass it down, otherwise
  // pass both left and right subtrees.
  if (depth > 0) {
	if (subtree == nullptr) {
	  printSubtree(subtree, depth-1, level, first);
	  printSubtree(subtree, depth-1, level, false);
	} else {
	  printSubtree(subtree->getLeftChild(), depth-1,
		  level, first);
	  printSubtree(subtree->getRightChild(), depth-1,
		  level, false);
	} // if

  // Otherwise, if the subtree is empty, display
  // an empty element. The leftmost element only
  // needs half the spacing.
  } else if (subtree == nullptr)
	std::cout << std::setw((first)?
		spacing(level)/2:spacing(level)) << "-";

  // Otherwise, we have a live element so display
  // it. Once more, use half spacing for the
  // leftmost element.
  else
	std::cout << std::setw((first)?
		spacing(level)/2:spacing(level)) <<
		subtree->getData();
} // printSubtree

// Figure out the default spacing for element. Each
// higher level doubles the preceeding. The bottom
// level is one.
template<typename T>
int AVLTree<T>::spacing(int level) {
  int result = 2;
  for (int i = 0; i < level; i++)
	result += result;
  return result;
}



template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::arrToNodesTree(T arr[], int start, int end)
{
    // Base Case
    if (start > end) 
    return NULL; 

    // Get the middle element and make it root
    int mid = (start + end)/2; 
	Node* node = new Node(arr[mid]);

	//Recursively construct the left subtree and make it left child of root
	node->left_child = arrToNodesTree(arr, start, mid-1);

	// Recursively construct the right subtree and make it right child of root
	node->right_child = arrToNodesTree(arr, mid+1, end);

	return node;
} 


template<typename T>
int AVLTree<T>::setNodesHeight(AVLTree<T>::Node* node)
{
	//if the node has no child
	if (node->getLeftChild()==nullptr && node->getRightChild()==nullptr)
	{
		node->height=0;
		return 0;
	}

	//if the node has only Left child
	if (node->getRightChild()==nullptr)
	{
		node->height=1;
		node->getLeftChild()->height=0;
		return 1;
	}

	//if the node has only Right child
	if (node->getLeftChild()==nullptr)
	{
		node->height=1;
		node->getRightChild()->height=0;
		return 1;
	}

	//if the node has both childs:
	if (node->getLeftChild()!=nullptr && node->getRightChild()!=nullptr)
	{
		node->height= 1+std::max(setNodesHeight(node->getLeftChild()), setNodesHeight(node->getRightChild()));
	}
	return node->height;
}

template<typename T>
void AVLTree<T>::setNodesParent(AVLTree<T>::Node* node)
{
	//if the node has no child
	if(node==nullptr || (node->getLeftChild()==nullptr && node->getRightChild()==nullptr))
	{
		return;
	}

	//if the node has a Left child
	if (node->getLeftChild() != nullptr)
	{
		node->getLeftChild()->parent= node;
		setNodesParent(node->getLeftChild());
	}

	//if the node has a Right child
	if (node->getRightChild() != nullptr)
	{
		node->getRightChild()->parent= node;
		setNodesParent(node->getRightChild());
	}	

	return;
}

//setting the linked-node's Highest node
template<typename T>
void AVLTree<T>::setHighestNode(AVLTree<T>::Node* node)
{
	while (node->getRightChild() != nullptr)
	{
		node = node->getRightChild();
	}
	this->highest= node;
	return;
}

//setting the linked-node's Lowest node
template<typename T>
void AVLTree<T>::setLowestNode(AVLTree<T>::Node* node)
{
	while (node->getLeftChild() != nullptr)
	{
		node = node->getLeftChild();
	}
	this->lowest= node;
	return;
}

//setting the linked-node's Root
template<typename T>	 
void AVLTree<T>::setNodesRoot(AVLTree<T>::Node* node)
{
	this->root=node;
	return;
}


//creates an AVLTree from sorted array
template<typename T>
AVLTree<T>* AVLTree<T>::arrToAVLTree(T arr[], int start, int end)
{ 
	//turns the sorted array to linked nodes
	typename AVLTree<T>::Node* node = AVLTree<T>::arrToNodesTree(arr, start, end);
	//seting the height of each node
	AVLTree<T>::setNodesHeight(node);
	//setting the parent of each node
	AVLTree<T>::setNodesParent(node);
	//initializing the AVLTree
	// perhaps should be encased in a trycatch block?
	AVLTree<T>* tree = new AVLTree<T>();
	//setting the root of the tree
	tree->setNodesRoot(node);
	//setting the highest node of the tree
	tree->setHighestNode(node);
	//setting the lowest node of the tree
	tree->setLowestNode(node);

	return tree;
}

// turns AVLTree to sorted array
template<typename T>
void AVLTree<T>::Node::AVLToArr(T arr[], int* index)
{
	if (this->getLeftChild() != nullptr)
	{
		this->getLeftChild()->AVLToArr(arr, index);
	}

	arr[*index] = this->data;
	(*index)++;
	
	if (this->getRightChild() != nullptr)
	{
		this->getRightChild()->AVLToArr(arr, index);
	}
}

// merging two sorted arrays
template<typename T>
void mergeArrays(T arr_1[], int size_1, T arr_2[], int size_2, T merged_arr[], int size_merged)
{
	int index_1 = 0;
	int index_2 = 0;
	int merged_index = 0;
	while (merged_index < size_merged)
	{
		// if the first array has ended
		if (index_1 == size_1)
		{
			// insert the element of the second array
			merged_arr[merged_index] = arr_2[index_2];
			index_2++;
		}

		// if the second array has ended
		else if (index_2 == size_2)
		{
			// insert the element from the first array
			merged_arr[merged_index] = arr_1[index_1];
			index_1++;
		}

		// if no array has ended, insert the smaller element
		else if (arr_1[index_1] < arr_2[index_2])
		{
			merged_arr[merged_index] = arr_1[index_1];
			index_1++;
		}
		else
		{
			merged_arr[merged_index] = arr_2[index_2];
			index_2++;
		}

		merged_index++;
	}
}

// setting node's subtree_size
template<typename T>
void AVLTree<T>::Node::AVLToRank()
{
	if (this->getLeftChild() != nullptr)
	{
		this->getLeftChild()->AVLToRank();
	}

	if (this->getRightChild() != nullptr)
	{
		this->getRightChild()->AVLToRank();
	}

	this->updateRotationSize();
}

// merging two AVLTrees
template<typename T>
AVLTree<T>* AVLTree<T>::mergeAVLTrees(AVLTree<T>* tree_1, AVLTree<T>* tree_2)
{
	// if both trees are empty
	// create and return an empty tree
	if (tree_1->root == nullptr && tree_2->root == nullptr)
	{
		AVLTree<T>* empty_tree = new AVLTree<T>();
		return empty_tree;
	}

	// initializing an index for each tree
	int i_1 = 0;
	int* index_1 = &i_1;
	int i_2 = 0;
	int* index_2 = &i_2;

	// if only one tree is empty, copy the other and return it
	if (tree_1->root == nullptr)
	{
		int size_2 = tree_2->root->subtree_size;
		T* arr_2 = new T[size_2];
		tree_2->root->AVLToArr(arr_2, index_2);
		AVLTree<T>* tree_2_copy = AVLTree<T>::arrToAVLTree(arr_2, 0, size_2-1);
		tree_2_copy->root->AVLToRank();
		delete[] arr_2;
		return tree_2_copy;
	}

	if (tree_2->root == nullptr)
	{
		int size_1 = tree_1->root->subtree_size;
		T* arr_1 = new T[size_1];
		tree_1->root->AVLToArr(arr_1, index_1);
		AVLTree<T>* tree_1_copy = AVLTree<T>::arrToAVLTree(arr_1, 0, size_1-1);
		tree_1_copy->root->AVLToRank();
		delete[] arr_1;
		return tree_1_copy;
	}

	// if no tree is empty, merge them

	// initializing an array for each tree
	int size_1;
	int size_2;
	if(tree_1->root != nullptr)
		size_1 = tree_1->root->subtree_size;
	else 
		size_1 = 0;
	if(tree_2->root != nullptr)
		size_2 = tree_2->root->subtree_size;
	else 
		size_2 = 0;

	T* arr_1 = new T[size_1];
	T* arr_2 = nullptr;
	try
	{
		arr_2 = new T[size_2];
	}
	catch(std::exception& e)
	{
		delete[] arr_1;
		throw e; // maybe change it later to return enum value
	}

	// turning each tree to array
	tree_1->root->AVLToArr(arr_1, index_1);
	tree_2->root->AVLToArr(arr_2, index_2);

	// initializing the merged array
	T* merged_arr = nullptr;
	int merged_size = size_1 + size_2;
	try
	{
		merged_arr = new T[merged_size];
	}
	catch(std::exception& e)
	{
		delete[] arr_1;
		delete[] arr_2;
		throw e; // maybe change it later to return enum value
	}
	
	
	// merging arr_1 and arr_2 to merged_arr
	mergeArrays(arr_1, size_1, arr_2, size_2, merged_arr, merged_size);

	// turning the merged_array to AVLTree
	AVLTree<T>* merged_tree = AVLTree<T>::arrToAVLTree(merged_arr, 0, merged_size-1);

	// deleting the arrays we've allocated
	delete[] arr_1;
	delete[] arr_2;
	delete[] merged_arr;

	// turning the merged AVLTree to ranks tree
	merged_tree->root->AVLToRank();
	return merged_tree;
}

template<typename T>
int AVLTree<T>::Node::getSubtreeSize()
{
	if (this)
	{
		return this->subtree_size;
	}
	return 0;
}

// find the node with the given rank
// returns nullptr if there's no node ranked "rank"
template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::Node::select(int rank)
{
	// stop condition
	if (this->getSubtreeSize() == 0)
	{
		return nullptr;
	}

	if (this->getLeftChild()->getSubtreeSize() == rank-1)
	{
		return this;
	}

	if (this->getLeftChild()->getSubtreeSize() > rank-1)
	{
		return this->getLeftChild()->select(rank);
	}

	if (this->getLeftChild()->getSubtreeSize() < rank-1)
	{
		return this->getRightChild()->select(rank- this->getLeftChild()->getSubtreeSize() -1);
	}

	return nullptr;
}

#endif //AVL_H_