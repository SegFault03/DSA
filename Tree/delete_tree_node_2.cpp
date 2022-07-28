//ALTERNATIVE APPROACH TO DELETING A TREE NODE
//ALGORITHM:
//deleteNode(<Root Node>) returns the root node of the new tree
//1. Return NULL if node to be deleted is not found
//2. Search for the node to be deleted using normal searching techniques
//3. When found, replace the node with either:
//        a. The node with the maximum value of it's left subtree (As for such a node all the nodes of the right subtree of the deleted node will
//           still be greater)
//        b. The node with the minimum value of it's right subtree (As for such a node all the nodes of the left subtree of the deleted node will
//           still be smaller)

#include <bits/stdc++.h>
#include "tree.h"

using namespace std;

//Note that any methods using an object of Tree class that is not declared inside the Tree class declaration is automatically made static
//...and as such cannot be treated as a member class, meaning they cannot be called using objects (using the error -> operator)
//Such methods work similar to non-class methods

Tree* deleteNode(Tree *root, int val)
{
    if(root==nullptr)
    return nullptr;
    else
    {
        if(root->val>val)
        root->left=deleteNode(root->left,val);
        else if(root->val<val)
        root->right=deleteNode(root->right,val);
        else
        {
            if(root->left!=nullptr)
            {
                Tree *temp=root->left;
                Tree *trav=temp->right;
                if(trav==nullptr)
                {
                    temp->right=root->right;
                    root=temp;
                }
                else
                {
                    while(trav->right!=nullptr)
                    {
                        temp=trav;
                        trav=trav->right;
                    }
                    temp->right=trav->left;
                    root->val=trav->val;
                    trav->left=NULL;
                }
            }
            else if(root->right!=nullptr)
            {
                Tree *temp=root->right;
                Tree *trav=temp->left;
                if(trav==nullptr)
                {
                    temp->left=root->left;
                    root=temp;
                }
                else
                {
                    while(trav->left!=nullptr)
                    {
                        temp=trav;
                        trav=trav->left;
                    }
                    temp->left=trav->right;
                    root->val=trav->val;
                    trav->right=NULL;
                }
            }
            else
            root=nullptr;
        }
        return root;
    }
}

int main()
{
    vector<int>test={8,5,3,6,11,10,9,12};
    Tree *root=nullptr;
    for(int i:test)
    root=root->buildTree(i);
    cout<<"\n";
    root->preOrder();
    root=deleteNode(root,9);
    cout<<"The deletion:\n"<<endl;
    root->preOrder();
}
