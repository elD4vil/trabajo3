# Trabajo 3: Sistemas Operativos (INFO198)

En este trabajo, mi propuesta consiste en crear una interfaz de usuario basada en la información de una base de datos almacenada en un archivo de texto. A modo de ejemplo, el archivo se llamara **basededatos.txt** y tiene la siguiente estructura:

Matias;admin  
Juan;userGeneral  
Sebastian;userRookie

En esta estructura, cada línea representa un usuario seguido de un comando que representara el perfil asociado de cada usuario.

También sera necesario un archivo txt de nombre **MenuOpciones.txt** con la siguiente estructura:

0,Salir,salir
1,Realizar sumatoria del vector,sumar
2,Realizar promedio del vector,promedio
3,Realizar moda del vector,moda
4,Contar elementos del vector,contar
5,Crear Archivo,crear
6,Agregar texto a archivo,agregar
7,Conteo de Palabras,conteo
8,indefinido,generico

Ademas se necesitara  el archivo txt de nombre **perfilUsuario** con la siguiente estructura:

admin;1,2,3,4,5,6,7
userGeneral;1,2,3,4
userRookie;1,4

Y finalmente los archivos txt de nombre **archivo1mb.txt**, que como su nombre lo dice, representa un txt que pesa 1mb, se recomienda que no sea de palabras repetidas, y el archivo **guardar.txt** el cual tiene que estar vacio.

Todos estos archivos estaran dentro de una carpeta con el nobre **txt**.

# Ejecucion

Para poder ejecutar este código, primero debemos compilarlo. Un ejemplo de cómo hacerlo es ejecutando el siguiente comando en la terminal:

```make```  

Donde sera necesario que tenga el archivo Makefile, sin este el comando anteriormente brindado no tendra utilidad alguna.

Una vez que el código esté compilado, para ejecutarlo será necesario proporcionar una entrada desde la consola que cumpla con el siguiente formato:

```./app -u <usuario> -v <vector> -f <path con el archivo a agregar> -t <texto para agregar en el archivo> -i <path con archivo txt de 1 mb> -o <path con archivo txt vacio>```

Un ejemplo: 

```./app -u Matias -v 1,2,3,4,5 -f crear.txt -t hola -i /home/benjaminc/Downloads/trabajo1.3-info198/txt/archivo1mb.txt -o /home/benjaminc/Downloads/trabajo1.3-info198/txt/guardar.txt```

Será necesario que el codigo app.cpp se encuentre en un carpeta de nombre main.

Se utilizara un archivo **.env** el cual contendra direcciones path importantes, que son los siguientes:

DATABASE_PATH=/home/benjaminc/Downloads/trabajo1.3-info198/txt/basededatos.txt
MENU_PATH=/home/benjaminc/Downloads/trabajo1.3-info198/txt/MenuOpciones.txt
PROFILE_PATH=/home/benjaminc/Downloads/trabajo1.3-info198/txt/perfilusuario.txt

# Argumentos

**-u** = representa el nombre de usuario.
**-v** = vector con varios numeros que `deben estar separados por comas`, que puede ser los valores enteros que usted deseé.
**-f** = direccion path de alguna de sus carpetas, donde sera necesario poner al final un archivo txt.
**-t** = texto que usted desee agregar al archivo txt que se le pidio ingresar.
**-i** = direccion path de archivo txt de 1 mb para leer.
**-o** = dirrecion path de archivo txt para poder guardar.

Si el Usuario es valido entrara al interfaz. pero si el usuario no existe el codigo mandara un mensaje de error y se saldra el programa.

En la pantalla se veran las opciones disponibles, si intenta ingresar una opcion que no se muestre en la pantalla, esto generar un error con su respectivo mensaje y pidiendo nuevamente el ingreso de alguna opcion.

# Funciones

Ahora podrás ver en detalle las funciones que fueron implementadas durante la creación de este código. Además del código principal "app.cpp", necesitarás los siguientes archivos:

**"funciones.cpp"**
**"funciones.h"**

Gracias a esto, el código será mucho más legible, y podrás revisar las funciones utilizadas en "funciones.cpp".

Ambas se encontraran dentro de una carpeta de nombre funciones.

# Opciones

Se han introducido nuevas funcionalidades en el menú, brindándote mayor control sobre el uso de este:

**Opción 0** te permitira salir del codigo
**Opción 1** te permitira sumar el vector ingresado desde la consola.
**Opción 2** te permitira sacar el promedio del vector.
**Opción 3** te permitira sacar la moda del vector.
**Opción 4** te permitira sacar la cantidad de elementos del vector.
**Opción 5** te permitira crear el archivo txt.
**Opción 6** te permitira crear el texto dentro del archivo txt(si este no esta creado, no funcionara esta opcion).
**Opción 7** te permitira poder contar las palabras del archivo 1mb al guardar.