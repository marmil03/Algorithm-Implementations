struct edge{
  int a,b,cost;
};

int n,m,v;
vector<edge>g;
const int INF=1e6;


//Classic
void Bellman_Ford(){
  vector<int>dist(n,INF);
  dist[v]=0;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m;j++){
      if(dist[g[j].a]<INF){
        dist[g[j].b]=min(dist[g[j].b],dist[g[j].a]+g[j].cost);
      }
    }
  }
}

//Better Implementation
void Bellman_Ford(){
  vector<int>dist(n,INF);
  dist[v]=0;
  while(true){
    bool any=false;
    for(int j=0;j<m;j++){
      if(dist[g[j].a]<INF){
        if(dist[g[j].b]>dist[g[j].a]+g[j].cost){
          dist[g[j].b]=dist[g[j].a]+g[j].cost;
          any=true;
        }
      }
    }
    if(!any) break;
  }
}

//With Negative cycles
void Bellman_Ford(){
  vector<int>dist(n,INF);
  dist[v]=0;
  int x;
  for(int i=0;i<n;i++){
    x=-1;
    for(int j=0;j<m;j++){
      if(dist[g[j].a]<INF){
        if(dist[g[j].b]>dist[g[j].a]+g[j].cost){
          dist[g[j].b]=max(-INF,dist[g[j].a]+g[j].cost);
          x=e[j].b;
          any=true;
        }
      }
    }
  }
  if(x==-1) cout<<"No negative cycle";
  else {} //...
}
