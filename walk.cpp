#include<stdio.h>
#define Max 1000
#include<vector>
using namespace std;
vector<int>vec[Max];
vector<int>rev[Max];
void init(int vis[],int n){
	int i;
	for(i=0;i<=n;i++){
		vis[i]=0;
	}
}
int dfs(int vis[],int stack[],int top,int src){
	vis[src]=1;
	int i;
	for(i=0;i<vec[src].size();i++){
		if(vis[vec[src][i]]==0){
			top=dfs(vis,stack,top,vec[src][i]);
		}
	}
	stack[++top]=src;
	return top;
}
int dfs2(int vis[],int src,int stack2[],int top){
	vis[src]=1;
	int i;
	for(i=0;i<rev[src].size();i++){
		if(vis[rev[src][i]]==0){
			top=dfs2(vis,rev[src][i],stack2,top);
		}
	}
	stack2[++top]=src;
	return top;
}
void del(){
	int i;
	for(i=0;i<Max;i++){
		vec[i].clear();
		rev[i].clear();
	}
}
int main(){
	int n,m,x,y,i,top=-1;
	scanf("%d%d",&n,&m);
	int vis[n+1],stack[n+1],out[n+1],stack2[n+1];
	init(vis,n);
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		rev[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		if(vis[i]==0){
			top=dfs(vis,stack,top,i);
		}
	}
	init(vis,n);
	init(out,n);
	init(stack2,n);
	int top2;
	while(top>=0){
		int node=stack[top--];
		top2=-1;
		if(vis[node]==0){
			top2=dfs2(vis,node,stack2,top2);
			if(top2>0){
				while(top2!=-1){
					int tmp=stack2[top2--];
					out[tmp]=1;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",out[i]);
	printf("\n");
	return 0;
}