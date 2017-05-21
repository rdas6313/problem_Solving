#include<stdio.h>
long long int big(long long int a,long long int b){
	return (a<b)?b:a;
}
long long int solve(int pos,int n,long long int dp[],int a[]){
	if(pos>=n)
		return 0;
 	if(dp[pos]==-1){
 		long long int sum=0;
 		
 		sum = a[pos]+solve(pos+2,n,dp,a);
 		
 		long long int val = solve(pos+1,n,dp,a);
 		dp[pos] = big(val,sum);
 	}
 	return dp[pos];
}
int main(){
	int test,k=1;
	scanf("%d",&test);
	while(k<=test){
		int n,i;
		scanf("%d",&n);
		int a[n];
		long long int dp[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			dp[i]=-1;
		}
		long long int tmp = solve(0,n,dp,a);
		printf("Case %d: %lld\n",k++,tmp);
	}

	return 0;

}