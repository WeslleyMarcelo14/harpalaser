#include <MIDIUSB.h>

// Definição dos pinos digitais
const int digitalPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Pinos digitais

// Mapeamento das notas MIDI para os pinos digitais
const int midiNotes[] = {60, 62, 64, 65, 67, 69, 71, 72, 74, 76, 77, 79}; // Notas MIDI (60 = Middle C)

// Número de pinos digitais
const int numDigitalPins = sizeof(digitalPins) / sizeof(digitalPins[0]);

// Limiares e estados das teclas
const int threshold = HIGH; // Valor para ativar a tecla (HIGH quando a tecla deve ser pressionada)
bool keyPlayed[numDigitalPins] = {false}; // Array para manter o estado das teclas

void setup() {
  // Inicializa a comunicação serial para depuração (opcional)
  Serial.begin(9600);
  
  // Configura os pinos digitais como entrada
  for (int i = 0; i < numDigitalPins; ++i) {
    pinMode(digitalPins[i], INPUT);
  }
}

void loop() {
  // Leitura dos pinos digitais
  for (int i = 0; i < numDigitalPins; ++i) {
    int pinState = digitalRead(digitalPins[i]);

    if (pinState == threshold && !keyPlayed[i]) {
      // Envia a mensagem MIDI de Nota ON
      noteOn(0, midiNotes[i], 127); // Canal 0, nota MIDI, velocidade 127 (máximo)
      keyPlayed[i] = true;
      Serial.print("Nota ON: ");
      Serial.println(midiNotes[i]);
    } else if (pinState != threshold && keyPlayed[i]) {
      // Envia a mensagem MIDI de Nota OFF
      noteOff(0, midiNotes[i], 0); // Canal 0, nota MIDI, velocidade 0 (Nota OFF)
      keyPlayed[i] = false;
      Serial.print("Nota OFF: ");
      Serial.println(midiNotes[i]);
    }
  }
  
  // Pequeno delay para evitar leituras excessivas
  delay(10);
}

// Função para enviar mensagem de Nota ON
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
  MidiUSB.flush();
}

// Função para enviar mensagem de Nota OFF
void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
  MidiUSB.flush();
}
