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

int ar[1000000];

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
    int n;
    switch ( (i-1)/4 ){
    
    case 0:
      n = ale(0, 10000);
      break;
    case 1:
      n = ale(0, 1000);
      break;

    case 2:
      n = ale(1000, 10000);
      break;

    case 3:
      n = ale(10000, 1000000);
      break;
    }
    //Se crean los casos de los problemas (.in)
    if ((i-1)/4 == 0 ){
      int k = rand()%2;
      for (int j = 0; j < n; j++)
        ar[j] = (j + k)%2;
      random_shuffle(ar, ar + n);
    }else{
      if (i == 5 || i == 6)
        for (int j = 0; j < n; j++)
          ar[j] = i%2; 
      else 
        for (int j = 0; j < n; j++)
          ar[j] = rand()%2;
    }
    //Ponemos todo en los archivos
    input << n << '\n';
    for (int j = 0; j < n; j++)
      input << ar[j] << " ";
    //Solución
    int x1, y1, x2, y3;
    x1 = y1 = x2 = y3 = 0;    
    for (int j = 0; j < n; j++){
      if(j%2)
        if(ar[j]%2) x2++;
        else x1++;
      else 
        if(ar[j]%2) y1++;
        else y3++;
    }
    //Sacamos la solución
    output << min( max(x1, y1), max(x2, y3) );
  }

  return 0;
}