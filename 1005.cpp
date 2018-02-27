/*
ID:PAT_A_1005
time@2018/2/9
author@cheyiwei
*/

#include<cstdio>
#include<cstring>

char number[][10]={"zero","one","two","three","four","five","six","seven","eight","nine","ten"};

int main(){
	char num[1010];
	scanf("%s",&num);
	int sum = 0;
	int i = 0;
	while(num[i]!='\0'){
		sum += (num[i] - '0');
		i++;	
	}
	int end[100]={0};
	int len = 0;
	if(sum==0) end[len++]=0;
	while(sum!=0){
		end[len++] = sum %10;
		sum /= 10;
	}
	for(int i = len - 1;i>=0;i--){
		printf("%s",number[end[i]]);
		if(i!=0) printf(" ");
	}
	return 0;
}
