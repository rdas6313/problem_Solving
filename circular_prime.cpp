#include <stdio.h>
#include<math.h>
#include <iostream>
#include<stdlib.h>
#define Max 1000000
using namespace std;
void sieve(int visit[]){
    int i,j;
    for(i=0;i<Max;i++)
        visit[i]=0;
    for(i=4;i<Max;i+=2)
        visit[i]=1;
    int sqr = sqrt(Max);
    for(i=3;i<=sqr;i++){
        if(visit[i]==0){
            for(j=i*i;j<Max;j+=i){
                visit[j]=1;
            }
        }
    }
}
int main() {
	//code
	int visit[Max];
	sieve(visit);
	string s;
	int test,i;
	scanf("%d",&test);
	while(test--){
	    int f=1;
	    cin >> s;
	    int len=s.length();
	    for(i=len-1;i>=0;i--){
	        string x =s.substr(i)+s.substr(0,i);
	        int tmp = atoi(x.c_str());
	        if(visit[tmp]!=0){
	            f=0;
	            break;
	        }
	    }
	    printf("%d\n",f);
	}
	return 0;
}