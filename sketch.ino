#define S1VERDE 23
#define S1AMARELO 25
#define S1VERMELHO 27

#define S2VERDE 29
#define S2AMARELO 31
#define S2VERMELHO 33

#define S3VERDE 35
#define S3AMARELO 37
#define S3VERMELHO 39

#define S4VERDE 41
#define S4AMARELO 43
#define S4VERMELHO 45

#define P1VERDE A8
#define P1VERMELHO A9

#define P2VERDE A10
#define P2VERMELHO A11

#define P3VERDE A12
#define P3VERMELHO A13

#define P4VERDE A14
#define P4VERMELHO A15

#define BTN1 3
#define BTN2 2
#define BTN3 20
#define BTN4 21

volatile bool pedestreSolicitadoNorte = false;
volatile bool pedestreSolicitadoLeste = false;
volatile bool pedestreSolicitadoSul = false;
volatile bool pedestreSolicitadoOeste = false;



void setup() {
  pinMode(S1VERDE, OUTPUT);
  pinMode(S1AMARELO, OUTPUT);
  pinMode(S1VERMELHO, OUTPUT);

  pinMode(S2VERDE, OUTPUT);
  pinMode(S2AMARELO, OUTPUT);
  pinMode(S2VERMELHO, OUTPUT);

  pinMode(S3VERDE, OUTPUT);
  pinMode(S3AMARELO, OUTPUT);
  pinMode(S3VERMELHO, OUTPUT);

  pinMode(S4VERDE, OUTPUT);
  pinMode(S4AMARELO, OUTPUT);
  pinMode(S4VERMELHO, OUTPUT);

  pinMode(P1VERDE, OUTPUT);
  pinMode(P1VERMELHO, OUTPUT);

  pinMode(P2VERDE, OUTPUT);
  pinMode(P2VERMELHO, OUTPUT);

  pinMode(P3VERDE, OUTPUT);
  pinMode(P3VERMELHO, OUTPUT);

  pinMode(P4VERDE, OUTPUT);
  pinMode(P4VERMELHO, OUTPUT);


  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);


  attachInterrupt(digitalPinToInterrupt(BTN1), solicitacaoPedestreNorte, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN2), solicitacaoPedestreLeste, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN3), solicitacaoPedestreSul, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN4), solicitacaoPedestreOeste, CHANGE);


  Serial.begin(9600);
  Serial.print("INICIAR");

  vermelho();

}

 
void loop() {
  

  if(pedestreSolicitadoNorte == true){
    cicloPedestre(P1VERDE, P1VERMELHO);
    pedestreSolicitadoNorte = false;

  }

  if(pedestreSolicitadoLeste == true){
    cicloPedestre(P2VERDE, P2VERMELHO);
    pedestreSolicitadoLeste = false;
  }

  if(pedestreSolicitadoSul == true){
    cicloPedestre(P3VERDE, P3VERMELHO);
    pedestreSolicitadoSul = false;
  }

  if(pedestreSolicitadoOeste == true){
    cicloPedestre(P4VERDE, P4VERMELHO);
    pedestreSolicitadoOeste = false;
  }

  if(Serial.available() > 0){
    switch(Serial.read()){
      case 'N':
        cicloSinal(S1VERDE, S1AMARELO, S1VERMELHO);
        break;

      case 'L':
        cicloSinal(S2VERDE, S2AMARELO, S2VERMELHO);
        break;

      case 'S':
        cicloSinal(S3VERDE, S3AMARELO, S3VERMELHO);
        break;

      case 'O':
        cicloSinal(S4VERDE, S4AMARELO, S4VERMELHO);
        break;
      
      default:
        break;
        
    }
  }
  else {
    digitalWrite(S1VERDE, HIGH);
    digitalWrite(S1VERMELHO, LOW);
  }

}

void cicloSinal(int verde, int amarelo,int vermelho){

  digitalWrite(vermelho, LOW);
  digitalWrite(verde, HIGH);
  delay(1000);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, HIGH);
  delay(1000);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);
  delay(1000);
}
void cicloPedestre(int verde, int vermelho){
  delay(100);
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, HIGH);
  delay(1000);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
  delay(1000);
}

void solicitacaoPedestreNorte(){
  pedestreSolicitadoNorte = true;
}

void solicitacaoPedestreLeste(){
  pedestreSolicitadoLeste = true;
}

void solicitacaoPedestreSul(){
  pedestreSolicitadoSul = true;
}

void solicitacaoPedestreOeste(){
  pedestreSolicitadoOeste = true;
}

void vermelho() {
  digitalWrite(S1VERMELHO, HIGH);
  digitalWrite(S2VERMELHO, HIGH);
  digitalWrite(S3VERMELHO, HIGH);
  digitalWrite(S4VERMELHO, HIGH);
  digitalWrite(P1VERMELHO, HIGH);
  digitalWrite(P2VERMELHO, HIGH);
  digitalWrite(P3VERMELHO, HIGH);
  digitalWrite(P4VERMELHO, HIGH);
  
}