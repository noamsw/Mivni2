#ifndef DS_MANAGER_H_
#define DS_MANAGER_H_
#include "car.h"
#include "dynamic_array.cpp"
#include "dealershipset.h"
// a class used to implement UNIONFIND
//for a dealership
class DSManager{
public:
    //the cardealerships are simply ints
    // as such the reverse tree will be imlemented using two arrays
    // one aray for sizes, one for parents. 
    // if the dealership is the parent
    // the parent will be itself
    // the name of the group will be the name of the parent dealership 
    dynamic_array<int> parents;
    dynamic_array<int> sizes;
    // array of pointers to DSets
    // which contain the trees, name and size of set
    dynamic_array<DSset*> groups;
public:
    DSManager();
    DSManager(const DSManager&) = delete;
    DSManager operator=(const DSManager&) = delete;
    ~DSManager();
    


};



#endif //DS_MANAGER_H_