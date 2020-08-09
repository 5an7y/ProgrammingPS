#include <bits/stdc++.h>
using namespace std;

// Estructura del nodo
struct nodo {
  nodo *next, *ant;
  int val;
};

nodo *con[1001]; // Arreglo donde se guardan los nodos
int n, q, x, y;
char tipo;

// Función para que X pase a ser jefe de Y
void unir(int x, int y, nodo** con) {
  
  if (con[y] -> ant && con[y] -> next) {
    /* Si Y tiene tanto un anterior como un siguiente
    entonces hacemos que el anterior se conecte con el 
    siguiente */
    con[y] -> ant -> next = con[y] -> next;
    con[y] -> next -> ant = con[y] -> ant;
  } else if (con[y] -> ant) {
    /* Si Y solo tiene un anterior entonces el
    siguiente de ese anterior pasa a ser nadie
    (NULL) */
    con[y] -> ant -> next = NULL;
  } else if (con[y] -> next) {
    /* Si Y solo tiene un siguiente entonces el
    anterior de ese siguiente pasa a ser nadie
    (NULL) */
    con[y] -> next -> ant = NULL;
  }

  // Hacemos que Y no apunte a nada
  con[y] -> next = NULL;
  
  if(con[x] -> next) {
    /* Si X tiene siguiente, hacemos ahora que
    Y apunte a ese siguiente */
    con[y] -> next = con[x] -> next;
    con[y] -> next -> ant = con[y];
  }

  // El siguiente de X pasa a ser Y
  con[x] -> next = con[y];
  // El anterior de Y pasa a ser X
  con[y] -> ant = con[x];
  return;
}

// Funcion para ver quien es el jefe maximo de X
int jefe (int x, nodo** con) {
  /* Llevamos una variable act, que es el nodo
  en el cual vamos actualmente */
  nodo * act = con[x];
  /* Movemos la variable por los anteriores
  hasta que ya no exista un anterior */
  while (act -> ant) {
    act = act -> ant;
  }
  return act->val;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0); 

  // Leer la entrada
  cin >> n >> q;

  // Inicializamos cada nodo
  for(int i = 0; i <= n; i++){
    con[i] = new nodo;
    con[i] -> val = i;
  }

  for (int i = 0; i < q; i++) {
      
    cin >> tipo;
    if (tipo == 'U') { // Operacion unir
      cin >> x >> y;
      unir(x, y, con);
    } else { // Decir quien es el jefe
      cin >> x;
      cout << jefe(x, con) << '\n';
    }
    
  }

  for(int i = 0; i <= n; i++)
    delete con[i]; // Borrar todos los nodos

  return 0;
}