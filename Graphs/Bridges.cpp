//Finding Bridges in O(N+M)
int n;
const int N=1e5+10;
vector<int>g[N];
vector<int>vis(N,0),tin(N,-1),low(N,-1);
int timer=0;

void dfs(int v,int p=-1){
  vis[v]=1;
  tin[v]=low[v]=timer++;
  for(auto u:g[v]){
    if(u==v) continue;
    if(vis[u]) low[u]=min(low[v],tin[u]);
    else{
      dfs(u,v);
      low[v]=min(low[v],low[u]);
      if(low[u]>tin[v]){
        //It is a bridge, do something
      }
    }
  }
}
