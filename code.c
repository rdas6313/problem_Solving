#include<stdio.h>
int main(){
	
	int n,i,c=0,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x%2==1)
			c++;
	}
	if(c%2==0)
		printf("%d\n",c/2);
	else
		printf("%d\n",c);

	return 0;
}