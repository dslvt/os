#include <stdio.h>
#include <string.h>

int main(){
	char str[1000];
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		printf("%c", str[len-i-1]);
	}
	return 0;
}
