#include<stdio.h>
#include<stdlib.h>

int modulo(int a){
	return a >= 0 ? a : -1 * a;
}


int main (){

	int linha, soma, diferenca, i, a, b;

	scanf("%d", &linha);

	for (i=0; i<linha; i++){
		scanf("%d", &soma);
		scanf("%d", &diferenca);

		a = (soma + diferenca)/2;
		b = (soma - a);

		if(soma>=diferenca && a+b==soma && modulo(a - b) == diferenca){
	
			printf("%d %d", a, b);	
	
		} else printf("impossible");			
		
		printf("\n");
	}
	return 0;	
}
