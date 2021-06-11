#ifndef RANKEDCAR_H_
#define RANKEDCAR_H_

#include <iostream>
class Rankedcar{
public:
    int car_id;
    int num_sales;
public:
    Rankedcar(int car_id, int num_sales):car_id(car_id), num_sales(num_sales){};
    Rankedcar(const Rankedcar&) = default;
    ~Rankedcar() = default;
    Rankedcar& operator=(const Rankedcar&) = default;
    // used to update the sales by 1
    void sell();
    bool operator==(const Rankedcar& other);
    bool operator<(const Rankedcar& other);
    bool operator>(const Rankedcar& other);
};






#endif // RANKEDCAR_H_
