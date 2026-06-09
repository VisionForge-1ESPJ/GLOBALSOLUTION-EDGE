// OrbiTrack - Estacao Base de Monitoramento de Anomalias Termicas
// Disciplina: Edge Computing & Computer Systems
// Prototipo = estacao TERRESTRE que recebe telemetria (buzzer/display
// fazem sentido num posto operado por humanos, nao num satelite no vacuo).

#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define LED_NORMAL 4
#define LED_ALERTA 5
#define BUZZER 6

LiquidCrystal_I2C lcd(0x27, 16, 2);  // 0x27 funciona no Wokwi
DHT dht(DHTPIN, DHTTYPE);

const float LIMIAR_QUEIMADA = 50.0;

unsigned long ultimaLeitura = 0;
const unsigned long INTERVALO = 2000;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED_NORMAL, OUTPUT);
  pinMode(LED_ALERTA, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ORBITRACK BASE");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");

  Serial.println("--- ORBITRACK GROUND STATION INICIADA ---");
  delay(1500);
  lcd.clear();
}

void loop() {
  if (millis() - ultimaLeitura < INTERVALO) return;
  ultimaLeitura = millis();

  float temperatura = dht.readTemperature();

  if (isnan(temperatura)) {
    Serial.println("Erro critico: Falha na leitura do sensor!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ERRO SENSOR");
    return;
  }

  Serial.print("Temperatura ambiente monitorada: ");
  Serial.print(temperatura);
  Serial.println(" C");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);
  lcd.print((char)223);
  lcd.print("C");

  if (temperatura >= LIMIAR_QUEIMADA) {
    digitalWrite(LED_NORMAL, LOW);

    Serial.println("[ALERTA CRITICO] FOCO DE INCENDIO DETECTADO!");
    Serial.println("[EMERGENCIA] TRANSMITINDO VETOR DE DADOS...");

    lcd.setCursor(0, 1);
    lcd.print("!! ALERTA FOGO !!");

    for (int i = 0; i < 4; i++) {
      digitalWrite(LED_ALERTA, HIGH);
      tone(BUZZER, 2000);
      delay(250);
      digitalWrite(LED_ALERTA, LOW);
      noTone(BUZZER);
      delay(250);
    }
  } else {
    digitalWrite(LED_NORMAL, HIGH);
    digitalWrite(LED_ALERTA, LOW);
    noTone(BUZZER);

    lcd.setCursor(0, 1);
    lcd.print("Status: Normal");
    Serial.println("Status: Operacao Normal. Sem anomalias.");
  }
}