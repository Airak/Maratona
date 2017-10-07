#include<stdio.h>
#include<stdlib.h>

int main(){

	int t, i;
	char str[5];

	scanf("%d", &t);

	for (i=0; i<t; i++){

		scanf("%s", str);

        if(str[0]=='t' && str[1]=='w' || str[0]=='t' && str[2]=='o' || str[1]=='w' && str[2]=='o')
                printf("2\n");
        else if(str[0]=='o' && str[1]=='n' || str[0]=='o' && str[2]=='e' || str[1]=='n' && str[2]=='e')
                printf("1\n");
            else
                printf("3\n");
    }
    return 0;
}
