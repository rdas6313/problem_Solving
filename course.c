#include<stdio.h>
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		int i,x,max=-1;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			if(max<x)
				max=x;
		}
		printf("%d\n",n-max);
	}
	return 0;
}