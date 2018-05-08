#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//FUNÇÃO PARA VERIFICAR SE É POSSÍVEL CRIPTOGRAFAR COM A MATRIZ INFORMADA
int validarMatriz(int a, int b, int c, int d){
	int i, e = 0, determinante = (a*d)-(b*c);
	if(determinante == 0){
		//MATRIZ NAO INVERSIVEL
		return (0);
	}else{
		//VERIFICA SE DETERMINANTE É COPRIMO DE 26 PARA ENCONTRAR INVERSA DA MATRIZ MODULO 26
		i = determinante;
		while(i>1){
			if((determinante%i==0) && (i==26 || i==13 || i==2)){
				//MATRIZ NAO VALIDADA
				return (0);
			}i--;
		}
		//MATRIZ VALIDADA
		return (1);
	}
}

//RETORNA O INDICE DA LETRA NO VETOR ALFABETO
int indice_alfabeto(char letra){
	char alfabeto[] = {"zabcdefghijklmnopqrstuvwxy"}; //em que Z está na 0 posição do vetor
	int i = 0;
	while(i<=26){
		if (letra == alfabeto[i]){
			return i;
		}else{
			i++;
		}
	}
}
char letra_alfabeto(int indice){
	char alfabeto[] = {"zabcdefghijklmnopqrstuvwxy"}; //em que Z está na 0 posição do vetor
	return alfabeto[indice];
}

//FUNÇÃO PARA LER STRING
char *EntraString()
{
    char tecla;
    char *retorno=NULL;
    int tam=0;
    do {
        tecla=getchar();
        if(retorno==NULL)
            retorno=(char*)malloc(sizeof(char));
        else
            retorno=(char*)realloc(retorno,tam+1);
        retorno[tam]=tecla;
        tam++;
    } while(tecla!='\n');
    retorno[tam-1]='\0';
    return retorno;
}

int main(int argc, char *argv[]) {
		int i = 1, j = 1, m[3][3], a, b, c, d, qtd_letras, indice, x, y;
		char alfabeto[] = {"zabcdefghijklmnopqrstuvwxy"};		
		char *palavra;
		
		while(i<=2){	
			j=1;		
			while(j<=2){
				printf("Digite o valor de A%d,%d: ",i,j);
				scanf("%d",&m[i][j]);
				j++;
			}			
			i++;
		}
		
		if(validarMatriz(m[1][1], m[1][2], m[2][1], m[2][2]) == 1){
			printf("Matriz validada com sucesso!\n\n");
		}else{
			printf("Por favor, insira outra matriz 2x2.\n\n");
		}getchar();
		
		printf("Digite a palavra: ");
		palavra = EntraString();
		qtd_letras = strlen(palavra);
		
		int matriz[2][qtd_letras/2];
		int resultante[2][qtd_letras/2];
		
		i=1; a=0;
		while(i<=qtd_letras/2){
			j = 1;
			while(j<=2){
				indice = indice_alfabeto(palavra[a]);					
				matriz[j][i] = indice;
				j++;
				a++;
			}
			i++;
		}	
		x=1;
		i = 1;j = 1;
		while(i<=qtd_letras/2){
			x =0; y=0;
			printf("x = %d\n",x);getchar();
			x = (m[1][1])*(matriz[1][i]);
			printf("x = %d = %d * %d\n",x,m[1][1],matriz[1][i]);getchar();
			printf("x = %d + %d*%d\n",x,m[1][2],matriz[2][i]);getchar();
			x = x + ((m[1][2])*(matriz[2][i]));			
			printf("x = %d\n",x);getchar();			
			printf("y = %d\n",y);getchar();
			y = (m[2][1])*(matriz[1][i]);
			printf("y = %d = %d * %d\n",y,m[2][1],matriz[1][i]);getchar();
			printf("y = %d + %d*%d\n",y,m[2][2],matriz[2][i]);getchar();
			y= y +((m[2][2])*(matriz[2][i]));		
			printf("y = %d\n",y);getchar();

			if(x<0){
				if(x>-27){
					x = 26+(x);
				}else{
					
				}
			}else if(x>26){
				x = (x%26);
			}
			if(y<0){
				if(y>-27){
					y = 26+(y);
				}
			}else if(y>26){
				y = (y%26);
			}			
			resultante[i][1] = x;
			resultante[i][2] = y;
			i++;
		}
		printf("Matriz resultante foi:\n\n");
		i=1;
		while(i<=qtd_letras/2){
			j = 1;
			while(j<=2){
				printf("|  "); 
				printf(" %d ",resultante[i][j]);
				printf("  |\n");
				j++;
			}
			printf("---\n");
			i++;
		}
		char resultado[2][qtd_letras/2];
		i=0;
		a=0;
		while(i<=qtd_letras/2){
			j = 1;
			while(j<=2){
				//printf("indice retornado = %d\n",indice);		getchar();					
				resultado[j][i] = letra_alfabeto(resultante[j][i]);
				j++;
				a++;
			}
			i++;
		}
		//printf("Nova palavra: %s\n\n",resultado);
	return 0;
}
