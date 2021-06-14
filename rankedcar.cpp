#include "rankedcar.h"

void Rankedcar::sell(){
    num_sales++;
}

bool Rankedcar::operator==(const Rankedcar& other)const{
    if (car_id == other.car_id)
        return true;
    return false;
}
bool Rankedcar::operator==( Rankedcar& other){
    if (car_id == other.car_id)
        return true;
    return false;
}

bool Rankedcar::operator<(const Rankedcar& other)const{
    if (*this == other)
        return false;
    // if other has more sales, it is a better seller
    if(num_sales < other.num_sales)
        return true;
    // if they have the same number of sales,
    // check who has the lower id
    if(num_sales == other.num_sales)
        return (this->car_id < other.car_id);
    // if we are here, this is ranked higher than other
    return false;
}
bool Rankedcar::operator<( Rankedcar& other){
    if (*this == other)
        return false;
    // if other has more sales, it is a better seller
    if(num_sales < other.num_sales)
        return true;
    // if they have the same number of sales,
    // check who has the lower id
    if(num_sales == other.num_sales)
        return (this->car_id < other.car_id);
    // if we are here, this is ranked higher than other
    return false;
}

bool Rankedcar::operator>(const Rankedcar& other)const{
    if (*this == other)
        return false;
    return !(*this < other);
}
bool Rankedcar::operator>( Rankedcar& other){
    if (*this == other)
        return false;
    return !(*this < other);
}
    