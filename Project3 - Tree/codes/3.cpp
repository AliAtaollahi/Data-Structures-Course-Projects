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
};
int main()
{
    Node* root = NULL;
    int commandNum, command, num;
    cin >> commandNum;
    for (int i = 0; i < commandNum; i++)
    {
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
            Node* index = root;
            int diff,num;
            cin >> num;
            diff = abs(num - index->key);
            while (index!=NULL)
            {
                if (diff > abs(num - index->key)) diff = abs(num - index->key);
                if (num >= index->key) index = index->left;
                else index = index->right;
            }
            cout << diff << endl;
        }
    }
    return 0;
}