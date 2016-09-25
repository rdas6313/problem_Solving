#include<stdio.h>
#include<vector>
#include<algorithm>
#define Max 1005
using namespace std;
struct node{
	int u,v,w;
	bool operator<(const node &a)const{
		return (w==a.w)?1:(w<a.w);
	}
};
vector<struct node>vec;
vector<int>v[Max];
vector<int>weight[Max];
int store[Max][Max];
void init(int par[],int n){
	int i,j;
	for(i=0;i<=n;i++){
		par[i]=i;
		for(j=0;j<=n;j++){
			store[i][j]=0;
		}
	}
}
void destroy(){
	int i;
	for(i=0;i<Max;i++){
		v[i].clear();
		weight[i].clear();
	}
	vec.clear();
}
int find(int par[],int x){
	if(x==par[x])
		return x;
	par[x]=find(par,par[x]);
	return par[x];
}
void dfs(int src,int vis[],int root,int val){
	vis[src]=1;
	int i;
	store[root][src]=val;
	//printf("%d---%d--%d\n",root,src,val);
	for(i=0;i<v[src].size();i++){
		if(vis[v[src][i]]==0){
			dfs(v[src][i],vis,root,weight[src][i]+val);
		}
	}
}
void mst(int par[],int n){
	int c=1,i,x,y,j;
	for(i=0;i<vec.size();i++){
		x=find(par,vec[i].u);
		y=find(par,vec[i].v);
		if(x!=y){
			c++;
			par[y]=x;
			v[vec[i].u].push_back(vec[i].v);
			v[vec[i].v].push_back(vec[i].u);
			weight[vec[i].u].push_back(vec[i].w);
			weight[vec[i].v].push_back(vec[i].w);
		}
		if(c==n)
			break;
	}
	int vis[n+1];
	for(j=1;j<=n;j++){
		for(i=0;i<=n;i++)
			vis[i]=0;
		dfs(j,vis,j,0);
}
}
int main(){
	int t,k=1;
	scanf("%d",&t);
	while(k<=t){
		int n,e,q,i,x,y,z;
		scanf("%d%d%d",&n,&e,&q);
		int par[n+1];
		init(par,n);
		for(i=0;i<e;i++){
			scanf("%d%d%d",&x,&y,&z);
			struct node tmp;
			tmp.u=x;
			tmp.v=y;
			tmp.w=z;
			vec.push_back(tmp);
		}
		sort(vec.begin(),vec.end());
		mst(par,n);
	
		printf("Case: %d\n",k);
		for(i=0;i<q;i++){
			scanf("%d%d",&x,&y);
			printf("%d\n",store[x][y]);
		}
		k++;
		destroy();
	}
	return 0;
}