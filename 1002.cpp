/*
ID:PAT_A_1002
time@2018/2/6
author@cheyiwei
*/

#include<cstdio>

int main(){
	double A[1010]={0};
	double B[1010]={0};
	int count = 0;
	scanf("%d",&count);
	for(int i = 0;i<count;i++){
		int e = 0;
		double d = 0;
		scanf("%d %lf",&e,&d);
		A[e]=d;
	}
	scanf("%d",&count);
	for(int i = 0;i<count;i++){
		int e = 0;
		double d = 0;
		scanf("%d %lf",&e,&d);
		B[e]=d;
	}
	count = 0;
	for(int i = 0;i<1010;i++){
		B[i] += A[i];
		if(B[i]!=0){
			count++;
		}
	}
	printf("%d",count);
	if(count!=0) printf(" ");
	for(int i = 1000;i>=0;i--){
		if(B[i] != 0){
			printf("%d %.1lf",i,B[i]);
			count--;
			if(count != 0) printf(" ");
		}
	}
	return 0;
}
