/*
ID:PAT_A_1036
time@2018/2/8
author@cheyiwei
*/
#include<cstdio>
#include<cstring>

struct STUDENT{
	char name[15];
	char id[15];
	int grade;
}max_f,min_m;

int main(){
	max_f.grade = -1;
	min_m.grade = 101;
	int n;
	scanf("%d",&n);
	while(n--){
		char name[15];
		char gender;
		char id[15];
		int grade;
		scanf("%s %c %s %d",name,&gender,id,&grade);
		if(grade<=100 && grade >= 0){
			if(gender == 'F'){
				if(max_f.grade < grade){
					strcpy(max_f.id,id);
					strcpy(max_f.name,name);
					max_f.grade = grade;
				}
			}else{
				if(min_m.grade > grade){
					strcpy(min_m.id,id);
					strcpy(min_m.name,name);
					min_m.grade = grade;
				}
			}
		}
	}
	if(max_f.grade == -1) printf("Absent\n");
	else printf("%s %s\n",max_f.name,max_f.id);
	if(min_m.grade == 101) printf("Absent\n");
	else printf("%s %s\n",min_m.name,min_m.id);
	
	if(max_f.grade == -1 || min_m.grade == 101) printf("NA");
	else printf("%d",max_f.grade - min_m.grade);
}
