#include <OneWire.h>
#include <DallasTemperature.h>
 
#define SensorPin 4
 
OneWire oneWire(SensorPin);
DallasTemperature DS18B20(&oneWire);
DeviceAddress SENSOR;

int A = 12;
int B = 13;
int C = 8;
int D = 7;
int E = 6;
int F = 11;
int G = 10;
int DP = 9;

void zero(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void um(){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
} 

void dois(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void tres(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void quatro(){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void cinco(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void seis(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void sete(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void oito(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void nove(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void ponto(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, HIGH);
}

void desligado(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void mostra_temperatura(float temp){
  int temp_int = (int) temp;
  float temp_decimais = temp - temp_int; //22,25 - 22 = 0,25
  int dezenas = temp_int / 10;
  int unidades = temp_int - (dezenas*10);
  int decimos = (temp - temp_int)*10;// 0,25*10 = 2,5 = 2
  int centesimos = temp_decimais*100 - decimos*10; //25-20=5

  // Serial.print("Temp_int:");
  // Serial.println(temp_int);

  // Serial.print("dezenas:");
  // Serial.println(dezenas);

  // Serial.print("unidades:");
  // Serial.println(unidades); 

  // Serial.print("decimos:");
  // Serial.println(decimos); 

  // Serial.print("centesimos:");
  // Serial.println(centesimos); 

  mostra_temp_aux(dezenas);
  delay(500);
  mostra_temp_aux(unidades);
  delay(500);

  ponto();
  delay(500);

  mostra_temp_aux(decimos);
  delay(500);
  mostra_temp_aux(centesimos);
  delay(500);
  desligado();
}

int mostra_temp_aux(int num){
  if (num == 0)
    zero();
  else if (num == 1)
    um();
  else if (num == 2)
    dois();
  else if (num == 3)
    tres();
  else if (num == 4)
    quatro();
  else if (num == 5)
    cinco();
  else if (num == 6)
    seis();
  else if (num == 7)
    sete();
  else if (num == 8)
    oito();
  else if (num == 9)
    nove();
  else{
    ponto();
    Serial.println("Erro");
  }
}

void setup(){
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  Serial.begin(9600);
  DS18B20.begin();
  Serial.println("Iniciando leitura da temperatura...");
  DS18B20.getAddress(SENSOR, 0);
}
 
void loop(){
  float temperatura = 0;
  DS18B20.requestTemperatures();
  temperatura = DS18B20.getTempC(SENSOR);  //Realiza conversões
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");
  mostra_temperatura(temperatura);

  delay(1500);
}

