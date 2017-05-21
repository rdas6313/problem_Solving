#include<stdio.h>
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,k,i,x;
		long long int big=0,tmp=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&x);
			if(x<=k){
				tmp+=x;
				if(tmp>big)
					big=tmp;
		//	printf("%d------%d\n",tmp,big);
			}else{
				tmp=0;
			}
		}
		printf("%lld\n",big);
	}
	return 0;
}

