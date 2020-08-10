#include <bits/stdc++.h>
#include <time.h>
using namespace std;

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

long long res;

int ale(int a, int b){
  int f = 0;
  for (int i = 1, con=0; con < 31; i*=2, con++)
    f += (rand()%2) ? i : 0 ;
  return f%(b - a + 1) + a;
}

int main(){
  
  srand(time(NULL));

  for (int ij = 1; ij <= 16; ij++){
    
    //Creando las variables para los archivos de entrada y salida
    string inputFile, outputFile;
    outputFile = inputFile = "cases/" + inToString(ij);
    inputFile += ".in";
    outputFile += ".out";
    ofstream input (inputFile);
    ofstream output (outputFile);
    
    //Los distintos casos, ajustando tamaños de entrada.
    
    int n, numax, numin;
    
    switch ( (ij - 1) / 4) {
      case 0:
        n = ale(1, 10000);
        numin = 1;
        numax = 10000;
        break;
    
      case 1:
        n = ale(1, 10000);
        numin = -100000000;
        numax = 100000000;
        break;

      case 2:
        n = ale(1, 1000000);
        numin = 1;
        numax = 1000000;
        break;

      case 3:
        n = ale(1, 10000);
        numin = -100000000;
        numax = 100000000;
    
    }

    //Se crean los casos de los problemas (.in)
    int ar[n];
    for (int i = 0; i < n; i++)
    {
      ar[i] = ale(numin, numax);
    }
    

    //Ponemos todo en los archivos
    
    input << n << '\n';

    for (int i = 0; i < n; i++)
    {
        input << ar[i] << " ";
    }
    
    
    //Solución
    
    sort(ar, ar + n);

    int cuantos = 1, res = 0;

    for(int i = 1; i < n; i++){
      if(ar[i] == ar[i-1])
        cuantos++;
      else{
        if(cuantos%2)
          res++;
        cuantos = 1;
      }
    }

    if(cuantos%2)
      res++;
    
    //Sacamos la solución
    output << res;
  }

  return 0;
}