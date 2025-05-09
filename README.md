# Programa DEMO en C++ (Windows) para comunicación serial con Arduino

Se implementó la siguiente [libreria](https://github.com/dmicha16/simple_serial_port) para el manejo del puerto serie en C++. El programa permite enviar comandos (caracteres) por el puerto serie, mismos que son reconocidos por el Arduino para realizar
distintas acciones en función del caracter recibido.

Se recomienda utilizar una velocidad de 9600 BPS con el formato estándar 8N1 para aplicaciones sencillas. La librería es bastante ligera y contiene los métodos básicos para manipulación del puerto, lo que hace bastante práctico su uso.
