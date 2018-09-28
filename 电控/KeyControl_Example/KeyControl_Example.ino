#define SVCC_Pin 53
#define SGND_Pin 51
#define S1_Pin 49
#define S2_Pin 47
#define S3_Pin 45
#define S4_Pin 43
#define S5_Pin 41
#define S6_Pin 39
#define S7_Pin 37
#define S8_Pin 35

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(S1_Pin, INPUT);
  pinMode(S2_Pin, INPUT);
  pinMode(S3_Pin, INPUT);
  pinMode(S4_Pin, INPUT);
  pinMode(S5_Pin, INPUT);
  pinMode(S6_Pin, INPUT);
  pinMode(S7_Pin, INPUT);
  pinMode(S8_Pin, INPUT);

  pinMode(SVCC_Pin, OUTPUT);
  pinMode(SGND_Pin, OUTPUT);
  digitalWrite(SVCC_Pin,HIGH);
  digitalWrite(SGND_Pin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.print(digitalRead(S1_Pin));
  Serial.print(digitalRead(S2_Pin));
  Serial.print(digitalRead(S3_Pin));
  Serial.print(digitalRead(S4_Pin));
  Serial.print(" ");
  Serial.print(digitalRead(S5_Pin));
  Serial.print(digitalRead(S6_Pin));
  Serial.print(digitalRead(S7_Pin));
  Serial.print(digitalRead(S8_Pin));
  Serial.println("");
  delay(500);
}
