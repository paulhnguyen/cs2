#include "tree.hh"

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
    tree_ptr_t t = new Tree;
    t->key_ = key;
    t->value_= value;
    t->left_ = left;
    t->right_ = right;

    return t;
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree)
{
    // assert(tree != nullptr); //make sure not null pointer, second line should do this
    if (!tree){ //if tree points to nothing, do nothing
        // std::cout << "invalid pointer! \n";
        return;
    }
    destroy_tree(tree->left_); // deleting subtrees
    tree->left_ = nullptr; //set to left to null to confirm its working when i check it
    destroy_tree(tree->right_);
    tree->right_ = nullptr; //set to null to confirm its working when i check it
    // std::cout << "current tree:" << tree << '\n';
    delete tree;
    // std::cout << "(deleted) tree:" << tree << '\n';


}





//////////////////////////////////////////////////////////////////////////////
// tree_ptr_t find_target(tree_ptr_t tree, key_type key){ // this function goes to left most node of tree, and wokrs it way up. thus, the left most value will be the encounter
//     // assert(tree);
//     // tree_ptr_t target = nullptr;
//     if (!tree){
//         return nullptr;
//     }
//     find_target(tree->left_, key);
//     if (tree->key_ == key){
//         std::cout << "Found! \n ";
//         target = tree;
//         return tree;
//     }
//     find_target(tree->right_, key);
//
//     // if (tree->key_ != key){
//     //     std::cout << "Key not in tree \n";
//     //     return nullptr; // what happens if key is not in the tree? then return null pointer
//     // }
//     return; //will return tree, but will be null if we didnt find key.. this doesnt work
// }
//
// std::string get_path(tree_ptr_t tree, tree_ptr_t target, std::string start_path){ //start path should be "", recursively gives path from tree to target
//     assert(tree);
//     std::string current_path = start_path;
//     std::cout << "getting path... \n";
//     get_path(tree->left_, target, current_path);
//     if (!target){
//         std::cout << "Key not found in current tree \n";
//         return "-";
//     }
//     if (tree == target){
//         return current_path;
//     }
//     if (tree->left_ == target){
//         std::cout << "going left... \n";
//         current_path = current_path + "L";
//     }
//     if (tree->right_ == target){
//         std::cout << "going right... \n";
//         current_path = current_path + "R";
//    }
//
//    get_path(tree->right_, target, current_path);
//    std::cout << current_path << "\n";
//    return current_path;
// }

//
// std::string
// path_to(tree_ptr_t tree, key_type key)
// {
//     tree_ptr_t target = find_target(tree, key); // finds target node
//     std::string start_path = ""; //empty string as starting path
//     std::string end_path = get_path(tree, target, start_path);
//     std::cout << "End Path: " << end_path << "\n";
//     return end_path;
// }


std::string
path_to(tree_ptr_t tree, key_type key)
{

    std::string path = ""; //empty string as starting path
    if (!tree){ //base case: if tree is null pt, just give dash
        // std::cout << "Tree given is null!";
        return "-";
    }
    if (tree->key_ == key){ // base case: if we have the right node, return path
        return path;
    }

    std::string left_path = path_to(tree->left_, key);

    std::string right_path = path_to(tree->right_, key);


    if (right_path != "-"){
        right_path = "R" + right_path;
        return right_path;
    }
    if (left_path != "-"){
        left_path = "L" + left_path;
        return left_path;
    }
    return "-";

}

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
    assert(tree);
    if (path == ""){ // if path is empty
        // std::cout << "Empty String; Tree: " << tree->key_ << "\n";
        return tree;
    }
    for(char c: path){
        // std::cout << c << "\n";
        if (c == 'L'){
            assert(tree->left_);
            tree = tree->left_;
            //std::cout << tree->value_ << "\n";
        }
        if (c == 'R'){
            assert(tree->right_);
            tree = tree->right_;
            //std::cout << tree->value_ << "\n";
        }
        if ((c != 'L') && (c != 'R')) {
            // std::cout << "DONE \n";
            return nullptr;
        }
    }
    // std::cout << tree->key_ << "\n";
    return tree;
}
