#include<stdio.h>
int find(int par[],int x){
	while(x!=par[x])
		x=par[x];
	return x;
}
void merge(int par[],int a,int b){
	int x=find(par,a);
	int y=find(par,b);
	if(x!=y){
		par[x]=y;
	}
}
void init(int par[],int n){
	int i;
	for(i=0;i<=n;i++)
		par[i]=i;
}
int main(){
	int n,q,i,tmp,x,y;
	scanf("%d%d",&n,&q);
	int par[n+1];
	init(par,n);
	for(i=0;i<q;i++){
		
		scanf("%d",&tmp);
		switch(tmp){
			case 1:
				scanf("%d%d",&x,&y);
				merge(par,x,y);
				break;
			case 2:
				scanf("%d",&x);
				int p=find(par,x);
				par[x]=x;
				par[p]=x;
				break;
			case 3:
				scanf("%d",&x);
			    x=find(par,x);
				printf("%d\n",x);
				break;
		}
	}
	return 0;
}