#include<stdio.h>
#include<string.h>
int main(){
	char s[1002];
	scanf("%s",s);
	int len=strlen(s);
	int c=1,i;
	for(i=1;i<len;i++){

		if(s[i-1]==s[i]){
			c++;
		}else{
			c=1;
		}
		if(c>=7){
			break;
		}
	}
	if(c>=7)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}