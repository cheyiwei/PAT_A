/*
ID:PAT_A_1055 
time@2018/2/17
author@cheyiwei
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Stu{
	char name[10];
	int age;
	int worth;
};

bool cmp(Stu a,Stu b){
	if(a.worth!=b.worth) return a.worth>b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name,b.name)<0;
}

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	Stu stu[N];
	for(int i = 0;i<N;i++){
		scanf("%s %d %d",stu[i].name,&stu[i].age,&stu[i].worth);
	}
	sort(stu,stu+N,cmp);
	for(int i = 0;i<K;i++){
		printf("Case #%d:\n",i+1);
		bool nonprin = true;
		int number,max,min;
		scanf("%d %d %d",&number,&min,&max);
		int num = 0;
		for(int j = 0;j<N;j++){
			if(num >= number) break;
			if(stu[j].age>=min && stu[j].age <=max){
				nonprin=false;
				num++;
				printf("%s %d %d\n",stu[j].name,stu[j].age,stu[j].worth);
			}
		}
		if(nonprin) printf("None\n");
	}
	return 0;
}
