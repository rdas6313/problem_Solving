#include<stdio.h>
#include<vector>
#define Max 100001
using namespace std;
vector<int>vec[Max];
vector<int>rev[Max];
int dfs(int vis[],int stack[],int top,int src){
	int i;
	vis[src]=1;
	for(i=0;i<vec[src].size();i++){
		if(vis[vec[src][i]]==0){
			top=dfs(vis,stack,top,vec[src][i]);
		}
	}
	stack[++top]=src;
	return top;
}
int dfs2(int vis[],int src,int top2){
	int i;
	vis[src]=1;
	for(i=0;i<rev[src].size();i++){
		if(vis[rev[src][i]]==0){
			top2=dfs2(vis,rev[src][i],top2);
		}
	}
	top2++;
	return top2;
}
void init(int vis[],int n){
	int i;
	for(i=0;i<n;i++)
		vis[i]=0;
}
void destroy(){
	int i;
	for(i=0;i<Max;i++){
		vec[i].clear();
		rev[i].clear();
	}
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m,i,x,y,top=-1,top2=0,mark=0;
		scanf("%d%d",&n,&m);
		int vis[n],stack[n];
		init(vis,n);
		for(i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			rev[y].push_back(x);
		}
		for(i=0;i<n;i++){
			if(vis[i]==0){
				top=dfs(vis,stack,top,i);
			}
		}
		init(vis,n);
		while(top!=-1){
			int tmp=stack[top--];
			top2=0;
			if(vis[tmp]==0){
				top2=dfs2(vis,tmp,top2);
				if(top2>1)
					mark++;
			}
		}
		printf("%d\n",mark);
		destroy();		
	}
	return 0;
}