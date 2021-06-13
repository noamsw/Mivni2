#include "dealershipset.h"

// ctor for DSset
// must revieve a name for the set
// size, ID_tree, rankded_tree are empty
DSset::DSset(int set_name):set_name(set_name){
    size = 0;
    id_tree = new AVLTree<car>();
    ranked_tree = new AVLTree<Rankedcar>();
}

DSset::~DSset(){
   delete ranked_tree;
   delete id_tree; 
}

DSset& DSset::merge(DSset& other){
    size += other.size;
    // this must be instantiated in avltree
    id_tree.merge(other.id_tree);
    ranked_tree.merge(other.ranked_tree);
    return *this;
}

void DSset::sell(int type_id, int num_sold){
    // search for the type in the id tree
    AVLTree<car>::Node* old_node = id_tree->findNode(car(type_id,0));
    // if it does not exist, than add it and return
    if (old_node == nullptr)
        {
            id_tree->insert(car(type_id,num_sold));
            ranked_tree->insert(Rankedcar(type_id, num_sold));
            return;
        }
    // if it existed, then find the num_sales,
    // update the ranked tree
    // update the id tree
    int old_num_sold = old_node->data.num_sales;
    int new_num_sold = old_num_sold + num_sold;
    ranked_tree->remove(Rankedcar(type_id, old_num_sold));
    ranked_tree->insert(Rankedcar(type_id, new_num_sold));
    id_tree->remove(car(type_id , old_num_sold));
    id_tree->insert(car(type_id, new_num_sold));
    return;
}


    // returns the "i"th sold car
    // from 0 till the end
    int DSset::getthsold(int i){
    }