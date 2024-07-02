#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pokemon.h"
#include "batalha.h"

#define SUCESSO 0
#define ERRO 1

int main(){

    char name_file[MAX] = "input.txt";
    //Abre o arquivo apenas para leitura
    FILE* arquivo = fopen(name_file, "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return ERRO;
    }

    int qntd_pokemon[PLAYERS], total = 0; 

     //le a primeira linha do arquivo e verifica se foram lidos 2 numeros
    if(fscanf(arquivo, "%d %d", &qntd_pokemon[PLAYER1], &qntd_pokemon[PLAYER2]) != 2){
        printf("Erro ao ler do arquivo, os dados fornecidos nao seguem o padrao esperado");
        return ERRO;
    }

    for(int i = 0; i < PLAYERS; i++){
        //Verifica a quantidade de pokemons informados
        if(qntd_pokemon[i] > 100 || qntd_pokemon[i] <= 0){
            printf("Numero de pokemons para cadastro invalido");
            return ERRO;
        }

        total += qntd_pokemon[i]; //O total de pokemons
    }

    //Aloca vetor de pokemons para cada player
    Pokemon *player1 = malloc(qntd_pokemon[PLAYER1] * sizeof(Pokemon));
    Pokemon *player2 = malloc(qntd_pokemon[PLAYER2] * sizeof(Pokemon));

    if(player1 == NULL || player2 == NULL){
        printf("Erro ao alocar memória");
        return ERRO;
    }

    int adicionados = 0; //Quantidade/indice de pokemons adicionados 
    Pokemon *pokemon;  // Ponteiro para o pokemon atual

    while(!feof(arquivo)){ 
        
        if(adicionados < qntd_pokemon[PLAYER1]){
            //Adiciona todos os pokemons do player 1
            pokemon = &player1[adicionados]; 
        }else if(adicionados - qntd_pokemon[PLAYER1] < qntd_pokemon[PLAYER2]){
            //Adiciona pokemons do Player 2 após todos do Player 1 terem sido adicionados
            pokemon = &player2[adicionados - qntd_pokemon[PLAYER1]]; 
        }

        // Lê os dados do pokemon do arquivo
        int conteudo = fscanf(arquivo, "%s %f %f %f %s\n", pokemon->nome, &pokemon->ataque, &pokemon->defesa, &pokemon->vida, pokemon->tipo);

        //Verifica se a linha segue o padrao
        if(conteudo != 5){
            printf("Erro ao ler do arquivo, os dados fornecidos nao seguem o padrao esperado");
            return ERRO;
        }

        adicionados++; // Incrementa o contador de pokemons adicionados

    }

    //Verifica se a quantidade de pokemons cadastrados é igual a quantidade de pokemons informados no arquivo
    if(adicionados > total || adicionados < total){
        printf("Numero incorreto de pokemons informado");
        return ERRO;
    }
    
    int player_turno = 0;
    int p1 = 0, p2 = 0; //Indices dos vetores de Pokemons do Players

    while (sobreviventes(player1, qntd_pokemon[PLAYER1]) > 0 && sobreviventes(player2, qntd_pokemon[PLAYER2]) > 0) {
        
        //O turno define qual player ira atacar
        if(player_turno == PLAYER1){
            Batalha(&player1[p1], &player2[p2]); 

        } else if(player_turno == PLAYER2){
            Batalha(&player2[p2], &player1[p1]); 
        }      

        //Caso ambos sobrevivam troca de turno
        if(player1[p1].vida > 0 && player2[p2].vida > 0){
            //Varia entre 0 e 1
            player_turno = 1 - player_turno; 
        } 

        //Caso um dos pokemons tenha sido derrotado
        //O indice do player aumenta e troca de turno
        if(player2[p2].vida <=0){ 
            printf("%s venceu %s\n", player1[p1].nome, player2[p2].nome);
            p2++;  
            player_turno = PLAYER1;
        }
        
        if(player1[p1].vida <=0){
            printf("%s venceu %s\n", player2[p2].nome, player1[p1].nome);
            p1++;
            player_turno = PLAYER2;
        }
                
    }
    
    //Define o vencendor
    if(sobreviventes(player1, qntd_pokemon[PLAYER1]) > 0){
        printf("Jogador 1 venceu!\n");

    }else if(sobreviventes(player2, qntd_pokemon[PLAYER2]) > 0){
        printf("Jogador 2 venceu!\n");
    }

    //Mostra os pokemons sobreviventes e derrotados
    statusPokemons(player1, player2, qntd_pokemon);

    //Libera memória alocada
    free(player1);
    free(player2);

    //Fecha o arquivo
    fclose(arquivo);

    return SUCESSO;
}