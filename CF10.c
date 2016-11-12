#include<stdio.h>
#include<string.h>
int cmp(char s1[],char s2[]){
	int i,len=strlen(s1),tmp;
	for(i=0;i<len;i++){
		 tmp = tolower(s1[i])-tolower(s2[i]);
		 if(tmp!=0)
		 	return tmp;
	}
	return tmp;
}
int main(){
	char s1[1000],s2[1000];
	int i,len;
	scanf("%s",s1);
	scanf("%s",s2);

	int tmp= cmp(s1,s2);
	if(tmp>0)
		printf("1\n");
	else if(tmp<0)
		printf("-1\n");
	else
		printf("%d\n",tmp);
	return 0;
}