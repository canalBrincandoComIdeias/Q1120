#define pinMotor1 9
#define pinMotor2 8
#define pinMotor3 7
#define pinMotor4 6

#define pinBotao 10

int portasMotor[4] = { pinMotor1, pinMotor2, pinMotor3, pinMotor4 };

int sequencia[8][4] = {
  { HIGH, LOW, LOW, HIGH },  // Passo 1
  { HIGH, LOW, LOW, LOW },   // Passo 2
  { HIGH, HIGH, LOW, LOW },  // Passo 3
  { LOW, HIGH, LOW, LOW },   // Passo 4
  { LOW, HIGH, HIGH, LOW },  // Passo 5
  { LOW, LOW, HIGH, LOW },   // Passo 6
  { LOW, LOW, HIGH, HIGH },  // Passo 7
  { LOW, LOW, LOW, HIGH }    // Passo 8
};

int passo = 0;
bool sentido = true;
int velocidade = 200;  //(de 0-parado até 255-velocidade máxima) 

unsigned long delayPasso;

void setup() {
  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
  pinMode(pinMotor3, OUTPUT);
  pinMode(pinMotor4, OUTPUT);

  pinMode(pinBotao, INPUT_PULLUP);
}

void loop() {
  sentido = digitalRead(pinBotao);

  if (((micros() - delayPasso) > (750+((255-velocidade)*36.27451))) && (velocidade > 0)) {
    delayPasso = micros();

    if (sentido) {
      passo++;
      if (passo > 7) passo = 0;
    } else {
      passo--;
      if (passo < 0) passo = 7;
    }

    for (int nL = 0; nL < 4; nL++) {
      digitalWrite(portasMotor[nL], sequencia[passo][nL]);
    }
  }
}
