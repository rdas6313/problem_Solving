#include <stdio.h>
#include<math.h>
int bit(int n){
    int c=0;
    while(n){
    	if((n&1)==0)
    		c++;
    	n=n>>1;
    }
   
    return c;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d",&n);
        int tmp=bit(n);
        tmp=pow(2,tmp)-1;
        printf("%d\n",tmp);
    }
    return 0;
}
