#ifndef POKEMON
#define POKEMON

#define MAX 500 //tamanho máximo da string
#define PLAYERS 2 //quantidade de jogadores

/* -------- ESTRUTURA DE DADOS POKEMON ----------*/
typedef struct pokemon{
    char nome[MAX];
    float ataque;
    float defesa;
    float vida;
    char tipo[MAX];
}Pokemon;

#endif //POKEMON