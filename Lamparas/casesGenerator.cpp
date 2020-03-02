#include <bits/stdc++.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int PI = M_PI;

string inToString(int h){
  if(!h) return "0";
  string auxiliar = "";
  while(h){
    auxiliar+= h%10 + '0';
    h /= 10;
  }
  reverse(auxiliar.begin(), auxiliar.end());
  return auxiliar;
}

int ar[1000000];

int ale(int a, int b){
  int f = 0;
  for (int i = 1, con=0; con < 31; i*=2, con++)
    f += (rand()%2) ? i : 0 ;
  return f%(b-a) + a;
}

int main(){
    srand(time(NULL));

  for (int ij = 1; ij <= 12; ij++){
    
    //Creando las variables para los archivos de entrada y salida
    string inputFile, outputFile;
    outputFile = inputFile = inToString(ij);
    inputFile += ".in";
    outputFile += ".out";
    ofstream input (inputFile);
    ofstream output (outputFile);
    
    //Los distintos casos, ajustando tamaños de entrada.
    
    int n = ale(1, 100000);
    bool cosa[n];
    int numeros[n];
    
    for (int i = 0; i < n; i++){
      cosa[i] = false;
      numeros[i] = i;
    }

    int m = ale(1, 1000);

    //Se crean los casos de los problemas (.in)

    input << n << ' ' << m << '\n';

    for (int i = 0; i < m; i++){
      int y = ale(1, min(1000, n/20) );
      input << y << ' ';
      random_shuffle(numeros, numeros + n);
      for (int j = 0; j < y; j++){
        cosa[numeros[j]] = true;
        input << numeros[j] << ' ';
      }
      input << '\n';
    }

    //Ponemos todo en los archivos
    
    //Solución

    int con = 0;

    for (int i = 0;i < n; i++)
      if(!cosa[i])
        con++;
    
    //Sacamos la solución
      output << con;
  }

  return 0;
}