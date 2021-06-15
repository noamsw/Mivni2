#include "dsunion.h"
#include <iostream>
int main(){
    DSUnion* union1 = new DSUnion();
    union1->DS_makeSet();
    union1->DS_makeSet();
    union1->DS_makeSet();
    union1->DS_makeSet();
    union1->parents->pretty_print();
    union1->DS_find(1)->sell(0,2);
    union1->DS_find(1)->sell(0,2);
    union1->DS_find(1)->sell(6,2);
    union1->DS_find(3)->sell(8,6);
    union1->DS_find(1)->sell(2,2);
    union1->DS_find(2)->sell(2,2);
    union1->DS_find(2)->sell(3,2);
    DSset* set0 = union1->DS_find(0);
    DSset* set1 = union1->DS_find(1);
    DSset* set2 = union1->DS_find(2);
    DSset* set3 = union1->DS_find(3);
    std::cout << "id tree of 1:" << std::endl;
    union1->DS_find(1)->id_tree->print();
    std::cout << "ranked tree of 1:" << std::endl;
    union1->DS_find(1)->ranked_tree->print();
    std::cout << "---------------------" << std::endl;
    std::cout << "id tree of 2:" << std::endl;
    union1->DS_find(2)->id_tree->print();
    std::cout << "ranked tree of 2:" << std::endl;
    union1->DS_find(2)->ranked_tree->print();
    std::cout << "---------------------" << std::endl;
    std::cout << "id tree of 3:" << std::endl;
    union1->DS_find(3)->id_tree->print();
    std::cout << "ranked tree of 3:" << std::endl;
    union1->DS_find(3)->ranked_tree->print();
    std::cout << "---------------------" << std::endl;
    union1->DS_union(1,2);
    std::cout << "after union:" << std::endl;
    std::cout << "id tree of 2:" << std::endl;
    union1->DS_find(2)->id_tree->print();
    std::cout << "ranked tree of 2:" << std::endl;
    union1->DS_find(2)->ranked_tree->print();
    std::cout << "---------------------" << std::endl;
    std::cout << "here we go:" << std::endl;
    union1->parents->pretty_print();
    delete union1;
}