
#include <iostream>

template <typename T>
struct tnode {
  T data;
  tnode<T> * left;
  tnode<T> * right;
};

template <typename T>
void insertion(tnode<T> * /*&*/ptr, const T val) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << ptr << '\n'
            << "  arg 2: " << val << '\n';
  if (ptr == NULL) {
    ptr = new tnode<T>;
    std::clog << "    new " << ptr << '\n';
    ptr->data = val;
    ptr->left = ptr->right = NULL;
  }
  else if (val < ptr->data) {
    insertion(ptr->left, val);
  }
  else {
    insertion(ptr->right, val);
  }
}

template <typename T>
void insert(const T val) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << val << '\n';
  static tnode<T> * root = NULL;
  insertion(root, val);
}

template <typename T>
void display(const tnode<T> * root) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << root << '\n';
  if (root == NULL) {
    return;
  }
  else {
    display(root->left);
    std::cout << root->data << ' ';
    display(root->right);
  }
}

int main(int argc, char const * argv[]) {
  std::clog << "In function " << __func__ << "()\n"
            << "  arg 1: " << argc << '\n'
            << "  arg 2: " << argv << '\n';
  std::cout << "Tree\n";

  insert(20);
  insert( 5);
  insert(67);
  insert( 7);
  insert( 8);
  insert( 5);

  return 0;
}