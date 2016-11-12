#include<stdio.h>
#include<string.h>
int main(){
	char s[1000];int a[1000],i,big=-1;char key;
	for(i=0;i<1000;i++)
		a[i]=0;
	scanf("%[^\n]",s);
	int len=strlen(s);
	for(i=len-1;i>=0;i--){
		a[s[i]]++;
	}
	for(i=999;i>=0;i--){
		if(big<=a[i]){
			key=i;
			big=a[i];
		}
	}
	printf("%c %d\n",key,big);
	return 0;
}