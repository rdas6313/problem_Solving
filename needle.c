#include<stdio.h>
#include<string.h>
#define Max 100009
int match(int thash[],int phash[]){
	int i;
	for(i=0;i<26;i++){
		if(thash[i]!=phash[i])
			return 0;
	}
	return 1;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		char s1[Max],s2[Max];
		scanf("%s%s",s1,s2);
		int phash[26],thash[26],i;
		for(i=0;i<26;i++){
			phash[i]=0;
			thash[i]=0;
		}
		int plen=strlen(s1),tlen=strlen(s2);
		for(i=0;i<plen;i++){
			phash[s1[i]-'a']++;
			if(i!=plen-1)
				thash[s2[i]-'a']++;
		}
		int found=0;
		for(i=0;i<=tlen-plen;i++){
			thash[s2[(i+plen)-1]-'a']++;
			int m = match(thash,phash);
			if(m){
				found=1;
				break;
			}else{
				thash[s2[i]-'a']--;
			}
		}
		if(found)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}