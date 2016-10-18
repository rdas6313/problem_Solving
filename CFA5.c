#include<stdio.h>
#include<string.h>
int main(){
	char s[105];
	int i;
	scanf("%s",s);
	int len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]>='A' && s[i]<='Z')
			s[i]=s[i]+32;
		if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='y')
			printf(".%c",s[i]);
	}
	printf("\n");
	return 0;
}