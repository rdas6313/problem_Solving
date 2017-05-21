#include<stdio.h>
int main(){
	int a,b,count=0;
	scanf("%d%d",&a,&b);
	while(a<=b){
		count++;
		a=(a*3);
		b=(b*2);
	}
	printf("%d\n",count);
	return 0;
}