#include <stdio.h>
#include <string.h>

void limparBuffer(int c){
     // Limpar o buffer de entrada
        while ((c = getchar()) != '\n' && c != EOF) {
        }
}

int main()
{
    typedef struct endereco{
        char rua[50];
        char estado[50];
        int numero;
    } Endereco;
    
    typedef struct pessoa{
        char nome[50];
        int idade;
        float salario;
        Endereco endereco;
    } Pessoa;
    
    Pessoa pessoas[5];
    
    char comando[50];
    int qntd = 0, encontrado = -1, c, opcao;
    
    do{
        
        fgets(comando, 50, stdin);
        comando[strlen(comando) -1] = '\0';
        
        if (strcmp(comando, "inserir") == 0) {  opcao = 1; }
        if (strcmp(comando, "mostrar") == 0) {  opcao = 2; }
        if (strcmp(comando, "alterar") == 0) {  opcao = 3; }
        if (strcmp(comando, "") == 0)  {         break;    }
        
        char nome[50], rua[50], estado[50];
        int idade, numero;
        float salario;
        
        switch(opcao){
            case 1: {
                scanf("%s", nome);
                scanf("%d", &idade);
                scanf("%f", &salario);
                scanf("%s", rua);
                scanf("%d", &numero);
                scanf("%s", estado);
                    
                if(qntd >= 5){ 
                    printf("Espaco insuficiente\n");
                }else{
                    strcpy(pessoas[qntd].nome, nome);
                    pessoas[qntd].idade = idade;
                    pessoas[qntd].salario = salario;
                    strcpy(pessoas[qntd].endereco.rua, rua);
                    pessoas[qntd].endereco.numero = numero;
                    strcpy(pessoas[qntd].endereco.estado, estado);
                    
                    printf("Registro %s %d %.2f %s %d %s inserido\n", pessoas[qntd].nome, pessoas[qntd].idade, pessoas[qntd].salario, pessoas[qntd].endereco.rua,pessoas[qntd].endereco.numero, pessoas[qntd].endereco.estado);
            
                    qntd++;
                }
                 
                limparBuffer(c);  
                break;
            }
            case 2:{
                scanf("%s", nome);
                
                for(int i = 0; i < qntd; i++){
                    if(strcmp(pessoas[i].nome,nome) == 0){
                        encontrado = i;
                    }
                }
                
                if(encontrado >= 0){
                    printf("Registro %s %d %.2f %s %d %s\n", pessoas[encontrado].nome, pessoas[encontrado].idade, pessoas[encontrado].salario, pessoas[encontrado].endereco.rua,pessoas[encontrado].endereco.numero, pessoas[encontrado].endereco.estado);
                    encontrado = -1;
                }else{
                    printf("Registro ausente\n");
                }
                
                limparBuffer(c);
                break;
            }
            case 3:{
                scanf("%s", nome);
                scanf("%d", &idade);
                scanf("%f", &salario);
                scanf("%s", rua);
                scanf("%d", &numero);
                scanf("%s", estado);
                
                for(int i = 0; i < qntd; i++){
                    if(strcmp(pessoas[i].nome,nome) == 0){
                        encontrado = i;
                    }
                }
                
                if(encontrado >= 0){
                    strcpy(pessoas[encontrado].nome, nome);
                    pessoas[encontrado].idade = idade;
                    pessoas[encontrado].salario = salario;
                    strcpy(pessoas[encontrado].endereco.rua, rua);
                    pessoas[encontrado].endereco.numero = numero;
                    strcpy(pessoas[encontrado].endereco.estado, estado);
                    
                    printf("Registro %s %d %.2f %s %d %s alterado\n", pessoas[encontrado].nome, pessoas[encontrado].idade, pessoas[encontrado].salario, pessoas[encontrado].endereco.rua,pessoas[encontrado].endereco.numero, pessoas[encontrado].endereco.estado);
                    
                    encontrado = -1;   
                }else{
                    printf("Registro ausente para alteracao\n");
                }
                
                limparBuffer(c);
                break;
            }
        }
        
        
    }while(1);

    
    return 0;
}
