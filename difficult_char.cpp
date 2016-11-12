#include<stdio.h>
#define Max 1000002
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	int ch;
	int repeat;
	bool operator<(const node &a)const{
		return (repeat==a.repeat)?(ch>a.ch):(repeat<a.repeat); 
	}
};
vector<struct node>vec;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		char s[Max];
		int a[26];
		int i;
		for(i=0;i<26;i++)
			a[i]=0;
		scanf("%s",s);
		int len=strlen(s);
		for(i=0;i<len;i++){
			a[s[i]-'a']++;
		}
		for(i=0;i<26;i++){
			struct node tmp;
			tmp.ch=i;
			tmp.repeat=a[i];
			vec.push_back(tmp);
		}
		sort(vec.begin(),vec.end());
		for(i=0;i<vec.size();i++)
		printf("%c ",vec[i].ch+'a');
		vec.clear();
		printf("\n");
	}
	
	return 0;
}