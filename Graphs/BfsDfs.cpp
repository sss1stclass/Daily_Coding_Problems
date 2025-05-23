#include <bits/stdc++.h>
using namespace std;


    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[5] = {0};
        vis[0]=1;
        vector<int>bfs;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;


    }

void dfs(int node, vector<int>&ans, int vis[], vector<int> adj[]) {
        vis[node]=1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, ans, vis, adj);
            }
        }
}

    void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector <int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);
//    vector <int> ans = bfsOfGraph(5, adj);
vector<int>ans;
int start = 0;
int vis[5]={0};
dfs(start, ans, vis, adj);
    printAns(ans);

    return 0;
}