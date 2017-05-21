#include <stdio.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--){
        long long	int n,i;
    	long long int siritime,total=1,lift_floor,wait,lift_up_time;
    	scanf("%d",&n);
 		int sqr=n;
 	
 		for(i=1;i<sqr;i++){
 			siritime=(i*(i+1))/2;
 			lift_floor=n-siritime;
 			
 			if(i==lift_floor){
 				lift_up_time=n-i;
 				total=siritime+lift_up_time;
 				break;
 			}else if(i>lift_floor){
 				siritime=siritime-i;
 				i--;
 				lift_floor=n-siritime;
 				lift_up_time=n-i;
 				wait=lift_floor-i;
 				total=siritime+wait+lift_up_time;
 				break;

 			}
 		}

 		long long int onlylift=2*n;
 			long long int onlystair=(n*(n+1))/2;
 			total=onlylift<total?onlylift:total;
 			total=onlystair<total?onlystair:total;
 		
 		printf("%lld\n",total);  	
    }
    return 0;
}
