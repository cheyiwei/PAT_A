/*
ID:PAT_A_1046
time@2018/2/6
author@cheyiwei
*/

#include<cstdio>

int main(){
	int N;
	scanf("%d",&N);
	int D[N];
	int Distance[N+1]={0};//Distance[i]记录从1到第i个的距离 
	int sum = 0;
	for(int i =0 ;i<N;i++){
		scanf("%d",&D[i]);
		sum+=D[i];
		Distance[i+1] += D[i];
		Distance[i+1] += Distance[i];
	}
	int n;
	scanf("%d",&n);
	while(n--){
		int d1,d2;
		scanf("%d %d",&d1,&d2);
		if(d1>d2){
			int temp = d1;
			d1 = d2;
			d2 = temp;
		}
		int distance = Distance[d2-1] - Distance[d1-1];
		printf("%d\n",distance>sum/2 ?sum-distance:distance);
	}
}
