vector<int>g[MAXN];
int vis[MAXN];

void DFS(int v){
  vis[v]=1;
  for(auto u:g[v]){
    if(!vis[u]) DFS(u);
  }
}
