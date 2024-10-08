#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBiopsia.h"

#include "tEncaminhamento.h"

struct tEncaminhamento{
    char nomePaciente[100];
    char CPF[20];
    char nomeEspecialidade[50];
    char motivo[300];
    char nomeMedico[100];
    char CRM[20];
    char dataStr[20];
};

tEncaminhamento *criaEncaminhamento(char *nomePaciente, char* CPF, 
                                    char *nomeEspecialidade, char *motivo, char *nomeMedico, char *CRM, char *dataStr){
    
    tEncaminhamento *e = (tEncaminhamento *)calloc(1, sizeof(tEncaminhamento));

    strncpy(e->nomePaciente, nomePaciente, sizeof(e->nomePaciente) - 1);
    strncpy(e->CPF, CPF, sizeof(e->CPF) - 1);
    strncpy(e->nomeEspecialidade, nomeEspecialidade, sizeof(e->nomeEspecialidade) - 1);
    strncpy(e->motivo, motivo, sizeof(e->motivo) - 1);
    strncpy(e->nomeMedico, nomeMedico, sizeof(e->nomeMedico) - 1);
    strncpy(e->CRM, CRM, sizeof(e->CRM) - 1);
    strncpy(e->dataStr, dataStr, sizeof(e->dataStr) - 1);

    return e;
}


void desalocaEncaminhamento(void *dado){
    if(dado != NULL){
        free(dado);
    }

}

void imprimeNaTelaEncaminhamento(void *dado){
    
    if(dado != NULL){
        tEncaminhamento *e = (tEncaminhamento *)dado;

        printf("PACIENTE: %s\n", e->nomePaciente);
        printf("CPF: %s\n\n", e->CPF);
        printf("ESPECIALIDADE ENCAMINHADA: %s\n\n", e->nomeEspecialidade);
        printf("MOTIVO: %s\n\n", e->motivo);
        printf("%s (%s)\n", e->nomeMedico, e->CRM);
        printf("%s\n\n", e->dataStr);
    
    }
}

void imprimeEmArquivoEncaminhamento(void *dado, char *path){
    FILE *pEncaminhamento = NULL;
    char caminho[100];

    sprintf(caminho, "%s/%s", path, NOME_ARQUIVO_ENCAMINHAMENTO);

    pEncaminhamento = fopen(caminho, "a");

    if(pEncaminhamento == NULL){
        printf("ERRO: Não foi possível abrir o arquivo de encaminhamento\n");
        return;
    }
    
    if(dado != NULL){
        tEncaminhamento *e = (tEncaminhamento *)dado;

        fprintf(pEncaminhamento, "PACIENTE: %s\n", e->nomePaciente);
        fprintf(pEncaminhamento, "CPF: %s\n\n", e->CPF);
        fprintf(pEncaminhamento, "ESPECIALIDADE ENCAMINHADA: %s\n", e->nomeEspecialidade);
        fprintf(pEncaminhamento, "MOTIVO: %s\n\n", e->motivo);
        fprintf(pEncaminhamento, "%s (%s)\n", e->nomeMedico, e->CRM);
        
        fprintf(pEncaminhamento, "%s\n\n", e->dataStr);
    }

    fclose(pEncaminhamento);


}
