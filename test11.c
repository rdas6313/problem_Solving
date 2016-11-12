#include<stdio.h>
int main(){
	int n,i,x,small=10000000;
	scanf("%d",&n);
	int a[n],index;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		/*	if(small>a[i]^x){
			small=a[i]^x;
			index=i;
		}*/
			printf("%d\n",a[i]^x);
	}
	//printf("%d\n",index);
	return 0;
}