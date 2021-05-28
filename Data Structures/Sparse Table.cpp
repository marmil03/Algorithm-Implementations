//Sparse table
const int MAXN=5e5;
const int K=25;
int st[MAXN][K+1];

vector<int>a(MAXN);
//RSQ
for(int i=0;i<n;i++) st[i][0]=a[i];

for(int j=1;j<=K;j++){
  for(int i=0;i+(1<<j)<=n;i++){
    st[i][j]=st[i][j-1]+st[i+(1<<(j-1))][j-1];
  }
}

ll sum=0;
int L,R; // some query
for(int j=Kj>=0;j--){
  if((1<<j)<=R-L+1){
    sum+=st[L][j];
    L+=(1<<j);
  }
}

//RMQ
int log[MAXN+1];
log[1]=0;
for(int i=2;i<=MAXN;i++) log[i]=log[i/2]+1;

for(int j=1;j<=K;j++){
  for(int i=0;i+(1<<j)<=n;i++){
    st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
  }
}

int j=log[R-L+1];
int minimum=min(st[i][j-1],st[R-(1<<j)+1][j]);
