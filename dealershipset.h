#ifndef DEALER_SHIP_SET_H_
#define DEALER_SHIP_SET_H_

#include "dynamic_array.cpp"
#include <iostream>
#include "avl.h"
#include "car.h"
#include "rankedcar.h"

// the class used to hold the information of a set
class DSset{
public:
    // the name of the group
    // it will be the name of the largest group to unioned
    int set_name;
    // size- the amount of dealerships in the group currently
    int size;
    // AvlTree of cars
    AVLTree<car> *id_tree;
    // ranked AVLtree of carmodels, by sales
    AVLTree<Rankedcar> *ranked_tree;
public:
    DSset(int set_name);
    DSset(const DSset&) = delete;
    ~DSset();
    DSset& operator=(const DSset&) = delete;
    // method used to merge two DSsets together
    // other will be merged into this
    // the set_name will remain this.set name
    // size will be the size of both together
    // other.idtree and other.ranked tree
    // will be merged into this.trees
    // other will be an invalid set, 
    // with nullptrs in tree fields. 
    DSset& merge(DSset* other);
    // sell num_sold of type_id car
    //  updates trees
    void sell(int type_id, int num_sold);
    // returns the "i"th sold car
    // from 0 till the end
    int getthsold(int i);
};



#endif //DEALER_SHIP_SET_H_
