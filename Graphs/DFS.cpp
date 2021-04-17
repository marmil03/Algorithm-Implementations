
//Time complexity
/*
Best-case:    O(|V|+|E|)??
Average-case: O(|V|+|E|)
Worst-case:   O(|V|+|E|)
*/
//Memory-Complexity: O(|V|)



const int MAXN=2e5+5;
vector<int>g[MAXN];
int vis[MAXN];

void DFS(int v){
  vis[v]=1;
  for(auto u:g[v]){
    if(!vis[u]) DFS(u);
  }
}
