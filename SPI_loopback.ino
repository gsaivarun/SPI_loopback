#define Tx 4
#define Rx 5
#define SCLK 2
#define CS 3
char data[4] = {'0', '1', '1', '0'};

int size = sizeof(data);
void setup() {
  Serial.begin(9600); // Initialize serial communication
Serial.print(size);
  pinMode(Tx, OUTPUT);
  pinMode(Rx, INPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(CS, OUTPUT);

  for (int i = 0; i < size; i++) {
    digitalWrite(SCLK, HIGH);
    digitalWrite(Tx, data[i] == '0' ? LOW : HIGH);
    delay(1000);  // Small delay to allow the data to be set before reading
    Serial.print(digitalRead(Rx));
    digitalWrite(SCLK, LOW);
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

