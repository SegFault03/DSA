#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printGraph(map<T,vector<T>>&graph)
{
    cout<<"The graph:-"<<endl;
    for(typename map<T,vector<T>>::iterator key=graph.begin();key!=graph.end();key++)
    {
        cout<<"["<<key->first<<"]"<<"--->";
        if(key->second[0]==-1)
        {
            cout<<"None"<<endl;
            continue;
        }
        for(typename vector<T>::iterator value=key->second.begin();value!=key->second.end();value++)
        cout<<*value<<" ";
        cout<<endl;
    }
}

// template <typename T>
// void BFS(map<T,vector<T>>&graph)
// {
//     vector<T>vis,queue;
//     typename map<T,vector<T>>::iterator itr=graph.begin();

// }

int main()
{
    int input=0,r_node=0,n_nodes=0;
    std::string adjacent_nodes="",temp="";
    map<int,vector<int>>graph;
    std::cout<<"Enter a node followed by it's adjacent nodes in space separated format:-\nEnter -1 to terminate, if no adjacent nodes present enter -1\n";
    cin>>r_node;
    do
    {
        if(r_node==-1)
        break;
        getline(cin>>ws,adjacent_nodes);
        adjacent_nodes+=" ";
        temp="";
        for(auto word:adjacent_nodes)
        {
            if(temp=="-1")
            {
                graph[r_node].push_back(-1);
                break;
            }
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