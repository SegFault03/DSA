#include <bits/stdc++.h>
using namespace std;
//IMPLEMENTING ADJACENCY LIST REP OF A GRAPH

template <typename T>
void printGraph(map<T,vector<T>>&graph, T null_value=-1)
{
    cout<<"The graph:-"<<endl;
    for(typename map<T,vector<T>>::iterator key=graph.begin();key!=graph.end();key++)
    {
        cout<<"["<<key->first<<"]"<<"--->";
        if(key->second[0]==null_value)
        {
            cout<<"None"<<endl;
            continue;
        }
        for(typename vector<T>::iterator value=key->second.begin();value!=key->second.end();value++)
        cout<<*value<<" ";
        cout<<endl;
    }
}

template <typename T>
void BFS(map<T,vector<T>>&graph, T null_value)
{
    if(graph.size()==0)
    return;
    cout<<"The BFS results:"<<endl;
    T key;
    typename map<T,vector<T>>::iterator itr=graph.begin();
    vector<T>vis={itr->first},queue={itr->first};
    typename vector<T>::iterator val_itr;
    while(!queue.empty())
    {
        val_itr=queue.begin();
        key=*val_itr;
        queue.erase(val_itr);
        cout<<key<<" ";
        if(graph[key].at(0)!=null_value)
        {
            for(val_itr=graph[key].begin();val_itr!=graph[key].end();val_itr++)
            {
                if(find(vis.begin(),vis.end(),*val_itr)==vis.end())
                {
                    queue.push_back(*val_itr);
                    vis.push_back(*val_itr);
                }
            }
        }
    }
}

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
    printGraph(graph,-1);
    BFS(graph,-1);
}