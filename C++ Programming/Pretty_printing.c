#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,j;
	scanf("%d",&n);
	while(n--){
		for(j=0;j<3*n;j++)
			printf(" ");
		printf("%d\r",n+1);
	}
	return 0;
}
