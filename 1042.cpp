/*
ID:PAT_A_1042
time@2018/2/6
author@cheyiwei
*/

#include<cstdio>

void prin(int num){
	if(num<=13)	printf("S%d",num);
	else if(num <= 26) printf("H%d",num-13);
	else if(num <= 39) printf("C%d",num-26);
	else if(num <= 52) printf("D%d",num-39);
	else if(num <= 54) printf("J%d",num-52);
	else printf("error\n");
}

int main(){
	int a[54],times=0;
	int b[54]={0};
	int trans[54] = {0};
	scanf("%d",&times);
	for(int i = 0;i<54;i++){
		a[i] = i+1;
		scanf("%d",&trans[i]);
	}
	while(times--){
		for(int i=0;i<54;i++){
			b[trans[i] - 1] = a[i];
		}
		for(int i=0;i<54;i++){
			a[i] = b[i];
		}
	}
	for(int i=0;i<54;i++){
		prin(a[i]);
		if(i!=53) printf(" ");
	} 
	return 0;
}
