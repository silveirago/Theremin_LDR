/*
 Músico Nerd
 Theremin com LDR
 por Gustavo Silveira
 www.musiconerd.com

 */

const int ldrPin = A0;      // Pino onde será ligado um dos terminais do LDR
const int speaker = 11;     // Pino onde será ligado o auto falante

int sensorValue = 0;        // Valor lido pelo pino onde está LDR
int LDR = 0;                // Valor que mapeado para o auto falante

int sensorMin = 42;         // Valor mínimo detctado pelo LDR (olhar na porta serial e alterar para a sua leitura)
int sensorMax = 950;        // Valor máximo detectado pelo LDR (olhar na porta serial e alterar para a sua leitura)

int freqMin = 200;          // Frequencia mínima (em Hz) a ser tocada pelo auto falante
int freqMax = 1200;         // Frequencia máxima (em Hz) a ser tocada pelo auto falante


void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lê o avalor analógico do LDR
  sensorValue= analogRead(ldrPin);

  // mapeia os valores do LDR para as frequencias desejadas
 LDR = map(sensorValue, sensorMin, sensorMax, freqMin, freqMax);

  
  tone(speaker, LDR); // A Função tone é responsável por fazer o auto falante tocar a frequencia desejada - tone(pino, frequencia);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.println(sensorValue);

  delay(2); // espera 2 milisegundos 
}
