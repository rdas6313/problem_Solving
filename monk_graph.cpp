#include<stdio.h>
#include<vector>
#include<queue>
#define INF 100000000
#define Max 100005
#define MAXX 100005
using namespace std;
vector<int>vec[Max];
vector<int>svec[MAXX];
queue<int>q;
void bfs(int src,int dis[],int n){
	int vis[n+1],i;
	for(i=0;i<=n;i++){
		vis[i]=0;
	    dis[i]=-1;
	}
	vis[src]=1;
	dis[src]=0;
	q.push(src);
	while(!q.empty()){
		src = q.front();
		q.pop();
		for(i=0;i<vec[src].size();i++){
			if(!vis[vec[src][i]]){
				vis[vec[src][i]]=1;
				dis[vec[src][i]]=dis[src]+1;
				q.push(vec[src][i]);
			}
		}
	}
}
int main(){
	int n,m,i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	int start,end,dis1[n+1],dis2[n+1];
	scanf("%d%d",&start,&end);
	bfs(start,dis1,n);
	bfs(end,dis2,n);
	for(i=1;i<=n;i++){
		if(dis1[i]+dis2[i]==dis1[end] && i!=start && i!=end){
			svec[dis1[i]].push_back(i);
		}
	}
	int val = INF;
	for(i=0;i<MAXX;i++){
		if(svec[i].size()==1 && svec[i][0]<val){
			val = svec[i][0];
		}
	}
	if(val == INF)
		printf("-1\n");
	else
		printf("%d\n",val);
	return 0;
}