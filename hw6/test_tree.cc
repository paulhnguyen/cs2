#include <iostream>
#include <string>

#include "tree.hh"
#include "tree.cc"
//////////////////////////////////////////////////////////////////////////////


int test_destroy_null(){
    std::cout << "testing destroying a null tree \n";
    destroy_tree(nullptr);
    std::cout << "nothing broken? \n";

    return 0;
}

int test_destroy_basic(tree_ptr_t tree){ //testing making a basic tree and destroying it
    tree_ptr_t tree4 = create_tree(4, 4, nullptr, nullptr);
    tree_ptr_t tree3 = create_tree(3, 3, nullptr, nullptr);
    tree_ptr_t tree2 = create_tree(2, 2, tree4, tree3);
    tree_ptr_t tree1 = create_tree(1, 1, tree2, nullptr);
    destroy_tree(tree1);
    //count the number of (deleted)'s to see if code works
    return 0;
}



int main(){
    tree_ptr_t tree7right = create_tree(7, 7, nullptr, nullptr);
    tree_ptr_t tree7 = create_tree(7, 7, nullptr, nullptr);
    tree_ptr_t tree6 = create_tree(6, 6, nullptr, nullptr);
    tree_ptr_t tree5 = create_tree(5, 5, tree7right, nullptr);
    tree_ptr_t tree4 = create_tree(4, 4, nullptr, nullptr);
    tree_ptr_t tree3 = create_tree(3, 3, tree6, tree7);
    tree_ptr_t tree2 = create_tree(2, 2, tree4, tree3);
    tree_ptr_t tree1 = create_tree(2, 1, tree2, tree5); //value of 1..

    // tree_ptr_t tree5 = create_tree(100, 100, nullptr, nullptr);


    // //testing node at function
    // std::cout << "Testing node at: \n";
    // // node_at(tree1, "LB"); // works for non-"L" "R" input
    // std::cout << "Should return 3: \n";
    // node_at(tree1, "LR");
    // std::cout << "\n";
    // std::cout << "Should return 1: \n";
    // node_at(tree1, ""); // will the node_at work for just the head?
    // std::cout << "\n";
    // std::cout << "Should return 4: \n";
    // node_at(tree1, "LL");
    // std::cout << "\n";
    // // std::cout << "What if too many L's?: \n";
    // // node_at(tree1, "LLLL");
    // // std::cout << "\n";
    // std::cout << "Should return 5: \n";
    // node_at(tree1, "R");
    // std::cout << "\n";
    // std::cout << "Should return 6: \n";
    // node_at(tree1, "LRL");
    // std::cout << "\n";
    // std::cout << "Should return 7: \n";
    // node_at(tree2, "RR");
    // std::cout << "\n";
    // std::cout << "Should return nullptr: \n";
    // node_at(tree2, "AB");
    // std::cout << "\n";


    // // testing find target function
    // std::cout << "Testing find_target: \n";
    // // find_target(tree1, 2);
    // // find_target(tree1, 100);
    // auto result = path_to(tree1, 3);
    // std::cout << result << "\n";

    // testing get_path function
    // get_path(tree1, tree5, "");

    // // testing path to function
    // std::cout << "Testing path_to: \n";
    // std::cout << "7: \n" ;
    // std::cout << path_to(tree7, 7)<< "\n";
    //
    // std::cout << "100: \n";
    // std::cout << path_to(tree1, 100)<< "\n";
    // std::cout << "1: \n";
    // std::cout << path_to(tree1, 1)<< "\n";
    // std::cout << "5: \n";
    // std::cout << path_to(tree1, 5)<< "\n";
    // std::cout << "7: \n";
    // std::cout << path_to(tree1, 7)<< "\n";
    // std::cout << "7 (from 2): \n";
    // std::cout << path_to(tree2, 7)<< "\n";
    // std::cout << "2 (from 2): \n";
    // std::cout << path_to(tree2, 2)<< "\n";



    // //testing destroying trees
    // std::cout << "Testing destroy_tree: \n";
    destroy_tree(tree1);


    // check if destroyed
    // node_at(tree1, "L");
    // tree_ptr_t tree2 = create_tree(3, 4, nullptr, nullptr);
    // tree_ptr_t tree1 = create_tree(1, 2, tree2, nullptr);
    // std::cout << "tree1 key:" << tree1->key_ << "\n";
    // std::cout << "tree1 value:" << tree1->value_ << "\n";
    // std::cout << "tree1 left:" << tree1->left_ << "\n";
    // std::cout << "tree1 right:" << tree1->right_ << "\n";


    // // trying to delete tree2
    // if (!tree2->left_) {
    //     std::cout << "tree2 left null! \n";
    // }
    // if (!tree2->right_) {
    //     std::cout << "tree2 right null! \n";
    // }
    //
    // std::cout << "tree2 exists? " << tree2 << "\n";
    // destroy_tree(tree2);
    //
    // std::cout << "tree2 destroyed \n";
    //
    // std::cout << "tree1 key:" << tree1->key_ << "\n";
    // std::cout << "tree1 value:" << tree1->value_ << "\n";
    // std::cout << "tree1 left key:" << tree1->left_->key_ << "\n";
    // std::cout << "tree1 right:" << tree1->right_ << "\n";
    //
    // std::cout << "tree2 exists? " << tree2 << "\n";

    //testing destroying null tree
    //test_destroy_null();

    return 0;
}
