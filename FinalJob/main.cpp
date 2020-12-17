//
//  main.cpp
//  FinalJob
//
//  Created by Thomas Kristan on 15.12.20.
//
#include "Binary_tree.hpp"
#include <iostream>
using namespace std;

template<typename Type>
void BFS(Binary_tree<Type> *);

template<typename Type>
void DFS_PreOrder(Binary_tree<Type> *);

template<typename Type>
void DFS_PostOrder(Binary_tree<Type> *);

template<typename Type>
void DFS_InOrder(Binary_tree<Type> *);

int main(int argc, char** argv){
    cout << "MENU: \nCreate your binary tree: \n";
    cout << "Enter root: ";
    int val;
    cin >> val;
    Binary_tree<int> *tree = new Binary_tree<int>(val);
    int menu = 0;
    int input = 0;
    int index = 0;
    while(menu != 2){
        cout << "(0) insert child node, (1) choose different node, (2) tree is finished. ";
        cin >> menu;
        switch (menu) {
            case 0:
                cout << "Enter value: ";
                cin >> input;
                tree->insert(input);
                break;
            case 1:
                cout << "Choose the node you want to use: (0) parent, (1) left, (2) right): ";
                cin >> index;
                if(index==0)
                    tree = tree->parent();
                else if (index==1)
                    tree = tree->left();
                else if (index == 2)
                    tree = tree->right();
                else
                    tree = nullptr;
                break;
            case 2:
                cout << "Tree is finished. \n";
                while (!tree->is_root())
                    tree = tree->parent();
                BFS(tree);
                cout << "DFS - Preorder traversal: ";
                DFS_PreOrder(tree);
                cout << endl << "DFS - Inorder traversal: ";
                DFS_InOrder(tree);
                cout << endl << "DFS - Postorder traversal: ";
                DFS_PostOrder(tree);
                break;
            default:
                cout << "Invalid input.";
                break;
        }
    }
    cout << endl;
    
    return 0;
}

template<typename Type>
void BFS(Binary_tree<Type> *root)
{
    queue<Binary_tree<Type>*> tqueue;
    cout << "BFS: ";
    
    tqueue.push(root);
    
    while(tqueue.empty() == false)
    {
        Binary_tree<Type>* node = tqueue.front();
        cout << node->value() << " ";
        tqueue.pop();
        if (node->left() != nullptr)
            tqueue.push(node->left());
        if (node->right() != nullptr)
            tqueue.push(node->right());
    }
    cout << endl;
}

template<typename Type>
void DFS_PreOrder(Binary_tree<Type> *root)
{
    if(root == nullptr) return;
    cout << root->value() << " ";
    DFS_PreOrder(root->left());
    DFS_PreOrder(root->right());
}

template<typename Type>
void DFS_InOrder(Binary_tree<Type> *root)
{
    if (root == nullptr) return;
    DFS_InOrder(root->left());
    cout << root->value() << " ";
    DFS_InOrder(root->right());
}

template<typename Type>
void DFS_PostOrder(Binary_tree<Type> *root)
{
    if (root == nullptr)  return;
    DFS_PostOrder(root->left());
    DFS_PostOrder(root->right());
    cout << root->value() << " ";
}
