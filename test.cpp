#include<stdio.h>
#include <iostream>
#include<set>
#include<utility>
using namespace std;

int main() {
	set< pair<int,int> >s;
	int i;
	for(i=0;i<5;i++){
		s.insert(make_pair(i,1));

	}
	set< pair<int,int> >::iterator it;
	//s.erase(1);
	//printf("%d\n",*(s.find(21)));
	for(it=s.begin();it!=s.end();it++)
		printf("%d %d\n",(*it).first,(*it).second);
	return 0;
}
