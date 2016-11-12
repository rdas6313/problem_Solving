#include<stdio.h>
int main(){
	int n,s,e,i;
	scanf("%d",&n);
	int a[n+1],size=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d%d",&s,&e);
	while(size<=n){
		if(s==e)
			break;
		s=a[s];
		size++;
	}
	if(s==e)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}