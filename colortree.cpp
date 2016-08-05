#include<stdio.h>
#include<vector>
#define Max 100000
using namespace std;
vector<int>vec[Max];
void dfs(int node,int a[],int color[],int final[]){
	int i,val;
	final[node]=color[a[node]];
	val=color[a[node]];
	color[a[node]]=node;
	for(i=0;i<vec[node].size();i++){
		int temp_node=vec[node][i];
		dfs(temp_node,a,color,final);
		color[a[node]]=node;
	}
	color[a[node]]=val;
}
void del(){
	int i;
	for(i=0;i<Max;i++)
		vec[i].clear();
}
int main(){
	int n,c,i,x;
	scanf("%d%d",&n,&c);
	int a[n+1],final[n+1],color[c+1];
	for(i=1;i<=c;i++)
		color[i]=-1;
	for(i=2;i<=n;i++){
		scanf("%d",&x);
		vec[x].push_back(i);
	}
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,a,color,final);
	for(i=1;i<=n;i++)
		printf("%d ",final[i]);
	printf("\n");
	return 0;
}