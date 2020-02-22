# Problema

Se tiene un arreglo de $N$ números, se quiere encontrar la longitud de la subcuencia creciente más larga. Una subsecuencia consiste en elementos del arreglo tomados en el mismo orden que el orignal, por ejemplo si tenemos el arreglo $\{ 1, 5, 2, 10, 4\}$.

Entonces una subsecuencia valida es $ \{ 1, 2, 10 \} $ porque son elementos del arreglo original en su mismo orden. Más aun, $ \{ 1, 2, 4, 5 \} $ no es una subsecuencia valida porque en el arreglo original el $5$ está antes que el $2$ y el $4$ está al final. Entonces la tarea, es encontrar cuanto mide la subsecuencia más larga que sea creciente (estrictamente), en el ejemplo la subsecuencia creciente más larga es $ \{ 1, 5, 10 \} $; tambien $ \{ 1, 2, 10 \} $ y $ \{ 1, 2, 4 \} $ es valido. Por tanto, la longitud es de $3$.

# Entrada

En la primera línea va la longitud del arreglo $N$.

Después en la segunda línea van los $N$ números del arreglo.

# Salida

Un único número que representa la longitud de la subsecuencia creciente más larga

# Ejemplos

||input
5
1 5 2 10 4
||output
3
||description
Es el ejemplo descrito en el problema
||input
7
4 1 3 2 4 3 4
||output
4
||description
La maxima subcadena de es 1, 2, 3, 4
||end

# Limites

**Para el 50% de los casos**

- $1 \leq n \leq 10^4$

- $1 \leq A_i \leq 10^8$

**Para el 50% de los casos**

- $10^4 \leq n \leq 10^6$

- $1 \leq A_i \leq 10^8$