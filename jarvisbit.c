#include<stdio.h>
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,i;
		long long int x,tmp=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lld",&x);
			tmp=tmp^x;
		}
		if(tmp==0)
		    printf("-1\n");
		else
	    	printf("%lld\n",tmp);

	}
	return 0;
}