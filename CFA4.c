#include<stdio.h>
int main(){
	int n,k,i;
	scanf("%d%d",&n,&k);
	int tmp[101],x,key,zero=0;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x==0)
			zero++;
		tmp[x]=i;
		if(i+1==k)
			key=x;
	}
	if(key==0){
		if(zero==n)
			printf("0\n");
		else
			printf("%d\n",n-zero);
	}
	else
		printf("%d\n",tmp[key]+1);

	return 0;
}