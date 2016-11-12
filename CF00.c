#include<stdio.h>
int main(){
	int n,i,x,c,k=0,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		c=0;
		for(j=0;j<3;j++){
			scanf("%d",&x);
			if(x==1)
				c++;
		}
		if(c>1)
			k++;
	}
	printf("%d\n",k);
	return 0;
}