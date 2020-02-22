Ultimamente el *coronavirus* ha sido un virus con gran efecto alrededor de todo el mundo, el problema con este virus es que no se había encontrada una cura ¡Hasta el día de hoy! Milagrosamente en la Organización de Mundos Intergalacticos (OMI) se ha encontrado una forma de combatir contra tan temible virus. Lo malo es que es un proceso un poco costoso. El coronavirus se ha visto (no efectos de la vida real) que cambia la secuencia de ADN en tu cuerpo, por tanto, la cura que se ha ideado es volver a los genes como estabán antes.

Existen dos tipos de genes diremos "1" y "0". Los genes normalmente están intercalados, es decir, después de un 1 siempre va un 0 y después de un 0 siempre va ir un 1. Esto quiere decir que los genes deben tener la forma ... 0 1 0 1 0 1 ..., entonces el coronavirus afecta esto y cambia unos genes.

Se ha creado una maquina que puede hacer 2 operaciones:
- Intercambiar la posición de dos genes. Es decir, si yo tengo 1 1 0 0; podemos intercambiar el de la ultima posicion con el de la primera para que quede 0 1 0 1.
- Cambiar un gen completo, es decir, si tenemos 1 1 1; podemos cambiar el gen de en medio por un 0.

Como cada vez que la maquina hace una operación genera cierto costo, nosotros queremos minimizar el número de movimientos.

# Problema

Dada una cadena genetica (representado por $n$ números $0$ o $1$) decir cuál es la minima cantidad necesaria de movimientos para generar una secuencia *normal* (que después de cada $0$ haya un $1$ y viceversa)

# Entrada

En la primera linea un número $n$ que representa el tamaño de la cadena genetica. En la siguiente linea $n$ números separados por un espacio representando la cadena genetica.

# Salida

Un único número entero que representa la cantidad mínima de movimientos a realizar.

# Ejemplos

|input
3
1 1 1
|output
1
|description
Solo debemos realizar la operación de cambiar un gen y cambiamos el de en medio.
|input
6
0 1 0 0 1 0
|output
2
|description
Podemos cambiar el ultimo 1 de posición con el tercer 0 y nos queda 0 1 0 1 0 0
Y solo cambiamos el último gen por un 1 para obtener 0 1 0 1 0 1.
|end

# Limites

**Para 1/4 de los casos**
- $1 \leq n \leq 10³$
- Solo se requieren hacer operaciones de intercambiar
  
**Para 1/8 de los casos**
- $1 \leq n \leq 10³$
- Solo se requieren hacer operaciones de poner uno nuevo

**Para 1/8 de los casos**
- $1 \leq n \leq 10³$

**Para 1/4 de los casos**
- $10³ \leq n \leq 10⁴$

**Para 1/4 de los casos**
- $10⁴ \leq n \leq 10⁶$