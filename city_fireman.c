#include<stdio.h>
#define MOD 1000000007
int find(int par[],int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par,par[x]);
}
int main(){
	int n,e,i,x,y,a,b;
	scanf("%d",&n);
	int risk[n+1],par[n+1],small[n+1];
	long long int dic[n+1];
	for(i=1;i<=n;i++){
		scanf("%d",&risk[i]);
		par[i]=i;
		small[i]=i;
		dic[i]=1;
	}
	scanf("%d",&e);
	for(i=0;i<e;i++){
		scanf("%d%d",&x,&y);
		a=find(par,x);
		b=find(par,y);
		if(a!=b){
			par[b]=a;
			if(risk[small[a]]>risk[small[b]]){
				dic[small[a]]=0;
				small[a]=small[b];
			}else if(risk[small[a]]<risk[small[b]]){
				dic[small[b]]=0;
			}else{
				dic[small[a]]+=dic[small[b]];
				dic[small[b]]=0;
			}
		}
	}
	long long int ans=1;
	for(i=1;i<=n;i++){
		if(dic[i]!=0){//printf("dic--------%d\n",dic[i]);
			ans=((ans%MOD)*(dic[i]%MOD))%MOD;
		}	
	}

	printf("%lld\n",ans);
	return 0;
}