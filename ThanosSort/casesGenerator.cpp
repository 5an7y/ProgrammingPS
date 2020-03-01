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

int ale(int a, int b){
  int f = 0;
  for (int i = 1, con=0; con < 31; i*=2, con++)
    f += (rand()%2) ? i : 0 ;
  return f%(b-a) + a;
}

int main(){
    srand(time(NULL));

  for (int i = 1; i <= 16; i++){
    
    //Creando las variables para los archivos de entrada y salida
    string inputFile, outputFile;
    outputFile = inputFile = inToString(i);
    inputFile += ".in";
    outputFile += ".out";
    ofstream input (inputFile);
    ofstream output (outputFile);
    
    //Los distintos casos, ajustando tamaños de entrada.
    int n = ale(0, 20);
    int kn = pow(2, n);
    int p = ale(0, n);
    int kp = pow(2, p);
    int ar[kp];

    //Se crean los casos de los problemas (.in)  

    input << kn << '\n';

    for (int i = 0; i < kp; i++)
      ar[i] = ale(0, 10000000);

    sort(ar, ar + kp);

    //Ponemos todo en los archivos
    
    for (int i = 0; i < kn - kp; i++)
      input << ale(0, 10000000) << " ";

    for (int i = 0; i < kp; i++)
      input << ar[i] << " ";

    //Solución

    output << kp;
    
    //Sacamos la solución
    
  }

  return 0;
}