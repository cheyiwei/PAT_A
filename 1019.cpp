/*
ID:PAT_A_1019 
time@2018/2/8
author@cheyiwei
*/

#include<cstdio>

int change(int *str,int n,int d){
	int len;
	if(n==0){
		str[0]=0;
		len = 1;
	}else{
		len = 0;
		while(n!=0){
			str[len++]=n%d;
			n/=d;
		}
	}
	return len;
}

bool isHui(int *str,int len){
	bool flag = true;
	int halfl = len/2;
	for(int i = 0;i<halfl;i++){
		if(str[i]!=str[len - i - 1]){
			flag = false;
			break;
		}
	}
	return flag;
}

int main(){
	int end[100]={0};
	int num,d;
	scanf("%d %d",&num,&d);
	int len=change(end,num,d);
	if(isHui(end,len)==true) printf("Yes\n");
	else printf("No\n");
	for(int i=len-1;i>=0;i--){
		printf("%d",end[i]);
		if(i) printf(" ");
	}
	return 0;
}
