#include "dealershipset.h"

// ctor for DSset
// must revieve a name for the set
// size, ID_tree, rankded_tree are empty
DSset::DSset(int set_name):set_name(set_name){
    size = 1;
    id_tree = new AVLTree<car>();
    try{
        ranked_tree = new AVLTree<Rankedcar>();
    }
    catch(std::exception& e)
    {
        delete id_tree;
    }
}

DSset::~DSset(){
   delete ranked_tree;
   delete id_tree; 
}

DSset& DSset::merge(DSset* other){
    size += other->size;
    // merge the trees from each set into two new trees
    AVLTree<Rankedcar>* new_rankedtree= AVLTree<Rankedcar>::mergeAVLTrees(this->ranked_tree, other->ranked_tree);
    AVLTree<car>* new_idtree= AVLTree<car>::mergeAVLTrees(this->id_tree, other->id_tree);
    // delete the tress in the old set and set them to nullptrs
    delete this->ranked_tree;
    delete this->id_tree;
    delete other->ranked_tree;
    delete other->id_tree;
    other->ranked_tree = nullptr;
    other->id_tree = nullptr;
    // update the sets trees to the new trees
    this->ranked_tree = new_rankedtree;
    this->id_tree = new_idtree;
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
    int DSset::getithsold(int i){
        return 0;
    }