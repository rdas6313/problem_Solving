#include<stdio.h>
#include<string.h>
int main(){
	char s[1000];
	scanf("%s",s);
	int i,len=strlen(s),f=0;

	for(i=0;i<len;i++){
		if(s[i]=='H' || s[i]=='Q' || s[i]=='9'){
			f=1;
			break;
		}
	}
	if(f)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}