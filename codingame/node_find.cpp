using namespace std;

/*
A tree is composed of nodes which follow these rules:
A node holds a value corresponding to an integer.
Except the root node of the tree, a node is always referenced by only one other node.
A node has no more than two children. They are called left child and right child.
If a node has no right or left child, the corresponding reference is NULL.
All the descendants to the left of a node are smaller than the node and all the descendants to the right of the node are greater than the node.
Here is an example of such a tree (the root node holds the integer 9):
 


Fig. 1
 

To simplify things, we combine everything into a single class named Node.
The height of the tree is between 0 and 300 000 nodes (the height of a tree is the length of the path from the root to the deepest node in the tree).
Question: Implement a new Node's method named find(int v) which returns the node holding the value of v. If the node doesn't exist then find should return NULL.

Important note: Try to save memory (RAM) space.

To test your solution you can use two examples of tree:

The variable small corresponds to the root node of the tree from Fig. 1.
The variable large corresponds to the root node of a tree of height 300 000 nodes. The deepest node holds 0.
*/
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    
    //! This method returns a pointer to the node with the given​​​​​​‌​‌​​​‌​​​​‌‌‌​‌‌‌‌​‌‌​‌​ value.
    Node* find(int v);
};

Node* Node::find(int v)
{
    Node* current = this;
    while(current != nullptr) {
        if(v == current->value) {
            break;
        } else if(v < current->value) {
            // Left branch
            current = current->left;
        } else {
            // Right branch
            current = current->right;
        }
    }
    return current;
}