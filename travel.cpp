#include<stdio.h>
#define Max 1300
#define INF 1000000000
#include<queue>
using namespace std;
int road[Max][Max],rail[Max][Max],backroad[Max][Max],backrail[Max][Max];
struct NODE{
	int s,d;
	bool operator<(const NODE &a)const{
		return a.d<d;
	}
};
priority_queue< struct NODE >q;

int min(int a,int b){
	return (a<b)?a:b;
}
void road_dijkstra(int start,int n,int dis[],int road[][Max]){
	int i;
	for(i=0;i<=n;i++)
		dis[i] = INF;
	dis[start] = 0;
	struct NODE tmp;
	tmp.s = start;
	tmp.d = dis[start];
	q.push(tmp);
	while(!q.empty()){
		struct NODE temp = q.top();
		q.pop();
		for(i=1;i<=n;i++){
			if(i!=start && dis[temp.s]+road[temp.s][i]<dis[i]){
				dis[i] = dis[temp.s]+road[temp.s][i];
				struct NODE tmp;
				tmp.s = i;
				tmp.d = dis[i];
					q.push(tmp);
			}
		}	
	}

	
}
void rail_dijkstra(int start,int n,int dis[],int rail[][Max]){
	int i;
	for(i=0;i<=n;i++)
		dis[i] = INF;
	dis[start] = 0;
	struct NODE tmp;
	tmp.s = start;
	tmp.d = dis[start];
	q.push(tmp);
	while(!q.empty()){
		struct NODE temp = q.top();
		q.pop();
		for(i=1;i<=n;i++){
			if(i!=start && dis[temp.s]+rail[temp.s][i]<dis[i]){
				dis[i] = dis[temp.s]+rail[temp.s][i];
				struct NODE tmp;
				tmp.s = i;
				tmp.d = dis[i];
					q.push(tmp);
			}
		}	
	}

	
}
int main(){
	
	int n,i,j;
	scanf("%d",&n);
	int road_dis[n+1],rail_dis[n+1],end_road[n+1],end_rail[n+1];
	for(i=1;i<=n;i++){
		rail_dis[i] = 0;
		road_dis[i] = 0;
		end_rail[i] = 0;
		end_road[i] = 0;
	}

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&road[i][j]);
			backroad[j][i]=road[i][j];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&rail[i][j]);
			backrail[j][i]=rail[i][j];
		}
	int start,end;
	scanf("%d%d",&start,&end);
	
	road_dijkstra(start,n,road_dis,road);
	rail_dijkstra(start,n,rail_dis,rail);

	road_dijkstra(end,n,end_road,backroad);
	rail_dijkstra(end,n,end_rail,backrail);

	int min_distance = INF;
	for(i=1;i<=n;i++){
		if(i!=start && i!=end){
			min_distance = min(min_distance,min(road_dis[i]+end_rail[i],rail_dis[i]+end_road[i]));

		}
	}
	printf("%d\n",min_distance);
	return 0;
}