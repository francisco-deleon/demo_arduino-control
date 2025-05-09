/*
* Programa DEMO que realiza la comunicación serial entre el Arduino UNO y una PC
* 
* Valores por defecto:
* 9600 BPS, 8N1 (8 bits de datos por byte, sin bit de paridad, 1 bit de parada)
* 
* ** MODIFICAR SOLAMENTE LA VELOCIDAD EN CASO DE SER NECESARIO **
* 
* Autor:
* Francisco Antonio De León Natareno
*/

#include <iostream>
#include "SimpleSerial.h" // Librería SimpleSerial (https://github.com/dmicha16/simple_serial_port)

using namespace std;

/*
* Identificador del puerto COM
* 
* Se obtiene desde el Arduino IDE o buscando en: Administrador de Dispositivos->Puertos(COM y LPT)
* - Los puertos del COM1 al COM9 se pueden colocar directamente como un string, ya que están incluídos en el espacio de nombres de Windows NT:
*   char puerto[] = "COM4";
* 
* - Cualquier otro puerto debe incluir el prefijo "\\.\" para acceder SOLO a los dispositivos y NO a los archivos:
*   char puerto[] = "\\\\.\\COM10";
*/ 
char puerto[] = "COM4";

/*
* Velocidad del puerto COM (en bits por segundo o baudios)
* 
* El valor nominal (por defecto) en Arduino es de 9600 BPS, pero ya comprobé las siguientes velocidades:
* 14400 BPS (CBR_14440)
* 19200 BPS (CBR_19200)
* 38400 BPS (CBR_38400)
* 57600 BPS (CBR_57600)
* 115200 BPS (CBR_115200) (Máximo soportado en el Arduino UNO)
* 
* - Una mayor velocidad permite aprovechar más ciclos de trabajo en el Arduino, pero consume más memoria y energía..
* - Una menor velocidad garantiza una transferencia de datos más estable (sin pérdida de paquetes o errores), pero consume más tiempo..
* 
* Para Windows se debe agregar el prefijo CBR_ antes del valor de BPS
*/ 
DWORD velocidad = CBR_9600;

// Instanciar la clase SimpleSerial y enviar como argumentos el número de puerto y su velocidad
SimpleSerial Serial(puerto, velocidad);

int main()
{
    char valor;
    
    do {
        printf("Ingrese comando a enviar: ");
        cin >> valor; // 'A': Activar salida, 'D' : Desactivar salida, 'X': Salir del programa
        string comando(1, valor); // Convertir a string antes de enviar (requerido por la librería)

        switch (valor) {
            case 'A': // Activará la salida en el Arduino
                if (Serial.IsConnected()) { // Devuelve TRUE si existe conexión con el puerto
                    if (Serial.WriteSerialPort(comando)) { // Devuelve TRUE si el envío fue exitoso
                        printf("Comando %s enviado!\n\n", comando.c_str());
                    }
                }
                
                break;

            case 'D': // Desactivará la salida en el Arduino
                if (Serial.IsConnected()) { // Devuelve TRUE si existe conexión con el puerto
                    if (Serial.WriteSerialPort(comando)) { // Devuelve TRUE si el envío fue exitoso
                        printf("Comando %s enviado!\n\n", comando.c_str());
                    }
                }

                break;

            default:
                cout << "Opción no válida. Por favor, selecciona una opción del menú.\n";
                break;
        }
    } while (valor != 'X'); // Saldrá del programa

    Serial.CloseSerialPort(); // Cerrar conexión con el puerto de comunicación

    return 0;
}
