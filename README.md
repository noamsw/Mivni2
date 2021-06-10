# Mivni2

Mivni Hw2 wet assignment. 
implementation of a Car dealership manager/
question- how does one join the two groups? what is the new group called. it seems that they
would both point to the carAvltree.
Data stucture over view:
unionFind implementaion on N dealerships. 
                      the members are the dealerships, 
                      the groups are the unified dealerships. 
                      two dynamic arrays. 
  Dealership Manager{
                      groups_array- points to the group in question, 
                        contains the name, size by amount of cardealerships,
                        and two trees:
                        Id_AvlTree ranked by id, in order to update sales,
                        Sales_AvlTree ranked by Sales, in order to 
                        return a model by rank of sales
                      cardealership_array points to the cardealerships
                      
                     }
  CarDealerships{
                  Dealership Id
                }
  CarRankbyId{
      Car_id
      num_sold
      }
  CarRankbySales{
      num_sold
      Car_id
      }
