#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
map<string, int>mymap;
int main(){
	string x;
	cin >> x;
	if(mymap[x]==0){
		mymap[x]=1;
		printf("%d",mymap[x]);

	}
}