/* Implementación del movimiento de los tres motores de la impresora 3D para formar un cuadrado */

/* Este código se encuentra bajo una licencia de Creative Commons
   en la modalidad "Atribución/Compartir Igual" */

#define IN1  11
#define IN2  10
#define IN3  9
#define IN4  8

#define IN5  7
#define IN6  6
#define IN7  5
#define IN8  4

#define IN9 3
#define IN10 2
#define IN11 1
#define IN12 0


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

int niveles = 5;
boolean Direction = true;
int Steps = 0; // Define el paso actual de la secuencia

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  pinMode(IN9, OUTPUT);
  pinMode(IN10, OUTPUT);
  pinMode(IN11, OUTPUT);
  pinMode(IN12, OUTPUT);
}

void loop() {

  while(niveles > 0) {

    Direction = true;
    
    for (int i=0; i <= 1536; i++){
      stepper1();
      delay(3);
    }
    delay(100);
  
    for (int i=0; i <= 1536; i++){
      stepper2();
      delay(3);
    }
    delay(10);
  
    Direction = ! Direction;
  
    for (int i=0; i <= 1536; i++){
      stepper1();
      delay(3);
    }
    delay(100);
  
    for (int i=0; i <= 1536; i++){
      stepper2();
      delay(3);
    }
    delay(10);
  
    Direction = ! Direction;
  
    for (int i=0; i <= 2048; i++){
      stepper3();
      delay(3);
    }

    niveles--;
  }
  
  /* delay(300);
  Direction = ! Direction; // Invertimos la direceccion de giro
  steps_left = 4095; */
}

void stepper1()     //EJE X. Avanza un paso
{
  digitalWrite(IN1, Paso[Steps][0]);
  digitalWrite(IN2, Paso[Steps][1]);
  digitalWrite(IN3, Paso[Steps][2]);
  digitalWrite(IN4, Paso[Steps][3]);
    
  SetDirection();
}

void stepper2()     //EJE Y. Avanza un paso
{
  digitalWrite(IN5, Paso[Steps][0]);
  digitalWrite(IN6, Paso[Steps][1]);
  digitalWrite(IN7, Paso[Steps][2]);
  digitalWrite(IN8, Paso[Steps][3]);
    
  SetDirection();
}

void stepper3()     //EJE Z. Avanza un paso
{
  digitalWrite(IN9, Paso[Steps][0]);
  digitalWrite(IN10, Paso[Steps][1]);
  digitalWrite(IN11, Paso[Steps][2]);
  digitalWrite(IN12, Paso[Steps][3]);
    
  SetDirection();
}

void SetDirection() {
  
  if (Direction)
    Steps++;
  
  else
    Steps--;

  Steps = (Steps + 8) % 8;
}
