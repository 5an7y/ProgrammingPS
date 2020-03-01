# Problema

Todos conocen que thanos es un villano malvado que atemoriza a los vengadores. Pero lo que nadie sabe, es que en secreto, thanos tiene el sueño de convertirse en un programador experto. En una de sus clases impartida por el maestro Santy, thanos quiere aprender a ordenar objetos, pero como no le salía ninguna implementación, decidio crear su propio ordenamiento.

El ordenamiento de thanos es muy sencillo, si el arreglo no esta ordenado (de forma no decreciente), entonces desaparece la primera mitad del arreglo y así sucesivamente hasta que el arreglo quede ordenado. Tu tarea es decir, de que tamaño queda el arreglo original despues de que thanos "ordene" el arreglo.

# Entrada

Un número $n$ representando el tamaño del arreglo original. Se siguien $n$ números que son el arreglo original.

# Salida

Un único número entero que representa el tamaño final de arreglo

# Ejemplo

||input
4
1 2 2 4
||output
4
||description
El arreglo original ya esta ordenado
||input
8
4 1 2 3 4 5 6 7
||output
4
||description
Como el arreglo original no esta ordenado se elimina la primera mitad y quedan los ultimos 4 que si estan ordenados
||end

# Limites

- $ 1 \leq n \leq 2 \times 10^6$
- $a_i \leq 10^8$
- $n$ es una potencia de 2