#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag = 0;
struct noletra {
    char data;
    struct noletra* prox;
};
typedef struct tipoRegistro{
	char cadeia[100];
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
	printf("%s\n", al.cadeia);
}

void mostraFila(tipoFila *plista){
	tipoNo *aux;
	aux = plista->prim;
    while(aux){
        mostradado(aux->dado);
        aux = aux->prox;
    }
}


int par(char ch1, char ch2){
    if (ch1 == '(' && ch2 == ')')
        return 1;
    else if (ch1 == '{' && ch2 == '}')
        return 1;
    else if (ch1 == '[' && ch2 == ']')
        return 1;
    else
        return 0;
}




int retiradaPilha(struct noletra** top_letra){
    char res;
    struct noletra* topo;
    if (*top_letra == NULL) {
        exit(0);
    }
    else {
        topo = *top_letra;
        res = topo->data;
        *top_letra = topo->prox;
        free(topo);
        return res;
    }
}


void botanaFila(struct noletra** topo_ref, int novo_dado){
    struct noletra* novo_no = (struct noletra*)malloc(sizeof(struct noletra));
    if (novo_no == NULL) {
        exit(0);
    }
    novo_no->data = novo_dado;
    novo_no->prox = (*topo_ref);
    (*topo_ref) = novo_no;
}


int eBalanceado(char cadeia_car[]){
	int i =0;
	struct noletra* l1 = NULL;
	while (cadeia_car[i]){
        if (cadeia_car[i] == '{' || cadeia_car[i] == '(' || cadeia_car[i] == '['){
		botanaFila(&l1, cadeia_car[i]);
	}    
        if (cadeia_car[i] == '}' || cadeia_car[i] == ')' || cadeia_car[i] == ']') {
            if (l1 == NULL)
                return 0;
            else if (!par(retiradaPilha(&l1), cadeia_car[i]))
                return 0;
        }
        i++;
    }

    if (l1 == NULL)
        return 1; 
    else
        return 0; 
}


void verificasequencia(tipoFila *plista){
	tipoNo *aux;
	aux = plista->prim;
    while(aux){
        if (eBalanceado(aux->dado.cadeia)){
			   printf("SIM \n");
		  }else{       
			  printf("NAO \n");
		  }
		 aux = aux->prox;
    }
}



int main() {
    tipoRegistro dado;
	 tipoFila l3;
	 criaFila(&l3);

while(1){
	 scanf("%[^\n]s", dado.cadeia);
	 getchar();
    if(!strcmp(dado.cadeia, "###")){
		  break;
	 } 
	inserirNafila(&l3, &dado);
}
	verificasequencia(&l3);
}
