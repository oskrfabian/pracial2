/variable
float sinVal;
int toneVal;

void setup(){
     pinMode(8, OUTPUT); // Definimos el pin 8 como salida.
                         
     Serial.begin(9600);
}
// para zumador  
void loop(){

  
  // el codigo la alarma 
     for(int x=0; x<180; x++){
      Serial.println("alarma ");
            // convertimos grados en radianes para luego obtener el valor.
            sinVal = (sin(x*(3.1412/180)));
            // generar una frecuencia a partir del valor sin
            toneVal = 2000+(int(sinVal*1000));
            tone(8, toneVal);
            delay(2); 
     }   
}
