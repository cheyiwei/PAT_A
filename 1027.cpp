/*
ID:PAT_A_1027 
time@2018/2/8
author@cheyiwei
*/

#include<cstdio>

char change(int num){
	if(num<=9) return num+'0';
	else if(num==10) return 'A';
	else if(num==11) return 'B';
	else if(num==12) return 'C';
}

int main(){
	char str[10]={'\0'};
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	str[0]='#';
	str[1]=change(a/13);
	str[2]=change(a%13);
	str[3]=change(b/13);
	str[4]=change(b%13);
	str[5]=change(c/13);
	str[6]=change(c%13);
	printf("%s",str);
}
