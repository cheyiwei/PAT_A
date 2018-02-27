/*
ID:PAT_A_1082
time@2018/2/9
author@cheyiwei
*/

#include<cstdio>
#include<cstring>

char conver[][10]={"Shi","Bai","Qian","Wan","Yi"};
char numbe[][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
	char number[15]={'\0'};
	scanf("%s",&number);
	int left = 0;
	int len = strlen(number);
	int right = len - 1;
	if(number[0]=='-'){
		printf("Fu");
		left++;
	}
	if(number[left]=='0'){
		if(left>0) printf(" ");
		printf("ling");
		return 0;
	}
	while(left + 4 <= right){
		right -= 4;
	}
	while(left<len){
		bool flag = false;
		bool isPrint = false;
		while(left<=right){
			if(left>=0&&number[left]=='0'){
				flag = true;
			}else{
				if(flag == true){
					printf(" ling");
					flag = false;
				}
				if(left>0) printf(" ");
				printf("%s",numbe[number[left]-'0']);
				isPrint = true;
				if(left!=right) printf(" %s",conver[right-left-1]);
			}
			left++;
		}
		if(isPrint == true && right != len - 1){
			printf(" %s",conver[(len - right - 1)/4+ 2]);
		}
		right+=4;
	}
	return 0;
}
