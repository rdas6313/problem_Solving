#include<stdio.h>
#define MOD 1000000007
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		long long int n;
		scanf("%lld",&n);
		long long int i=2,tmp,sum=0;
		int flag=1,count=1;
		while(flag){
			int c=0;
			while(c<count){
				tmp=(i|(1<<c));
				if(tmp<=n){
					sum=(sum%MOD+tmp%MOD)%MOD;
				}else{
					flag=0;
					break;
				}
				c++;
			}
			i=i<<1;
			count++;
		}
		printf("%lld\n",sum);
	}
	return 0;
}