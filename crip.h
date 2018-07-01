#ifndef __CRIP_h
#define __CRIP_h

#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define KEY 2

/* Funcao de codificacao do texto */
string encryptRailFence(string text);
/* Funcao de decodificação do texto */
string decryptRailFence(string cipher);
/* Funcao de converte array de *cgar para string */
string sconvert(const char *pCh, int arraySize);
#endif
