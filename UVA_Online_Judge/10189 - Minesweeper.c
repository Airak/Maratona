#include<stdlib.h>
#include<stdio.h>

int main (){

	int linha, coluna, n=100, m=100, cont=0, c_field=0;	

	while(n!=0 && m!=0){

		scanf("%d",&n);
		scanf("%d",&m);

        if(n==0 && m==0)
            break;
            
        char field[n][m];
        int aux[n][m];

		for (linha=0; linha<=n; linha++){
			for(coluna=0; coluna<m; coluna++){
				scanf("%c", &field[linha][coluna]);
				aux[linha][coluna]=0;
			}
		}		
		
		c_field++;
		
		for (linha=0; linha<n; linha++){
			for(coluna=1; coluna<=m; coluna++){
                if(field[linha][coluna]=='*')
                    aux[linha][coluna]=9;
                else{
                
                	if((linha-1)>=0){
                		if((coluna-1)>=0)
                    		if(field[linha-1][coluna-1] == '*')
                        		aux[linha][coluna]++;                 		
                        		                    	
                    	if(field[linha-1][coluna] == '*')
                        	aux[linha][coluna]++;
                        
                    	if((coluna+1)<m)    
                    		if(field[linha-1][coluna+1] == '*')
                        		aux[linha][coluna]++;
                    }
                    
                    if((coluna-1)>=0){
                    	if(field[linha][coluna-1] == '*')
                       		aux[linha][coluna]++;

                    	if((linha+1)<n)   
                    		if(field[linha+1][coluna-1] == '*')
                       			aux[linha][coluna]++;
                    }
                       
                    if((linha+1)<n)   
                    	if(field[linha+1][coluna] == '*')
                       		aux[linha][coluna]++;
                       
                    if((coluna+1)<m){
                    	if((linha+1)<n)
                    		if(field[linha+1][coluna+1] == '*')
                       			aux[linha][coluna]++;
                       			
                        if(field[linha][coluna] == '*')
                       		aux[linha][coluna]++;
                    }
                }
			}
		}
		printf("\n");
			
		printf("Field #%d:\n", c_field);
		for (linha=0; linha<n; linha++){
			for(coluna=1; coluna<=m; coluna++){
				if(aux[linha][coluna]==9)
					printf("*");
				else
					printf("%d", aux[linha][coluna]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
