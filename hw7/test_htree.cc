/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>
#include <iostream>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  auto tree = make_shared<HTree>(126, 1);
  cout << "made a tree" << endl;
  return
    tree;
}

void test_htree(const HTree::tree_ptr_t root)
{
  assert(*(root->path_to(126)) == HTree::path_t({ }));
}

int main()
{
  cout<< "running program..." << endl;
  auto root = create_test_tree();
  cout << "returned the tree" << endl;
  test_htree(root);

  return 0;
}

