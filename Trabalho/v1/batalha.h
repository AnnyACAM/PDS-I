#include <stdio.h>
#include "pokemon.h"

//Indice dos jogadores
#define PLAYER1 0
#define PLAYER2 1

/*  FUNÇÃO QUE RETORNA A QUANTIDADE DE SOBREVIVENTES NO VETOR DE POKEMONS DO PLAYER */
int sobreviventes(Pokemon player[], int n){
    int sobreviventes = 0;
    for(int i = 0; i < n; i++){
        if (player[i].vida > 0) {  sobreviventes++;}
    }

    return sobreviventes;
}

/*  PROCEDIMENTO QUE IMPRIME OS NOMES DOS POKEMONS SOBREVIVENTES E DERROTADOS */
void statusPokemons(Pokemon p1[], Pokemon p2[], int tamanho[]){
    
    for(int status = 0; status < 2; status++){
        if(status == 0){    printf("Pokemon sobreviventes:\n"); }
        if(status == 1){    printf("Pokemon derrotados:\n");    }

        for (int i = 0; i < PLAYERS; i++) {
            for(int j = 0; j < tamanho[i]; j++){
                if (i == PLAYER1 && ((status == 0 && p1[j].vida > 0) || (status == 1 && p1[j].vida <= 0))) {    printf("%s\n", p1[j].nome);}
                if (i == PLAYER2 && ((status == 0 && p2[j].vida > 0) || (status == 1 && p2[j].vida <= 0))) {    printf("%s\n", p2[j].nome);}
            }
        }
    }
}

/*  FUNÇÃO QUE RETORNA O BONUS DE ATAQUE DO POKEMON */
float bonusAtaque(char* tp_pokemon, char* tp_oponente){

    // Inicias dos tipos de pokemom: e = eletrico, a = agua, f = fogo, g = gelo, p = pedra
    char tipos[5][3] = {
        {'e', 'a', 'p'},      //coluna 0 = tipo do pokemom
        {'a', 'f', 'e'},      //coluna 1 = tipo do oponente (forte)
        {'f', 'g', 'a'},      //coluna 2 = tipo do oponente (fraco)
        {'g', 'p', 'f'},
        {'p', 'e', 'g'}
    };
    
    //inciais do tipo do pokemon e do seu oponente
    char pokemon = tp_pokemon[0], oponente = tp_oponente[0]; 
    float fraco = 0.8, forte = 1.2, bonus = 1; 
    
    for(int i = 0; i < 5; i++){
        if(pokemon == tipos[i][0]){ 
            //Compara as inicias dos tipos
            if(oponente == tipos[i][1]){ bonus = forte;}
            if(oponente == tipos[i][2]){ bonus = fraco;}
        }
    }
    return bonus;
}

/*  PROCEDIMENTO QUE SIMULA A BATALHA ENTRE OS POKEMONS CALCULANDO O DANO DO OPONENTE */
void Batalha(Pokemon *pokemon, Pokemon *oponente){
    
    //Calcula o dano
    if(pokemon->vida > 0 && oponente->vida > 0){
        float dano = (pokemon->ataque * bonusAtaque(pokemon->tipo, oponente->tipo)) - oponente->defesa;

        //Subtrai o dano da vida do oponente
        if(dano > 0){
            oponente->vida -= dano;
        }else{
            oponente->vida -= 1;
        }
    }

    if(oponente->vida < 0){ oponente->vida = 0; }
}