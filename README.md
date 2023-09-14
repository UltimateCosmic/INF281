# INF281 - Lenguaje de Programación 1 👨🏻‍💻
Este es un repositorio de solucionarios del curso de Lenguaje de Programación 1. Incluye soluciones de laboratorios y exámenes.
## Detalles
- La mayoría de las evaluaciones están desarrolladas hasta el ciclo 2023-1.
- El archivo `.gitignore` sirve para ignorar las carpetas y archivos de los proyectos que se generan al momento de la compilación.
- Cualquier duda que pueda aclarar o si necesitan ayuda me pueden contactar por Discord (**cosmodev**).

[![ANSI C](https://i.imgur.com/tFapy8s.png "ANSI C")](https://i.imgur.com/tFapy8s.png "ANSI C")
> Nota: Si alguien desea aportar al repositorio pueden hacer un pull request. Lo mismo si ven alguna falla en los códigos ya que son muchos programas.
---
# **Capítulo 1 - Introducción al Lenguaje C++**
Este documento es el primer capítulo del curso INF281 - Lenguaje de Programación 1 y se enfoca en una introducción al lenguaje de programación C++.

## **Etapas en la generación de un programa: Compilación y enlace**
Para que un computador entienda un programa hay que traducirlo a un lenguaje que entienda, esto es lenguaje de máquina. Al proceso de traducción se le llama compilación.

### Precompilación
Proceso previo a la compilación. Se debe declarar cualquier cosa antes de utilizarla, esto incluye las instrucciones del preprocesador (las que empiezan con #). La precompilación consiste en ejecutar instrucciones de preprocesador antes de empezar la traducción de máquina. 

![Untitled](./Adicional/Pictures/Untitled.png)

La función de la instrucción `#include <iostream>` es buscar el archivo de textos “iostream” y extraer todo el código que se encuentra en él, y lo coloca en el reemplazo de la instrucción. Dentro de este archivo se encuentra la declaración del identificador “cout”, por eso no hay necesidad de hacerlo cada vez que iniciamos un proyecto o programa.

![Untitled](./Adicional/Pictures/Untitled%201.png)

![Untitled](./Adicional/Pictures/Untitled%202.png)

### Compilación
Es la traducción del código de nuestro programa a lenguaje de máquina. Se traduce a archivos con extensión .o, los cuales se le les denomina programa objeto, pero estos aún no pueden ejecutarse. Esto quiere decir, que nuestra computadora entienda las ordenes, pero aún no sabe como ejecutarlas porque le falta las instrucciones.

![Untitled](./Adicional/Pictures/Untitled%203.png)

![Untitled](./Adicional/Pictures/Untitled%204.png)

### Enlace
El compilador crea un nuevo archivo agregándole al código del programa objeto todo lo que se requiera para ejecutarse. También agregará las instrucciones para que el programa pueda ejecutarse independientemente de cualquier otro programa.

![Untitled](./Adicional/Pictures/Untitled%205.png)

## **Tipos de datos en C++**
Existen varios tipos de datos en C++, a continuación una lista de ellos, acompañado de su tamaño.

| Group | Type names* | Notes on size / precision |
| --- | --- | --- |
| Character types | char | Exactly one byte in size. At least 8 bits. |
|  | char16_t | Not smaller than char. At least 16 bits. |
|  | char32_t | Not smaller than char16_t. At least 32 bits. |
|  | wchar_t | Can represent the largest supported character set. |
| Integer types (signed) | signed char | Same size as char. At least 8 bits. |
|  | signed short int | Not smaller than char. At least 16 bits. |
|  | signed int | Not smaller than short. At least 16 bits. |
|  | signed long int | Not smaller than int. At least 32 bits. |
|  | signed long long int | Not smaller than long. At least 64 bits. |
| Integer types (unsigned) | unsigned char | (same size as their signed counterparts) |
|  | unsigned short int |  |
|  | unsigned int |  |
|  | unsigned long int |  |
|  | unsigned long long int |  |
| Floating-point types | float |  |
|  | double | Precision not less than float |
|  | long double | Precision not less than double |
| Boolean type | bool |  |
| Void type | void | no storage |
| Null pointer | decltype(nullptr) |  |

## **Diferencias ente el Lenguaje C y el Lenguaje C++**
El Lenguaje C es el núcleo de lenguajes C++, Java y C#. Por lo que C y C++ son lenguajes de programación diferentes, pero se puede decir que C es un subconjunto de C++.

![Lo que hacemos en C se puede en C++, pero no viceversa.](./Adicional/Pictures/Untitled%206.png)

Lo que hacemos en C se puede en C++, pero no viceversa.

Novedades con la llegada de C++ (Bjarne Stroustrup):

- Programación orientada a objetos (POO).
- Sobrecarga de funciones y operadores.
- Programación genérica mediante uso de plantillas.

### Instrucción `#include`
Ahora, en C++, añadimos las bibliotecas sin la extensión `.h`. Y las librerías que previamente usábamos en lenguaje C se les antepone la letra `c` al momento de añadirlas.

![Untitled](./Adicional/Pictures/Untitled%207.png)

### Espacio de Nombres `namespace`
Puede existir algo llamado choque entre elementos, esto sucede cuando dos identificadores con el mismo nombre son incluidos en un proyecto desde dos bibliotecas de funciones diferentes. Esto se puede solucionar con la instrucción `namespace`. La instrucción nos permite asignarle un nombre a un conjunto de funciones. 

![Uso del `namespace` en un header o archivo .h](./Adicional/Pictures/Untitled%208.png)

Uso del `namespace` en un header o archivo .h

![Uso del `namespace` en un archivo .c](./Adicional/Pictures/Untitled%209.png)

Uso del `namespace` en un archivo .c

![Uso del `namespace` en el archivo main.c](./Adicional/Pictures/Untitled%2010.png)

Uso del `namespace` en el archivo main.c

<aside>
💡 El espacio de nombres se separa del nombre de la función por el operador `::` que se denomina operador de ámbito.

</aside>

Hay formas para simplificar el uso de funciones definidas con un `namespace`, ejemplo:

- Cuando tenemos que usar una función de una espacio de nombres varias veces.

![Untitled](./Adicional/Pictures/Untitled%2011.png)

- Cuando tenemos que usar muchas funciones de un mismo espacio de nombres.

![Untitled](./Adicional/Pictures/Untitled%2012.png)

Las bibliotecas estándar de C++ han sido declaradas en el espacio de nombres `std`, por lo que tenemos que indicarlo en nuestro programa, una forma de hacerlo es de la siguiente manera:

```cpp
// Se empléa la cláusula "using namespace"
using namespace std;
```

### Parámetros por Referencia
En C, nosotros **aparentábamos** que enviábamos nuestras variables por referencia, pero lo que realmente sucedía era que creábamos una variable puntero que apuntaba a nuestra variable. Ahora, en C++, podemos pasar realmente parámetros por referencia, pero esto se realiza diferente.

![Untitled](./Adicional/Pictures/Untitled%2013.png)

Como podemos ver, ahora no necesitamos enviar la dirección de memoria de nuestra variable, lo que hacemos es enviar a nuestra variable misma.

![Untitled](./Adicional/Pictures/Untitled%2014.png)

Y ahora, viendo la función, vemos que no usamos el clásico `*` como antes, ahora lo que hacemos es usar el `&` antes de nuestra variable. Y controlamos la variable sin especificar que estamos tratando con el valor de la misma.

### Punteros
En lenguaje C usábamos la constante `NULL`, ahora usamos la palabra reservada `nullptr`.

![Untitled](./Adicional/Pictures/Untitled%2015.png)

Para la asignación dinámica usábamos la función `malloc`, ahora usamos el operador `new`.

![Untitled](./Adicional/Pictures/Untitled%2016.png)

### Otras diferencias significativas
- Sobrecarga de funciones: Se puede definir dos o más funciones con el mismo nombre y que realicen cosas diferentes.
- Sobrecarga de operadores: Un operador puede cumplir una función diferente a la usual.
- Entrada y salida de datos: Ahora usaremos los operadores `cin`, `cout`, `<<` y `>>`.
- Plantillas: Permite que el compilador cree varias funciones que se adapte a un tipo de dato.
- Clases y Objetos: Las clases son la evolución de las estructuras.
- Booleanos: Se usa las constantes `true` y `false`.
- Clase String: Cadenas de caracteres sin tener que hacer arreglos de `char` manualmente.

# **Capítulo 2 - Entrada y salida de datos**
Este es el segundo capítulo del curso INF281 - Lenguaje de Programación 1 y se enfoca en la entrada y salida de datos del lenguaje de programación C++.

## **Introducción a la entrada y salida de datos desde C++**
La biblioteca definida por el lenguaje C++ es `iostream`, y sus elementos definidos son:

| Clases | Objetos | Operadores Sobrecargados |
| --- | --- | --- |
| ostream | cout | << |
| istream | cin | >> |

### Formas de invocación
1. Acompañando el objeto del espacio de nombres en cada invocación, esto es:

```cpp
#include <iostream>
...
std::cout << ...
std::cin >> ...
```

1. Empleando la cláusula `using` al inicio del módulo y después de la orden de preprocesador `#include <iostream>`, de la siguiente manera:

```cpp
#include <iostream>
using std::cout;
...
cout << ...
std::cin >> ...
```

1. Utilizando la cláusula `using` acompañándolo de cláusula `namespace`, como se indica a continuación:

```cpp
#include <iostream>
using namespace std;
...
cout << ...
cin >> ...
```

### Valor de retorno
Cuando usamos los objetos **`cout`** y **`cin`** podríamos pensar que son los objetos que ejecutan la acción de enviar o recibir un flujo de datos, pero los que realmente ejecutan esa orden son los operadores `<<` y/o `>>`.

### Los operadores trabajan como funciones
El `cout<<a;` o `cin>>a;` es interpretado por el compilador como `<<(cout,a);` y `<<(cout,a);`. De esta forma entendemos que existe un valor de retorno, el cuál será una **referencia al objeto que entro como parametro**, en este caso `&cout` o `&cin`.

Este valor retornado permite manipular varias expresiones en una misma línea de código.

```cpp
cout<<a<<b<<c<<d;
cin>>a>>b>>c>>d;
```

### Interpretación
El valor de retorno mencionado anteriormente permite reutilizar el objeto múltiples veces.

![Untitled](./Adicional/Pictures/Untitled%2017.png)

El computador interpretará lo que está en la izquierda de la forma que está a la derecha.

```cpp
cout<<a<<b<<c<<d;
```

```cpp
cout<<a; cout<<b; cout<<c; cout<<d;
```

### Operadores
- Operador `<<`: Operador de inserción de flujo - Utilizado para `cout`.
- Operador `<<`: Operador de extracción de flujo - Utilizado para `cin`.

## **Entrada de datos: Instrucción `cout`**
Las operaciones de entrada y salida ya se hacen a través de "objetos" definidos por "clases" que han sido diseñadas de manera apropiada para este fin.

### Bibliotecas de funciones y espacios de nombres
Para emplear los elementos que permitan entrada y slida de datos usaremos primordialmente la biblioteca `iostream`. Para poder manipular la salida de datos usaremos la biblioteca `iomanip`. El espacio de nombres de ambas bibliotecas es `std`.

### Objeto `cout`
El objeto `cout` permite enviar al medio estándar de salida el resultado de expresiones que se le proporcionan. Las operaciones de entrada y salida en C++ se hacen por medio de objetos, en este sentido `cout` es un objeto definido **(también se dice "instanciado")** de la clase `ostream` que se encuentran en la biblioteca `iostream`.

| Clase (tipo de dato) | Objeto (variable) | Operador de inserción de flujo |
| --- | --- | --- |
| ostream | cout | << |
| istream | cin | >> |

![Untitled](./Adicional/Pictures/Untitled%2018.png)

<aside>
💡 C++ nos proporciona la herramienta `endl` (*endline*) que funciona como `‘\n’`.

```cpp
cout<<expresión<<endl;
```

</aside>

El operador `<<` se aplica una sola vez con el objeto `cout`, pero como esta operación, luego de enviar el resultado al medio de salida, **devuelve una referencia al objeto** `cout`, permite concatenarla de modo que parezca que estamos ejecutando una sola instrucción. En otras palabras si escribimos la siguiente instrucción:

El compilador va ainterpretar esta línea como si lo hubieramos escrito a la derecha:

```cpp
cout<<a<<b<<c<<endl;
```

```cpp
cout << a;
cout << b;
cout << c;
cout << endl;
```

### Solucionar problema del formato
Para solucionar el problema del formato tenemos herramientas que son funciones de la biblioteca `iomanip` y funciones miembros del objeto `cout`.

1. `cout.width(n)`: Representa el llamado a ejecución de la función miembro (o también denominado método) `width` que pertenece a (es miembro de) `cout`.  `n` es un valor entero que indica la cantidad mínima de caracteres a emplear en la salida del valor (es equivalente al uso de `%nd` en el Lenguaje C). El ejemplo siguiente muestra el efecto de esta función:
    
    
    ```cpp
    int a = 2351, b = 765;
    cout << a;
    cout.width(10);
    cout << a << endl;
    cout << b << endl;
    ```
    
    ```
    2351
    			2351
    765
    _
    
    ```
    
    <aside>
    💡 La función miembro `cout.width(n)` solo se aplica a la primera variable.
    
    </aside>
    
2. `setw(n)`: Función definida en `iomanip`. Funciona igual que la función anterior, pero la forma de emplearla es más secilla y práctica. Se puede concatenar el código.
    
    
    ```cpp
    int a = 2351, b = 765, b = 1234;
    cout << setw(10) << a << setw(10) << b << endl;
    cout << setw(10) << c << endl;
    ```
    
    ```
         2351     765
    		 1234
    _
    ```
    

### Banderas de formato (*format flags*)
Son constantes que permiten definir ciertos atributos que influenciarán en la forma cómo aparecerán los datos en el medio de salida.

- `left`: Alinea los resultados a la izquierda.
- `right`: Alinea los resultados a la derecha.
- `hex`: Muestra el número en base hexadecimal.
- `oct`: Muestra el número en base octal.
- `dec`: Muestra el número en base decimal.
- `uppercase`: Muestra las letras en mayúsculas.
- `nouppercase`: Muestra las letras en minusculas.

También se puede ver que una vez que se ejecuta el elemento, la alineación se mantenga hasta que se use de otro elemento lo cambie.

```cpp
cout << left << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout << right << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout << hex << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout << uppercase << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout << oct << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout << dec << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout << nouppercase;
```

Ahora, para poder rellenar los espacios colocados en los formatos con otro caracter diferente:

- `cout.fill(n)`: Llena los espacios con el caracter n. Función miembro.
- `setfill(n)`: Llena los espacios con el caracter n.  Función definida en `iomanip`.

```cpp
int a = 39963, b = 765, b = 1234;
cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout.fill('0');
cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout.fill(' ');
cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout << setfill('X');
cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
cout << setfill(' ');
```

```
      39963      765      1234
000000399630000007650000001234
      39963      765      1234
XXXXXX39963XXXXXX765XXXXXX1234
_

```

### Formato en valores de punto flotante
Para dar format a valores de punto flotante, C++ requiere del uso de dos herramientas, una que define la precisión en la que aparecerá el número (`cout.presicion(n)` o `setpresicion(n)`) y la otra que interpretará el significado de la precisión (`fixed`).

```cpp
double f = 314.15926535;
cout << setw(14) << f << endl;
cout.precision(10); 
cout << setw(14) << f << endl; 
cout.precision(3);
cout << setw(14) << f << endl;
```

```
      314.159
  314.1592653
          314
_ 

```

Las herramientas `cout.presicion(n)` y `setpresicion(n)` definen **el número de dígitos que aparecerán en la salida**. Por eso se requiere otra herramienta, en este caso `fixed`. Al activar esta bandera, el valor de precisión se interpretará como el número de decimales.

```cpp
double f = 3.1415926535;
cout << fixed;
cout.precision(5);
cout << setw(14)
cout.precision(10);
cout << setw(14) << f << endl;
cout.precision(3);
cout << setw(14) << f << endl;
cout.unsetf(ios::fixed);
```

```
      3.14159
 3.1415926534
        3.142
_ 

```

### Objeto `cin`
El objeto `cin` permite leer, uno por uno, los caracteres de un flujo de caracteres que ingresa del medio estándar de entrada. Los caracteres son convertidos de acuerdo al tipo de variable que acompaña al objeto.

```cpp
using namespace std;
cin>>expresión.
```

Como se observa, aquí también se ha **sobrecargado un operado**r, en este caso el operador de bits `>>`, que en adelante será nombrado como "operador de extracción de flujo". De igual manera, como en `cout`, la operación devolverá una referencia al objeto `cin`.

Al ejecutar la orden, el sistema detendrá el programa para que el usuario pueda colocar los datos en el **buffer de entrada**, luego de presionar la tecla `ENTER [↵]` el programa convertirá los caracteres del flujo de entrada en la representación binaria correspondiente al tipo de dato de la variable y lo asignará a ella. Los caracteres ingresados deberán corresponder con el tipo de la variable de lo contrario el proceso se detendrá, asignando a la variable lo que se haya podido convertir hasta ese momento. **El proceso termina satisfactoriamente cuando se encuentre un separador (espacio en blanco, cambio de línea o tabulador).**

### Entrada y salida de caracteres
La entrada y salida de caracteres desde C++ se puede realizar, de igual manera que
con los números, con los objetos `cin` y `cout` empleando una variable una variable de tipo
`char`, sin embargo existen algunos métodos que pueden ser muy útiles dado el caso. A
continuación describiremos algunos de éstos:

- Método `cin.get()`:  El método toma un caracter del buffer de entrada y lo entrega al programa. El siguiente ejemplo muestra su efecto:
    
    ```cpp
    char c = 'A';
    cout << "Ingrese un texto: ";
    c = cin.get();
    cout << "C = " << c << endl;
    ```
    
    Al ejecutarlo, primero se verá el mensaje en la ventana y el programa se detendrá,
    como se ve a continuación:
    
    ```
    Ingrese un texto: _
    ```
    
    Luego de ingresar el texto y presionar la tecla `ENTER [↵]` se verá lo siguiente:
    
    ```
    Ingrese un texto: Hola↵
    C = H
    _
    ```
    
- Método `cout.put(c)`:  El método toma el caracter contenido en la variable "c" y lo envía al medio de salida. El siguiente ejemplo muestra su uso:
    
    ```cpp
    char c = 'A';
    cout << "Ingrese un texto: ";
    c = cin.get();
    cout << "C = "
    cout.put(c);
    cout << endl;
    ```
    
    Al ejecutarlo se mostrará de manera idéntica al resultado del programa anterior.
    
- Método `cin.unget()`:  El método envía al buffer de entrada el último caracter extraído por el método `cin.get()`. Los ejemplos siguientes mostrarán el efecto de este método:
    
    ```cpp
    char a, b, c;
    cout << "Ingrese un texto: ";
    a = cin.get();
    cin.unget();
    b = cin.get();
    c = cin.get();
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "C = " << c << endl;
    ```
    
    ```
    Ingrese un texto: Hola↵
    A = H
    B = o
    C = l
    _
    ```
    
- Método `cin.peek()`: El método obtiene una copia del caracter del buffer de entrada, sin extraerlo y lo entrega al programa. En el ejemplo siguiente se podrá ver el efecto de este método:
    
    ```cpp
    char a, b, c d;
    cout << "Ingrese un texto: ";
    d = cin.peek();
    a = cin.get();
    b = cin.get();
    c = cin.get();
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "C = " << c << endl;
    cout << "D = " << d << endl;
    ```
    
    ```
    Ingrese un texto: Hola↵
    A = H
    B = o
    C = l
    _
    ```
    
- Método `cin.putback(c)`: El método es similar a `cin.unget()` con la diferencia que **el usuario puede enviar al buffer de entrada el caracter que desee.** En el ejemplo siguiente se podrá ver su efecto:
    
    ```cpp
    char a, b, c d;
    cout << "Ingrese un texto: ";
    a = cin.get();
    cin.putback('M');
    b = cin.get();
    c = cin.get();
    d = cin.get();
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "C = " << c << endl;
    cout << "D = " << d << endl;
    ```
    
    ```
    Ingrese un texto: Hola↵
    A = H
    B = M
    C = o
    D = l
    _
    ```
    
- Función `ws`: La función permite extraer del buffer de entrada todos los espacios (espacios en blanco, tabuladores y cambios de línea) que vaya encontrando hasta encontrar un
caracter no blanco.
    
    ```cpp
    char a, b, c d;
    cout << "Ingrese un texto: ";
    a = cin.get();
    cin << ws;
    b = cin.get();
    c = cin.get();
    d = cin.get();
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "C = " << c << endl;
    cout << "D = " << d << endl;
    ```
    
    ```cpp
    Ingrese un texto: H__ola↵
    A = H
    B = M
    C = o
    D = l
    _
    ```
    

# **Capítulo 3 - Archivos**
Todos los archivos son lo mismo para el computador. La diferencia es la forma cómo se almacena la información. Existen dos formas básicas de codificar la información para guardarlas en archivos:

- El formato de texto - *archivos de texto*.
- El formato binario - *archivos binarios*.

## Diferencias entre Archivos de Texto y Binarios
1. **Cómo se almacena un dato en el archivo:**
    1. En un archivo de textos el dato se transforma y cuarda como una secuencia de caracteres.
        
        
        | ‘2’ | ‘3’ | ‘7; |
        | --- | --- | --- |
    2. En un archivo binario el dato se guarda tal cual está en la memoria principal.
        
        <aside>
        <img src="https://www.notion.so/icons/snippet_blue.svg" alt="https://www.notion.so/icons/snippet_blue.svg" width="40px" /> Es decir que en el archivo se guardarán siempre 2 bytes para datos del tipo short,
        tengan el número de cifras que tengan, ya sean 15238, 9, 15, 222, etc.
        
        </aside>
        
        | 0011 1101 | 000 0010 |
        | --- | --- |
2. **Separación entre datos:**
    1. En un “archivo de textos”, como los datos se transforma una secuencia de caracteres, luego de almacenarlos no se podrían recuperar a menos que se les separe por un espacio en blanco, tabulador o cambio de línea.
        
        
        | ‘2’ | ‘3’ | ‘7; | ‘ ‘ | ‘7’ |
        | --- | --- | --- | --- | --- |
    2. En un “archivo binario”, no se requieren separadores porque los datos se almacenan según el tipo y por lo tanto ocupan el mismo espacio cada uno.
        
        
        | 0011 1101 | 000 0010 |
        | --- | --- |
        | 37 | 19 |
3. **Acceso a los datos:**
    1. En un “archivo de textos”, por el tamaño no uniforme de los datos, no se puede determinar la posición de uno de ellos, por lo que habrá que leerlos uno a continuación del otro. Esto se denomina “acceso secuencial”.
    2. En un “archivo binario”, por el contrario, debido a la uniformidad del tamaño de los datos, se puede determinar la posición de uno de ellos, por lo que se podrá acceder a uno de ellos sin tocar el resto, a esto se le denomina “acceso directo o aleatorio”.
4. **Actualización de datos:**
    1. En un “archivo de textos”, no se pueden actualizar los datos, esto se debe a que el espacio que ocupa un dato depende del número de cifras. Si se lee un dato de un archivo y en la modificación cambia su número de cifras, no habrá lugar para volverlo a grabar.
        
        ![Untitled](./Adicional/Pictures/Untitled%2019.png)
        
    2. En un “archivo binario”, esta tarea es perfectamente posible ya que a pesar que el valor cambie, el espacio que ocupa.
        
        ![Untitled](./Adicional/Pictures/Untitled%2020.png)
        

## Archivos de Textos en C++
- Biblioteca definida por el lenguaje C++: `fstream`.
- Elementos definidos en `fstream`:
    - Clases: `ofstream` y `ifstream`.
    - Operadores sobrecargados: `<<` y `>>`.

[](https://cplusplus.com/reference/fstream/)

`<fstream>`

[](https://cplusplus.com/reference/fstream/ofstream/)

`std::ofstream`

[](https://cplusplus.com/reference/fstream/ifstream/)

`std::ifstream`

### Objetos de Archivo
Se deberá definir un objeto que se relacione con el archivo con el que se va a trabajar. A través del objeto se abrirá el archivo, se harán operaciones en él y se cerrará.

### Constructores y Destructores
Son métodos o funciones miembro definidos para una clase que se ejecutan de forma automática. Los constructores para las clases `ofstream` y `ifstream` permiten abrir los archivos, y los destructores permiten cerrarlos.

### Definición y apertura de un archivo de textos
- **Creación:**
    - Empleando el constructor:
        
        ```cpp
        ofstream arch("arch.txt", ios::out);
        ```
        
        - `arch`: Es el objeto que manejará el archivo.
        - `ios::out`: Define el modo de apertura, con la clase `ofstream`. Si el archivo existe se borra.
    - Sin emplear el constructor:
        
        ```cpp
        ofstream arch;
        arch.open("arch.txt", ios::out);
        ```
        
- **Lectura:**
    - Empleando el constructor:
        
        ```cpp
        ifstream arch("arch.txt", ios::in);
        ```
        
        - `arch`: Es el objeto que manejará el archivo.
        - `ios::`in: Indica que el archivo se abrirá para leer, con la clase `ifstream`. Si no existe se produce error.
    - Sin emplear el constructor:
        
        ```cpp
        ifstream arch;
        arch.open("arch.txt", ios::in);
        ```
        
- **Añadidura:**
    - Empleando el constructor:
        
        ```cpp
        ofstream arch("arch.txt", ios::app);
        ```
        
        - `ios::app`: Indica que el archivo se abrirá para escribir en él desde el final. Si el archivo no existe se produce un error. Se debe ligar a la clase `ofstream`.
    - Sin emplear el constructor:
        
        ```cpp
        ofstream arch;
        arch.open("arch.txt", ios::app);
        ```
        

### Verificación de la apertura de un archivo de textos
Si queremos que se imprima un error en caso no se abra el archivo podemos verificar la apertura:

```cpp
ofstream arch("arch.txt", ios::out);
if (!arch) { // not arch
		cout<<"ERROR: No se pudo abrir el archivo."<<endl;
		exit(1);
}
```

### Operaciones de lectura y escritura en archivos de textos
Lo que sabemos hacer con `cout` se puede aplicar con un objeto `ofstream` y lo que sabemos hacer con `cin` se puede aplicar con un objeto `ifstream`.

```cpp
cout<<"Hola mundo!"<<endl; // Hola mundo! <- terminal
arch<<"Hola mundo!"<<endl; // Hola mundo! <- archivo
```

### Cierre de archivos de texto
El destructor se encarga de hacerlo, pero se puede forzar con la instrucción `arch.close();`.

## Archivos Binarios en C++
Para sacar provecho a esto, se deben almacenar los datos de manera homogénea, en bloque del mismo tamaño que llamaremos registros.

### Definición y apertura de un archivo binario
```cpp
ofstream arch("arch.bin", ios::out | ios::binary);
ifstream arch("arch.bin", ios::in | ios::binary);
fstream arch("arch.bin", ios::out | ios::in | ios::binary);
```

### Operaciones de lectura y escritura en archivos binarios
- **Escritura:** En el método de escritura se debe proporcionar la dirección dónde se encuentre el dato a grabar y la cantidad de bytes que a partir de allí se van a enviar al archivo.
    
    ```cpp
    arch.write(reinterpret_cast<const char *> (&v), sizeof(t));
    ```
    
    - `reinterpret_cast<const char *>`: Es un operador que busca manipular la información contenida en la variable `v`, byte por byte.
    - `v`: Variable donde se encuentra el dato.
    - `t`: Tipo de dato de la variable `v`.
    
    Escritura con arreglos:
    
    ```cpp
    arch.write(reinterpret_cast<const char *> (a), sizeof(t)*n);
    ```
    
    - `a`: Indica un arreglo.
    - `t`: Tipo de dato de los elementors del arreglo `a` que se quieren guardar.
    - `n`: Número de elemtnos del arreglo `a`.
- **Lectura:** En el método de lectura se debe proporcionar la dirección dónde se encuentre la variable que recibirá el dato leído y la cantidad de bytes que se extraerán del archivo.
    
    ```cpp
    arch.read(reinterpret_cast<const char *> (&v), sizeof(t));
    ```
    
    - `reinterpret_cast<const char *>`: Es un operador que busca manipular la información contenida en la variable `v`, byte por byte.
    
    Lectura con arreglos:
    
    ```cpp
    arch.read(reinterpret_cast<const char *> (a), sizeof(t)*n);
    ```
    
    - `reinterpret_cast<const char *>`: Es un operador que busca manipular la información contenida en la variable `v`, byte por byte, de modo que pueda colocar la información que viene en el archivo.

### Acceso aleatorio o directo en archivos binarios
Método para posicionar el indicador del archivo en algún byte del archivo:

```cpp
arch.seekg(n, ios::beg);
arch.seekg(n, ios::cur);
arch.seekg(n, ios::end);
```

Mueve el archivo `n` bytes desde:

- El inicio del archivo: `ios::beg`
- La posición del indicador: `ios::cur`
- Desde el final del archivo: `ios::end`

El método para determinar la cantidad de bytes que hay desde el inicio del archivo hasta la posición del archivo es:

```cpp
arch.tellg();
```

<aside>
💡 El método devuelve un valor entero con la cantidad de bytes.

</aside>

## Objetos de archivos como parámetros de funciones
El encabezado de cualquier función que pase como parámetro un objeto definido en `iostream` y `fstream` deberá pasar por referencia, y en su implementación también:

```cpp
void function(iostream &);
void function(iostream &arch) {
		// code segment
}
```

# Manejo de funciones en el lenguaje C++
La principal diferencia es el posible uso de parámetros con valores por defecto, ejemplo.

```cpp
// Header de la función
int function(int=10, int=7);

// Implementación de la función
int function(int a=10, int b=7) {
	// Instrucciones
}
```

## Sobrecarga de funciones
Es una propiedad de C++ que nos permite definir dos o más funciones con el mismo nombre, el único requisito es que los parámetros sean diferentes (ya sea en cantidad o tipo de dato).

```cpp
int function(int, int);
int function(int, double);
int function(int, int, double);
```

## Sobrecarga de operadores
Es una propiedad de C++ que nos permite realizar otras aplicaciones para los operadores. Por ejemplo, la instrucción `a+b` se interpreta como `+(a, b)`.

```cpp
void operator *(struct Persona &per, double porcentaje) {
	per.suelto *= (1+porc/100.0);
}
```

<aside>
💡 No se puede cambiar la prioridad de un operador (precedencia de operadores).

</aside>

### Lista de operadores
- Se pueden sobrecargar:

![Untitled](./Adicional/Pictures/Untitled%2021.png)

- No se pueden sobrecargar:

![Untitled](./Adicional/Pictures/Untitled%2022.png)

## Plantillas de funciones
Es una herramienta de C++ que permite implementar una función y que a la hora de compilarla el sistema genere varias versiones de esta función. Para esto se emplea un tipo de dato genérico: `template<typename TIPO>`.

![Untitled](./Adicional/Pictures/Untitled%2023.png)

<aside>
<img src="https://www.notion.so/icons/exclamation-mark_blue.svg" alt="https://www.notion.so/icons/exclamation-mark_blue.svg" width="40px" /> **Importante**: Las plantillas de funciones se definen solo en su header (archivo .h). Ahí mismo tienen que incluirse las bibliotecas `iostream`, etc. Además por cada función que definamos debemos de indicar el `template<typename>`.

</aside>

## Bibliotecas estáticas de funciones
Es una agrupación de datos, tipos de datos y funcionalidades organizados de forma que sean reutilizables en más de un proyecto. Las estáticas tienen extensiones .a o .lib, aunque también se pueden considerar los archivos .o.

### Procedimiento para crear una biblioteca estática
1. Creación de proyecto “Biblioteca Estática”: Si el proyecto no se creo correctamente no se debe haber creado el archivo main.cpp.
2. Creación de proyecto que use “Biblioteca Estática”: Incorpore la biblioteca estática en el proyecto, vaya a las propiedades del proyecto, y enlace la biblioteca con la opción linker.

# Arreglos y punteros
Los temas a tratar son: Entrada y salidas de cadenas de caracteres, métodos de asignación dinámica, punteros a punteros, punteros genéricos, punteros a funciones, y argumentos en la línea de comandos.

## Inicialización dinámica
```cpp
int *p;
p = nullptr;
p = new int;
p = new int{53};
p = new int[5];
p = new int[5]{12,7,9};
```

![Untitled](./Adicional/Pictures/Untitled%2024.png)

### Errores comunes en el uso de punteros dentro de funciones

![Untitled](./Adicional/Pictures/Untitled%2025.png)

## Liberación de un puntero

![Untitled](./Adicional/Pictures/Untitled%2026.png)

## Cadenas de caracteres

Se usa la librería `cstring` para el uso de funciones de cadenas de caracteres.

### Funciones de `cstring`

- Uso del `strlen()`.
    
    ```cpp
    n = strlen(cad); // Retorna la cantidad de caracteres de la cadena
    ```
    
- Uso del `strcpy()`.
    
    ```cpp
    strcpy(cad1, cad2); // Copia la cadena 2 en la cadena 1
    ```
    
- Uso del `strcmp()`.
    
    ```cpp
    n = strcmp(cad1, cad2); // Compara dos cadenas de caracteres
    ```
    
- Uso del `strcat()`.
    
    ```cpp
    n = strcat(cad1, cad2); // Concatena la cadena 2 en la cadena 1
    ```

## Funciones miembro para la lectura de cadena de caracteres
- Uso del `cin.getline(char *, int n)`:
    - Lee todos los caracteres del buffer de entrada hasta completar `n-1` caracteres o hasta encontrar el caracter de cambio de línea, el que llegue primero y los asigna a `cad`.
    - Agrega a `cad` el carácter de terminación (0).
    - El carácter de cambio de línea es extraido del buffer, pero no se asigna a `cad`.
    - Si el buffer de entrada tiene más de `n-1` caracteres, sin incluir el cambio de línea, se levanta una bandera de error.
    
    ```cpp
    cin.getline(cad, 100);
    ```
    
- Uso del `cin.getline(char *, int n, char delim)`:
    - Lee todos los caracteres del buffer de entrada hasta completar `n-1` caracteres o hasta encontrar el caracter `delim`, el que llegue primero y los asigna a `cad`.
    - Agrega a `cad` el carácter de terminación (0).
    - El carácter `delim` es extraido del buffer, pero no se asigna a `cad`.
    - Si el buffer de entrada tiene más de `n-1` caracteres, sin incluir el `delim`, se levanta una bandera de error.
    
    ```cpp
    cin.getline(cad, 100, ',');
    ```
    
- Uso del `cin.get(char *, int n)`:
    - Lee todos los caracteres del buffer de entrada hasta completar `n-1` caracteres o hasta encontrar el caracter de cambio de línea, el que llegue primero y los asigna a `cad`.
    - Agrega a `cad` el carácter de terminación (0).
    - El carácter de cambio de línea **NO** es extraido del buffer.
    - Si el buffer de entrada tiene más de `n-1` caracteres `NO` se levanta una bandera de error.
    
    ```cpp
    cin.get(cad, 100);
    ```
    
- Uso del `cin.get(char *, int n, char delim)`:
    - Lee todos los caracteres del buffer de entrada hasta completar `n-1` caracteres o hasta encontrar el caracter `delim`, el que llegue primero y los asigna a `cad`.
    - Agrega a `cad` el carácter de terminación (0).
    - El carácter `delim` **NO** es extraido del buffer.
    - Si el buffer de entrada tiene más de `n-1` caracteres, `NO` se levanta una bandera de error.
    
    ```cpp
    cin.get(cad, 100, ',');
    ```
    

## Asignación dinámica de memoria

Los métodos que presentaremos son:

1. Métodos de asignación de exacta de memoria.
2. Método de asignación de memoria por incrementos.

### Método de asignación exacta de memoria
Se utiliza una variable que vaya contando la cantidad de datos.

```cpp
int *arr, numDatos=0;
leerDatos(arr, numDatos);
escribirDatos(arr, numDatos);
```

Pasos para la implementación de la función `leerDatos()`.

1. Se define un arreglo estático dentro de la función lo suficientemente grande (buffer).
2. Se leen todos los datos en el buffer.
3. Se copian los datos para el arreglo que va a contener los datos del buffer.

### Método de asignación de memoria por incrementos
Lo que se busca es tener un mínimo de desperdicio.

```cpp
int *arr, numDatos=0;
leerDatos(arr, numDatos); // void leerDatos(int *&arr, int &numDat);
escribirDatos(arr, numDatos);
```

1. Se define para `arr` un espacio de memoria reducido.
2. En una variable auxiliar se guarda la capacidad del arreglo.
3. Se leen los datos.
4. Cuando el número de datos se iguale la capacidad, se gesta un nuevo arreglo de mayor capacidad.
5. Se copian los datos allí.
6. Se libera el arreglo antiguo y se hace apuntar `arr` al nuevo.
7. El proceso se repite hasta leer todos los datos.

## Variantes a los métodos
En las situaciones en las que no se puede contar el número de datos, se usara colocar marcas al final de los datos, como se hace por ejemplo con el cero en las cadenas de caracteres.

<aside>
💡 Considerar el 0 como un dato más que ingresa al arreglo.

</aside>

# Arreglos y punteros (Parte 2)
## Punteros a punteros
Aquel cuya variable referenciada contiene una dirección de memoria.

```cpp
// Declaración
int **a;
char ***n;
double ****r;
```

### Asignación: Puntero simple
![Untitled](./Adicional/Pictures/Untitled%2027.png)

### Asignación: Puntero doble
![Untitled](./Adicional/Pictures/Untitled%2028.png)

### Matrices dinámicas
![Untitled](./Adicional/Pictures/Untitled%2029.png)

![Untitled](./Adicional/Pictures/Untitled%2030.png)

# **Punteros a función**
Es aquel puntero que apunta al código de una función. Se almacena la dirección y se ejecuta la función a través de puntero.

![Untitled](./Adicional/Pictures/Untitled%2031.png)

## Declaración
Se define de la siguiente manera:

```cpp
double (*a)(int, int);
```

Se lee de la siguiente manera: “a” es un puntero que puede apuntar a cualquier función cuyo encabezado indique que recibe dos enteros como parámetros y devuelve un double.

## Usos de punteros a función
Ejemplos de funciones definidas en `cstdlib`:

### Función `qsort`
**Es una función genérica**, es capaz de ordenar cualquier conjunto de datos sin importar el tipo de dato que lo conforma ni la estructura que contenga a esos datos, y en el orden que se desee.

```cpp
qsort(arr, nd, size, cmp);
```

- `arr`: arreglo de cualquier tipo.
- `nd`: número de datos del arreglo.
- `size`: tamaño en bytes de los elementos del arreglo primario.
- `cmp`: función de comparación que regirá la ordenación de datos.

Header de la función:

```cpp
void qsort(void *arr, int nd, int size, int (*cmp)(const void *, const void *));
```

### Función `bsearch`
Es una función genérica. Header de la función:

```cpp
void *bsearch(void *llave, void *arr, int nd, int size, int (*cmp)(const void *, const void *));
```

### Función de ordenación genérica
Es una función genérica de ordenación empleando Quick Sort. La función se invocará de la siguiente manera:

```cpp
ordenarG(arr, 0, n-1, cmp);
```

- `arr`: arreglo de cualquier tipo.
- `0` y `n-1`: límites del arreglo.
- `cmp`: función de comparación.

Los elementos del arreglo primario tendrán siempre un tamaño fijo. La función de comparación recibe dos punteros genéricos pero con el contenido de los elementos del arreglo primario.

# Herencia
Es una propiedad de la POO que permite crear una clase a partir de otra.

![La clase B está heredando de la clase A.](./Adicional/Pictures/Untitled%2032.png)

La clase B está heredando de la clase A.

## Características
1. Al heredar de una clase base, la clase derivada adquiere todos los atributos y métodos de la clase base. 

![Untitled](./Adicional/Pictures/Untitled%2033.png)

1. La clase derivada puede “ocultar” o “sobrescribir” algún método. Esto no implica destruir el método original, sino ocultarlo.
2. Desde la clase derivada no se podrá acceder a los elementos de la zona privada de la clase base.

![Untitled](./Adicional/Pictures/Untitled%2034.png)

## Tipos de herencia
Cuando se hereda una única clase la herencia es simple, mientras que cuando una clase hereda de dos a más clases se dice que es herencia múltiple.

## Zona `protected`
En la zona protegida se pueden colocar atributos y métodos. Solo tiene efecto en herencia.

### Caracteristicas
1. Los objetos no pueden acceder a la zona protegida, para ellos es una zona privada.
2. Una clase derivada si puede acceder a la zona protegida de su clase base.

![Untitled](./Adicional/Pictures/Untitled%2035.png)

## Especificadores de acceso
Se emplea para restringir el acceso a los elementos de una clase base, de las clases que hereden de las clases derivadas de la base.

```cpp
class derivada : public base { ...
class derivada : protected base { ...
class derivada : private base { ...
```

# Polimorfismo
Veremos conceptos de polimorfismo.

## Punteros en herencia
Un puntero de clase base puede apuntar directamente a cualquier puntero de clase derivada, sin necesidad de castear.

```jsx
class ClaseA *pt;
class ClaseB objB;
class ClaseC objC;
class ClaseD objD;
```

![Untitled](./Adicional/Pictures/Untitled%2036.png)

![Untitled](./Adicional/Pictures/Untitled%2037.png)

### Restricciones
Solo podrá acceder a los elementos de la clase base definidos en la clase derivada. El puntero no podrá acceder a los elementos propios de la clase derivada.

## Métodos virtuales
Con un método virtual el compilador le asigna una dirección de memoria , pero ésta no corresponde con el código de inicios de la función, sino que lo hace trabajar como un doble puntero.

### Implementación
Se realiza dentro de una jerarquía de clases (herencia), por lo general en la clase base.

![Untitled](./Adicional/Pictures/Untitled%2038.png)

### Definición
Si se cumplen **todas** estas condiciones:

1. Si en un proyecto se implementa una jerarquía de clases.
2. Si en las clases derivadas existen métodos que sobrescriban algunos métodos de la clase base.
3. Si los métodos de la clase base que han sido sobrescritos son declarados como virtuales.
4. Si los métodos virtuales son ejecutados a través de un puntero a la clase base. 

<aside>
💡 Si se cumplen todas etas condiciones estaremos ante el polimorfismo de la POO.

</aside>

## Clase abstracta
En los casos en los que tenemos varias clases que no se relacionan pero que tienen métodos con encabezados iguales.

Para solucionar este problema se crea una clase que declare estos métodos de manera virtual, y se hace que las demás clases hereden de ésta.

### Método virtual puro
Es aquel que no se requiere que tenga implementación. Para evitar que el compilador detecte error de enlace, se le implementa de la manera siguiente:

```jsx
virtual T metodoA (...) = 0;
```

La igualdad con cero hará que el compilador no busque la implementación.

![Untitled](./Adicional/Pictures/Untitled%2039.png)

Como la nueva clase solo se ha creado para poder realizar polimorfismo, se declaran los métodos puros.

# Biblioteca estándar de plantillas (STL)
Se trata de un conjunto de bibliotecas en las que se definen distintas estructuras de datos (contenedores). Los contenedores pueden almacenar cualquier tipo de dato. Veremos tres:

1. Biblioteca vector: Simulará el trabajo con un arreglo dinámico.
2. Biblioteca list: Simulará el trabajo con una lista ligada.
3. Biblioteca map: Se puede manejar como una tabla Hash.

# Iteradores
Los vectores se manejan a través de índices, mientras que las listas no. Para esto se ha definido otra biblioteca `#include<iterator>` que permite definir elementos similares a los punteros para recorrerlos y manipularlos.

# Atributos y métodos estáticos
Los atributos estáticos se definen en el heap de la siguiente manera:

```cpp
class ClaseX {
	private:
		static int valor;
		...
	public:
		...
}
```

Los métodos estáticos se definen de la siguiente manera:

```cpp
class ClaseX {
	private:
		...
	public:
		static int metodo();
		...
}
```
