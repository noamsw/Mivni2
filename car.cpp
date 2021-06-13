#include "car.h"

// used to sell one car of type model
void car::sell()
{
    num_sales++;
}
// compares car by id
bool car::operator==(const car& other)
{
    return car_id == other.car_id;
}
// returns the smaller car
bool car::operator<(const car& other)
{
    return car_id < other.car_id;
}
bool car::operator>(const car& other)
{
    if (car_id == other.car_id)
        return false;
    return !(*this < other);
}