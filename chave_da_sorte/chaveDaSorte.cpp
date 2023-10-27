/**
 * @file chaveDaSorte.cpp
 * @author your name (you@domain.com)
 * @brief Jogo que gera uma chave aleatória de 5 núemros de 1 a 50 e duas estrela de 1 a 12
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
using namespace std;

/**
 * @brief Função que gera um número aleatório entre 1 e 50
 * 
 * @return int 
 */
int geraNumero(){
    return rand() % 50 + 1;
}

/**
 * @brief Função que gera um número aleatório entre 1 e 12
 * 
 * @return int 
 */
int geraEstrela(){
    int estrela = rand() % 12 + 1;
    return estrela;
}


/**
 * @brief Função que gera uma chave aleatória de 5 números e 2 estrela com prevenção de duplicação
 * 
 * @param chave 
 * @param estrela 
 */
void geraChave(int chave[], int estrela[]){
    int i = 0, j = 0, aux = 0;
    bool repetido = false;
    while(i < 5){
        cout << "\033[2J\033[1;1H";
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
    i = 0;
    while(i < 2){
        aux = geraEstrela();
        for(j = 0; j < i; j++){
            if(aux == estrela[j]){
                repetido = true;
                break;
            }
        }
        if(!repetido){
            estrela[i] = aux;
            i++;
        }
        repetido = false;
    }   
}

/**
 * @brief Função para ordenar os arrays das chaves
 * 
 */
void ordenaChave(int chave[], int estrela[]){
    int aux = 0;
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(chave[i] > chave[j]){
                aux = chave[i];
                chave[i] = chave[j];
                chave[j] = aux;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = i + 1; j < 2; j++){
            if(estrela[i] > estrela[j]){
                aux = estrela[i];
                estrela[i] = estrela[j];
                estrela[j] = aux;
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
    int chave[5], estrela[2];
    char resposta;
    do{
        geraChave(chave, estrela);
        ordenaChave(chave, estrela);
        cout << "Chave: ";
        for(int i = 0; i < 5; i++){
            cout << chave[i] << " ";
        }
        cout << "Estrela: ";
        for(int i = 0; i < 2; i++){
            cout << estrela[i] << " ";
        }
        cout << endl;
        cout << "Deseja gerar outra chave? (s/n) ";
        cin >> resposta;
    }while(resposta == 's');
    
    return 0;
}