#include<stdio.h>
#include<stdlib.h>

int main(){

	int t, s1, s2, s3, medio, i;

	scanf("%d", &t);

	for (i=0; i<t; i++){
		
		scanf("%d", &s1);
		scanf("%d", &s2);
		scanf("%d", &s3);

		if(s1>=s2){
			if(s2>=s3)
				medio=s2;
			else if(s3>s2)
				if(s3>s1) medio=s1;
				else medio=s3;
		}
		else if(s2>s1){
			if(s1>=s3) medio=s1;
			else if(s3>s1) 
				if(s3>s2) medio=s2;
				else medio=s3;
		}

		printf("Case %d: %d\n", (i+1), medio);
	}
}
