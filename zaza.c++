#include <wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614()

FLAME SENSOR PINS
int FlameLeft =A0;
int flameFront =A1;
int FlameRight =A2;
                              
SMOKE SENSORS PINS
Int smokePin =A3;

MOTOR PINS
Int leftmotor1 =5;
Int leftMotor2 =6;
Int rightMotor1 =9;
Int rightMotor2 =10;

WATER PUMP RELAY
Int relayPin =7;

void setup() {
    seria.begin(9600);
    mlx.begin();

    pinMode(flameLeft, INPUT);
    pinmode(flamefront, INPUT);
    pinmode(flameRight, INPUT);
    pinMode(smokePin, INPUT);

    Pinmode(leftmotor1, OUTPUT);
    Pinmode(leftmotor2, OUTPUT);
    Pinmode(rightmotor1, OUTPUT);
    pinmode(rightmotor2, OUTPUT);

    pinmode(relayPin, OUTPUT);
    Digitalwrite(relayPin, LOW);
}
MOTOR FUNCTIONS

void foward(){
    digitalwrite(leftmotor1,HIGH);
    digitalwrite(leftmotor2, LOW);
    digitalwrite(rightmotor1, HIGH);
    digitalwrite(rightmotor2, LOW);
}

void turnleft(){
    digitalwrite(leftmotor1, LOW);
    digitalwrite(leftmotor2, LOW);
    digitalwrite(rightmotor1, HIGH);
    digitalwrite(rightmotor2, LOW);

}

void turnright(){
    digitalwrite(leftmotor1, HIGH);
    digitalwrite(leftmotor2, LOW);
    digitalwrite(rightmotor1,LOW);
    digitalwrite(rightmotor2, LOW);
}

void stopmotors(){
    digitalwrite(leftmotor1, LOW);
    digitalwrite(leftmotor2, LOW);
    digitalwrite(rightmotor1,LOW);
    digitalwrite(rightmotor2, LOW);
}

MAIN LOOP

void loop(){

    read flame Sensors
int L = analogread(flameleft);
int F = analogread(flamefront);
int R = analogread(flamerigh);

flame threshold 
int flamethreshold =300;

bool leftflame = L < flamethreshold;
bool frontflame = F < flamethreshold;
bool rightflame = R < flamethreshold;
}
THERMAL CAMERA
float temperature = mlx.readobjectTempC(); 
bool hotfire = temperature>60;

READ SMOKE SENSOR
int smokeValue = analogread(smokepin);
bool smokeDetected = smokeValue > 400;

serial.print("L:");serial.print(L);
serial.print("F:");serial.print(F);
serial.print("R:");serial.print(R);
serial.print("temp:");serial.print(temperature);
serial.print("smoke:");serial.printIn(smokeValue);

MOVE TOWARD FIRE DIRECTION

if (frontfire){
    foward();
}
else if (leftfire){
    turnleft();
}
else if (rightfire){
    turnright();
}
else{
    foward();
}
if (hotfire && smokedetected && F < 150){
    stopmotor();
    digitalwrite(relaypin, HIGH);
    delay(4000);
    digitalwrite(relaypin, LOW);
    delay(1000);
}
delay(100);
}
 


