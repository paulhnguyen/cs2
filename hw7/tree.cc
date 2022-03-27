/*
 * Tree: A simple recursive data structure to hold keys and values.
 */

#include <cassert>
#include "tree.hh"

//////////////////////////////////////////////////////////////////////////////
// create_tree allocates space for a new tree node and fills it with the given
// data parameters. By default, the tree is a leaf, so its children point to
// nullptr, but you may override with actual pointers to other nodes.
tree_ptr_t
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
  tree_ptr_t tree = new Tree({ key, value, left, right });
  return tree;
}

//////////////////////////////////////////////////////////////////////////////
// Deallocate all space consumed by this tree and its children.
void
destroy_tree(tree_ptr_t tree)
{
  if (tree) {
    destroy_tree(tree->left_);
    destroy_tree(tree->right_);
    delete tree;
  }
}


//////////////////////////////////////////////////////////////////////////////
// path_to: return a string representing the path taken from a given tree root
// to a given key in the tree. For each left child taken along the path, the
// string contains an 'L' character, and 'R' for a right child, in order.
// So for example for the following tree (only keys depicted, values omitted):
/*
            126
           /   \
          /     \
        -5       12
        / \     /
      12   6    3
          /
         9
*/
// path_to(tree, 9) will return "LRL", path_to(tree, 3) will return "R", and
// path_to(126) will return "".
// If the key isn't found in the tree, path_to should return "-".
//
// If multiple matches to key exist in the tree, return the path to the
// leftmost match. For the tree above, path_to(tree, 12) returns "LL".
std::string
path_to(tree_ptr_t tree, key_type key)
{
  if (!tree) {
    return "-";
  }

  if (tree->key_ == key) {
    return "";
  }

  const auto left_res = path_to(tree->left_, key);
  if (left_res != "-") {
    return "L" + left_res;
  }
  const auto right_res = path_to(tree->right_, key);
  if (right_res == "-") {
    return "-";
  } else {
    return "R" + right_res;
  }
}

//////////////////////////////////////////////////////////////////////////////
// node_at: Follow a path from a given root node and return the node that is
// at the end of the path. For example, for the root of the tree above,
// node_at("LR") will return a pointer to the node whose key is 6.
// If the path leads to an invalid or empty child, or contains any character
// other than 'L' or 'R', return nullptr (don't crash)
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
  for (auto c : path) {
    if (!tree)         return nullptr; 
    if (c == 'L')      tree = tree->left_;
    else if (c == 'R') tree = tree->right_;
    else               return nullptr;
  }

  return tree;
}

