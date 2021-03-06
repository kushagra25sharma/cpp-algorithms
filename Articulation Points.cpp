#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v[200001];
int n;
int currTime = 0;

void dfs(int vis[], int parent, int ap[], int low[], int disc[], int vertex){
    vis[vertex] = 1;
    currTime += 1;
    low[vertex] = disc[vertex] = currTime; // first tinme when this node is discovered
    int child = 0;
    for(auto z : v[vertex]){// iterating over every vertex of the graph
        if(z == parent) continue;
        if(!vis[z]){
            child += 1;
            dfs(vis, vertex, ap, low, disc, z);
            low[vertex] = min(low[vertex], low[z]);// discovery time for earliest discovered
            // vertex that can that can be reached from any vertex in the subtree
            if(parent[vertex] != -1 && low[z] >= disc[vertex]){
                ap[vertex] = 1;
            }
        }
        else{// if vertex z is already visited
            low[vertex] = min(low[vertex], disc[z]);
        }
    }
    if(parent == -1 && child > 1){ // if it is the root
           ap[vertex] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int vis[n+1] = {0};
    int ap[n+1] = {0};
    int low[n+1] = {0};
    int disc[n+1] = {0};
    dfs(vis, -1, ap, low, disc, 0);
    for(int i=0;i<n;i++){
        if(ap[i] == 1){
            cout<<i<<" ";
        }
    }
    return 0;
}
