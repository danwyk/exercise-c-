#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
  public:
    string name;
    vector<Node *> children;

    Node(){};
    Node(string str) { name = str; }

    vector<string> depthFirstSearch(vector<string> *array);

    Node *addChild(string name) {
      Node *child = new Node(name);
      children.push_back(child);
      
      return this;
    }
};


vector<string> Node::depthFirstSearch(vector<string> *array) {
  
  // Write your code here.
  array->push_back(this->name);

  for(int i = 0; i < this->children.size(); ++i) {
    
    children[i]->depthFirstSearch(array);

  } // for

      
  return *array;
} // depthFirstSearch


int main() {
  
  // Tree:
  //                        root
  //        child1        child2              child3
  // child1_1 child1_2   child2_1    child3_1 child3_2 child3_3

  Node *root = new Node("root");
  root->addChild("child1");
  root->addChild("child2");
  root->addChild("child3");

  root->children[0]->addChild("child1_1");
  root->children[0]->addChild("child1_2");
  root->children[1]->addChild("child2_1");
  root->children[2]->addChild("child3_1");
  root->children[2]->addChild("child3_2");
  root->children[2]->addChild("child3_3");

  vector<string> result;
  vector<string> *array_ptr= &result; 
  root->depthFirstSearch(array_ptr);


  cout << "Result is: \n{";
  for(auto &item : *array_ptr) {
    cout << item;

    if(item != array_ptr->back()) {
      cout << ", ";
    }
  } // for
  cout << "}\n";
} // main