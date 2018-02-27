/*
ID:PAT_A_1009
time@2018/2/6
author@cheyiwei
*/

#include<cstdio>

int main(){
	int count = 0;
	double A[1010]={0};
	double B[1010]={0};
	double C[2020]={0};
	scanf("%d",&count);
	for(int i = 0;i<count;i++){
		int e;
		double k;
		scanf("%d %lf",&e,&k);
		A[e]=k;
	}
	scanf("%d",&count);
	for(int i = 0;i<count;i++){
		int e;
		double k;
		scanf("%d %lf",&e,&k);
		B[e]=k;
	}
	count = 0;
	for(int i=0;i<1010;i++){
		if(A[i]!=0){
			for(int j = 0;j<1010;j++){
				if(B[j]!=0){
					C[i+j] +=A[i]*B[j];
				}
			}
		}
	}
	for(int i=0;i<2020;i++){
		if(C[i]!=0) count++;
	}
	printf("%d",count);
	if(count!=0) printf(" ");
	for(int i=2000;i>=0;i--){
		if(C[i]!=0){
			printf("%d %.1lf",i,C[i]);
			count--;
			if(count!=0) printf(" ");
		}
	}
	return 0;
}
