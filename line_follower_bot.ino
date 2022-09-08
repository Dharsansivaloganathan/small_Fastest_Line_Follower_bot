#define left 6
#define center 7
#define right 8

//motor one
#define ENA 9
#define IN1 2
#define IN2 3

//motor two
#define ENB 10
#define IN3 4
#define IN4 5

int Speed = 120; // speed of this robot

void setup() {
  Serial.begin(9600);
  pinMode(left, INPUT);
  pinMode(center, INPUT);
  pinMode(right, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  bool leftV = digitalRead(left);
  bool centerV = digitalRead(center);
  bool rightV = digitalRead(right);

  Serial.println(rightV);

  if (leftV == 1 && centerV == 0 && rightV == 1) {
    carforward();
    Serial.println("forward");
  } else if (leftV == 0 && centerV == 0 && rightV == 0) {
    carStop();
  } else if (leftV == 1 && centerV == 1 && rightV == 1) {
    carStop();
  } else if (leftV == 0 && centerV == 0 && rightV == 1) {
    carturnleft();
  } else if (leftV == 1 && centerV == 0 && rightV == 0) {
    carturnright();
  } else if (leftV == 0 && centerV == 1 && rightV == 1) {
    carturnleft();
  } else if (leftV == 1 && centerV == 1 && rightV == 0) {
    carturnright();
  }
}

void carforward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
