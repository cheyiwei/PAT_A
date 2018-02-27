/*
ID:PAT_A_1016 
time@2018/2/17
author@cheyiwei
*/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char online[20] = "on-line";
char deadline[20] = "off-line";

struct Bill{
	char name[25];
	int day;
	int hour;
	int min;
	int month;
	bool state;
}bill[1001];

bool cmp(Bill a,Bill b){
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else if(a.day!=b.day) return a.day < b.day;
	else if(a.month != b.month) return a.month < b.month;
	else if(a.hour != b.hour) return a.hour < b.hour;
	else return a.min < b.min;
}

int main(){
	int toll[24];
	for(int i=0;i<24;i++) scanf("%d",&toll[i]);
	int N = 0;
	scanf("%d",&N);
	for(int i = 0;i<N;i++){
		char word[20];
		scanf("%s %d:%d:%d:%d %s",bill[i].name,&bill[i].month,&bill[i].day,&bill[i].hour,&bill[i].min,word);
		if(strcmp(word,"on-line")==0) bill[i].state = true;
		else bill[i].state = false;
	}
	sort(bill,bill+N,cmp);
	int now = 0;
	while(now < N){
		char name[20]={'\0'};
		strcpy(name,bill[now].name);
		double sum = 0;
		while(now < N && strcmp(name,bill[now].name) == 0){
			while(now + 1 < N && bill[now].state == bill[now+1].state) now++;
			if(now + 1 < N){
				double begin = sum;
				int timebegin = 0;
				if(sum == 0) printf("%s %02d\n",bill[now].name,bill[now].month);
				int time1[3]={0},time2[3]={0};
				time1[0]=bill[now].min;
				time1[1]=bill[now].hour;
				time1[2]=bill[now].day;
				time2[0]=bill[now+1].min;
				time2[1]=bill[now+1].hour;
				time2[2]=bill[now+1].day;
				while(time1[0]!=time2[0]||time1[1]!=time2[1]||time1[2]!=time2[2]){
					time1[0]++;
					timebegin++;
					sum += toll[time1[1]] *0.01;
					if(time1[0]==60){
						time1[0]=0;
						time1[1]++;
						if(time1[1] == 24){
							time1[1]=0;
							time1[2]++;
						}
					}
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",bill[now].day,bill[now].hour,bill[now].min,bill[now+1].day,
				bill[now+1].hour,bill[now+1].min,timebegin,(sum-begin));
			}
			now+=2;
		}
		printf("Total amount: $%.2lf\n",sum);
	}
	return 0;
}
