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