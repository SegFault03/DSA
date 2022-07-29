//IMPLEMENTING A GRAPH USING ADJACENCY LIST
#include <bits/stdc++.h>
using namespace std;


//printGraph(<graph-name>,<null-value>) is used for printing any graph, where null-value is the value which keys having no values 
//are assigned to. Used for checking purposes. The default null-value is -1.
template <typename T>           
void printGraph(map<T,vector<T>>&graph, T null_value=-1)        
{
    cout<<"The graph:-"<<endl;
    for(typename map<T,vector<T>>::iterator key=graph.begin();key!=graph.end();key++)   //typename is required when declaring an 
    //iterator using a template variable
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

/*BFS implementation. BFS(<vector-name>,<null-value>) is used for traversing any graph, 
where null-value is the value which keys having no values have.*/
template <typename T>                          
void BFS(map<T,vector<T>>&graph, T null_value)
{
     //redeclaration of templates is required for using templates in more than one functions
    if(graph.size()==0)     //if graph has no keys
    return;
    cout<<"The BFS results:"<<endl;
    T key;
    typename map<T,vector<T>>::iterator itr=graph.begin();
    vector<T>vis={itr->first},queue={itr->first};       //vis is used for storing the visited nodes, queue is used 
    //for storing the nodes to be visited
    typename vector<T>::iterator val_itr;
    while(!queue.empty())
    {
        val_itr=queue.begin();
        key=*val_itr;
        queue.erase(val_itr);
        cout<<key<<" ";
        if(graph[key].at(0)!=null_value)                //if key has values
        {
            for(val_itr=graph[key].begin();val_itr!=graph[key].end();val_itr++)
            {
                if(find(vis.begin(),vis.end(),*val_itr)==vis.end())         //find(<vector>.begin,<vector>.end,item_to_be_Searched) 
                //is used for checking if the value is already present in the vector. If not present, it returns the end() iterator.
                //else it returns a reference to the position where the item is
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