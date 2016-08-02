#include<stdio.h>
#include<vector>
#define Max 100002
using namespace std;
vector<int>vec[Max];
vector<int>weight[Max];
void dfs(int root,int vis[],int dis[],long long int ans[]){
	int i;
	vis[root]=1;
	for(i=0;i<vec[root].size();i++){
		if(vis[vec[root][i]]==0){
			dis[vec[root][i]]=dis[root]+weight[root][i];
			if(dis[vec[root][i]]>ans[0]){
				ans[0]=dis[vec[root][i]];
				ans[1]=vec[root][i];
			}
			dfs(vec[root][i],vis,dis,ans);

		}
	}

}
void init(int vis[],int dis[],int node,long long int ans[]){
	int i;
	for(i=0;i<=node;i++){
		vis[i]=0;
		dis[i]=0;
		ans[0]=0;
		ans[1]=0;
	}
}
void del(){
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
		int node,i,x,y,z,cost;
		scanf("%d",&node);
		int vis[node+1],dis[node+1];
		long long int ans[2];
		init(vis,dis,node,ans);
		for(i=1;i<node;i++){
			scanf("%d%d%d",&x,&y,&z);
			vec[x].push_back(y);
			vec[y].push_back(x);
			weight[x].push_back(z);
			weight[y].push_back(z);
		}
		dfs(1,vis,dis,ans);
		int root=ans[1];
		init(vis,dis,node,ans);
		dfs(root,vis,dis,ans);
		if(ans[0]>10000)
			cost=10000;
		else if(ans[0]>1000)
			cost=1000;
		else if(ans[0]>100)
			cost=100;
		else if(ans[0]<100)
			cost=0;
		printf("%d %lld\n",cost,ans[0]);
		del();
	}
	return 0;
}