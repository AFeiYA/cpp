
#include <iostream>
#include "Tree.h"
#include "BST.h"

int main()
{
    BST t;
    t.Insert(10);
    t.Insert(5);
    t.Insert(20);
    t.Insert(8);
    t.Insert(30);
    //t.CreateTree();
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
    auto res = t.Search(5);
    if (res == nullptr) {
		std::cout << "Search: Not found" << std::endl;
    }
    else {
		std::cout << "Search: found" << res->data << std::endl;
	}

    return 0;

}
