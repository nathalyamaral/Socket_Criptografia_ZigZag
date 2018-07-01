
#include "crip.h"


string encryptRailFence(string text){

    /* cria a matriz para codificar texto simples KEY = rows, length (text) = colunas */
    char rail[KEY][(text.length())];
 
    /* preenchendo a matriz de trilhos para distinguir espaços dos em branco */
    for (int i = 0; i < KEY; i++){
        for (int j = 0; j < static_cast<int>(text.length()); j++){
            rail[i][j] = '\n';
        }
    }
 
    /* para encontrar a direção */
    bool dir_down = false;
    int row = 0, col = 0;
 
    for (int i = 0; i < static_cast<int>(text.length()); i++){
        /*  verifique a direção do fluxo
            inverter a direção se tivermos acabado
            preencheu o trilho superior ou inferior */
        if (row == 0 || row == KEY-1){
            dir_down = !dir_down;
        }
 
        /* preencha o alfabeto correspondente */
        rail[row][col++] = text[i];
 
        /* encontre a próxima linha usando o flag de direção */
        dir_down?row++ : row--;
    }
 
    /*agora podemos construir a cifra usando a matriz */
    string result;
    for (int i = 0; i < KEY; i++){
        for (int j = 0; j < static_cast<int>(text.length()); j++){
            if (rail[i][j]!='\n'){
                result.push_back(rail[i][j]);
            }
        }
    }
 
    return result;
}
 
/* Esta função recebe texto cifrado e chave e retorna o texto original após a descriptografia */
string decryptRailFence(string cipher){

    
    char rail[KEY][cipher.length()];
 
    
    for (int i = 0; i < KEY; i++){
        for (int j = 0; j < static_cast<int>(cipher.length()); j++){
            rail[i][j] = '\n';
        }
    }
 
    bool dir_down;
    int row = 0, col = 0;
 
    /* marcar com '*' */
    for (int i=0; i < static_cast<int>(cipher.length()); i++){
        /*verifique a direção do fluxo */
        if (row == 0){
            dir_down = true;
        }
        if (row == KEY-1){
            dir_down = false;
        }
 
        rail[row][col++] = '*';
 
        dir_down?row++ : row--;
    }

    int index = 0;
    for (int i = 0; i<KEY; i++){
        for (int j = 0; j < static_cast<int>(cipher.length()); j++){
            if (rail[i][j] == '*' && index < static_cast<int>(cipher.length())){
                rail[i][j] = cipher[index++];
            }
        }
    }
 
 
    /* ler a matriz em zig-zag para construir o texto resultante*/
    string result;
 
    row = 0, col = 0;
    for (int i = 0; i < static_cast<int>(cipher.length()); i++){
 
        if (row == 0){
            dir_down = true;
        }
        if (row == KEY-1){
            dir_down = false;
        }
 
        if (rail[row][col] != '*'){
            result.push_back(rail[row][col++]);
        }
 
        dir_down?row++: row--;
    }
    return result;
}
 
/* converter array char(cadeia de caractere) para string */
string sconvert(const char *CadeiadeChar, int arraySize){
    string str;

    if (CadeiadeChar[arraySize-1] == '\0'){
        str.append(CadeiadeChar);
    }else{
        for(int i = 0; i < arraySize; i++) {
            str.append(1, CadeiadeChar[i]);
        }
    }
  return str;
}
