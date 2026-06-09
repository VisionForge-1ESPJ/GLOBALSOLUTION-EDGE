# 🚀 OrbiTrack

### 🌍 Estação Base de Monitoramento de Anomalias Térmicas e Resposta Rápida

📚 **Disciplina:** Edge Computing & Computer Systems — FIAP
🛰️ **Projeto Integrador:** Indústria Espacial

---

## ⚠️ O Problema: A Latência no Combate a Incêndios Florestais

Incêndios florestais têm uma janela de contenção extremamente curta. O grande desafio atual do monitoramento ambiental não é apenas detectar o fogo, mas a **latência na comunicação**. 

Em áreas remotas, a conectividade é escassa. Sistemas tradicionais dependem de enviar dados brutos de satélites ou sensores de campo para processamento em uma nuvem distante (Cloud Computing). Essa dependência de rede constante gera atrasos críticos na detecção e no despacho de equipes. Quando a central finalmente recebe o alerta processado, o foco de incêndio inicial já pode ter se transformado em um desastre incontrolável. 

## 🧠 A Solução: OrbiTrack e o Poder do Edge Computing

O **OrbiTrack** É uma solução inteligente de monitoramento focada em eliminar o atraso na comunicação — atuando como um **“Waze para brigadas de incêndio”**. 

Para resolver o problema da latência, aplicamos o conceito de **Edge Computing (Computação de Borda)**. Em vez de enviar todas as leituras térmicas para a nuvem analisar, o OrbiTrack realiza o processamento dos dados *localmente*, no próprio ambiente monitorado. 

**Como funciona na prática?**
1. O dispositivo (nó) lê as variações climáticas em tempo real.
2. O microcontrolador processa a lógica de decisão localmente.
3. Se a temperatura atingir o gatilho de **anomalia térmica (FRP)** estipulado em **50°C**, o próprio dispositivo entende o perigo e dispara os protocolos de emergência, sem precisar perguntar para a internet o que fazer.

> 🔔 **“O satélite detecta o fogo no espaço. O OrbiTrack processa a urgência na borda e apita na base.”**

Dessa forma, garantimos um tempo de resposta de milissegundos, economizamos largura de banda de rede e mantemos o sistema de alerta funcional mesmo em cenários de instabilidade de conexão.

---

## 👨‍🚀 Integrantes do Projeto

* **Gustavo Braga Araujo** — RM: 569211
* **Leonardo Ursini** — RM: 569812
* **Henry Gabriel** — RM: 570063
* **Matheus Carvalho** — RM: 569454
* **Nicholas Belo** — RM: 571063

---

## 🎯 Objetivos da Solução

✔️ **Monitoramento em Tempo Real:** Leitura contínua de temperatura atuando como proxy de telemetria climática.
✔️ **Processamento na Borda:** Tomada de decisão local, garantindo autonomia e desvinculação da nuvem para alertas críticos.
✔️ **Feedback Multicanal:** Resposta imediata em 3 canais redundantes para a equipe de monitoramento:
  * 🔴 **Visual:** Acionamento de LEDs de alerta.
  * 📟 **Informativo:** Diagnóstico e status em display LCD.
  * 🔊 **Sonoro:** Sirene piezoelétrica (Buzzer) de alta frequência.

---

## ⚙️ Nota de Engenharia

* Sensor **DHT22** simula dados térmicos vindos de satélite
* Threshold de **50 °C** representa o gatilho de **anomalia térmica (FRP)**
* Decisão ocorre localmente 

---



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











