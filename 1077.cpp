/*
ID:PAT_A_1077
time@2018/2/9
author@cheyiwei
*/

#include<cstdio>
#include<cstring>

void reverse(char *str){
	int len = strlen(str);
	for(int i = 0;i<len/2;i++){
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len-1-i] = temp;
	}
	return;
}

char str[100][257]={{'\0'}};

int main(){
	int N = 0;
	scanf("%d",&N);
	int len = 256;
	getchar();
	for(int i = 0;i<N;i++){
		gets(str[i]);
		reverse(str[i]);
		len = len>strlen(str[i])?strlen(str[i]):len;
	}
	int ans = -1;
	for(int i = 0;i<len;i++){
		char c = str[0][i];
		bool equal = true;
		for(int j = 1;j < N;j++){
			if(c != str[j][i]){
				equal = false;
				break;
			}
		}
		if(equal){
			ans = i;
		}else{
			break;
		}
	}
	if(ans == -1) printf("nai\n");
	else{
		for(int i=ans;i>=0;i--) printf("%c",str[0][i]);
	return 0;
	}
}
