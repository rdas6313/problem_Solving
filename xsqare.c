#include<stdio.h>
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		char s[102];
		int a[26];
		int i,mid,j,f=0;
		scanf("%s",s);
		int len=strlen(s);
		for(i=0;i<26;i++)
			a[i]=0;
		for(i=0;i<len;i++){
			a[s[i]-'a']++;
			if(a[s[i]-'a']>1){
				f=1;
				break;
			}
		}
		if(f)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}