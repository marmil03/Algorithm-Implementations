//Strongly connected components (SCC) - Kosaraju O(N+M)

const int N=1e5+500;
vector<int>g[N],g_rev[N];
vector<bool>used;
vector<int>order,scc;

//Condesnation graph
vector<int>roots(N),root_nodes;
vector<int>g_scc[N];

void dfs1(int v){
  used[v]=1;
  for(auto u:g[v]){
    if(!used[u]) dfs1(u);
  }
  order.pb(v);
}

void dfs2(int v){
  used[v]=1;
  scc.pb(v);
  for(auto u:g_rev[v]){
    if(!used[u]) dfs2(u);
  }
}

void find_scc(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int u,v;
    g[u].pb(v);
    g_rev[v].pb(u);
  }
  used.assign(n,false);
  for(int i=0;i<n;i++){
    if(!used[i]) dfs1(i);
  }
  used.assign(n,false);
  reverse(order.begin(),order.end());
  for(auto v:order){
    if(!used[v]) {
      dfs2(v);
      //Adding node to condenastion graph
      int root=scc.front();
      for(auto u:scc) roots[u]=root;
      root_nodes.pb(root);
      scc.clear();
    }
  }
  //Condensation graph adj list
  for(int v=0;v<n;v++){
    for(auto u:g[v]){
      int root_v=roots[v];
      int root_u=roots[u];
      if(root_u!=root_v) g_scc[root_v].pb(root_u);
    }
  }
}
