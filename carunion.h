#ifndef CARUNION_H_
#define CARUNION_H_

#include "car.h"
#include "dynamic_array.cpp"
// a class used to implement UNIONFIND
//for a dealership
class CarUnion{
public:
    //the cardealerships are simply ints
    // as such the reverse tree will be imlemented using two arrays
    // one aray for sizes, one for parents. 
    // the name of the group will be the name of the parent dealership 
    dynamic_array<int> parents;
    dynamic_array<int> sizes;
    
};



#endif //CARUNION_H_