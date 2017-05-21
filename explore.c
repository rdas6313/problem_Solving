#include<stdio.h>
#define Max 100000
#include<string.h>
int main(){
	char s[Max];
	int i;
	scanf("%s",s);
	int len = strlen(s);
	for(i=0;i<len;i++){
		if(s[i]!='?')
			continue;
		if((i>0 && s[i-1]=='a')||(i+1<len && s[i+1]=='a')){
			s[i]='b';
		}else
			s[i]='a';
	}
	printf("%s\n",s);
	return 0;
}