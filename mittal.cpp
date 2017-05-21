#include<stdio.h>
#define Max 10004
#include<vector>
#include<queue>
#define INF 10000000
using namespace std;
vector<int>vec[Max];
vector<int>weight[Max];
priority_queue< pair<int,int> >q;
void dijkstra(int src,int dis[]){
	dis[src]=0;
	int i;
	q.push(make_pair(src,dis[src]));
	while(!q.empty()){
		src = q.top().first;
		q.pop();
		for(i=0;i<vec[src].size();i++){
			if(dis[src]+weight[src][i]<dis[vec[src][i]]){
				dis[vec[src][i]]=dis[src]+weight[src][i];
				q.push(make_pair(vec[src][i],dis[vec[src][i]]));
			}
		}
	}
}
void clear(){
	int i;
	for(i=0;i<Max;i++){
		vec[i].clear();
		weight[i].clear();
	}

}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m;
		scanf("%d%d",&n,&m);
		int i,x,y,z;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			vec[x].push_back(y);
			vec[y].push_back(x);
			weight[x].push_back(z);
			weight[y].push_back(z);
		}
		int dis[n+1];
		for(i=0;i<=n;i++)
			dis[i]=INF;
		dijkstra(1,dis);
		int q,tmp;
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&x,&z);
			tmp = dis[x]*2;
			if(tmp<z){
				printf("%d\n",z-tmp);
			}else{
				printf("0\n");
			}
		}
		clear();
	}
	return 0;
}