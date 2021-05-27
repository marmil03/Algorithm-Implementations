//Kruskal-MST

struct edge{
  int u,v,w;
  bool operator<(edge const& other){
    return w<other.w;
  }
};

int n;
vector<edge>g;

void kruskal(){
  int cost=0;
  vector<int>tree_id(n);
  vector<edge>result;
  for(int i=0;i<n;i++) tree_id[i]=i;

  sort(g.begin(),g.end());

  for(edge e:g){
    if(tree_id[e.u]!=tree_id[e.v]){
      cost+=e.w;
      result.push_back(e);

      int old_id=tree_id[e.u],new_id=tree_id[e.v];
      for(int i=0;i<n;i++){
        if(tree_id[i]==old_id) tree_id[i]=new_id;
      }
    }
  }
  cout<<cost;
}
