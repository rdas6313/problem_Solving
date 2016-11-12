#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int u,v,w;
	bool operator<(const node &a)const{
		return (w>a.w);
	}
};
vector<struct node>vec;
int find(int par[],int x){
	if(x==par[x])
		return x;
	par[x]=find(par,par[x]);
	return par[x];
}
int mst(int n){
	int i,x,y,a,b,edge=0,z;
	int par[n+1],men[n+1],women[n+1];
	for(i=0;i<=n;i++){
		par[i]=i;
		men[i]=0;
		women[i]=0;
	}
	for(i=0;i<vec.size();i++){
		 x=vec[i].u;
		 y=vec[i].v;
		 z=vec[i].w;
		 a=find(par,x);
		 b=find(par,y);
		 if(a!=b){
				 if(z==3){
			 		men[x]=1,
			 		men[y]=1,
			 		women[x]=1,
			 		women[y]=1;
				 }else if(z==2){
				 		women[x]=1,
				 		women[y]=1;
				 		if(men[x] && men[y])
				 			edge++;
				 }else if(z==1){
				 		men[x]=1,
				 		men[y]=1;
				 		if(women[x] && women[y])
				 			edge++;
				 }
				if(men[x] && men[y] && women[x] && women[y]){
					par[b]=a;
					edge++;
				}
		}
	}
	for(i=1;i<=n;i++){
		if(men[i]!=1 || women[i]!=1){
			edge=-1;
		}
	}
	return edge;
}
int main(){
	int n,m,a,b,c,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		struct node tmp;
		tmp.u=a;
		tmp.v=b;
		tmp.w=c;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
	int e=mst(n);
	if(e!=-1)
		e=m-e;
	printf("%d\n",e);
	vec.clear();
	return 0;
}