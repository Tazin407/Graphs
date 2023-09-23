#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int u; 
    int v; 
    int w;
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w= w;
    }
};

int main(){
   int n,e; cin>>n >>e;
   vector<Edge>g;
   while(e--){
    int a,b,w;
    cin>>a>>b>>w;
    Edge ed(a,b,w);
    g.push_back(ed);
   }

int dist[n+1];
for (int i = 1; i <=n; i++)
{
    dist[i]=INT_MAX;
}
dist[1]= 0;
for(int i=1; i<=n-1; i++){
   for(auto ed: g){
      int u= ed.u;
      int v= ed.v;
      int w= ed.w;
      if(dist[v]>dist[u]+w){
        dist[v]=dist[u]+w;
      }
   }
}
bool cycle=false;
for(auto ed: g){
      int u= ed.u;
      int v= ed.v;
      int w= ed.w;
      if(dist[v]>dist[u]+w){
        cycle =true;
        break;
        dist[v]=dist[u]+w;
      }
   }
if(cycle) cout<<"Cycle exists";
else{
    for(int i=1; i<=n;i++){
    cout<< "Distance of node "<<i<<" is "<<dist[i]<<endl;
}
}
   
return 0;
}