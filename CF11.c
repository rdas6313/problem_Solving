#include<stdio.h>
#include<string.h>
int main(){
	char s[1000];
	scanf("%s",s);
	int len=strlen(s);
	int a[4],i,x=0;
	for(i=0;i<4;i++)
		a[i]=0;
	for(i=0;i<len;i++){
		if(s[i]!='+'){
			a[s[i]-48]++;
			x++;
		}
	}
	for(i=1;i<4;i++){
		while(a[i]>0){
			printf("%d",i);
			x--;
			a[i]--;
			if(x>0)
				printf("+");
		}
	}
	printf("\n");
	return 0;
}