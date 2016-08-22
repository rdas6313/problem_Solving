#include<stdio.h>
#define Mod 1000000007
void init(int par[],int n,int size[],int vis[]){
	int i;
	for(i=0;i<n;i++){
		par[i]=i;
		size[i]=1;
		vis[i]=0;
	}
}
int find(int par[],int x){
	if(par[x]==x)
		return x;
	par[x]=find(par,par[x]);
	return par[x];
}
void add(int par[],int x,int y,int size[]){
	 x=find(par,x);
     y=find(par,y);
     if(x!=y){
     	par[y]=x;
     	size[x]+=size[y];
     } 
}
long long int fact(int n){
 	int i;long long int s=1;
	for(i=2;i<=n;i++)
		s=((s%Mod)*(i%Mod))%Mod;
	return s;
}
int main(){
	int n,k,i,x,y;
	scanf("%d%d",&n,&k);
	int par[n],size[n],vis[n];
	init(par,n,size,vis);
	for(i=0;i<k;i++){
		scanf("%d%d",&x,&y);
		add(par,x,y,size);
	}
	long long int sum=1;int tmp;
	for(i=0;i<n;i++){
		tmp=find(par,i);
		if(size[tmp]>1 && vis[tmp]==0){
			sum=((sum%Mod)*(fact(size[tmp])%Mod))%Mod;
			vis[tmp]=1;
		}
	}
	
	printf("%lld\n",sum);
	return 0;
}