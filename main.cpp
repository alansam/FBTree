/*
 * What if i don't want to make a global variable of
 * root so is there any other way  to display the
 * tree by using the same approach
 */

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
struct tnode {
  T data;
  tnode<T> * left;
  tnode<T> * right;

  std::string toString(void) const {
    std::ostringstream os;
    os <<  "\n[@"  << this
       << " : "    << data
       << ", L: @" << left
       << ", R: @" << right
       << "]";
    return os.str();
  }
};

template <typename T>
void insertion(tnode<T> *&  ptr, const T val) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << ptr << '\n'
            << "  arg 2: " << val << '\n';
  static auto count { 0ul };
  if (ptr == nullptr) {
    ptr = new tnode<T>;
    std::clog << "    new tnode @" << ptr
              << " allocate count " << ++count
              << '\n';
    ptr->data = val;
    ptr->left = ptr->right = nullptr;
  }
  else if (val < ptr->data) {
    insertion(ptr->left, val);
  }
  else {
    insertion(ptr->right, val);
  }
}

template <typename T>
tnode<T> * insert(const T val) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << val << '\n';
  static tnode<T> * root = nullptr;
  std::clog << "    root: @" << root << '\n';
  insertion(root, val);

  return root;
}

template <typename T>
void display(const tnode<T> * root) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << root << '\n';
  if (root == nullptr) {
    return;
  }
  else {
    display(root->left);
    std::cout << root->toString() << ' ';
    display(root->right);
  }
}


template <typename T>
void destroy(const tnode<T> * node) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << node << '\n';
  static auto count { 0ul };
  if (node == nullptr) {
    return;
  }
  else {
    if (node->left != nullptr) {
      std::clog << "    L: chain  @" << node->left << '\n';
      destroy(node->left);
    }
    if (node->right != nullptr) {
      std::clog << "    R: chain  @" << node->right << '\n';
      destroy(node->right);
    }
    std::clog << "    R: delete @" << node
              << " delete count: " << ++count
              << '\n';
    delete node;
  }
}

int main(int argc, char const * argv[]) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << argc << '\n'
            << "  arg 2: " << argv << '\n';
  std::cout << "Tree\n";

  tnode<int> * root = nullptr;

  root = insert(20);
  std::clog << "    " << __func__
            << " root @" << root << '\n';
  root = insert( 5);
  std::clog << "    " << __func__
            << " root @" << root << '\n';
  root = insert(67);
  std::clog << "    " << __func__
            << " root @" << root << '\n';
  root = insert( 7);
  std::clog << "    " << __func__
            << " root @" << root << '\n';
  root = insert( 8);
  std::clog << "    " << __func__
            << " root @" << root << '\n';
  root = insert( 5);
  std::clog << "    " << __func__
            << " root @" << root << '\n';

  display(root);
  std::cout << std::endl;

  destroy(root);

  return 0;
}
