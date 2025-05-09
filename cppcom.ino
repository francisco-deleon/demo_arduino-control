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

const int ledPin = 13;  // the pin that the LED is attached to

void setup() {
  /*
  * Inicializar la comunicación serial
  *
  * Valores por defecto:
  * 9600 BPS, 8N1 (8 bits de datos por byte, sin bit de paridad, 1 bit de parada)

  * Otros formatos soportados por Arduino:
  * https://docs.arduino.cc/language-reference/en/functions/communication/serial/begin/
  */
  Serial.begin(9600);

  /*
  * Configurar el pin 13 como SALIDA
  *
  * - La versión más reciente del IDE reconocen la variable "ledPin" asociada al pin #13 del Arduino
  *   pinMode(ledPin, OUTPUT);
  *
  * - Versiones anteriores del IDE requieren utilizar el número de pin asociado:
  *   pinMode(13, OUTPUT);
  */
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available()) { // Si hay datos disponibles en el puerto serie
    char data = Serial.read(); // Almacenar en una variable de tipo char el valor recibido
    
    if(data == 'A') { // Si el comando recibido es el caracter 'A'
      digitalWrite(ledPin, HIGH); // Activar la salida #13
    }
    else { // El comando recibido es un caracter diferente
      digitalWrite(ledPin, LOW); // Desactivar la salida #13s
    }
  }
}
