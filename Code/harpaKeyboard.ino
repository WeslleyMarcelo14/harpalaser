// Deve ser usado Arduino Leonardo por conta do seu chip ter funcionamento como a de um "teclado"

#include <Keyboard.h>

// Configurações dos pinos
int digitalPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // 12 entradas digitais

// Teclas correspondentes aos sensores
char keys[] = {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 't', 'T', 'y', 'Y', 'u'};

// Estado das teclas (para evitar enviar múltiplas vezes a mesma tecla)
bool keyPlayed[12] = {false};

void setup() {
  // Inicializa a comunicação com o teclado
  Keyboard.begin();
  
  // Configura os pinos digitais como entradas
  for (int i = 0; i < 12; i++) {
    pinMode(digitalPins[i], INPUT_PULLUP); // Configura com pull-up interno
  }
}

void loop() {
  // Leitura dos pinos digitais
  for (int i = 0; i < 12; i++) {
    int sensorValue = digitalRead(digitalPins[i]);

    // Altera a lógica para tocar o teclado quando o sensor não detectar luz (HIGH)
    if (sensorValue == HIGH && !keyPlayed[i]) { // A tecla é pressionada quando a luz está ausente
      Keyboard.press(keys[i]); // Pressiona a tecla correspondente
      keyPlayed[i] = true;
    } else if (sensorValue == LOW && keyPlayed[i]) { // A tecla é liberada quando a luz é detectada
      Keyboard.release(keys[i]); // Solta a tecla
      keyPlayed[i] = false;
    }
  }
}
