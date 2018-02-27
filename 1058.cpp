/*
ID:PAT_A_1058 
time@2018/2/8
author@cheyiwei
*/

#include<cstdio>

const int Galleon = 29*17;
const int Sickle = 29;

int main(){
	int a,b,c,d,e,f;
	scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
	int carry = 0;
	c = c + f;
	carry = c/29;
	c%=29;
	b=b+e+carry;
	carry=b/17;
	b%=17;
	a = a+d+carry;
	printf("%d.%d.%d",a,b,c);
	return 0;
}
