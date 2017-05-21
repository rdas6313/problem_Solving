#include<stdio.h>
#define Max 100
#define INF 100000000
int n,input[Max][3],dp[Max][3];
int solve(int src,int col){
	if(src>=n || col>=3)
		return 0;
	if(dp[src][col]==-1){
		int a = solve(src+1,(col+1)%3);
		int b = solve(src+1,(col+2)%3);
		dp[src][col]=input[src][col]+((a<b)?a:b);
	}
	return dp[src][col];
}
int main(){
	int test,k=1;
	scanf("%d",&test);
	while(k<=test){
		int i,j;
		for(i=0;i<Max;i++)
			for(j=0;j<3;j++)
				dp[i][j]=-1;
		scanf("\n%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<3;j++)
				scanf("%d",&input[i][j]);
		
		int min=INF;
		for(i=0;i<3;i++){
			int x = solve(0,i);
			min=(min>x)?x:min;
		}
		printf("Case %d: %d\n",k,min);
		k++;
	}
	return 0;
}