#include<stdio.h>
#include<vector>
#include<stack>
#define Max 500000
using namespace std;
vector<int>vec[Max];
vector<int>revgraph[Max];
stack<int>st;
vector<int>sccnodes;
void dfs(int src,int vis[]){
	vis[src]=1;
	int i;
	for(i=0;i<vec[src].size();i++){
		if(vis[vec[src][i]]==0){
			dfs(vec[src][i],vis);
		}
	}
	st.push(src);
}
void makescc(int src,int visited[],int node,int hash[]){
	visited[src]=1;
	hash[src]=node;
	sccnodes.push_back(src);
	int i;
	for(i=0;i<revgraph[src].size();i++){
		if(visited[revgraph[src][i]]==0){
			makescc(revgraph[src][i],visited,node,hash);
		}
	}
}
void dpdfs(int src,int vis[],int dp[],int hash[]){
	if(vis[src]==1 && dp[hash[src]]==-1){
		dp[hash[src]]=0;
		return;
	}
	vis[src]=1;
	if(dp[hash[src]]!=-1){
		return;
	}else{
		dpdfs(vec[src][0],vis,dp,hash);
		dp[hash[src]]=dp[hash[vec[src][0]]]+1;
		return;
	}
}
void clear(){
	int i;
	for(i=0;i<Max;i++){
		vec[i].clear();
		revgraph[i].clear();
	}
	sccnodes.clear();
}
int main(){
	int k=1,test;
	scanf("%d",&test);
	while(k<=test){
		int n,i,x,y,j;
		scanf("%d",&n);
		int vis[n+1],hash[n+1],visited[n+1];
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			revgraph[y].push_back(x);
			vis[i+1]=0;
			visited[i+1]=0;
		}
		for(i=1;i<=n;i++){
			if(vis[i]==0){
				dfs(i,vis);
			}
		}
		int node=1;
		while(!st.empty()){
			x = st.top();
			st.pop();
			if(visited[x]==0){
				makescc(x,visited,node,hash);
				node++;
			}
		}
		int dp[n+1];
		for(i=0;i<=n;i++){
			vis[i]=0;
			dp[i]=-1;
		}
		for(i=0;i<sccnodes.size();i++){
			if(vis[sccnodes[i]]==0){
				dpdfs(sccnodes[i],vis,dp,hash);
			}
		}
		int big=0,index;
		for(i=1;i<=n;i++){
			if(dp[hash[i]]>big){
				big = dp[hash[i]];
				index = i;
			}
		}
		printf("Case %d: %d\n",k,index);
		clear();
		k++;
	}
	return 0;
}