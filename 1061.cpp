/*
ID:PAT_A_1061
time@2018/2/9
author@cheyiwei
*/

#include<cstdio>
#include<cstring>

int main(){
	int day=0,minute=0,second=0;
	char str_day[][4]={"","MON","TUE","WED","THU","FRI","SAT","SUN"};
	char str_1[62],str_2[62];
	scanf("%s %s",str_1,str_2);
	int len = ( strlen(str_1) > strlen(str_2) )? strlen(str_2) : strlen(str_1);
	for(int i = 0;i<len;i++){
		if(str_1[i] == str_2[i]){
			if(day == 0){
				if(str_1[i] >= 'A' && str_1[i] <= 'G') day = str_1[i] - 'A' + 1;
			}else if(minute == 0){
				if(str_1[i] >= '0' && str_1[i] <= '9') minute = str_1[i] - '0' + 1;
				else if(str_1[i] >= 'A' && str_2[i] <= 'N') minute = str_1[i] - 'A' + 11;
			}
			if(day != 0 && minute != 0) break;
		}
	}
	scanf("%s %s",str_1,str_2);
	len = (strlen(str_1) > strlen(str_2) )? strlen(str_2) : strlen(str_1);
	for(int i = 0;i<len;i++){
		if(str_1[i] == str_2[i]){
			if(str_1[i] >= 'A' && str_1[i] <= 'Z') second = i + 1;
			else if(str_1[i] >= 'a' && str_1[i] <= 'z') second = i + 1;
			if(second != 0) break;
		}	}
	printf("%s %02d:%02d",str_day[day],minute - 1,second - 1);
}
