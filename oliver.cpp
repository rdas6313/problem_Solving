#include<stdio.h>
#include<vector>
#define Max 100001
using namespace std;
vector<int>vec[Max];
int t;
void dfs(int src,int start[],int end[],int vis[]){
	int i;
	t++;
	vis[src]=1;
	start[src]=t;
	for(i=0;i<vec[src].size();i++){
		if(vis[vec[src][i]]==0){
			dfs(vec[src][i],start,end,vis);
		}
	}
	t++;
	end[src]=t;
}
int check(int x,int y,int start[],int end[]){
	if(start[y]<start[x] && end[y]>end[x])
		return 1;
	return 0;
}
int main(){
	int n,x,y,i;
	t=1;
	scanf("%d",&n);
	int start[n+1],end[n+1],vis[n+1];
	for(i=0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
		start[i+1]=end[i+1]=vis[i+1]=0;
	}
	start[i+1]=end[i+1]=vis[i+1]=0;
	dfs(1,start,end,vis);
	int q,k;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d%d",&k,&x,&y);
		if(k){
			if(check(x,y,start,end)){
				printf("YES");
			}else
				printf("NO");
		}else{
			if(check(y,x,start,end)){
				printf("YES");
			}else
				printf("NO");
		}
		printf("\n");
	}
	return 0;
}