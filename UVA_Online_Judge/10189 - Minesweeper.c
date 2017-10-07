#include<stdlib.h>
#include<stdio.h>
 
char field[102][102];
int  aux[102][102];
 
int main (){
 
        int linha, coluna, n, m, cont=0;
               
        while(scanf("%d %d", &n ,&m)==2){
       
                if(n==0 && m==0)
                        return 0;      
               
                for (linha=1; linha<=n; linha++)
                        for (coluna=1; coluna<=m; coluna++){
                                scanf(" %c", &field[linha][coluna]);
                                aux[linha][coluna]=0;
                        }
				for(coluna=0; coluna<=m+1; coluna++){
					field[0][coluna]=0;
					field[n+1][coluna]=0;
				}
				
				for(linha=0; linha<=n+1; linha++){
					field[linha][0]=0;
					field[linha][m+1]=0;
				}
               
                for (linha=1; linha<=n; linha++)
                        for (coluna=1; coluna<=m; coluna++){
                       
                                if(field[linha][coluna]=='*'){
                                        aux[linha][coluna]=9;
                                }
                                       
                                else{                          
                                        if(field[linha-1][coluna-1]=='*')
                                		aux[linha][coluna]++;
                                	if(field[linha-1][coluna]=='*')
                                		aux[linha][coluna]++;
				        if(field[linha-1][coluna+1]=='*')
				        	aux[linha][coluna]++;
				        if(field[linha][coluna-1]=='*')
				        	aux[linha][coluna]++;
				        if(field[linha][coluna+1]=='*')
				              	aux[linha][coluna]++;
				        if(field[linha+1][coluna-1]=='*')
				               	aux[linha][coluna]++;
				        if(field[linha+1][coluna]=='*')
				              	aux[linha][coluna]++;
				        if(field[linha+1][coluna+1]=='*')
				              	aux[linha][coluna]++;                                  
                                }                              
                        }
                               
                cont++;                 
                if(cont>1)
                	 printf("\n");                       
                printf("Field #%d:\n", cont);                       
                       
                for (linha=1; linha<=n; linha++){
                        for (coluna=1; coluna<=m; coluna++)
                                if(aux[linha][coluna]>=9)
                                        printf("*");
                                else
                                        printf("%d", aux[linha][coluna]);
                        printf("\n");
                }
                
         
        }      
       
        return 0;
}