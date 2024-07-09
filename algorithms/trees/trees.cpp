
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

    return 0;

}
