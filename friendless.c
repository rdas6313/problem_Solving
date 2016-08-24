#include<stdio.h>
void init(int par[],int n){
	int i;
	for(i=0;i<=n;i++)
		par[i]=i;
}
int find(int par[],int x){
	if(x==par[x])
		return x;
	par[x]=find(par,par[x]);
	return par[x];
}
int add(int par[],int x,int y){
	x=find(par,x);
	y=find(par,y);
	if(x!=y){
		par[y]=x;
		return 1;
	}
	return 0;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int node,edge,x,y,i,s=0;
		scanf("%d%d",&node,&edge);
		int par[node+1];
		init(par,node);
		for(i=0;i<edge;i++){
			scanf("%d%d",&x,&y);
			s+=add(par,x,y);
		}
		printf("%d\n",s);
	}
	return 0;
}