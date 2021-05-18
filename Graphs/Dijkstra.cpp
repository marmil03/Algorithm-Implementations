//Priority Queue implementation


// mp[{u,v}]<-weight is stored in the map

//prints the path from source to target
void print(ll x){
  if(x!=1) print(prevv[x]);
  cout<<x<<' ';
}

void Dijkstra_PriQ(int src){
  priority_queue<ll,vector<ll>>q;
  q.push(src);
  dist[1]=0;
  while(!q.empty()){
    int v=q.top();
    q.pop();
    for(auto u:g[v]){
      if(dist[u]>dist[v]+mp[{u,v}]){
        prevv[u]=v;
        dist[u]=dist[v]+mp[{u,v}];
        q.push(u);
      }
    }
  }
  if(dist[n]==INF) {cout<<"-1";return;}
  print(n);
}
