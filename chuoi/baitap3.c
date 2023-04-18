#include <stdio.h>
#include <string.h>
#include <conio.h>
int DoiXung(char x[]){
	size_t len = strlen(x);
	for(int i=0; i<len/2; i++){
		if(x[i]!=x[len-i-1])
			return 0;
	}
	return 1;
}
void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}

void main()
{
	char s[50];
	printf("Nhap s = ");
	fgets(s, sizeof(s), stdin);
	xoaXuongDong(s);
	if (DoiXung(s)){
		printf("Day la chuoi doi xung!");
	}else{
		printf("Day la chuoi khong doi xung!");
	}
getch();	
}