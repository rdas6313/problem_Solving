#include<stdio.h>
#include<vector>
#include<stdlib.h>
#define Max 100002
using namespace std;
vector<int>vec[Max];
int b;
void bridge(int t,int par[],int vis[],int low[],int dis[],int node[],int src,int n,int p){
	int i;
	t+=1;
	vis[src]=1;
	dis[src]=t;
	low[src]=t;
	node[src]=1;
	for(i=0;i<vec[src].size();i++){
		int tmp=vec[src][i];
		if(par[src]==tmp)
			continue;
		if(vis[tmp]!=1){
			par[tmp]=src;
			bridge(t,par,vis,low,dis,node,tmp,n,p);
			node[src]+=node[tmp];
			int par_node= (n-node[tmp])-node[tmp];
			par_node=abs(par_node);
			low[src]=(low[src]>low[tmp])?low[tmp]:low[src];
			if(dis[src]<low[tmp] && par_node<p){
				b++;
			}
		}else{
			low[src]=(low[src]>dis[tmp])?dis[tmp]:low[src];
			
		}
	}

}
int dfs(int vis[],int src){
	vis[src]=1;
	int node_no=1;
	int i;
	for(i=0;i<vec[src].size();i++){
		if(vis[vec[src][i]]==0){
			node_no+=dfs(vis,vec[src][i]);
		}
	}
	return node_no;
}
int main(){
	int n,m,p,x,y,i;
	scanf("%d%d%d",&n,&m,&p);
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	int t=0,par[n+1],vis[n+1],low[n+1],dis[n+1],node[n+1],visited[n+1];
	for(i=0;i<=n;i++){
		par[i]=0,vis[i]=0,low[i]=0,node[i]=visited[i]=0;
		
	}
	b=0;
	for(i=1;i<=n;i++){
		if(visited[i]==0){
			int nn=dfs(visited,i);
			bridge(t,par,vis,low,dis,node,i,nn,p);	
		}
	}
	
	
	printf("%d\n",b);
	return 0;
}