#include<stdio.h>
#include<string.h>
#define Max 1000005
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		char s[Max];
		scanf("%s",s);
		int i,f=0;
		int len = strlen(s);
		for(i=1;i<len;i++)
			if(s[i]<s[i-1])
				f=1;
		if(f)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}