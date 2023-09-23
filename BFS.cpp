#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;

    while (!q.empty())
    {
        int u = q.front();
    cout<<"visiting node "<<u<<endl;
        q.pop();

        for(int v: adj[u]){
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bfs(1);

    return 0;
}
