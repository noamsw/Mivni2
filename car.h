#ifndef CAR_H_
#define CAR_H_

#include <iostream>
class car{
public:
    int car_id;
    int num_sales;
public:
    car(int car_id, int num_sales):car_id(car_id), num_sales(num_sales){};
    car(const car&) = default;
    ~car() = default;
    car& operator=(const car&) = default;
    // used to update the sales by 1
    void sell();
    bool operator==(const car& other);
    bool operator<(const car& other);
    bool operator>(const car& other);
};

// commits check






#endif // CAR_H_
