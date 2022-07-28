#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printGraph(map<T,vector<T>>&graph)
{
    cout<<"The graph:-"<<endl;
    for(typename map<int,vector<int>>::iterator key=graph.begin();key!=graph.end();key++)
    {
        cout<<"["<<key->first<<"]"<<"--->";
        for(typename vector<T>::iterator value=key->second.begin();value!=key->second.end();value++)
        cout<<*value<<" ";
        cout<<endl;
    }
}



int main()
{
    int input=0,r_node=0,n_nodes=0;
    std::string adjacent_nodes="",temp="";
    map<int,vector<int>>graph;
    std::cout<<"Enter a node followed by it's adjacent nodes in space separated format:-\nEnter -1 to terminate\n";
    cin>>r_node;
    do
    {
        if(r_node==-1)
        break;
        getline(cin>>ws,adjacent_nodes);
        adjacent_nodes+=" ";
        for(auto word:adjacent_nodes)
        {
            if(word==' ')
            {
                graph[r_node].push_back(stoi(temp));
                temp="";
            }
            else
            temp+=word;
        }
        cin>>r_node;
    }
    while(r_node!=-1);
    printGraph(graph);
}