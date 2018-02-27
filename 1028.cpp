/*
ID:PAT_A_1028 
time@2018/2/17
author@cheyiwei
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student{
	int id;
	char name[10];
	int grade;
};

int now = 0;

bool cmp(Student a,Student b){
	if(now == 1) return a.id < b.id;
	else if(now == 2){
		int s = strcmp(a.name,b.name);
		if(s!=0) return s<0;
		else return a.id<b.id;
	}
	else{
		if(a.grade != b.grade) return a.grade<b.grade;
		else return a.id<b.id;
	}
}

int main(){
	int n;
	scanf("%d %d",&n,&now);
	Student stu[n];
	for(int i = 0;i<n;i++){
		scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	sort(stu,stu+n,cmp);
	for(int i = 0;i<n;i++){
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
	return 0;
}
