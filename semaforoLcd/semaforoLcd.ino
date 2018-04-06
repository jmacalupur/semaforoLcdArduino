#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int ledR = 6;
const int ledY = 9;
const int ledG = 10;
const int boton = 13;
int timeSem = 100;
int reduccionTiempo = 20;


void setup() {
Serial.begin(9600);  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(ledR, OUTPUT);
pinMode(ledY, OUTPUT);
pinMode(ledG, OUTPUT);
pinMode(boton, INPUT_PULLUP);
}

void loop() {
cambioSem(ledR, ledY, ledG, timeSem);
}


void cambioSem(int rojo, int amarillo, int verde, int tiempo) {
  char luz0[9] = "Rojo"; 
  char luz1[9] = "Amarillo"; 
  char luz2[9] = "Verde"; 
  char *luzSem[3];
  luzSem[0]=luz0;
  luzSem[1]=luz1;
  luzSem[2]=luz2;
  int timeL[] = {100, 5, 120};


for (int a = 0; a<3; a++) {
 for (int i = timeL[a]; i>=0; i=i-1) {
     lcd.clear();
     lcd.setCursor(0,1);
     lcd.print(i);
     lcd.setCursor(0,0);
     lcd.print(luzSem[a]);

     
     switch (luzSem[a][0]) {
      case 'R':
        analogWrite(rojo, HIGH);
        analogWrite(amarillo, LOW);
        analogWrite(verde, LOW);
        break;
      case 'A':
         analogWrite(rojo, LOW);
         analogWrite(amarillo, HIGH);
         analogWrite(verde, LOW);
         break;
      case 'V':
        analogWrite(rojo, LOW);
        analogWrite(amarillo, LOW);
        analogWrite(verde, HIGH);
        if (digitalRead(boton)==LOW) {
           i = i - reduccionTiempo;
         }
        break;
     }
     delay(1000);
    }
}
    
}



