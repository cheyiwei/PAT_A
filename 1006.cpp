/*
ID:PAT_A_1006
time@2018/2/8
author@cheyiwei
*/

#include<cstdio>
#include<cstring>

int isLegal(char *sign_in,char *sign_out){
	if(strcmp(sign_out,sign_in)<=0) return 0;
	return 1;
}

struct RECORD{
	char id[20];
	char sign_in[20];
	char sign_out[20];
}max,min;

int main(){
	strcpy(min.sign_in,"25:00:00");
	strcpy(max.sign_out,"00:00:00");
	int n;
	scanf("%d",&n);
	while(n--){
		char sign_in[20];
		char sign_out[20];
		char id[20];
		scanf("%s %s %s",id,sign_in,sign_out);
		if(isLegal(sign_in,sign_out)){
			if(strcmp(min.sign_in,sign_in)>0){
				strcpy(min.sign_in,sign_in);
				strcpy(min.id,id);
			}
			if(strcmp(max.sign_out,sign_out)<0){
				strcpy(max.sign_out,sign_out);
				strcpy(max.id,id);
			}
		}
	}
	printf("%s %s",min.id,max.id);
}
