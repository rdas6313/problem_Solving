#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct NODE{
	int u,v,w;
	bool operator<(const NODE &a)const{
		return w>a.w;
	}
};
int find(int x,int par[]){
	if(par[x]==x)
		return x;
	par[x]=find(par[x],par);
}
vector<struct NODE>vec;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m;
		scanf("%d%d",&n,&m);
		int i,x,y,z;
		int par[n+1];
		for(i=0;i<=n;i++)
			par[i]=i;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			struct NODE tmp;
			tmp.u=x;
			tmp.v=y;
			tmp.w=z;
			vec.push_back(tmp);
		}
		sort(vec.begin(),vec.end());


		
		int sum=0;
		for(i=0;i<vec.size();i++){
			struct NODE tmp=vec[i];
			int a = find(tmp.u,par);
			int b = find(tmp.v,par);
			if(a!=b){
				sum+=tmp.w;
				par[a]=b;
			}
		}
		printf("%d\n",sum);
		vec.clear();
	}
	return 0;
}