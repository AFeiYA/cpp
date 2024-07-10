
#include <iostream>
#include "Tree.h"

int main()
{
    Tree t;
    t.CreateTree();
    std::cout << "Preorder: ";
    t.Preorder();
    std::cout << std::endl;
    std::cout << "Inorder: ";
    t.Inorder();
    std::cout << std::endl;
    std::cout << "Postorder: ";
    t.Postorder();
    std::cout << std::endl;
    std::cout << "Levelorder: ";
    t.Levelorder();
    std::cout << std::endl;
    std::cout << "Height: " << t.Height() << std::endl;
    std::cout << "Count: " << t.Count() << std::endl;
    std::cout << "CountLeaf: " << t.CountLeaf() << std::endl;
    std::cout << "CountNonLeaf: " << t.CountNonLeaf() << std::endl;
    std::cout << "CountDegree2: " << t.CountDegree2() << std::endl;
    std::cout << "CountDegree1: " << t.CountDegree1() << std::endl;
    return 0;

}
