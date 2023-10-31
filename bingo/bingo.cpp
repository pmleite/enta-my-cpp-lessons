/**
 * @file bingo.cpp
 * @author Paulo Leite (pauloleite@enta.pt)
 * @brief Jogo do bingo
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <unistd.h>

#define NUMEROS     100
#define COLUNAS     10
#define DELAY       1000000 //1 segundo
#define MODO_AUTO   false

using namespace std;

/**
 * @brief Função que apresenta uma mensagem de boas vindas ao jogo do bingo
 * 
 */
void boasVindas(){
    cout << "\033[2J\033[1;1H"; //limpa ecrã
    cout << "Bem vindo ao jogo do bingo" << endl;
    cout << "O sorteio é compreendido entre o número 1 e " << NUMEROS << "\n\n";
    cout << "[C] Para continuar, [Q] Para sair.";
}


/**
 * @brief Função que gera um número aleatório entre 1 e 50
 * 
 * @return int 
 */
int geraNumero(){
    return rand() % NUMEROS + 1;
}

/**
 * @brief Função que gera uma chave aleatória de 5 números e 2 estrela com prevenção de duplicação
 * 
 * @param chave 
 * @param estrela 
 */
void geraChave(int chave[]){
    int i = 0, j = 0, aux = 0;
    bool repetido = false;
    while(i < NUMEROS){
        aux = geraNumero();
        for(j = 0; j < i; j++){
            if(aux == chave[j]){
                repetido = true;
                break;
            }
        }
        if(!repetido){
            chave[i] = aux;
            i++;
        }
        repetido = false;
    }
}

/**
 * @brief Função para ordenar os arrays das chaves
 * 
 */
void ordenaChave(int chave[]){
    int aux = 0;
    for(int i = 0; i < NUMEROS; i++){
        for(int j = i + 1; j < NUMEROS; j++){
            if(chave[i] > chave[j]){
                aux = chave[i];
                chave[i] = chave[j];
                chave[j] = aux;
            }
        }
    }
}

/**
 * @brief Função principal
 * 
 * @return int 
 */
int main(){

    //Gera chave da sorte e pergunta se quer outra
    char resposta;
    int ctrl = 0;

    do{
       boasVindas();
       cin >> resposta; 
       if(resposta == 'q' || resposta == 'Q'){
           return 0;
       }else if(resposta == 'c' || resposta == 'C'){
           break;
       }else{
           cout << "Opção inválida" << endl;
           usleep(DELAY);
       }
    }while(true); 
      


    do{
        
        cout << "\033[2J\033[1;1H"; //limpa ecrã
        int chave[NUMEROS];
        geraChave(chave);

        //apresenta numero de forma sequêncial com pausa de 1 segundo 
        for(int i = 0; i < NUMEROS; i++){
            cout << chave[i];
            usleep(DELAY);
            cout << "\t" << flush; 
            if((i + 1) % COLUNAS == 0){
                cout << endl;
            }
        }
        cout << endl;
        cout << "Deseja gerar outra chavsequência de bingo? (s/n) ";
        cin >> resposta;
    }while(resposta == 's');
    
    return 0;
}