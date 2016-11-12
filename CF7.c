#include<stdio.h>
int main(){
	int n,x=0,i;
	char s[5];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s);
		if(s[1]=='+')
			x+=1;
		else
			x-=1;
	}
	printf("%d\n",x);
	return 0;
}