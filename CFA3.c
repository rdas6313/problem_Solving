#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char s[102];
		scanf("%s",s);
		int len=strlen(s);
		if(len>10){
			printf("%c%d%c\n",s[0],len-2,s[len-1]);
		}else{
			printf("%s\n",s);
		}
	}
	return 0;
}