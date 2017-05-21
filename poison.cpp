#include<stdio.h>
#include<vector>
#include<queue>
#define Max 1001
#define INF 1000000000
using namespace std;
struct node{
	int u,ro,co;
	bool operator<(const node &a)const{
		return co==a.co?true:(co>a.co);
	}
};
vector< pair<int,int> >vec[Max];

int dijkstra(int src,int target,int capacity,int n,int a[]){
	priority_queue<struct node>q;
	int d[n][capacity+1],i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<=capacity;j++){
			d[i][j]=INF;
		}
	d[src][0]=0;
	struct node tmp;
	tmp.u=src;
	tmp.ro=0;
	tmp.co=0;
	q.push(tmp);
	int diff=0;
	while(!q.empty()){
		tmp = q.top();
		q.pop();
		if(tmp.u==target)
			return tmp.co;
		for(i=0;i<vec[tmp.u].size();i++){
			int v = vec[tmp.u][i].first;
			int w = vec[tmp.u][i].second;
			for(k=w;k<=capacity;k++){
				if(k>tmp.ro){
					diff=(k-tmp.ro);
				}else{
					diff=0;
				}
				int remain = (k-w);
				if(tmp.co+(diff*a[tmp.u])<d[v][remain]){
					d[v][remain]=tmp.co+(diff*a[tmp.u]);
					struct node temp;
					temp.u=v;
					temp.ro=remain;
					temp.co=d[v][remain];
					q.push(temp);
				}
			}
		}
	}
	return -1;
}
void clear(){
	int i=0;
	for(i=0;i<Max;i++)
		vec[i].clear();
}
int main(){
	int tt=1,test;
	scanf("%d",&test);
	while(tt<=test){
		int n,m;
		scanf("%d%d",&n,&m);
		int a[n],i,x,y,z;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			vec[x].push_back(make_pair(y,z));
			vec[y].push_back(make_pair(x,z));
		}
		int q,tmp,c,s,t;
		scanf("%d",&q);
		printf("Case %d:\n",tt);
		while(q--){
			scanf("%d%d%d",&c,&s,&t);
			
			tmp = dijkstra(s,t,c,n,a);
			if(tmp==-1)
				printf("impossible\n");
			else
				printf("%d\n",tmp);
		}
		clear();
		tt++;
	}
	return 0;
}