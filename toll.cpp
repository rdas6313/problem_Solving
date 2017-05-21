#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#define Max 10005
#define INF 1000000000
using namespace std;
struct node{
	int u,w,max;
	bool operator<(const node &a)const{
		return w<a.w;
	}
};
vector<int>vec[Max];
vector<int>weight[Max];

vector<int>revec[Max];
vector<int>reweight[Max];

void dijkstra(int s,int n,int dis[][2],int f){
	priority_queue<struct node>q;
	int i;
	dis[s][0]=0;
	dis[s][1]=-1;
	struct node tmp;
	tmp.u = s;
	tmp.w = 0;
	tmp.max = -1;
	q.push(tmp);
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		if(f){

			for(i=0;i<vec[tmp.u].size();i++){
				if(dis[tmp.u][0]+weight[tmp.u][i]<dis[vec[tmp.u][i]][0]){
					dis[vec[tmp.u][i]][0]=dis[tmp.u][0]+weight[tmp.u][i];
					dis[vec[tmp.u][i]][1]=(dis[tmp.u][1]<weight[tmp.u][i])?weight[tmp.u][i]:dis[tmp.u][1];
					struct node temp;
					temp.u=vec[tmp.u][i];
					temp.w=dis[vec[tmp.u][i]][0];
					temp.max=dis[vec[tmp.u][i]][1];
					q.push(temp);
				}
			}

		}else{

			for(i=0;i<revec[tmp.u].size();i++){
				if(dis[tmp.u][0]+reweight[tmp.u][i]<dis[revec[tmp.u][i]][0]){
					dis[revec[tmp.u][i]][0]=dis[tmp.u][0]+reweight[tmp.u][i];
					dis[revec[tmp.u][i]][1]=(dis[tmp.u][1]<reweight[tmp.u][i])?reweight[tmp.u][i]:dis[tmp.u][1];
					struct node temp;
					temp.u=revec[tmp.u][i];
					temp.w=dis[revec[tmp.u][i]][0];
					temp.max=dis[revec[tmp.u][i]][1];
					q.push(temp);
				}
			}
		}
	}

}
int maximum(int a,int b,int c){
	//printf("%d---%d---%d\n",a,b,c);
	return (a<b)?((b<c)?c:b):((a<c)?c:a);
}
int main(){
	int j=1,test,i;
	scanf("%d",&test);
	while(j<=test){
		int n,m,s,t,p,x,y,z,k;
		scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
		for(i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			vec[x].push_back(y);
			weight[x].push_back(z);
			revec[y].push_back(x);
			reweight[y].push_back(z);
		}
		int sdis[n+1][2],tdis[n+1][2];
		for(i=0;i<=n;i++){
			sdis[i][0]=INF;
			sdis[i][1]=-1;
			tdis[i][0]=INF;
			tdis[i][1]=-1;
		}
		dijkstra(s,n,sdis,1);
		dijkstra(t,n,tdis,0);
		int tmp=-1,temp;
		for(i=1;i<=n;i++){
			for(k=0;k<vec[i].size();k++){
				if(sdis[i][0]+weight[i][k]+tdis[vec[i][k]][0]<=p){
					temp = maximum(sdis[i][1],weight[i][k],tdis[vec[i][k]][1]);
					tmp = (temp>tmp)?temp:tmp;
				}	
			}
		}
		printf("Case %d: %d\n",j,tmp);


		for(i=0;i<Max;i++){
			vec[i].clear();
			weight[i].clear();
			revec[i].clear();
			reweight[i].clear();
		}
		j++;
	}	
	return 0;
}