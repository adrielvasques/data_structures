#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag = 0;
typedef struct tipoRegistro{
	char comp[15];
}tipoRegistro;

typedef struct tipoNo{
	tipoRegistro dado;
	struct tipoNo *prox;
}tipoNo;

typedef struct tipoFila{
	struct tipoNo *prim;
    struct tipoNo *ult;
}tipoFila;

void criaFila(tipoFila *plista){
	plista->prim=NULL;
    plista->ult=NULL;
}


void inserirNafila(tipoFila *plista,tipoRegistro *al){
	tipoNo *aux;
	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->dado = *al;
    aux->prox = NULL;
    if(plista->ult){
        plista->ult->prox =aux;
    }else{
        plista->prim = aux;
    }
    plista->ult = aux;
}




void mostradado(tipoRegistro al){
	printf("%s\n", al.comp);
}


void mostraFila(tipoFila *plista){
	tipoNo *aux;
	aux = plista->prim;
    while(aux){
        mostradado(aux->dado);
        aux = aux->prox;
    }
}

void mostraFilaAviao(tipoFila *plista){
	tipoNo *aux;
	aux = plista->prim;
    while(aux){
		  printf("%s\n", aux->dado.comp);
        aux = aux->prox;
    }
}

void mostraPrim(tipoFila *plista){
	tipoNo *aux;
	aux = plista->prim;
   //mostradado(aux->dado);
	printf("%s\n", aux->dado.comp);
}

void contaAvioes(tipoFila *plista){
	tipoNo *aux;
	aux = plista->prim;
	int cont= 0;
    while(aux){
        cont++;
        aux = aux->prox;
    }
	printf("%d\n", cont);
}

int removedaFila(tipoFila *plista){
	tipoNo *tmp;
	tmp = plista->prim;
	if(tmp){
		plista->prim = tmp->prox;
		if(plista->prim == NULL){
			plista->ult == NULL; 
		}
		free(tmp);
	}

}

void removeinicio(tipoFila *plista){
	tipoNo *aux;
	aux = plista->prim;
    while(aux){
		  memmove(aux->dado.comp, aux->dado.comp +2 , 15);
        aux = aux->prox;
    }
	

}

void processa(tipoFila *plista, tipoFila *paviao){
	tipoNo *aux;
	aux = plista->prim;
    while(aux){
		 	if(aux->dado.comp[0] ==  65){
			   memmove(aux->dado.comp, aux->dado.comp +2 , 15);
				inserirNafila(paviao, &aux->dado);
			}
        if(aux->dado.comp[0] == 81){ //Q - conta avioes na lista
			  contaAvioes(paviao);
		  }else if(aux->dado.comp[0] == 68){//D - remove primeiro item da fila
			  removedaFila(paviao);
		  }else if(aux->dado.comp[0] == 76){//L - imprime toda lista
			  mostraFilaAviao(paviao);
		  }else if(aux->dado.comp[0] == 80){ //P - - imprime primeiro da lista 
			 	mostraPrim(paviao);
		  }
        aux = aux->prox;
    }
}


int main() {
	tipoFila acoes;
	tipoFila avioes;
	tipoRegistro dado;
	criaFila(&acoes);
	criaFila(&avioes);

	while(1) {
		 scanf("%[^\n]s", dado.comp);
		 getchar();

		if(dado.comp[0] == 83){
			  break;
		 }

			 inserirNafila(&acoes, &dado);
	}
		//removeinicio(&avioes);
		processa(&acoes,&avioes);
}
