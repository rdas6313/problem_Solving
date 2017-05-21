#include<stdio.h>
#include<math.h>
#define Max 100000
int prime[Max],dp[Max];
int prime_numbers[Max],top;
void sieve(){
	int i,j;
	for(i=0;i<Max;i++)
		prime[i]=1;
	for(i=4;i<Max;i+=2)
		prime[i]=0;
	int sqr = sqrt(Max);
	for(i=3;i<=sqr;i++){
		if(prime[i]==1){
			for(j=i*i;j<Max;j+=i){
					prime[j]=0;
			}
		}
	}
	for(i=2;i<=sqr;i++){
		long long int index = pow(i,i);
		if(prime[i]==1 && index<Max){
			prime[index]=2;
		}
	}
	j=0;
	for(i=2;i<Max;i++){
		if(prime[i]==1 || prime[i]==2)
			prime_numbers[j++]=i;
	}
	top=j;

}
int min(int a,int b){
	return (a<b)?a:b;
}
int solve(int n){
	if(n == 0)
		return 0;
	else if(n<2)
		return -1;
	if(dp[n]==-1){
		int i,tmp,total=Max;
		for(i=0;prime_numbers[i]<=n;i++){
			tmp = solve(n-prime_numbers[i]);
			if(tmp == -1)
				continue;
			total = min(total,1+tmp); 
		}
		dp[n]=total;
	}
	return dp[n];
}
int main(){
	int test,i;
	sieve();
	for(i=0;i<Max;i++)
		dp[i]=-1;
	dp[2]=dp[3]=1;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		int tmp = solve(n);
		printf("%d\n",tmp);
	}

	return 0;
}