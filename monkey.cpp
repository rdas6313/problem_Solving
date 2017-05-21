#include<stdio.h>
#include<vector>
#define Max 100003
using namespace std;
vector<int>vec[Max];
long long int max(long long int a,long long int b){
    return (a<b)?b:a;
}
long long int dfs(int src,int vis[],long long int gold[]){
	vis[src] = 1;
	int i;long long int tmp=0;
	for(i=0;i<vec[src].size();i++){
		if(vis[vec[src][i]]==0){
			tmp += dfs(vec[src][i],vis,gold);
		}
	}
	return tmp+gold[src];
}
void clear(){
    int i;
    for(i=0;i<Max;i++)
        vec[i].clear();
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m,x,y,i;
		scanf("%d%d",&n,&m);
		int vis[n+1];
		for(i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		long long int gold[n+1];
		for(i=1;i<=n;i++){
			scanf("%lld",&gold[i]);
			vis[i]=0;
		}
		long long int tmp=0,s;
		for(i=1;i<=n;i++){
			if(vis[i]==0){
			    s = dfs(i,vis,gold);
				tmp = max(s,tmp);
			//	printf("%d---------------%d---%d\n",i,s,tmp);
			}
		}
		printf("%lld\n",tmp);
		clear();
	}
	return 0;
}