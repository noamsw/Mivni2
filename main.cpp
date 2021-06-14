#include "dsunion.h"
#include <iostream>
int main(){
    DSUnion union1 = DSUnion();
    union1.DS_makeSet();
    union1.DS_makeSet();
    union1.DS_makeSet();
    union1.DS_makeSet();
    union1.parents->pretty_print();
    union1.DS_union(1,2);
    union1.parents->pretty_print();
}