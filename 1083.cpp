/*
ID:PAT_A_1083
time@2018/2/17
author@cheyiwei
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Stu{
	char name[11];
	char id[11];
	bool state;
}stu[101];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<101;i++) stu[i].state = false;
	for(int i = 0;i<n;i++){
		char name[11];
		char id[11];
		int grade;
		scanf("%s %s %d",name,id,&grade);
		strcpy(stu[grade].name,name);
		strcpy(stu[grade].id,id);
		stu[grade].state=true;
	}
	int grade1,grade2;
	scanf("%d %d",&grade1,&grade2);
	bool nonprint = true;
	for(int i = grade2;i>= grade1;i--){
		if(stu[i].state){
			printf("%s %s\n",stu[i].name,stu[i].id);
			nonprint = false;
		}
	}
	if(nonprint) printf("NONE\n");
}
