#include<stdio.h>
#define Max 100005
#define maxx 1000000000
int dp[Max][3];
int min(int a,int b){
	return (a<b)?a:b;
}
int solve(int pos,int a[][3],int n,int prev){
	if(pos>=n)
		return 0;
	int sum=maxx,i,val;
	for(i=0;i<3;i++){
		if(i!=prev){
			if(dp[pos][i]==-1)
				dp[pos][i] = a[pos][i]+solve(pos+1,a,n,i);
			sum = min(sum,dp[pos][i]);
		}		
	}
	return sum;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,i;
		for(i=0;i<Max;i++)
			dp[i][0]=dp[i][1]=dp[i][2]=-1;
		scanf("%d",&n);
		int a[n][3];
		for(i=0;i<n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		int tmp = solve(0,a,n,-1);
		printf("%d\n",tmp);
	}	
}