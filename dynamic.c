#include<stdio.h>
#include<math.h>
#define Max 5010
int sieve(int prime_array[]){
	int i,j,prime[Max];
	for(i=0;i<Max;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(i=4;i<Max;i+=2)
		prime[i]=0;
	int sqr = sqrt(Max);
	for(i=3;i<=sqr;i++){
		if(prime[i]!=0){
			for(j=i*i;j<Max;j+=i){
				prime[j]=0;
			}
		}
	}
	j=0;
	for(i=0;i<Max;i++){
		if(prime[i]==1){
			prime_array[j++]=i;
		}
	}
	return j; 
}
int big(int a,int b){
	return (a<b)?b:a;
}
int solve(int pos,int n,int a[],int prime[],int dp[]){
	if(pos>n)
		return 0;
	if(dp[pos]==-1){
		int max=0,val;
		for(i=0;prime[i]+pos-1<=n;i++){
			 val = a[prime[i]+pos-1]-a[pos-1];
			 max = big(max,solve(prime[i]+pos+1,n,a,prime,dp)+val);
		}
		int tmp = solve(pos+1,n,a,prime,dp);
		dp[pos] = big(tmp,max);
	}
	return dp[pos];
}
int main(){
	int n,i,prime[Max];
	int prime_len = sieve(prime);
	scanf("%d",&n);
	int a[n+1],dp[n+1],x;
	a[0]=0;
	dp[0]=-1;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=a[i-1]+x;
		dp[i]=-1;
	}
	int tmp = solve(1,n,a,prime,dp);
	printf("%d\n",tmp);
	return 0;
}