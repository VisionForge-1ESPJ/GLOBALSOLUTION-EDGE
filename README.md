# 🚀 OrbiTrack

### 🌍 Estação Base de Monitoramento de Anomalias Térmicas


📚 **Disciplina:** Edge Computing & Computer Systems — FIAP
🛰️ **Projeto Integrador:** Indústria Espacial

---

## 🧠 Sobre o Projeto

O **OrbiTrack** é o componente de hardware do sistema **Agnelo**, uma solução inteligente de monitoramento e resposta a incêndios florestais — inspirado na lógica de um **“Waze para brigadas de incêndio”**.

https://wokwi.com/projects/465270335124027393

> 🔔 **A estação terrestre que recebe o alerta e notifica a equipe em campo**

---

## 👨‍🚀 Integrantes

* **Gustavo Braga Araujo** — RM: 569211
* **Leonardo Ursini** — RM: 569812
* **Henry Gabriel** — RM: 570063
* **Matheus Carvalho** — RM: 569454
* **Nicholas Belo** — RM: 571063



## 🛰️ Conceito

> **“O satélite detecta o fogo no espaço.
> O OrbiTrack é o que apita na base.”**

---

## ⚙️ Nota de Engenharia

* Sensor **DHT22** simula dados térmicos vindos de satélite
* Threshold de **50 °C** representa o gatilho de **anomalia térmica (FRP)**
* Decisão ocorre localmente 

---

## 🎯 Objetivos

✔️ Leitura contínua de temperatura (proxy de telemetria)
✔️ Processamento local (sem depender da nuvem)
✔️ Resposta imediata em **3 canais redundantes**:

* 🔴 Visual (LEDs)
* 📟 Informativo (LCD)
* 🔊 Sonoro (buzzer)

---

## 🧩 Componentes

| Componente      | Qtd | Função                 |
| --------------- | --- | ---------------------- |
| Arduino Uno R3  | 1   | Microcontrolador       |
| Protoboard      | 1   | Distribuição elétrica  |
| Sensor DHT22    | 1   | Leitura de temperatura |
| LCD 16x2 (I2C)  | 1   | Exibição               |
| LED Verde       | 1   | Status normal          |
| LED Vermelho    | 1   | Alerta                 |
| Buzzer          | 1   | Alarme                 |
| Resistores 220Ω | 2   | Proteção LEDs          |
| Jumpers         | —   | Conexões               |

---

## 📚 Bibliotecas

```txt
DHT sensor library
Adafruit Unified Sensor
LiquidCrystal I2C
```

---

## 🔄 Funcionamento

⏱️ Sistema roda em ciclos **não bloqueantes (millis)** a cada 2s

### 🔁 Fluxo:

1. **Inicialização**

   * Serial (9600)
   * Sensor DHT22
   * LCD
   * Mensagem de boot

2. **Leitura**

   * Temperatura a cada 2s
   * Tratamento de erro (`isnan`)

3. **Decisão (Edge Computing)**

#### 🟢 Normal (< 50 °C)

* LED verde ON
* LED vermelho OFF
* Buzzer OFF
* LCD: `Status: Normal`

#### 🔴 Alerta (≥ 50 °C)

* LED vermelho pisca ⚡
* Buzzer toca (2000Hz) 🔊
* LCD: `!! ALERTA FOGO !!`
* LED verde OFF

4. **Log**

* Monitor Serial registra tudo

---

## 🔌 Estrutura do Circuito

### ⚡ Alimentação

* Arduino → Protoboard (5V / GND)
* Distribuição centralizada

---

### 🔗 Conexões

| Componente   | Pino | Destino |
| ------------ | ---- | ------- |
| DHT22 SDA    | D2   | Arduino |
| LCD SDA      | A4   | Arduino |
| LCD SCL      | A5   | Arduino |
| LED Verde    | D4   | Arduino |
| LED Vermelho | D5   | Arduino |
| Buzzer       | D6   | Arduino |

📡 Comunicação I2C reduz fios → apenas **2 pinos (A4/A5)**

---

## ▶️ Execução

### 🧪 Wokwi (Simulação)

1. Criar projeto Arduino Uno
2. Colar `sketch.ino`
3. Colar `diagram.json`
4. Criar `libraries.txt`
5. ▶️ Start Simulation

💡 Teste: Ajuste temperatura ≥ 50 °C

---

### 🔧 Hardware Real

1. Montar circuito
2. Instalar Arduino IDE
3. Instalar bibliotecas
4. Upload do código











