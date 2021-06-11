#ifndef DGROUPS_H_
#define DGROUPS_H_

#include "dynamic_array.cpp"
#include <iostream>
#include "AVL.h"
#include "car.h"
#include "rankedcar.h"

// the class used to hold the information of a group
class Dgroup{
public:
    // the name of the group
    // it will be the name of the largest group to unioned
    int group_name;
    // size- the amount of dealerships in the group currently
    int size;
    // AvlTree of cars
    AVLTree<car> Id_tree;
    // ranked AVLtree of carmodels, by sales
    AVLTree<Rankedcar> ranked_tree;

};



#endif //DGROUPS_H_
