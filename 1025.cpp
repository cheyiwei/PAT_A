/*
ID:PAT_A_1025
time@2018/2/9
author@cheyiwei
*/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Stu{
	char registername[15];
	int score;
	int final_rank;
	int local_number;
	int local_rank;
}stu[30010];

bool cmp_local(Stu s1,Stu s2){
	if(s1.score!=s2.score) return s1.score > s2.score;
	else return strcmp(s1.registername,s2.registername)<0;
}

int main(){
	int N;
	scanf("%d",&N);
	int sum = 0;
	for(int i=0;i<N;i++){
		int local_sum = 0;
		int now = sum;
		scanf("%d",&local_sum);
		while(local_sum--){
			stu[sum].local_number = i + 1;
			scanf("%s",stu[sum].registername);
			scanf("%d",&stu[sum++].score);
		}
		sort(stu+now,stu+sum,cmp_local);
		for(int i = now;i<sum;i++){
			if(i==0 || stu[i].score != stu[i - 1].score)
			stu[i].local_rank = i - now + 1;
			else
			stu[i].local_rank = stu[i-1].local_rank;
		}
	}
	sort(stu,stu+sum,cmp_local);
	printf("%d\n",sum);
	for(int i = 0;i<sum;i++){
		if(i==0 || stu[i].score != stu[i - 1].score)
		stu[i].final_rank = i + 1;
		else
		stu[i].final_rank = stu[i-1].final_rank;
		printf("%s %d %d %d\n",stu[i].registername,stu[i].final_rank,stu[i].local_number,stu[i].local_rank);
	}
}
