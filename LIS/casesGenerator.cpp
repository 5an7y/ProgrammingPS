#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define mit(a, b) (a + b)/2

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
    f += (rand()%2) ? i : 0;
  return f%(b-a) + a;
}

int binSearch(int *arr, int l, int r, int k){
  if (l == r) return l;
  if (arr[mit(l, r)] >= k) return binSearch(arr, l, mit(l, r), k);
  return binSearch(arr, mit(l, r) + 1, r, k);
}

int ar[1000000], dp[1000000];

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

    //Los distintos casos, ajustando tamaños de entrada
    int n;
    
    switch ( (i - 1) % 2 ){
    
      case 0:
        //Primer subset
        n = ale(1, 10000);
        break;
      case 1:
        //Segundo subset
        n = ale(10000, 100000);
        break;
  
    }

    ar[0] = 0;

    for (int i = 1; i < n; i++)
      ar[i] = ar[i-1] + ale(1, 100);

    random_shuffle(ar, ar + n);

    //Ponemos todo en los archivos
    
    input << n << '\n';
    
    for (int j = 0; j < n; j++){
      input << ar[j] << " ";
      dp[j] = 0;
    }
    //Solución
    int t = 0;
    dp[0] = ar[0];

    for (int j = 1; j < n; j++){
      int p = binSearch(dp, 0, t + 1, ar[j]);
      if (p > t) t++;
      dp[p] = ar[j];
    }

    //Sacamos la solución
    output << t+1;
  }

  return 0;
}