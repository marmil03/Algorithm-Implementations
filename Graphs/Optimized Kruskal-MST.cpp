//UNION-FIND - Kruskal
vector<int>parent,rank;

void make_set(int v){
  parent[v]=v;
  size[v]=1;
}

int find_set(int v){
  if(parent[v]==v) return v;
  return parent[v]=find_set(parent[v]);
}

void union_sets(int a,int b){
  a=find_set(a);
  b=find_set(b);
  if(a!=b){
    if(rank[a]<rank[b]) swap(a,b);
    parent[b]=a;
    if(rank[a]==rank[b]) rank[a]++;
  }
}

struct edge{
  int u,v,w;
  bool operator<(edge const& other){
    return w<other.w;
  }
};

int n;
vector<edge>edges;

void kruskal(){
  int cost=0;
  vector<edge>result;
  parent.resize(n),rank.resize(n);
  for(int i=0;i<n;i++) make_set(i);
  sort(edges.begin(),edges.end());
  for(edge e:edges){
    if(find_set(e.u)!=find_set(e.v)){
      cost+=e.w;
      result.push_back(e);
      union_sets(e.u,e.v);
    }
  }
}