/*
 * What if i don't want to make a global variable of
 * root so is there any other way  to display the
 * tree by using the same approach
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

static
bool constexpr logging { false };

template <typename T>
struct tnode {
  T data;
  tnode<T> * left;
  tnode<T> * right;

  std::string toString(void) const {
    std::ostringstream os;
    os <<  "\n[@"  << std::setw(14) << this
       << " : "    << std::setw( 5) << data
       << ", L: @" << std::setw(14) << left
       << ", R: @" << std::setw(14) << right
       << "]";
    return os.str();
  }
};

template <typename T>
void insertion(tnode<T> *&  ptr, const T val) {
  if (logging) {
    std::clog << "In function " << __func__ << "()\n"
              << "  arg 1: " << ptr << '\n'
              << "  arg 2: " << val << '\n';
  }
  static auto count { 0ul };
  if (ptr == nullptr) {
    ptr = new tnode<T>;
    if (logging) {
      std::clog << "    new tnode @" << ptr
                << " allocate count " << ++count
                << '\n';
    }
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
  if (logging) {
    std::clog << "In function " << __func__ << "()\n"
              << "  arg 1: " << val << '\n';
  }
  static tnode<T> * root = nullptr;
  if (logging) {
    std::clog << "    root: @" << root << '\n';
  }
  insertion(root, val);

  return root;
}

template <typename T>
void display(const tnode<T> * root) {
  if (logging) {
    std::clog << "In function " << __func__ << "()\n"
              << "  arg 1: " << root << '\n';
  }
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
  if (logging) {
    std::clog << "In function " << __func__ << "()\n"
              << "  arg 1: " << node << '\n';
  }
  static auto count { 0ul };
  if (node == nullptr) {
    return;
  }
  else {
    if (node->left != nullptr) {
      if (logging) {
        std::clog << "    L: chain  @" << node->left << '\n';
      }
      destroy(node->left);
    }
    if (node->right != nullptr) {
      if (logging) {
        std::clog << "    R: chain  @" << node->right << '\n';
      }
      destroy(node->right);
    }
    if (logging) {
      std::clog << "    R: delete @" << node
                << " delete count: " << ++count
                << '\n';
    }
    delete node;
  }
}

int main(int argc, char const * argv[]) {
  if (logging) {
    std::clog << "In function " << __func__ << "()\n"
              << "  arg 1: " << argc << '\n'
              << "  arg 2: " << argv << '\n';
  }
  std::cout << "Tree\n";

  tnode<int> * root = nullptr;

  root = insert( 20);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }
  display(root);
  std::cout << std::endl;

  root = insert(  5);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }
  display(root);
  std::cout << std::endl;

  root = insert( 67);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }
  display(root);
  std::cout << std::endl;

  root = insert(  7);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }
  display(root);
  std::cout << std::endl;

  root = insert(  8);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }
  display(root);
  std::cout << std::endl;

  root = insert(  5);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }
  display(root);
  std::cout << std::endl;

  root = insert(666);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }
  display(root);
  std::cout << std::endl;

  root = insert(  0);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }
  display(root);
  std::cout << std::endl;

  root = insert( -1);
  if (logging) {
    std::clog << "    " << __func__
              << " root @" << root << '\n';
  }

  display(root);
  std::cout << std::endl;

  destroy(root);

  return 0;
}
