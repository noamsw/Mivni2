#include "dsunion.h"
#include "assert.h"
// ctor for dsunionfind
// will create an empty array of DSsets 
// empty array car dealerships
// empty array of sizes
DSUnion::DSUnion(){
    parents = new dynamic_array<int>;
    // sizes = new dynamic_array<int>;// removing this for now
    sets = new dynamic_array<DSset*>;
    num_dealerships = 0;
}

DSUnion::~DSUnion(){
    delete parents;
    // delete sizes; // removing this for now
    // it is our responibility to erase the pointers
    for(int i =0; i++; i<num_dealerships)
    {
        delete (*sets)[i];
        (*sets)[i] = nullptr;
    }
    delete sets;
}

// adds a new agency to DSunion
// it will be the responsibilty if the DSManger 
// to make sure to add agencies in the correct order
DSset* DSUnion::DS_makeSet(){
    // inserts the new agency name into the parents array
    parents->append(num_dealerships);
    // makes the size of said array 1
    // sizes->append(1);// removing this for now
    // inserts a new set
    // comprised of one empty dealership
    // into the DSset array
    DSset* new_set = new DSset(num_dealerships);
    sets->append(new_set);
    // updates the amount of dealerships
    num_dealerships++;
    return new_set;
}

// finds and returns the set
// of the ds
DSset* DSUnion::DS_find(int dealership_id){
    // assert that we are in the range of the sets
    assert ( dealership_id >= 0 && dealership_id < parents->getsSize());
    int parent_dealership = dealership_id; 
    // find the parent dealership
    // going over the array until reaching a dealership
    // which is its own parent
    while(parent_dealership != (*parents)[parent_dealership])
        parent_dealership =  (*parents)[parent_dealership];
    // shortens paths to parent
    // goes over the former path and updates each ds
    // to go directly to the parent ds
    while(dealership_id != (*parents)[dealership_id])
    {
        int next_ds =  (*parents)[dealership_id];
        (*parents)[dealership_id] = parent_dealership;
        dealership_id =  (*parents)[next_ds];
    }
    return (*sets)[parent_dealership];
}

// recieves the name of two sets and unites them
// the set which is smaller in size will be merged into the larger set
// if equal it does not matter
DSset* DSUnion::DS_union(int set1, int set2){
     // assert that we are in the range of the sets
    assert ( set1 >= 0 && set1 < parents->getsSize());
    assert ( set2 >= 0 && set2 < parents->getsSize());
    int size_set1 = (*sets)[set1]->size;
    int size_set2 = (*sets)[set2]->size;
    if( size_set1 >= size_set2)
    {
        // update the parent of the smaller set
        // to be the larger set
        (*parents)[set2] = set1;
        // merge set2 into set1
        (*sets)[set1]->merge((*sets)[set2]);
        return (*sets)[set1];
    }
    if( size_set2 > size_set1)
    {
        // update the parent of the smaller set
        // to be the larger set
        (*parents)[set1] = set2;
        // merge set1 into set2
        (*sets)[set2]->merge((*sets)[set1]);
        return (*sets)[set2];
    }
}

