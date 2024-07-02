#include <stdio.h>
#include <string.h>

void limparBuffer(int c){
     // Limpar o buffer de entrada
        while ((c = getchar()) != '\n' && c != EOF) {
        }
}

int main()
{
    typedef struct pessoa{
        char nome[50];
        int idade;
        float salario;
    } Pessoa;
    
    Pessoa pessoas[4];
    
    char nome[50], comando[50];
    int idade;
    float salario;
    int qntd = 0, encontrado = -1, c;
    
    do{
        
        fgets(comando, 50, stdin);
        
        if(strcmp(comando, "inserir\n") == 0){
            
            
            scanf("%s", nome);
            scanf("%d", &idade);
            scanf("%f", &salario);
                
            if(qntd < 4){
                strcpy(pessoas[qntd].nome, nome);
                pessoas[qntd].idade = idade;
                pessoas[qntd].salario = salario;
                
                printf("Registro %s %d %2.f inserido\n", pessoas[qntd].nome, pessoas[qntd].idade, pessoas[qntd].salario);
    
                qntd++;
                
            }else{
                printf("Espaco insuficiente\n");
            }
            
            limparBuffer(c);
            
        }else if(strcmp(comando, "mostrar\n") == 0){
            scanf("%s", nome);
            
            for(int i = 0; i < qntd; i++){
                if(strcmp(pessoas[i].nome,nome) == 0){
                    encontrado = i;
                }
            }
            
            if(encontrado >= 0){
                printf("Registro %s %d %2.f\n", pessoas[encontrado].nome, pessoas[encontrado].idade, pessoas[encontrado].salario);
                encontrado = -1;
            }else{
                printf("Registro ausente\n");
            }
            
            limparBuffer(c);
        }
        
    }while(strcmp(comando,"\n") != 0);

    
    return 0;
}
