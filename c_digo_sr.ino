//Código do Projeto Separador de Remédios do Grupo das Batatas (Alunas: Amanda Smanioto, Camila Faleiros, Daniela Flauto, Fernanda Hamatsu)

#include <Servo.h>                                     //importar a biblioteca dos motores

#define S0 2                                           //define a porta do led S0 do sensor

#define S1 3                                           //define a porta do led S1 do sensor

#define S2 4                                           //define a porta do led S2 do sensor

#define S3 5                                           //define a porta do led S3 do sensor

#define sensorOut 6                                    //define a saída do sinal do sensor

Servo Servo7;                                          //define o nome do primeiro motor

Servo Servo8;                                          //define o nome do segundo motor

int frequency = 0;                                     //valor inicial da variável frequência

int color = 0;                                         //valor inicial da variável cor

String cor = "";                                       

 

void setup() {

  pinMode(S0, OUTPUT);                                 //porta S0 como saída

  pinMode(S1, OUTPUT);                                 //porta S1 como saída

  pinMode(S2, OUTPUT);                                 //porta S2 como saída

  pinMode(S3, OUTPUT);                                 //porta S3 como saída

  pinMode(sensorOut, INPUT);                           //porta sensorOut (6) como de entrada

  digitalWrite(S0, HIGH);                              //acende o led S0

  digitalWrite(S1, LOW);                               //acende o led S1

  Servo7.attach(7);                                    //define a porta do motor Servo7

  Servo8.attach(8);                                    //define a porta do motor Servo8

  Serial.begin(9600);                                  //identifica o Arduino Uno R3

}

void loop() {                                          

  Servo7.write(115);                                   //altera a posição do Servo7 para 115 (inicial), onde coletará o remédio

  delay(2000);                                         //espera 2s

 

  for(int i = 115; i > 65; i--) {                      //loop qe altera aposição do Servo7 em intervalos de 20ms

    Servo7.write(i);

    delay(20);

  }

  delay(2000);                                         //espera 2s

 

  color = readColor();                                 //chama a função readColor para identificar a cor do remédio

  delay(1000);                                         //espera 1s

  switch (color) {                                     //testa a variável color e a compara com os seguintes casos

    case 1:                                            //cor vermelho

    Servo8.write(50);                                  //altera a posição do Servo8

    Serial.println(cor);                               //retorna a cor no monitor serial para o controle

    break;                                             //encerra o teste

    case 2:                                            //cor verde

    Serial.println(cor);                               //retorna a cor no monitor serial para o controle

    Servo8.write(75);                                  //altera a posição do Servo8   

    break;                                             //encerra o teste

    case 3:                                            //cor amarelo

    Serial.println(cor);                               //retorna a cor no monitor serial para o controle

    Servo8.write(100);                                 //altera a posição do Servo8 

    break;                                             //encerra o teste

    case 4:                                            //cor azul

    Serial.println(cor);                               //retorna a cor no monitor serial para o controle

    Servo8.write(125);                                 //altera a posição do Servo8 

    break;                                             //encerra o teste

    case 5:                                            //cor não identificada / branco

    Serial.println(cor);                               //retorna a cor no monitor serial para o controle

    Servo8.write(150);                                 //altera a posição do Servo8 

    break;                                             //encerra o teste

   

    case 0:                                            //caso não hajam remédios a serem identificados

    break;                                             //encerra o teste

  }

  delay(2000);                                         //espera 2s

 

  for(int i = 65; i > 29; i--) {                       //loop: altera a posição do Servo7 a cada 20ms

    Servo7.write(i);

    delay(20);

  }

  delay(2000);                                         //espera 2s

 

  for(int i = 29; i < 115; i++) {                      //loop: altera a posição do Servo7 a cada 20ms

    Servo7.write(i);                                   

    delay(20);

  }

  color=0;

}

 

int readColor() {                                      //define a função readColor


  digitalWrite(S2, LOW);                               //apaga o led S2

  digitalWrite(S3, LOW);                               //apaga o led S3


  frequency = pulseIn(sensorOut, LOW);                 //mede a frequência com a reflexão da cor vermelha

  int R = frequency;                                   //atribui o valor medido a variável R


  Serial.print("R= ");                                 //retorna o valor ao monitor serial

  Serial.print(frequency);

  Serial.print("  ");


  delay(50);                                           //espera 50ms


  digitalWrite(S2, HIGH);                              //acende o led S2

  digitalWrite(S3, HIGH);                              //acende o led S3


  frequency = pulseIn(sensorOut, LOW);                 //mede a frequência com a reflexão da cor verde

  int G = frequency;                                   //atribui o valor medido a variável G


  Serial.print("G= ");                                 //retorna o valor ao monitor serial

  Serial.print(frequency);

  Serial.print("  ");


  delay(50);                                           //espera 50ms


  digitalWrite(S2, LOW);                               //apaga o led S2

  digitalWrite(S3, HIGH);                              //acende o led S3

 

  frequency = pulseIn(sensorOut, LOW);                 //mede a frequência com a relfexão da cor azul

  int B = frequency;                                   //atribui o valor medido a variável B

 
  Serial.print("B= ");                                 //retorna o valor ao monitor serial

  Serial.print(frequency);

  Serial.println("  ");

 
  delay(50);                                           //espera 50ms


//os seguintes valores dever ser alterados para calibrar o sensor de cores no início do processo


  if(100<R && R<130 && 20<G && G<50 && 20<B && B<26){        //valores para a cor azul

    color = 4; // Azul                                 

    cor = "azul";

  }

  if(80<R && R<220 && 40<G && G<65 && 60<B && B<180){        //valores para a cor verde

    color = 2; // Verde

    cor = "verde";

  }

  if(10<R && R<55 && 25<G && G<70 && 45<B && B<110) {        //valores para a cor amarela

    color = 3; // Amarelo

    cor = "Amarelo";

  }

  if(105<R && R<130 && 150<G && G<190 && 135<B && B<155){    //valores para a cor vermelha

    color = 1; // Vermelho

    cor = "vermelho";

  }

  else {

    color = 5; // Outras cores

    cor = "Outras cores";

  }
   
  return color;                                              //retorna o valor da variável cor

   

}
