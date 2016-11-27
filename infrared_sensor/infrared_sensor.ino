#define G 7
#define F 8
#define A 9
#define B 10
#define E 6
#define D 5
#define C 4

int digit = 0;

void digit0() {
  // for 0 needed to turn ON F A B C D E segments, so:

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  //////////////////////// G segment should be turn OFF
  digitalWrite(G, LOW);

};

void digit1() {

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
};

void digit2() {

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
};

void digit3() {

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
};

void digit4() {

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
};

void digit5() {

  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
};

void digit6() {

  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
};

void digit7() {

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
};

void digit8() {

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

};

void digit9() {

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

};


void showdigit(int digit)
{

  switch (digit) {

    case 0:
      digit0();
      break;

    case 1:
      digit1();
      break;

    case 2:
      digit2();
      break;

    case 3:
      digit3();
      break;

    case 4:
      digit4();
      break;

    case 5:
      digit5();
      break;

    case 6:
      digit6();
      break;

    case 7:
      digit7();
      break;

    case 8:
      digit8();
      break;

    case 9:
      digit9();
      break;
      

    default:

      break;

  };

}

//calibration time
//Temps de reinitialisation précisemment à 37 secondes
int calibration = 30;

int val = 0;
int previous = 0;


void setup(){

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);


  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  Serial.begin(9600);

  Serial.print("Calibrating sensor ...");
  for(int i = 0; i < calibration; i++){
    if(i > (calibration - 10)) {
      showdigit(calibration - i);
    } else {
      if(i%2 == 0) {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      } else {
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
      }
    }
    delay(1000);
  }
  digit = 0;
  showdigit(digit);
  Serial.println("\nFin de la calibration");
}



void reset() {
  digit = 0;
}



void loop() {
  val = (int) digitalRead(2);

  if(val != previous) {
    previous = val;
    Serial.println(val);
    if(val == 1) {
      digit = (digit + 1)%10;
      showdigit(digit);
    }

    
  } 


  
    
  delay(500);
}

