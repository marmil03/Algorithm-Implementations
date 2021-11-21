struct LCA {
	vector<int> height, euler, first, segtree;
	vector<bool> visited;
	int n;

	LCA(vector<vector<int>>&g, int root = 0){
		n=g.size();
		height.resize(n);
		first.resize(n);
		euler.reserve(n);
		visited.assign(n,false);
		dfs(g,root);
		int m=euler.size();
		segtree.resize(m*4);
		build(1,0,m-1);
	}

	void dfs(vector<vector<int>>&g,int node,int h = 0){
		visited[node]=true;
		height[node]=h;
		first[node]=euler.size();
		for(auto u:g[node]){
			if(!visited[u]) {
				dfs(g,u,h+1);
				euler.pb(node);
			}
		}
	}

	void build(int node,int b,int e){
		if(b==e) segtree[node]=euler[b];
		else{
			int mid=(b+e)/2;
			build(node<<1,b,mid);
			build(node<<1 | 1,mid+1,e);
			int l=segtree[node<<1],r=segtree[node<<1|1];
			segtree[node]=(height[l]<height[r]?l:r);
		}
	}

	int query(int node,int b,int e,int l,int r){
		if(b>r || e<l) return -1;
		if(b>=l && en<=r) return segtree[node];
		int mid=(b+e)>>1;

		int left=query(node<<1,b,mid,l,r);
		int right=query(node<<1|1,mid+1,e,l,r);
		if(left==-1) return right;
		if(right==-1) return left;
		return height[left]<height[right]?left:right;
	}

	int lca(int u,int v){
		int left=first[u],right=first[v];
		if(left>right) swap(left,right);
		return query(1,0,euler.size()-1,left,right);
	}
};
