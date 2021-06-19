#include "dsmanager.h"

bool DSManager::SellCar(int agency_id, int type_id, int num_sold)
{
    // if the agency does not exist return false
    if (agency_id >= num_dealerships)
            return false;
    // search for the set in the unionfind
    // sell the car
    DSset* set = DS_find(agency_id);
    set->sell(type_id, num_sold);
    return true;
}

bool DSManager::UniteAgencies(int agency_id1, int agency_id2)
{
    // if the agencies do not exist return false
    if( agency_id1 >= num_dealerships || agency_id2 >= num_dealerships)
        return false;
    // find the agecncies' sets
    DSset* set_agency1 = DS_find(agency_id1);
    DSset* set_agency2 = DS_find(agency_id2);
    // check if they are already in the same set
    int set1 = set_agency1->set_name;
    int set2 = set_agency2->set_name;
    if(set1 == set2)
        return true;
    // else we must unite them
    DS_union(set1, set2);
    return true;
}
    // returns 1 if the car exists
    // returns -1 if the agency does not exist
    // or if the car does not exist in this agency
int DSManager::GetIthSoldType(int agency_id, int i, int* res)
{
    // check if the agency exists
    if (agency_id >= num_dealerships)
    {
        return -1;
    }

    // find the agency's set
    DSset* set_agency = DS_find(agency_id);

    // get the agency's Ith sold car type
    return set_agency->getIthsold(i, res);
}