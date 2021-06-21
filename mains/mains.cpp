// #include "avl.h"
// #include <iostream>
// int main(){
//     AVLTree<int> tree = AVLTree<int>();
//     tree.insert(2);
//     tree.insert(3);
//     tree.insert(4);
//     tree.insert(0);
//     tree.print();
//     AVLTree<int>* tree1 = new AVLTree<int>();
//     tree1->insert(2);
//     tree1->insert(3);
//     tree1->insert(3);
//     tree1->insert(3);
//     tree1->insert(3);
//     tree1->insert(3);
//     tree1->insert(1);
//     tree1->insert(31);
//     tree1->insert(14);
//     tree1->insert(17);
//     tree1->insert(4);
//     tree1->print();
//     delete tree1;
//     return 0;
// }



// #include "dynamic_array.cpp"
// #include <iostream>
// int main(){
//     dynamic_array<int> arr;
//     arr.append(3);
//     arr.append(4);
//     arr.append(5);
//     arr.append(7);
//     arr.append(6);
//     arr.pretty_print();
//     arr.deleteAt(2);
//     arr.pretty_print();
//     arr.deleteAt(2);
//     arr.pretty_print();
//     std::cout << arr.get(2) << std::endl;
//     arr[2]=3;
//     std::cout << arr.get(2) << std::endl;

//     dynamic_array<int> *arr1 = new dynamic_array<int>;
//     arr1->append(3);
//     arr1->append(5);
//     arr1->append(4);
//     arr1->append(7);
//     arr1->append(6);
//     arr1->pretty_print();
//     arr1->deleteAt(2);
//     arr1->pretty_print();
//     arr1->deleteAt(2);
//     arr1->pretty_print();
//     std::cout << arr1->get(2) << std::endl;
//     delete arr1;
// }


// #include "dsunion.h"
// #include <iostream>
// int main(){
//     DSUnion* union1 = new DSUnion();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->parents->pretty_print();
//     union1->DS_find(1)->sell(0,2);
//     union1->DS_find(2)->sell(3,2);
//     union1->DS_union(1,2);
//     std::cout << "here we go:";
//     union1->parents->pretty_print();
//     delete union1;
// }


// #include "dsunion.h"
// #include <iostream>
// int main(){
//     DSUnion* union1 = new DSUnion();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->parents->pretty_print();
//     union1->DS_find(1)->sell(0,2);
//     union1->DS_find(1)->sell(0,2);
//     union1->DS_find(1)->sell(6,2);
//     union1->DS_find(3)->sell(8,6);
//     union1->DS_find(1)->sell(2,2);
//     union1->DS_find(2)->sell(2,2);
//     union1->DS_find(2)->sell(3,2);
//     std::cout << "id tree of 1:" << std::endl;
//     union1->DS_find(1)->id_tree->print();
//     std::cout << "ranked tree of 1:" << std::endl;
//     union1->DS_find(1)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "id tree of 2:" << std::endl;
//     union1->DS_find(2)->id_tree->print();
//     std::cout << "ranked tree of 2:" << std::endl;
//     union1->DS_find(2)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "id tree of 3:" << std::endl;
//     union1->DS_find(3)->id_tree->print();
//     std::cout << "ranked tree of 3:" << std::endl;
//     union1->DS_find(3)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     union1->DS_union(1,2);
//     std::cout << "after union:" << std::endl;
//     std::cout << "id tree of 2:" << std::endl;
//     union1->DS_find(2)->id_tree->print();
//     std::cout << "ranked tree of 2:" << std::endl;
//     union1->DS_find(2)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "here we go:" << std::endl;
//     union1->parents->pretty_print();
//     delete union1;
// }


// #include "dsunion.h"
// #include <iostream>
// int main(){
//     DSUnion* union1 = new DSUnion();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->parents->pretty_print();
//     union1->DS_find(1)->sell(0,2);
//     union1->DS_find(1)->sell(0,2);
//     union1->DS_find(1)->sell(6,2);
//     union1->DS_find(3)->sell(8,6);
//     union1->DS_find(1)->sell(2,2);
//     union1->DS_find(2)->sell(3,2);
//     union1->DS_find(2)->sell(5,2);
//     union1->DS_find(2)->sell(1,2);
//     union1->DS_find(2)->sell(3,2);
//     union1->DS_find(0)->sell(9,2);
//     union1->DS_find(2)->sell(1,2);
//     union1->DS_find(2)->sell(10,4);
//     std::cout << "id tree of 1:" << std::endl;
//     union1->DS_find(1)->id_tree->print();
//     std::cout << "ranked tree of 1:" << std::endl;
//     union1->DS_find(1)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "id tree of 2:" << std::endl;
//     union1->DS_find(2)->id_tree->print();
//     std::cout << "ranked tree of 2:" << std::endl;
//     union1->DS_find(2)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "id tree of 3:" << std::endl;
//     union1->DS_find(3)->id_tree->print();
//     std::cout << "ranked tree of 3:" << std::endl;
//     union1->DS_find(3)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     union1->DS_union(1,2);
//     std::cout << "after union:" << std::endl;
//     std::cout << "id tree of 2:" << std::endl;
//     union1->DS_find(2)->id_tree->print();
//     std::cout << "ranked tree of 2:" << std::endl;
//     union1->DS_find(2)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "here we go:" << std::endl;
//     union1->parents->pretty_print();
//     union1->DS_union(3,1);
//     std::cout << "after union 3,1:" << std::endl;
//     std::cout << "id tree of 3:" << std::endl;
//     union1->DS_find(2)->id_tree->print();
//     std::cout << "ranked tree of 3:" << std::endl;
//     union1->DS_find(2)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "here we go:" << std::endl;
//     union1->parents->pretty_print();
//     union1->DS_union(0,1);
//     std::cout << "after union 0,1:" << std::endl;
//     std::cout << "id tree of 0:" << std::endl;
//     union1->DS_find(2)->id_tree->print();
//     std::cout << "ranked tree of 0:" << std::endl;
//     union1->DS_find(2)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "here we go:" << std::endl;
//     union1->parents->pretty_print();
//     delete union1;
// }


// #include "library2.h"

// int main(){
//     void* ds = Init();
//     AddAgency(ds);
//     AddAgency(ds);
//     AddAgency(ds);
//     SellCar(ds, 0, 1, 1);
//     SellCar(ds, 1, 2, 2);
//     UniteAgencies(ds, 0, 1);
//     Quit(&ds);
//     return 0;
// }



// #define _CRTDBG_MAP_ALLOC
// #include "dsunion.h"
// #include <iostream>
// #include "crtdbg.h"
// int main(){
//     _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//     DSUnion* union1 = new DSUnion();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_find(0)->sell(1,1);
//     union1->DS_find(1)->sell(2,2);
//     union1->DS_find(1)->sell(-1,3);
//     union1->DS_find(2)->sell(3,3);
//     int i;
//     union1->DS_find(0)->getIthsold(0,&i);
//     union1->DS_find(0)->getIthsold(1,&i);
//     union1->DS_find(1)->getIthsold(0,&i);
//     union1->DS_find(1)->getIthsold(1,&i);
//     union1->DS_find(2)->getIthsold(0,&i);
//     union1->DS_find(2)->getIthsold(1,&i);
//     std::cout << "id tree of 1:" << std::endl;
//     union1->DS_find(1)->id_tree->print();
//     std::cout << "ranked tree of 1:" << std::endl;
//     union1->DS_find(1)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "id tree of 0:" << std::endl;
//     union1->DS_find(0)->id_tree->print();
//     std::cout << "ranked tree of 0:" << std::endl;
//     union1->DS_find(0)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     union1->DS_union(0,1);
//     std::cout << "after union:" << std::endl;
//     std::cout << "id tree of 1:" << std::endl;
//     union1->DS_find(1)->id_tree->print();
//     std::cout << "ranked tree of 1:" << std::endl;
//     union1->DS_find(1)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "here we go:" << std::endl;
//     union1->parents->pretty_print();
//     DSset* set0 = (*union1->sets)[0];
//     DSset* set1 = (*union1->sets)[1];
//     std::cout << "look" <<std::endl;
//     delete union1;
//     _CrtDumpMemoryLeaks();
//     return 0;
// }







// #include "dsunion.h"
// #include <iostream>
// int main(){
//     DSUnion* union1 = new DSUnion();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_find(0)->sell(1,1);
//     // union1->DS_find(1)->sell(2,2);
//     union1->DS_find(1)->sell(2,2);
//     union1->DS_find(1)->sell(-1,3);
//     union1->DS_find(2)->sell(3,3);
//     int i;
//     union1->DS_find(0)->getIthsold(0,&i);
//     union1->DS_find(0)->getIthsold(1,&i);
//     union1->DS_find(1)->getIthsold(0,&i);
//     union1->DS_find(1)->getIthsold(1,&i);
//     union1->DS_find(2)->getIthsold(0,&i);
//     union1->DS_find(2)->getIthsold(1,&i);
//     std::cout << "id tree of 1:" << std::endl;
//     union1->DS_find(1)->id_tree->print();
//     std::cout << "ranked tree of 1:" << std::endl;
//     union1->DS_find(1)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "id tree of 0:" << std::endl;
//     union1->DS_find(0)->id_tree->print();
//     std::cout << "ranked tree of 0:" << std::endl;
//     union1->DS_find(0)->ranked_tree->print();
//     std::cout << "---------------------" << std::endl;
//     // union1->DS_union(0,1);
//     // std::cout << "after union:" << std::endl;
//     // std::cout << "id tree of 1:" << std::endl;
//     // union1->DS_find(1)->id_tree->print();
//     // std::cout << "ranked tree of 1:" << std::endl;
//     // union1->DS_find(1)->ranked_tree->print();
//     // std::cout << "---------------------" << std::endl;
//     // std::cout << "here we go:" << std::endl;
//     // union1->parents->pretty_print();
//     // std::cout << "look" <<std::endl;
//     delete union1;
//     return 0;
// }


// non wrapped test of segel
// #include "dsunion.h"
// #include <iostream>
// int main(){
//     DSUnion* union1 = new DSUnion();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_find(0)->sell(1,1);
//     union1->DS_find(1)->sell(2,2);
//     union1->DS_find(1)->sell(-1,3);
//     union1->DS_find(2)->sell(3,3);
//     int i;
//     union1->DS_find(0)->getIthsold(0,&i);
//     union1->DS_find(0)->getIthsold(1,&i);
//     union1->DS_find(1)->getIthsold(0,&i);
//     union1->DS_find(1)->getIthsold(1,&i);
//     union1->DS_find(2)->getIthsold(0,&i);
//     union1->DS_find(2)->getIthsold(1,&i);
//     union1->DS_union(0,1);
//     union1->DS_union(0,2);
//     union1->DS_find(0)->getIthsold(0,&i);
//     union1->DS_find(0)->getIthsold(1,&i);
//     union1->DS_find(0)->getIthsold(2,&i);
//     union1->DS_find(0)->getIthsold(3,&i);
//     delete union1;
//     return 0;
// }



// non wrapped test
// #include "dsunion.h"
// #include <iostream>
// int main(){
//     DSUnion* union1 = new DSUnion();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_makeSet();
//     union1->DS_find(0)->sell(1,1);
//     union1->DS_find(0)->sell(2,1);
//     AVLTree<car>::Node* node1 = union1->DS_find(0)->id_tree->lowest;
//     delete union1;

//     return 0;
// }


// in5 nonsegel test
// #include "library2.h"
// #include "dsmanager.h"
// int main(){
//     void* ds = Init();
//     AddAgency(ds);
//     AddAgency(ds);
//     AddAgency(ds);
//     AddAgency(ds);
//     AddAgency(ds);
//     SellCar(ds, 0, 1, 1);
//     SellCar(ds, 1, 2, 2);
//     SellCar(ds, 2, 3, 3);
//     SellCar(ds, 2, 3, 3);
//     SellCar(ds, 2, 3, 3);
//     SellCar(ds, 3, 5, 2);
//     SellCar(ds, 4, 6, 7);
//     SellCar(ds, 5, 10, 30);
//     UniteAgencies(ds, 0, 1);
//     UniteAgencies(ds, 0, 2);
//     DSset* set1=((*((DSManager *)(ds))->sets)[0]);
//     UniteAgencies(ds, 3, 4);
//     DSset* set2=((*((DSManager *)(ds))->sets)[3]);
//     UniteAgencies(ds, 3, 5);
//     UniteAgencies(ds, 3, 0);
//     SellCar(ds, 4, 6, 2);
//     DSset* set=((DSManager *)(ds))->DS_find(4);
//     Quit(&ds);
//     return 0;
// }
