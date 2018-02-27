/*
ID:PAT_A_1012
time@2018/2/9
author@cheyiwei
*/

#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int now = 0;

struct Stu{
	int id;
	int grade[4];
}stu[2010];

int Rank[1000000][4]={0};

bool cmp(Stu a,Stu b){
	return a.grade[now] > b.grade[now];
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		scanf("%d",&stu[i].id);
		int sum = 0;
		for(int j = 1;j<=3;j++){
			scanf("%d",&stu[i].grade[j]);
			sum+=stu[i].grade[j];
		}
		stu[i].grade[0]=sum;
	}
	for(now = 0;now < 4;now++){
		sort(stu,stu+n,cmp);
		Rank[stu[0].id][now] = 1;
		for(int i = 1;i<n;i++){
			if(stu[i].grade[now] == stu[i - 1].grade[now]) Rank[stu[i].id][now]=Rank[stu[i-1].id][now];
			else Rank[stu[i].id][now] = i + 1;		
		}
	}
	int query;
	char c[4]={'A','C','M','E'};
	for(int i = 0;i<m;i++){
		scanf("%d",&query);
		if(Rank[query][0]==0) printf("N/A\n");
		else{
			int k = 0;
			for(int j = 1;j < 4;j++){
				if(Rank[query][k] > Rank[query][j]) k = j;
			}
			printf("%d %c\n",Rank[query][k],c[k]);
		}
	}
	return 0;
}
