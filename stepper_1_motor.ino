/* Implementación del movimiento de un motor */

/* Este código se encuentra bajo una licencia de Creative Commons
   en la modalidad "Atribución/Compartir Igual" */

#define IN1  11
#define IN2  10
#define IN3  9
#define IN4  8


int Paso [ 8 ][ 4 ] =
{ {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

int steps_left = 4095;
boolean Direction = true;
int Steps = 0; // Define el paso actual de la secuencia

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  
  while(steps_left > 0) {
    stepper();
    steps_left--;
    delay(1);
  }
  
  delay(300);
  Direction = ! Direction; // Invertimos la direceccion de giro
  steps_left = 4095;
}

void stepper()
{
  digitalWrite(IN1, Paso[Steps][0]);
  digitalWrite(IN2, Paso[Steps][1]);
  digitalWrite(IN3, Paso[Steps][2]);
  digitalWrite(IN4, Paso[Steps][3]);
    
  SetDirection();
}

void SetDirection() {
  
  if (Direction)
    Steps++;
  
  else
    Steps--;

  Steps = (Steps + 8) % 8;
}
