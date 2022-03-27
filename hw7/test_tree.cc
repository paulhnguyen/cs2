/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "tree.hh"
#include <cassert>

// Create an elaborate example test tree:
tree_ptr_t create_test_tree()
{
  return
    create_tree(126, 1,
      create_tree(-5, 2,
        create_tree(12, 3),
        create_tree(6, 4,
          create_tree(9, 5))),
      create_tree(12, 6,
        create_tree(3, 7)));
}

void test_tree(const tree_ptr_t root)
{
  assert(path_to(root, 9) == "LRL");
  assert(path_to(root, 3) == "RL");
  assert(path_to(root, 12) == "LL");
  assert(path_to(root, 126) == "");
  assert(path_to(root, 54) == "-");

  assert(node_at(root, "")->key_ == 126);
  assert(node_at(root, "L")->key_ == -5);
  assert(node_at(root, "LL")->key_ == 12);
  assert(node_at(root, "LLL") == nullptr);
  assert(node_at(root, "LLR") == nullptr);
  assert(node_at(root, "LR")->key_ == 6);
  assert(node_at(root, "LRL")->key_ == 9);
  assert(node_at(root, "LLRL") == nullptr);
  assert(node_at(root, "LLRR") == nullptr);
  assert(node_at(root, "LRR") == nullptr);
  assert(node_at(root, "RR") == nullptr);
  assert(node_at(root, "x") == nullptr);
}

int main()
{
  auto root = create_test_tree();
  test_tree(root);
  destroy_tree(root);

  return 0;
}

