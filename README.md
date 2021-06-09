# Mivni2

Mivni Hw2 wet assignment. 
implementation of a Car dealership manager/
question- how does one join the two groups? what is the new group called. it seems that they
would both point to the carAvltree.
Data stucture over view:
  Dealership Manager{
                      unionFind implementaion on N dealerships. 
                      the members are the dealerships, 
                      the groups are the unified dealerships. 
                      two dynamic arrays. 
                      groups array- points to the group in question. 
                      cardealership array points to the cardealership. 
                      the groups array will contain the carsTree
                     }
  CarDealerships{
                  Dealership Id
                }
  unifiedCarDealerships{
                    Avl Tree of cars
                    num of Cardealerships in group
                    }
  Car{
      Car_id
      num_sold
      }
