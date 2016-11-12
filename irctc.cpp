#include<stdio.h>
#include<vector>
#define Max 100002
#define INF 1000000000000000
#include<queue>
using namespace std;
vector<int>vec[Max];
vector<int>weight[Max];
struct NODE{
	long long int dis;
	int node;
	bool operator<(const struct NODE &a)const{
		return (dis==a.dis)?1:(dis<a.dis);
	}
};
long long int dijkstra(int start,int end,int n){
	long long int d[n+1];
	int i,vis[n+1];
	for(i=0;i<=n;i++){
		d[i]=INF;
		vis[i]=0;
	}
	priority_queue<struct NODE>q;
	d[start]=0;
	vis[start]=1;
	struct NODE tmp;
	tmp.node = start;
	tmp.dis = 0;
	q.push(tmp);
	while(!q.empty()){
		struct NODE tmp=q.top();
		q.pop();
		int temp=tmp.node;
		vis[temp]=1;
		for(i=0;i<vec[temp].size();i++){
			if(vis[vec[temp][i]]==1)
				continue;
			if(d[temp]+weight[temp][i]<d[vec[temp][i]]){
				d[vec[temp][i]]=d[temp]+weight[temp][i];
				struct NODE tmp;
				tmp.node=vec[temp][i];
				tmp.dis=d[vec[temp][i]];
				q.push(tmp);
			}
		}
	}
	return d[end];
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,k,i,x,y,z;
		scanf("%d%d",&n,&k);
		for(i=0;i<k;i++){
			scanf("%d%d%d",&x,&y,&z);
			vec[x].push_back(y);
			vec[y].push_back(x);
			weight[x].push_back(z);
			weight[y].push_back(z);
		}
		scanf("%d%d%d",&x,&y,&z);
		long long int distance=dijkstra(x,y,n);
		printf("%lld\n",distance);
		distance=dijkstra(z,y,n);
		printf("%lld\n",distance);
	
	}
	return 0;
}