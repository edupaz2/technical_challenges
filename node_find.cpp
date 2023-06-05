using namespace std;

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