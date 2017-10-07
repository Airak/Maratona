#include<stdio.h>
#include<stdlib.h>

int main (){

	int k=1, x, y, n, m, i;
	
	while (k!=0){
	
		scanf("%d", &k);
		scanf("%d", &n);
		scanf("%d", &m);
		
		for(i=0; i<k; i++){
		
			scanf("%d", &x);
			scanf("%d", &y);
			
			if(x<n){
				if(y<m)
					printf("SO\n");
				else if(y>m)
					printf("NO\n");
			}
			else if(x>n){
				if(y<m)
					printf("SE\n");
				else if(y>m)
					printf("NE\n");
			}
			if ( x==n || y==m ){
				printf("divisa\n");
			}
		}
	}	
}