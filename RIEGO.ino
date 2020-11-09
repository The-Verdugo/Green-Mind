#include <DHT.h>
#include <DHT_U.h>
//Incluimos biblioteca para poder utilizar el DHT11

//Asignamos nombre de nuestros pines de Arduino a utilizar
const int ventilador=3;
const int sensorDHT=A2;

//Declaramos 2 variables tipo entero para almacenar los datos leidos del sensor
int temperatura, humedad;

//Le asignamos un nombre a nuestro objeto
DHT dht (sensorDHT,DHT11);

//Configuaraciòn inicial de la Tarjeta Arduino
void setup(){
  Serial.begin(9600); //Iniciamos comunicaciòn con la PC a 9600 Batios
  pinMode(ventilador,OUTPUT); //Le indicamos que el ventilador (pin 8) serà de salida
  dht.begin(); //Iniciamos nuestro sensor DHT11
  }

void loop(){
      humedad= dht.readHumidity(); //Funcion incluida en la libreria. Permite leer la humedad.
      temp= dht.readTemperature(); //Permite leer la temperatura.


      //Se imprime en pantalla los datos leìdos.
      Serial.print("Temperatura: ");
      Serial.print(temp);
      Serial.print("ºC"); //Tempertura: 29ºC
      Serial.print("Humedad: ");
      Serial.print(humedad);
      Serial.print("%");
      Serial.println(" ");
      Serial.println(" ");

      //Pausa de 1 Segundo para poder apreciar los datos.
      delay(1000);

      while (temp>=24){ //Condición para mantener el ambiente fresco.
        Serial.println("Ventiladores Encendidos");V  V
        digitalWrite(ventilador,HIGH); //Encendemos el ventilador
        temp= dht.readTemperature(); //Volvemos a leer la temperatura
        delay(2000);
        }
        digitalWrite(ventilador,LOW);

  }
