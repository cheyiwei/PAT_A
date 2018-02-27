/*
ID:PAT_A_1035
time@2018/2/9
author@cheyiwei
*/

#include<stdio.h>
#include<cstring>

char change(char c){
	if(c=='1') return '@';
	else if(c=='0') return '%';
	else if(c=='l') return 'L';
	else if(c=='O') return 'o';
	return c;
}
char name[1001][100]={{'\0'}};
char password[1001][100]={{'\0'}};
 
int main(){
	int N;
	scanf("%d",&N);
	int sum = N,modified = 0;
	while(N--){
		char n[100]={'\0'};
		char psw[100]={'\0'};
		scanf("%s %s",n,psw);
		bool flag = false;
		for(int i=strlen(psw)-1;i>=0;i--){
			char c=change(psw[i]);
			if(c!=psw[i]){
				psw[i]=c;
				flag = true;
			}
		}
		if(flag){
			strcpy(name[modified],n);
			strcpy(password[modified++],psw);
		}
	}
	if(modified==0){
		if(sum == 1) printf("There is 1 account and and no account is modified");
		else printf("There are %d accounts and no account is modified",sum);
	}else{
		printf("%d\n",modified);
		for(int i=0;i<modified;i++){
			printf("%s %s",name[i],password[i]);
			if(i!=modified - 1) printf("\n");
		}
	}
	return 0;
}
