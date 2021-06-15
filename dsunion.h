#ifndef DS_UNION_H_
#define DS_UNION_H_
#include "car.h"
#include "dynamic_array.cpp"
#include "dealershipset.h"
// a class used to implement UNIONFIND
//for a dealership
class DSUnion{
public:
    //the agencies are simply ints
    // as such the reverse tree will be imlemented using two arrays
    // one aray for sizes, one for parents. 
    // if the agency is the parent
    // the parent will be itself
    // the name of the set will be the name of the parent dealership 
    dynamic_array<int>* parents;
    // dynamic_array<int>* sizes;// removing this for now
    // array of pointers to DSets
    // which contain the trees, name and size of set
    dynamic_array<DSset*>* sets;
    // a counter which stores the current amount of dealerships
    int num_dealerships;
public:
    DSUnion();
    DSUnion(const DSUnion&);
    DSUnion operator=(const DSUnion&);
    ~DSUnion();
    DSset* DS_makeSet();
    DSset* DS_find(int dealership_id);
    DSset* DS_union(int set1, int set2);
};



#endif //DS_UNION_H_