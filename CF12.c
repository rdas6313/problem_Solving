#include<stdio.h>
int main(){
	int n,i,a,b,x=0,big=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		x-=a;
		x+=b;
		if(big<x)
			big=x;
	}
	printf("%d\n",big);
	return 0;
}