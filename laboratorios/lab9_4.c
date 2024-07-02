#include <stdio.h>
#include <stdlib.h>

#define MAX 100

enum meses {
    JAN = 1, FEV, MAR,
    ABR, MAI, JUN,
    JUL, AGO, SET,
    OUT, NOV, DEZ
};

typedef struct data{
    int dia, ano; 
    enum meses mes;
}Data;

typedef struct evento{
    char nome[MAX];
    char local[MAX];
    Data data;
}Evento;

void cadastrar_eventos(Evento agenda[], int n){

    for(int i = 0; i < n; i++){
        scanf("%s",agenda[i].nome);
        scanf("%s",agenda[i].local);
        scanf("%d %u %d", &agenda[i].data.dia, &agenda[i].data.mes, &agenda[i].data.ano);
    }

}

void imprimir_eventos(Evento agenda[], Data d, int n){

    int encontrado = 0;
    for(int i = 0; i < n; i++){
        if(agenda[i].data.ano == d.ano && agenda[i].data.mes == d.mes && agenda[i].data.dia == d.dia){
            printf("%s %s\n", agenda[i].nome, agenda[i].local);
            encontrado = 1;
        }
    }

    if(!(encontrado)){
        printf("Nenhum evento encontrado!");
    }
    
}

int main(){
    int qntd;
    scanf("%d", &qntd);

    Evento *agenda = malloc(qntd * sizeof(Evento));

    if(agenda == NULL){
        return 1;
    }

    cadastrar_eventos(agenda, qntd);

    Data consulta;
    scanf("%d %u %d", &consulta.dia, &consulta.mes, &consulta.ano);

    imprimir_eventos(agenda, consulta, qntd);

    free(agenda);

    return 0;
}