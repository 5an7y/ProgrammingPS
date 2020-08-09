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
  return f%(b - a + 1) + a;
}

struct nodo{
  nodo* next;
  int val;
  nodo* ant;
  nodo(){
    next = ant = NULL;
    val = 0;
  }
  ~nodo(){
    next = ant = NULL;
    val = 0;
  }
};

void unir(int x, int y, nodo** con){
  if(con[y] -> ant && con[y] -> next){
    (con[y] -> ant) -> next = con[y] -> next;
    (con[y] -> next) -> ant = con[y] -> ant;
  } else{
    if (con[y] -> ant)
      (con[y] -> ant) -> next = NULL;
    if(con[y] -> next)
      (con[y] -> next) -> ant = NULL;
  }

  if(con[x] -> next){
    con[y] -> next = con[x] -> next;
    (con[y] -> next) -> ant = con[y];
  }else{
    con[y] -> next = NULL;
  }
  con[x] -> next = con[y];
  con[y] -> ant = con[x];
  return;
}

int jefe (int x, nodo** con){
  nodo * act = con[x];
  while (act -> ant)
    act = act -> ant;
  return act->val;
}

int main(){
    srand(time(NULL));
  nodo **ar = new nodo*[1001];

  for(int i = 0; i < 1001; i++){
    ar[i] = new nodo;
    ar[i] -> val = i;
  }
  for (int ij = 1; ij <= 16; ij++){
    
    //Creando las variables para los archivos de entrada y salida
    string inputFile, outputFile;
    outputFile = inputFile = "cases/" + inToString(ij);
    inputFile += ".in";
    outputFile += ".out";
    ofstream input (inputFile);
    ofstream output (outputFile);
    
    //Los distintos casos, ajustando tamaños de entrada.
    int n = ale(1, 1000);
    int q = ale(1, 10000), x, y; 

    if(ij%8 == 0){
      n = ale(2, 20);
      q = ale(2, 30);
    }

    cout << "Caso: " << ij << " con n = " << n << " y q = " << q << "\n"; 

    for (int i = 1; i <= n; i++)
    {
      ar[i] -> next = NULL;
      ar[i] -> ant = NULL;
    }
    

    input << n << " " << q << '\n';

    for (int i = 0; i < q; i++) {
      
      int tipo = ale(0, 1);
      x = ale(1, n);
      
      if(tipo){
        do {y = ale(1, n);} while(x == y);
        input << "U " << x << " " << y << '\n';
        unir(x, y, ar);
      }else{
        input << "J " << x << '\n';
        output << jefe(x, ar) << '\n';
      }
    }
    
  }

  for(int i = 0; i < 1001; i++)
    delete ar[i];

  delete ar;

  return 0;
}