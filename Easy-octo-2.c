#include<stdio.h>
#include<string.h>
#define Max 100001
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		char s[Max];int dic[26],index,i;
		scanf("%s",s);
		for(i=0;i<26;i++)
			dic[i]=0;
		int len=strlen(s);
		for(i=0;i<len;i++){
			index=s[i]-'A';
			dic[index]++;
		}
		double sum=0.0;
		for(i=0;i<len;i++){
			index=s[i]-'A';
			sum+=dic[index]/(double)len;
		}
		printf("%.6lf\n",sum);
	}
	return 0;
}