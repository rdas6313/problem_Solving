#include<stdio.h>
#include<vector>
#include<stack>
#define Max 1000000
using namespace std;
vector<int>vec[Max];
void clear(){
	int i;
	for(i=0;i<Max;i++)
		vec[i].clear();
}
int dfs(int src,int vis[],int n){
	stack<int>s;
	vis[src]=1;
	int tmp = 0;
	int i;
	s.push(src);
	while(!s.empty()){
		src = s.top();
		s.pop();
		for(i=0;i<vec[src].size();i++){
			if(vis[vec[src][i]] == 0){
				vis[vec[src][i]] = 1;
				tmp++;
				s.push(vec[src][i]);
			}
		}
	}
	return tmp;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m,lib,road,i,x,y;
		scanf("%d%d%d%d",&n,&m,&lib,&road);
		for(i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		int vis[n+1];
        long long int price=0,lib_price=0;
		for(i=0;i<=n;i++)
			vis[i]=0;
		for(i=1;i<=n;i++){
			if(vis[i]==0){
				int tmp = dfs(i,vis,n);
				price += lib+((long long int)tmp*road);
			}
		}
		lib_price = ((long long int)lib*n);
		if(price>lib_price)
			printf("%lld\n",lib_price);
		else
			printf("%lld\n",price);

		clear();
	}
}