# Descripción

Hay un nuevo superheroe en la ciudad, Santiago! Este heroe a derrotado a mucho villanos y estos tienen miedo. La gente sabe que santiago esta aquí solo porque Elías no ha hecho bien su trabajo ultimamente. Entonces, enterado de la noticia Elías decide ponerse manos a la obra y hacer algo por el pueblo.

Tras la llegada de Santiago lo villanos deciden unirse. Pero sus alianzas son especiales, la forma en la que se unen los villanos es mediante una cadena de mandos. Es decir, un villano decide aliarse a otro como su subordinado, si el villano $X$ quiere aliarse al villano $Y$, entonces $Y$ va a trabajar para $X$, donde $X$ queda como el jefe de $Y$.

Pero como en toda alianza siempre hay disputas, se rompen lazos y muchas cosas más. Entonces, es dificil llevar la cuenta de como están aliados los villanos. Elías se la pasa vigilando a los villanos y llego a que estos hacen sus alianzas de forma sencilla.

Puedes ver a los enemigos como números; esto es que estan los enemigos número $1, 2, 3,...$. Antes de que viniera Santy nadie estaba aliado con nadie. Luego, se empezaron hacer alianzas y ahora supongamos que tenemos el enemigo $X$ y $Y$. Vamos a llamar $X_{ant}$ y $Y_{ant}$ como los jefes de $X$ y $Y$ respectivamente, y $X_{sig}$ y $Y_{sig}$ como los subordinados de $X$ y $Y$ respectivamente.

Si $Y$ quiere empezar a trabajar para $X$, entonces pasan varias cosas (en caso de que no existan los jefes o subordinados se omiten los pasos correspondientes)

- El subordinado de $Y_{ant}$ ahora es $Y_{sig}$. Que es lo mismo que el jefe de $Y_{sig}$ pasa a ser $Y_{ant}$.
- El subordinado de $X$ pasa a ser $Y$.
- El subordinado de $Y$ pasa a ser $X_{sig}$.

Con este procedimiento se sabe que siempre hay un jefe de todos en cierto grupo (el que está más alto en el rango). El problema es que con los cambios es dificil saber como están la cadena de ciertos mandos y quien se alía con quien.

Por ejemplo, supongamos que tenemos a los enemigos $1, 2, 3, 4$. Entonces, al inicio cada quien es el jefe de cada uno de sus grupos (porque están solos). Ahora imaginemos que conectamos $1 -> 2$, $1 -> 3$, $4-> 1$. Aplicando lo anterior nos quedan las cadenas de mando:

$$4 -> 1$$
$$3 -> 2$$

Entonces, si queremos saber el jefe del $2$ sería $3$. Mientrás que el del $1$ sería el $4$.

# Problema

Dado $N$ el número de villanos, se haran $Q$ operaciones. Las operaciones son de la forma

- 1: **x y**. Significa que el villano $y$ trabajara para $x$ (se unen).
- 2: **x** Deberás decir el jefe maximo del grupo al que pertenece $x$ en ese punto.

Al incio todos incian solos.

# Entrada

Se te dara el número $N$, representando el número de villanos. El número $Q$ representando el número de preguntas. Las siguientes $Q$ líneas se daran caracteres que indican la operación hacer

- **U**, seguido de este caracter se te darán dos números con el cuál se hara la operacion 1.
- **J**, seguido de este caracter se te dara el numero con el cuál se hara la operacion 2.

# Salida

Se debera dar una respuesta a todas las operaciones del tipo 2, en el orden que se te fueron dadas.

# Ejemplo

||input
4 7
1 1 2
1 1 3
2 2
1 4 1
2 2
2 1
||output
1
3
4
||description
Es del ejemplo, solo notamos que después de la segunda operación la cadena queda como $1 -> 3 -> 2$ y el jefe más alto de $2$ es $1$.
||input
7 5
1 3 5
1 5 1
1 1 7
2 7
2 2
||output
3
2
||end

# Limites

- $1 \leq N \leq 10^3$
- $1 \leq Q \leq 10^5$
- $1 \leq x,y \leq N$