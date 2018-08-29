#include <stdio.h>
#include <string.h>

void sw(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main(){
	char str[1000];
	gets(str);
	int a, b;
	sscanf(str, "%d %d", &a, &b); 
	sw(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}
