# Alianza de villanos (Solución)

## Reducción del problema

El problema se puede reducir a tener varias listas de nodos, entonces quieres poder quitar un nodo de cierta lista y además añadir. Debemos responder preguntas del estilo *quien es la cabeza de la lista a la que pertenece el nodo **X***.

## Solución

Para la solución usaremos una lista doblemente ligada. Podemos considerar un nodo solitario como una lista de tamaño $1$. Teniendo esto en cuenta, al inicio tenemos un total de $n$ listas de tamaño $1$.

```cpp
// Estructura del nodo
struct nodo {
  nodo *next, *ant;
  int val;
};
```

Las implementaciones se hacen con apuntadores, se pueden ajustar para usar memoria estatica. Después de cada codigo se indicara como; por ejemplo, aquí solo cambia los apuntadores por enteros.

```cpp
// Inicializamos cada nodo
for (int i = 0; i <= n; ++i) {
  conexiones[i] = new nodo;
  conexiones[i] -> val = i;
}
```

En esta caso $n$ es la cantidad de villanos. Solo se asegura que el valor de cada nodo sea su posición, para cuando iteremos con los apuntadores sepamos en que nodo estamos.

### Operación unir

Vamos a tener operaciones de dos tipos, una de ellas es la de unir. Precisamente lo que se hace es que se nos dan dos nodos, $X$ y $Y$. Vamos hacer que el siguiente a $X$ sea $Y$. 

Para eso lo que haremos es primero desconectar a $Y$ de su lista.

![Join Linked List](./img/JoinLinkedList.png)

Después conectar $Y$ a la lista de $X$.

![Join Linked List 2](./img/JoinLinkedList2.png)

```cpp
// Función para que X pase a ser jefe de Y
void unir(int x, int y) {
  
  if (conexiones[y] -> ant) {
    /* Si Y tiene un anterior, entonces el
    siguiente de ese anterior, pasa a ser el
    siguiente de Y */
    conexiones[y] -> ant -> next = conexiones[y] -> next;
  }
  if (conexiones[y] -> next) {
    /* Si Y tiene un siguiente, entonces el
    anterior de ese siguiente, pasa a ser el
    anterior de Y */
    conexiones[y] -> next -> ant = conexiones[y] -> ant;
  }

  // Hacemos que Y no apunte a nada
  conexiones[y] -> next = NULL;
  
  if(conexiones[x] -> next) {
    /* Si X tiene siguiente, hacemos ahora que
    Y apunte a ese siguiente */
    conexiones[y] -> next = conexiones[x] -> next;
    conexiones[y] -> next -> ant = conexiones[y];
  }

  // El siguiente de X pasa a ser Y
  conexiones[x] -> next = conexiones[y];
  // El anterior de Y pasa a ser X
  conexiones[y] -> ant = conexiones[x];
  return;
}
```

Si no lo implementas con apuntadroes, los -> next se deben cambiar por `conexiones[conexiones[y].next]`. Analogamente con el anterior (ya depende de como se implemente).

### Encontrar el jefe

La otra operación a realizar es encontrar la cabeza de una lista. Para eso solo vamos al nodo pedido y retrocedemos hasta encontrar el nodo que no tiene anterior

```cpp
// Funcion para ver quien es el jefe maximo de X
int BuscarElJefe (int x) {
  /* Llevamos una variable act, que es el nodo
  en el cual vamos actualmente */
  nodo* act = conexiones[x];
  /* Movemos la variable por los anteriores
  hasta que ya no exista un anterior */
  while (act -> ant) {
    act = act -> ant;
  }
  return act->val;
}
```

Usamos esa dos funciones para responder cada tipo de operación y se tiene la respuesta esperada.

En cuanto a complejidad, se tiene que **unir** es constante $O(1)$. Mientras que **buscar el jefe** es a lo más $O(N)$, considerando el caso que te dan el último nodo y todo está lleno. Y como son $Q$ preguntas se tiene de complejidad $O(N \times Q)$ en total.