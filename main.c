#include <stdio.h>
#include <stdlib.h>

struct no {
	int info;
	struct no* primo;
	struct no* irmao;
};

typedef struct no Arv;

/*Arv* create() {
	return NULL;
}*/

int vazia(Arv *raiz) {
	if(raiz == NULL) {
		printf("\nVazia\n");
		return 1;
	} else {
		printf("\nNao vazia\n");
		return 0;
	}
}

Arv* criarNo(int valor) {
	Arv* novoNo = (Arv*)malloc(sizeof(Arv));
	novoNo->info = valor;
	novoNo->primo = NULL;
	novoNo->irmao = NULL;
	return novoNo;
}

Arv* criarRaiz(int valor) {
	Arv* raiz = criarNo(valor);
	return raiz;
}

Arv* buscar(Arv* raiz, int valor) {
	if(raiz == NULL) {
		return NULL;
	}
	if (raiz->info == valor) {
		return raiz;
	}
	Arv* primo = buscar(raiz->primo, valor);
	if(primo != NULL) {
		return primo;
	}
	Arv* irmao = buscar(raiz->irmao, valor);
	return irmao;
}

void exibir(Arv* raiz) {
	if(raiz == NULL) {
		return NULL;
	}
	printf("%d(", raiz->info);
	Arv* primo = raiz->primo;
	if(primo == NULL) {
		return NULL;
	}
	while(primo != NULL) {
		exibir(primo);
		primo = primo->irmao;
	}
	printf(")");
}

Arv* inserir(Arv* raiz, int valorNo, int valorPai) {
	Arv* pai = buscar(raiz, valorPai);
	if(pai == NULL) {
		return NULL;
	}
	Arv* novo = criarNo(valorNo);
	novo->irmao = pai->primo;
	pai->primo = novo;
	return pai;	
}

Arv* liberar(Arv* raiz) {
	if(raiz != NULL) {
		liberar(raiz->primo);
		liberar(raiz->irmao);
		free(raiz);
		return NULL;
	}
}

int main(int argc, char *argv[]) {
	
	Arv* a = criarRaiz(9);
	
	vazia(a);
	
	inserir(a, 5, 9);
	inserir(a, 3, 9);
	inserir(a, 2, 9);
	inserir(a, 4, 5);
	inserir(a, 8, 5);
	inserir(a, 1, 5);
	inserir(a, 7, 2);
	inserir(a, 6, 2);
	inserir(a, 5, 9);
	inserir(a, 17, 3);
	
	Arv* b = buscar(a, 26);
	
	if(b != NULL) {
		printf("\nValor da busca %d\n", b->info);
	} else {
		printf("\nValor nao encontrado %s\n", b);
	}
	
	exibir(a);
	
	a = liberar(a);
	
	exibir(a);
	
	vazia(a);
	
	a = criarRaiz(7);
	
	vazia(a);
	
	exibir(a);
	
	return 0;
}
