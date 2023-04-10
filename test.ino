#define RED 13

#define BLUE 12

#define GREEN 11

#define TERMINER 10

#define TEMP_SENSOR A0

void setup(){
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(TERMINER, OUTPUT);
    pinMode(TEMP_SENSOR, INPUT);
    Serial.begin(9600);
}
int val = 255;
void loop(){
    float volatage = analogRead(TEMP_SENSOR) * 5.0 / 1024.0;
    float temperature = volatage * 100 - 50;
    Serial.println(temperature);

if(temperature <= 20){
    digitalWrite(RED, LOW);
    digitalWrite(TERMINER, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
    val = 20;
}else if(temperature <= 30){
    digitalWrite(RED, LOW);
    digitalWrite(TERMINER, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
    val = 30;
}else{
    digitalWrite(RED, HIGH);
    digitalWrite(TERMINER, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    val = 31;
}
analogWrite(TERMINER, val);
}