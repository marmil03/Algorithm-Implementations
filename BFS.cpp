//Time complexity
/*
Best-case:    O(|V|+|E|)
Average-case: O(|V|+|E|)
Worst-case:   O(|V|+|E|)
*/
//Memory-Complexity: O(|V|)

const int N=150000;
vector<int>g[N];
int vis[N];

void BFS(int root){
  deque<int>q;
  vis[root]=1;
  q.push_back(root);
  while(!q.empty()){
    int v=q.front();
    q.pop_front();
    for(auto u:g[v]){
      if(!vis[u]) {
        q.push_back(u);
        vis[u]=1;
      }
    }
  }
}
