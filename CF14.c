#include<stdio.h>
int main(){
	int n,i,sum=0,c=1;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	for(i=1;i<n;i++){
		if(s[i]==s[i-1])
			c++;
		else{
			sum+=c-1;
			c=1;
		}
	}
	sum+=c-1;
	printf("%d\n",sum);
	return 0;
}