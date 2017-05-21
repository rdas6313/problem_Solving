#include<stdio.h>
#include<vector>
#define Max 100000
using namespace std;
vector<int>vec[Max];
int min(int a,int b){
	return (a<b)?a:b;
}
int dfs(int src,int vis[]){
	vis[src]=1;
	int i,s=100000000,tmp=0;
	for(i=0;i<vec[src].size();i++){
		if(vis[vec[src][i]]==0){
			s = min(dfs(vec[src][i],vis),s);
			tmp = s;
		}
	}
	return tmp+1;
}
int main(){
	int n,m,x,y,i;
	scanf("%d%d",&n,&m);
	int vis[n+1];
	for(i=0;i<=n;i++)
		vis[i]=0;
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
	}
	int s = 100000000,tmp=0,j;
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++)
		vis[j]=0;
		s = min(dfs(i,vis),s);
//	printf("%d--%d\n",s,tmp);
		if(vec[i].size()==0){
				tmp++;
		}
	}
	if(tmp>0)
		s = min(s,tmp);
	printf("%d\n",s);
	return 0;
}