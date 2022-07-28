#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int main()
{
    vector<int> array={5,1,2,10,3,9,7};
    Tree *root=nullptr;
    for(int i:array)
    root=root->buildTree(i);
    root->preOrder();
}