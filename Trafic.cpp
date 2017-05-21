#include<stdio.h>
#include<vector>
#define Max 100002
#define INF 1000000000
#include<queue>
using namespace std;
struct NODE{
	int u,rtype,distance;
	bool operator<(const NODE &a)const{
		return (distance>a.distance);
	}
};
vector<int>vec[Max];
vector<int>type[Max];
vector<int>weight[Max];

int dijkstra(int src,int n,int d){
	priority_queue< struct NODE >q;
	int dis[n][11],i,j;
	for(i=0;i<n;i++)
		for(j=0;j<11;j++)
			dis[i][j]=INF;
	dis[src][0]=0;
	struct NODE tmp;
	tmp.u = src;
	tmp.rtype = 0;
	tmp.distance = 0;
	q.push(tmp);
	while(!q.empty()){
		struct NODE tmp = q.top();
		q.pop();
	//	printf("%d----%d------%d\n",tmp.u,tmp.rtype,tmp.distance);
		if(tmp.u==n-1)
			break;
		for(i=0;i<vec[tmp.u].size();i++){
			if(dis[tmp.u][tmp.rtype]+weight[tmp.u][i]<dis[vec[tmp.u][i]][tmp.rtype+type[tmp.u][i]] && tmp.rtype+type[tmp.u][i]<=d){
				dis[vec[tmp.u][i]][tmp.rtype+type[tmp.u][i]] = dis[tmp.u][tmp.rtype]+weight[tmp.u][i];
				struct NODE temp;
				temp.u = vec[tmp.u][i];
				temp.rtype = type[tmp.u][i]+tmp.rtype;
				temp.distance = dis[vec[tmp.u][i]][tmp.rtype+type[tmp.u][i]];
				
				q.push(temp); 
			}
		}
	}
	int min=INF;
	for(i=0;i<11;i++)
		if(dis[n-1][i]<min)
			min = dis[n-1][i];
	return min;
}
void clear(){
	int i;
	for(i=0;i<Max;i++){
		vec[i].clear();
		weight[i].clear();
		type[i].clear();
	}
}
int main(){
	int test,j=1;
	scanf("%d",&test);
	while(j<=test){
		int n,m,k,d,i,x,y,z;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			vec[x].push_back(y);
			weight[x].push_back(z);
			type[x].push_back(0);
		}
		for(i=0;i<k;i++){
			scanf("%d%d%d",&x,&y,&z);
			vec[x].push_back(y);
			weight[x].push_back(z);
			type[x].push_back(1);
		}
		int temp = dijkstra(0,n,d);
		printf("Case %d: ",j);
		if(temp!=INF)
			printf("%d\n",temp);
		else
			printf("Impossible\n");
		clear();
		j++;
	}
	return 0;
}