#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph{
    int v;
    vector<vector<int>> adjlist;

public:
    graph(int vertex):v(vertex){
        adjlist.resize(v);
    }

    void addedge(int node1,int node2,bool directed=true){
        adjlist[node1].push_back(node2);

        if(directed){
            adjlist[node2].push_back(node1);
        }
    }

    void addvertex(int vertex){
        adjlist.push_back({});
        v++;

    }

    void bfs(int startnode,vector<vector<int>> adjlist,vector<bool>& visit){
        queue<int> q;

        q.push(startnode);
        visit[startnode]=true;

        while(!q.empty()){
            int cur=q.front();
            q.pop();

            cout<<cur<<" ";

            for(auto adj:adjlist[cur]){
                if(!visit[adj]){
                    visit[adj]=true;
                    q.push(adj);
                }
            }
        }
    }

   void dfs(int currentnode, vector<vector<int>>& adjlist, vector<bool>& visit){
    visit[currentnode] = true;

    cout << currentnode << " ";

    for(auto it : adjlist[currentnode]){
        if(!visit[it]){
            dfs(it, adjlist, visit);
        }
    }
}

//  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         vector<bool> visited(n, 0);
//         vector<vector<int>>adj(n);
//         for(auto it:edges){
//           adj[it[0]].push_back(it[1]);
//           adj[it[1]].push_back(it[0]);

//         }
//     }
};

int main(){
graph g(5);

    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(1, 4);

    vector<bool> visit(5, false);

    vector<vector<int>> adj = {
        {1, 2},
        {0, 3, 4},
        {0},
        {1},
        {1}
    };

    g.bfs(0, adj, visit);

    return 0;
}