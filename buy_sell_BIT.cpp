#include<stdio.h>
#include<map>
#include<iostream>
#define Max 100004
using namespace std;
map<string, int>mymap,m;
int BIT[Max];
void update(int idx,int val){
	while(idx<Max){
		BIT[idx]+=val;
		idx+=idx & -idx;
	}
}
int query(int idx){
	int sum=0;
	while(idx>0){
		sum+=BIT[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main(){
	int n,i,q;
	string s;
		int price;
	for(i=0;i<Max;i++)
		BIT[i]=0;
	scanf("%d",&n);
	while(n--){
		
		cin >> s;
		scanf("%d",&price);
		mymap[s]=price;
	}
	char ch[2];
	scanf("%d",&q);

	while(q--){
		scanf("%s",ch);
		
		switch(ch[0]){
			case '+':
				cin >> s;
				update(mymap[s],1);
				m[s]++;		
				break;
			case '-':
				cin >> s;
				if(m[s]>0){
					update(mymap[s],-1);
					m[s]--;
				}
				
				break;
			case '?':
				scanf("%d",&price);
				int tmp	=	query(Max-1)-query(price);
				printf("%d\n",tmp);
				break;
		}
	}
	return 0; 
}