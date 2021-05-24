//SPFA
const int INF=1e9;
vector<vector<pair<int,int>>>adj;

bool spfa(int s,vector<int>&d){
  int n=adj.size();
  d.assign(n,INF);
  vector<int>cnt(n,0);
  vector<bool>inqueue(n,false);
  queue<int>q;

  d[s]=0;
  q.push(s);
  inqueue[s]=1;
  while(!q.empty()){
    int v=q.front();
    q.pop();
    inqueue[v]=false;
    for(auto edge:adj[v]){
      int to=edge.first;
      int len=edg.second;

      if(d[v]+len<d[to]){
        d[to]=d[v]+len;
        if(!inqueue[to]){
          q.push(to);
          inqueue[to]=1;
          cnt[to]++;
          if(cnt[to]>n) return false; //negative cycle
        }
      }
    }
  }
  return true; //successful
}
