//Kuhn's algorithm for bipartite graph matching O(V*E)
int n,k;
vector<vector<int>>g;
vector<int>mt;
vector<bool>used;

bool try_kuhn(int v){
  if(used[v]) return false;
  used[v]=true;
  for(int to:g[v]){
    if(mt[to]==-1 || try_kuhn(mt[to])) {
      mt[to]=v;
      return true;
    }
  }
  return false;
}

int main(){
  //..reading the graph ...
  mt.assign(k,-1);
  vector<bool>used1(n,false);
  for(int v=0;v<n;++v){
    for(int to:g[v]){
      if(mt[to]==-1){
        mt[to]=v;
        used1[v]=true;
        break;
      }
    }
  }
  for(int v=0;v<n;v++){
    if(used1[v]) continue;
    used.assing(n,false);
    try_kuhn(v);
  }
}
