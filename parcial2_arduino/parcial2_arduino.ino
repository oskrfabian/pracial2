//para el boton
int boton = 2;
//variable para el zumbador
int zumbador = 6; //Pin PWM  a donde va conectado el zumbador


void setup(){
  pinMode(boton,INPUT_PULLUP);// para el boton
  pinMode(zumbador, OUTPUT);// para el zumbador

     Serial.begin(9600);
}
// para zumador
void loop(){
// PARA EL BOTON
if (digitalRead(boton)==HIGH){// if(digitalRead(boton)==o)
  Serial.println("alarma");//imprime  "alarma"
  digitalWrite (zumbador,HIGH);// ACTIVAR EL ZUMBADOR
  delay (300); // el tiempo que esta activado el zumbador
  digitalWrite(zumbador,LOW);
      }

//para el char

  if (Serial.available() ) {
    char letra = Serial.read();
    if (letra == 'E') {//encendido
      digitalWrite(zumbador, HIGH);
    }
    else if (letra == 'A') {//apagado
      digitalWrite(zumbador, LOW);
    }
  }





}
