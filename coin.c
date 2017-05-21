#include<stdio.h>
#define Max 10000
#define MOD 100000007
int n,k,dp[Max][Max],coin[Max],c_count[Max];
int solve(int amount,int src){
	if(src>=n){
		if(amount==k)
			return 1;
		else
			return 0;
	}
	if(dp[src][amount]==-1){
		int a=0,b=0,c=1,x=amount,y;
		while(c<=c_count[src] && coin[src]+x<=k){
			x+=coin[src];
			y=solve(x,src+1);
			b=(b%MOD+y%MOD)%MOD;
			c++;
		}
		a=solve(amount,src+1);
		dp[src][amount]=(a%MOD+b%MOD)%MOD;
	}
	return dp[src][amount];

}
void init(){
	int i,j;
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++)
			dp[i][j]=-1;
}
int main(){
	int test,j=1;
	scanf("%d",&test);
	while(j<=test){
		init();
		scanf("%d%d",&n,&k);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&coin[i]);
		for(i=0;i<n;i++)
			scanf("%d",&c_count[i]);

		int tmp = solve(0,0);
		printf("Case %d: %d\n",j,tmp);
		j++;
	}
	return 0;
}