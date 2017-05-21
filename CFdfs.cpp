#include<stdio.h>
#include<vector>
#include<stack>
#define Max 150005
using namespace std;
vector<int>vec[Max];
stack<int>s;

int dfs(int src,int vis[]){
	int i;
	s.push(src);
	long long int edge=0,node=0;
	while(!s.empty()){
		src = s.top();
		s.pop();
		if(vis[src]==0)
			node++;
		vis[src]=1;
		for(i=0;i<vec[src].size();i++){
			if(vis[vec[src][i]]==0){
				s.push(vec[src][i]);
				edge++;
			}
			
		}
	}
	//printf("node edge---%lld %lld\n",node,edge);
	long long int total = (node*(node-1))/2;
	if(total!=edge)
		return 0;
	return 1;
}
int main(){
	int n,m,i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	int vis[n+1],tmp;
	for(i=1;i<=n;i++){
		vis[i]=0;
	}
	for(i=1;i<=n;i++){
		if(vis[i]==0){
		 	tmp = dfs(i,vis);
			if(tmp==0)
				break;
		}

	}
	if(!tmp)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}