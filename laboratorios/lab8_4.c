#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUANTIDADE 10

typedef struct aluno {
    char nome[50];
    char sobrenome[50];
    int matricula;
    float notas[3];
    float media;
} Aluno;

int MelhorAluno(Aluno *alunos){
    int posc = 0;
    
    for(int i = 0; i < QUANTIDADE; i++){
        if(alunos[posc].media < alunos[i].media){
            posc = i;
        }else if(alunos[posc].media == alunos[i].media){
            
            if (alunos[i].matricula < alunos[posc].matricula) {
                posc = i;
            }
        }
    }
    
    return posc;
    
}

int PiorAluno(Aluno *alunos){
    int posc = 0;
    
    for(int i = 0; i < QUANTIDADE; i++){
        if(alunos[i].media < alunos[posc].media){
            posc = i;
        }else if(alunos[posc].media == alunos[i].media){
            if (alunos[i].matricula < alunos[posc].matricula) {
                posc = i;
            }
        }
    }
    
    return posc;
    
}

int main() {

    Aluno alunos[QUANTIDADE];
    int qntd = 0;

    do {
        
        float media = 0;
        int j = 4;
        
        scanf("%s", alunos[qntd].nome);
        scanf("%s", alunos[qntd].sobrenome);
        scanf("%d", &alunos[qntd].matricula);
        for(int i = 0; i < 3; i++){
            scanf("%f", &alunos[qntd].notas[i]);
            media += alunos[qntd].notas[i] * (j--); //Dar pesos as materias
        }
        alunos[qntd].media = media / 6; //Dividi pela soma dos pesos(3, 2, 1)
        
        qntd++;

    } while (qntd < QUANTIDADE);
    
    int melhorAluno = MelhorAluno(alunos);
    int piorAluno = PiorAluno(alunos);
    
    float media_melhorA = 0;
    for(int i = 0; i < 3; i++)
        media_melhorA += alunos[melhorAluno].notas[i];
        media_melhorA = media_melhorA / 3;
    
    printf("Melhor Aluno: %s %s\n", alunos[melhorAluno].nome, alunos[melhorAluno].sobrenome);
    printf("Matrícula: %d\n", alunos[melhorAluno].matricula);
    printf("Média: %.02f\n", media_melhorA);
    printf("Situação: ");
    
    int xara = -1;
    
    if(strcmp(alunos[piorAluno].nome,alunos[melhorAluno].nome) == 0){
        printf("O melhor aluno quer mudar de nome");

    }else{
        
        for(int i = 0; i < QUANTIDADE; i++){
            if((strcmp(alunos[i].nome,alunos[melhorAluno].nome) == 0)&&(i != melhorAluno)){
                xara = i;
                break;
            }
        }
        
        if(xara < 0){
            printf("O melhor aluno não tem xará");

        }else{
            //Conseguiu passar em todas as materias
            for(int j = 0; j < 3; j++)
                if(alunos[xara].notas[j] < 60){
                    printf("O melhor aluno evita seu xará");
                    return 0;
                }
            printf("O melhor aluno é amigo do seu xará");
        }
    }

    return 0;
}
