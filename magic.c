#include<stdio.h>
int day(int n){
	if(n==0)
		return 0;
	int tmp=1;
	while((tmp<<1)<=n){
		tmp=tmp<<1;
	}
	return 1+day(n-tmp);
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		int tmp = day(n);
		printf("%d\n",tmp);
	}
	return 0;
}