/*
ID:PAT_A_1001
time@2018/2/9
author@cheyiwei
*/

#include<cstdio> 
#include<cstring>
void change(int value,char str[]){
	if(value==0){
		str[0] = '0';
	}
	else{
		int i = 0;
		while(value!=0){
			str[i] = value % 10 + '0';
			value /= 10;
			i++;
		}
	}
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	char str[100]={'\0'};
	int c = a+b;
	if(c < 0){
		printf("-");
		c = -c;
	}
	change(c,str);
	int len = strlen(str);
	for(int i=len-1;i>=0;i--){
		printf("%c",str[i]);
		if(i>0 && i%3==0) printf(",");
	}
	return 0;
}
