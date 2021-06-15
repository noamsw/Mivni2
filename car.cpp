#include "car.h"

// used to sell one car of type model
void car::sell()
{
    num_sales++;
}
// compares car by id
bool car::operator==(const car& other) const
{
    return car_id == other.car_id;
}
// compares car by id
bool car::operator==(car& other) 
{
    return car_id == other.car_id;
}
// returns the smaller car
bool car::operator<(const car& other) const
{
    return car_id < other.car_id;
}
bool car::operator<( car& other) 
{
    return car_id < other.car_id;
}
bool car::operator>(const car& other) const
{
    if (car_id == other.car_id)
        return false;
    return !(*this < other);
}
bool car::operator>( car& other) 
{
    if (car_id == other.car_id)
        return false;
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const car& car)
{
    os << car.car_id << "." << car.num_sales;
    return os;
}