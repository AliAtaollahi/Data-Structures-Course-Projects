#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Node {
public:
    Node(int key_) { key = key_; }
    int key;
    Node* left;
    Node* right;
    void insert(int key_) {
        if (key_ >= key) {
            if (left == NULL) left = new Node(key_);
            else left->insert(key_);
        }
        else if (key_ < key) {
            if (right == NULL) right = new Node(key_);
            else right->insert(key_);
        }
    }
};
void printing(Node* n)
{
    if (n == NULL) return;
    cout << n->key << " ";
    if (n->left != NULL) printing(n->left);
    if (n->right != NULL)printing(n->right);
}
int main()
{
    Node* root = NULL;
    int commandNum, command, num;
    cin >> commandNum;
    for (int i = 0; i < commandNum; i++)
    {
       // printing(root);
       // cout << endl;
        cin >> command;
        if (command == 1) {
            cin >> num;
            Node** index = &root;
            if (root == NULL) {
                root = new Node(num);;
                continue;
            }
            else {
                while (*index != NULL)
                    if ((*index)->key > num) index = &(*index)->right;
                    else index = &(*index)->left;
                *index = new Node(num);
            }
        }
        else if (command == 2) {
            if (root->left == NULL && root->right == NULL) {
                cout << root->key << endl;
                delete root;
                root = NULL;
               // cout << 123123;
                continue;
            }
            Node** index = &root;
            Node** parrent = index;
            while ((*index)->right != NULL)
            {
                parrent = index;
                index = &(*index)->right;
            }
            cout << (*index)->key << endl;
            if ((*index)->left == NULL) {
                delete* index;
                (*parrent)->right = NULL;
            }
            else {
                // Node* temp = index;
                *index = (*index)->left;
               // cout << (parrent==index)<<" "<<123123<<endl<<endl;
                //(*parrent)->right = *index;
                // delete temp;
            }

        }
        else if (command == 3) {
            if (root->left == NULL && root->right == NULL) {
                cout << root->key << endl;
                delete root;
                root = NULL;
                continue;
            }
            Node** index = &root;
            Node** parrent = index;
            while ((*index)->left != NULL) {
                parrent = index;
                index = &(*index)->left;
            }
            cout << (*index)->key << endl;
            if ((*index)->right == NULL) {
                delete* index;
                (*parrent)->left = NULL;
            }
            else {
                //  Node* temp = index;
                *index = (*index)->right;
                //(*parrent)->left = *index;
                // delete temp;
            }

        }
    }
    return 0;
}