/*
ID:PAT_A_1065
time@2018/2/6
author@cheyiwei
*/

#include<cstdio>

int main(){
	int times;
	scanf("%d",&times);
	int t = 0;
	while(times--){
		t++;
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		long long res = a+b;
		if(a > 0 && b > 0 && res <= 0) printf("Case #%d: true\n",t);
		else if(a < 0 && b < 0 && res >= 0) printf("Case #%d: false\n",t);
		else if(res > c) printf("Case #%d: true\n",t);
		else printf("Case #%d: false\n",t);
	}
	return 0;
}
