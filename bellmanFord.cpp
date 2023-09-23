#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//ekhane edge list use korchi, karon amar khali edge guli lagbe.
class Edge{
public: 
    int u; //source
    int v; //destination
    int w; // weight
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }

};

int main(){

    int n,e;
    cin>>n>>e;
    vector<Edge>g;
    while(e--){
        int a,b,w;
        cin>> a >>b>>w;
        Edge ed(a,b,w);
        g.push_back(ed);

    }
//shobar distance INF kore dibo.
int dist[n+1]; //n index pawar jnno n+1 size nilam
for (int i = 1; i <=n; i++)
{
    dist[i]=INT_MAX;
}
dist[1]=0;

//shob edge n-1 bar relax hobe
for (int i = 1; i < n-1; i++)
{
   for(auto ed: g){
       int u=ed.u;
       int v= ed.v;
       int w= ed.w;
//in case there are isolated components
       if(dist[u]<INT_MAX && dist[v]>dist[u]+w){
          dist[v]= dist[u]+w;
       }
   }
    
}
for(int i=1; i<=n;i++){
    cout<< "Distance of node "<<i<<" is "<<dist[i]<<endl;
}


   
return 0;
}