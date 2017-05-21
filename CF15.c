#include<stdio.h>
int main(){
	
	int n,i,a=0,d=0;
	scanf("%d",&n);
	char s[n+10];
	scanf("%s",s);
	for(i=0;i<n;i++){
		if(s[i]=='A')
			a++;
		else
			d++;
	}
	if(a>d)
		printf("Anton\n");
	else if(d>a)
		printf("Danik\n");
	else
		printf("Friendship\n");
	return 0;


}