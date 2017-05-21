#include<stdio.h>
#define Max 100005
int data[2][Max],dp[2][Max],change[2][Max];
int solve(int track,int troll){
	if(dp[track][troll]==-1){
		int t1 = solve(track,troll+1);
		int t2 = solve((track+1)%2,troll+1)+change[track][troll];
		//printf("%d--%d\n",t1,t2);
		dp[track][troll] = min(t1,t2)+data[track][troll];
	}
	return dp[track][troll];
}
void init(){
	int i,j;
	for(i=0;i<2;i++)
		for(j=0;j<Max;j++){
			data[i][j]=change[i][j]=0;
			dp[i][j]=-1;
		}
}
int min(int a,int b){
	return (a<b)?a:b;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,i,j;
		scanf("%d",&n);
		init();
		for(i=0;i<2;i++){
			for(j=0;j<n;j++){
				scanf("%d",&data[i][j]);
				dp[i][j]=-1;
			}
		}
		dp[0][n-1]=data[0][n-1];
		dp[1][n-1]=data[1][n-1];
		for(i=0;i<2;i++)
			for(j=0;j<n-1;j++){
				scanf("%d",&change[i][j]);
			}
		int t1 = solve(0,0);
		int t2 = solve(1,0);

		int tmp = min(t1,t2);
		printf("%d\n",tmp);
	}
	return 0;
}