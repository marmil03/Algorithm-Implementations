//Prim-MST(Minimum Spanning Tree)
int n;
const int INF=1e9;
vector<vector<int>>g;

struct edge{
  int w=INF, to =-1;
};

//Dense graphs O(n^2)
void prim(){
  int ttl=0;
  vector<bool>selected(n,false);
  vector<edge>min_e(n);
  min_e[0].w=0;
  for(int i=0;i<n;i++){
    int v=-1;
    for(int j=0;j<n;j++){
      if(!selected[j] && (v==-1 || min_e[j].w<min_e[v].w)) v=j;
    }
    if(min_e[v].w==INF) {cout<<"NO MST!!!\n";return;}
    selected[v]=true;
    ttl+=min_e[v].w;
    for(int to=0;to<n;to++){
      if(g[v][to]<min_e[to].w) min_e[to]={g[v][to],v};
    }
  }
  cout<<ttl<<'\n';
}

//Sparse graphs O(m log n)
struct Edge{
  int w=INF,to=-1;
  bool operator<(Edge const& other) const{
    return mk(w,to) < mk(other.w,other.to);
  }
};

int n;
vector<vector<Edge>>g;

void prim(){
  int ttl=0;
  vector<Edge>min_e(n);
  min_e[0].w=0;
  set<Edge>s;
  s.insert({0,0});
  vector<bool>selected(n,false);
  for(int i=0;i<n;i++){
    if(s.empty()){
      cout<<"NO MST!!!\n";
      return 0;
    }
    int v=s.begin()->to;
    selected[v]=true;
    ttl+=s.begin()->w;
    s.erase(s.begin());
    for(Edge e:g[v]){
      if(!selected[e.to] && e.w<min_e[e.to].w){
        s.erase({min_e[e.to].w,e.to});
        min_e[e.to]={e.w,v};
        s.insert({e.w,e.to});
      }
    }
  }
  cout<<ttl<<'\n';
}
