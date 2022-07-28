//Deleting a node from a binary tree
//Algo:
//Search for the node first, if not found return nullptr
//If found, store the preorder format of it's children and use them to build a tree
//Return the tree to the parent node, and reassign root->left or right accordingly

#include <bits/stdc++.h>
#include "tree.h"

using namespace std;

void getArray(Tree *root, vector <int> *array)
{
    if (root == NULL)
        return;
    array->push_back(root->val);
    getArray(root->left, array);
    getArray(root->right, array);
}

Tree* buildTreefromArray(vector <int> *array)
{
    if(array->size() == 0)
        return NULL;
    else
    {
        Tree *root=nullptr;
        for(int i=2;i<array->size();i++)
        root=root->buildTree(array->at(i));
        return root;
    }
}

Tree* deleteNode(Tree *root,int val)
{
    if(root==nullptr) return nullptr;
    else
    {
        if(root->val>val) 
        {
            Tree* temp = deleteNode(root->left,val);
            root->left=temp;
            return root;
        }
        else if(root->val<val)
        {
            Tree* temp = deleteNode(root->right,val);
            root->right=temp;
            return root;
        }
        else
        {
            vector <int> array={0};
            getArray(root,&array);
            return(buildTreefromArray(&array));
        }
    }
}

int main()
{
    vector <int> array={12,14,6,4,10,11,5,2,1,0,8,7,9};
    Tree *root=nullptr;
    for(int i:array)
    root=root->buildTree(i);
    root->preOrder();
    cout<<"\nTree after deletion\n";
    root=deleteNode(root,12);
    root->preOrder();
}