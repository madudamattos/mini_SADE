#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSade.h"
#include "tPessoa.h"

#define TAM_NOME_CAMINHO 300

int main(int argc, char *argv[]){
    char *caminhoConfig = argv[1];
    char caminhoPastaSaida[TAM_NOME_CAMINHO];
    char caminhoBancoDados[TAM_NOME_CAMINHO];
    
    if(argc < 2){
        printf("ERRO: Pasta de saída não foi informada\n");
        return 0;
    }    

    sprintf(caminhoPastaSaida, "%s/saida/", caminhoConfig);

    printf("%s", caminhoPastaSaida);

    tSade* sade = CriaSADE();

    InicializaSADE(sade, caminhoBancoDados);

    ExecutaSADE(sade, caminhoPastaSaida);

    FinalizaSADE(sade, caminhoBancoDados);

    return 0;
}

