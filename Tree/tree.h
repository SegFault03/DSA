#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:

    int val;
    Tree *left;
    Tree *right;

public:

    //class constructor called when any object or pointer is created without any parameter.
    Tree()                          
    {
        val=0;
        left=nullptr;
        right=nullptr;
    }

     //class constructor called when an object or pointer is called while passing an argument (val). 
    Tree(int val)                  
    {
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }

    //builds a Binary Tree taking (int) value as an argument and returns the root to the tree built. 
    Tree* buildTree(int val)
    {
        if(this==nullptr)
        {
            Tree *temp = new Tree(val);
            return temp;
        }
        else
        {
            Tree *temp=nullptr;
            if(this->val>val)
            {
                temp=this->left->buildTree(val);
                this->left=temp;
            }
            else
            {
                temp=this->right->buildTree(val);
                this->right=temp;
            }
            return this;
        }
    }
    
    //RECURSIVE DFS PREORDER
    void preOrder()     
    {
        if(this!=nullptr)
        {
            cout<<this->val<<",";
            this->left->preOrder();
            this->right->preOrder();
        }
    }
    
    //non-recursive DFS search
    void DFS()          
    {
        cout<<"Printing the Tree in DFS fashion:"<<endl;
        Tree *temp=nullptr;
        vector<Tree*>stack;     //Using a container (vector) to store pointers to Tree objects (Container stores Tree* and behaves as a stack)
        stack.push_back(this);
        while (!stack.empty())
        {
            temp=stack[stack.size()-1];     //STACK [.....]<-INSERT/REMOVE. pop_back() doesn't return anything, so retreiving the last element must be done
                                            //manually
            stack.pop_back();               //pop_back() only removes the last element
            cout<<temp->val<<" ";
            if(temp->left!=nullptr)
            stack.push_back(temp->left);
            if(temp->right!=nullptr)
            stack.push_back(temp->right);
        }
    }

    //non-recursive BFS search
    void BFS()
    {
        cout<<"Printing the Tree in BFS fashion:"<<endl;
        Tree *temp=nullptr;
        vector<Tree*>queue;                  //Using a container (vector) to store pointers to Tree objects (Container stores Tree* and behaves as a queue)
        queue.push_back(this);
        while (queue.size()>0)
        {
            temp=queue[0];                  //REMOVE->QUEUE[.....]<-INSERT
            vector<Tree*>::iterator i=queue.begin();       //initializing an iterator that points to the first element. begin() returns a pointer to the 
                                            //first element.
            queue.erase(i);                  //erase(<iterator>) removes an element at the position where the iterator is pointing, in this case its queue[0]
            cout<<temp->val<<" ";
            if(temp->left!=nullptr)
            queue.push_back(temp->left);
            if(temp->right!=nullptr)
            queue.push_back(temp->right);
        }  
    }    
};

//DRIVER FUNCTION
Tree* getInput()
{
    Tree *root=nullptr;
    int c=0;
    vector<int>tree_elements;
    cout<<"Enter elements separated by space, enter 0 to terminate: ";
    cin>>c;
    do
    {
        tree_elements.push_back(c);
        cin>>c;
    }while(c!=0);
    for(int i: tree_elements)
    root=root->buildTree(i);
    root->DFS();cout<<endl;
    return(root);
}