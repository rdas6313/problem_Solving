#include<stdio.h>
#include<string.h>
int main(){
	int f=0;
	char s[1000];
	scanf("%s",s);
	int len=strlen(s),i;
	for(i=1;i<len;i++){
		if(s[i]>='a' && s[i]<='z'){
			f=1;
			break;
		}
	}
	if(!f){
		for(i=0;i<len;i++){
			if(s[i]>='a' && s[i]<='z')
				s[i]=toupper(s[i]);
			else
				s[i]=tolower(s[i]);
		}
	}
	printf("%s\n",s);
	return 0;
}