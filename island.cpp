#include<stdio.h>
#include<vector>
#define Max 10002
using namespace std;
vector<int>vec[Max];
int bfs(int n){
	int i,src=1,vis[n+1],dis[n+1];
	for(i=0;i<=n;i++){
		vis[i]=0;
		dis[i]=-1;
	}
	vis[src]=1;
	int queue[2*n],rear=-1,front=-1;
	queue[++rear]=src;
	front++;
	while(front<=rear){
		int tmp=queue[front++];
		for(i=0;i<vec[tmp].size();i++){
			if(vis[vec[tmp][i]]==0){
				vis[vec[tmp][i]]=1;
				queue[++rear]=vec[tmp][i];
				dis[vec[tmp][i]]=dis[tmp]+1;
			}
		}

	}
	return dis[n];
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m,x,y;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		int tmp=bfs(n);
		
		printf("%d\n",tmp);
	}
	return 0;
}