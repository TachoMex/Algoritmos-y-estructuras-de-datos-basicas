#include <iostream>
using namespace std;

// A binary search tree node stores a value and the next two nodes, one to the left
// and another to the right.
class TreeNode{
public:
  int left;
  int right;
  int value;
};

const int N = 1000;

// an array long enough to store all the data.
TreeNode tree[N];

// Means that there is no tree at all
const int EMPTY_TREE = -1;

// a counter that stores which node is the next available.
int next_node = 0;

void tree_insert(int& node, int value){
  // inserting into an empty tree means to set the tree into the root.
  if(node == EMPTY_TREE){
    node = next_node ++;
    tree[node].value = value;
    tree[node].left = EMPTY_TREE;
    tree[node].right = EMPTY_TREE;
   }else{

    int current_node = node;
    int parent = node;
    // infinite loop
    while(true){
      // the values are stored by the following rule:
      //  - if the new value is leasser than the current_node value, send it to the left
      // - otherwise, send it to the right.
      int next_node = (tree[current_node].value > value ? tree[current_node].left : tree[current_node].right);
      if(next_node == EMPTY_TREE){
        // when the current node is an empty tree exit loop.
        break;
      }
      current_node = next_node;
      parent = current_node;
    }
    int new_node = next_node++;
    tree[new_node].value = value;
    tree[new_node].left = EMPTY_TREE;
    tree[new_node].right = EMPTY_TREE;
    // apply the rule to set the parent
    if(tree[parent].value > value){
      tree[parent].left = new_node;
    }else{
      tree[parent].right = new_node;
    }
  }
}

// finds the node that contains certain value, it return EMPTY_TREE if not found
int tree_find(int node, int value){
  int current_node;
  while(current_node  != EMPTY_TREE){
    current_node = (tree[current_node].value < value ? tree[current_node].left : tree[current_node].right);
    if(tree[current_node].value == value){
      return next_node;
    }
  }
  return EMPTY_TREE;
}

// prints the char c n times.
void print(int n, char c){
  for(int i = 0; i < n; i++){
    cout << c;
  }
}

// prints the tree on a visible way like a JSON format by using {}
void print_tree(int node, int indent = 0){
  if(node != EMPTY_TREE){
    print(indent, '-');
    cout << tree[node].value << '{' << endl;
    print_tree(tree[node].left, indent + 2);
    print_tree(tree[node].right, indent + 2);
    print(indent, '-');
    cout << '}' << endl;
  }
}

int main(){
  int t = EMPTY_TREE;
  int data[] = {3, 8, 2, 5, 6, 9, 10, 1};
  for(int i = 0; i < 8; i++){
    cout << data[i] << " added." << endl;
    tree_insert(t, data[i]);
    print_tree(t, 0);
    cout << "---------------------------------------------------------" << endl;
  }
  return 0;
}
