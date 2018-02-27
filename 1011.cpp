/*
ID:PAT_A_1011
time@2018/2/7
author@cheyiwei
*/

#include<cstdio>

char change(int i){
	if(i==0) return 'W';
	if(i==1) return 'T';
	return 'L';
}

int main(){
	int max[3]={0};
	double score[3];
	double sum=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%lf",&score[j]);
			if(score[j] > score[max[i]]) max[i]=j;
		}
		sum *= score[max[i]];
	}
	sum *= 0.65;
	sum -= 1;
	sum *= 2;
	printf("%c %c %c %.2lf",change(max[0]),change(max[1]),change(max[2]),sum);
}
