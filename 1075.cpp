/*
ID:PAT_A_1075
time@2018/2/17
author@cheyiwei
*/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Student{
	int id;
	int score[6];
	int solve_sum;
};

int score[10001][6]={{0}};//-2´ú±íÎ´±àÒë 

bool cmp(Student a,Student b){
	if(a.score[0] != b.score[0]) return a.score[0] > b.score[0];
	else return a.solve_sum > b.solve_sum;
}

int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	for(int i =0 ;i<10001;i++){
		int j = 5;
		while(j){
			score[i][j--] = -2;
		}
	}
	Student stu[n] = {{0}};
	int p[k + 1];
	for(int i=0;i<k;i++) scanf("%d",&p[i+1]);
	for(int i=0;i<m;i++){
		int u_id,u_pro,u_sc;
		scanf("%d %d %d",&u_id,&u_pro,&u_sc);
		if(u_pro<=k && score[u_id][u_pro] < u_sc){
			score[u_id][u_pro] = u_sc;
			score[u_id][0] = 1;
		}
	}
	int now = 0;
	for(int i=0;i<10001;i++){
		if(score[i][0] > 0){
			stu[now].id = i;
			int sum = 0;
			for(int j = 1;j<=k;j++){
				int s = score[i][j];
				if(s==-2) stu[now].score[j] = -1;
				else if(s==-1) stu[now].score[j] = 0;
				else{
					if(s == p[j]) stu[now].solve_sum++;
					stu[now].score[j] = s;
					sum += s;
				}
			}
			stu[now].score[0] = sum;
			now++;
		}
	}
	sort(stu,stu+n,cmp);
	int rk = 1;
	for(int i =0;i<n;i++){
		if(stu[i].score[0] <= 0) break;
		else{
			if(i==0 || stu[i].score[0] != stu[i-1].score[0]) printf("%d",rk);
			else{
				rk = i+1;
				printf("%d",rk);
			}
			printf(" %05d",stu[i].id);
			for(int j = 0;j<=k;j++){
				if(stu[i].score[j]==-1) printf(" -");
				else printf(" %d",stu[i].score[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
