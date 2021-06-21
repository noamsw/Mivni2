#include "library2.h"
#include "dsmanager.h"
#include "dsunion.h"

void* Init()
{
    DSManager* DS = new DSManager();
    return (void*)DS;
}

StatusType AddAgency(void *DS)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try{
        ((DSManager *)(DS))->DS_makeSet();
    }
    catch(std::exception & e)
    {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType SellCar(void *DS, int agency_id, int type_id, int k)
{
    if(DS == NULL || k <= 0 || agency_id < 0)
    {
        return INVALID_INPUT;
    }
    int numsets = ((DSManager *)(DS))->num_dealerships;
    if(agency_id >= numsets)
        return FAILURE;
    bool inserted = false;
    try{
        inserted = ((DSManager *)(DS))->SellCar(agency_id, type_id, k);
    }
    catch(std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    if (inserted)
        return SUCCESS;
    return FAILURE;
}

StatusType UniteAgencies(void *DS, int agency_id1, int agency_id2)
{
    if(DS == NULL || agency_id2 < 0 || agency_id1 < 0)
    {
        return INVALID_INPUT;
    }
    // check that the agencies exist
    // if they are not in the boudries 
    // then return failure
    int numsets = ((DSManager *)(DS))->num_dealerships;
    if(agency_id2 >= numsets || agency_id1 >= numsets)
        return FAILURE;
    // if we are here the agencies exist
    bool united = false;
    int set1 = ((DSManager *)(DS))->DS_find(agency_id1)->set_name;
    int set2 = ((DSManager *)(DS))->DS_find(agency_id2)->set_name;
    try{
        united = ((DSManager *)(DS))->UniteAgencies(set1, set2);
    }
    catch(std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    if (united)
        return SUCCESS;
    return FAILURE;
}

StatusType GetIthSoldType(void *DS, int agency_id, int i, int* res)
{
    if(DS == NULL || i<0 || agency_id < 0)
    {
        return INVALID_INPUT;
    }
    int exists = false;
    try{
        exists = ((DSManager *)(DS))->GetIthSoldType(agency_id, i, res);
    }
    catch(std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    if (exists == 1)
        return SUCCESS;
    return FAILURE;
}

void Quit(void** DS)
{
    delete ((DSManager *)(*DS));
    *DS = NULL;
}