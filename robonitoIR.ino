//IRobonito V 2
//IR remote controlled Robot 
// (c) hernan Moya
#include <Servo.h>
#include <IRremote.h>

int RECV_PIN = 4;
//int ledPin = 5;
//int button = 7;
int servoRightPin = 8;
int servoLeftPin = 9;
//const int numberOfKeys = 5; // 5 keys are learned (0 through 4)
//long irKeyCodes[numberOfKeys]; // holds the codes for each key
Servo servoRight;
Servo servoLeft;
IRrecv irrecv(RECV_PIN);
decode_results results;

/*
* Declara las acciones del robot
*/
void moveForward()
{
servoLeft.write(180);
servoRight.write(0);
//digitalWrite(ledPin, HIGH);
Serial.println("IRbonito. ADELANTE");
}
void moveBack()
{
servoLeft.write(0);
servoRight.write(180);
Serial.println("IRbonito. BACK");
}
void turnRight()
{
servoLeft.write(180);
servoRight.write(180);
Serial.println("IRbonito. DERECHA");
}
void turnLeft()
{
servoLeft.write(0);
servoRight.write(0);
Serial.println("IRbonito. IZQUIERDA");

}

void stopMoving()
{
servoLeft.write(90);
servoRight.write(90);
Serial.println("IRbonito. STOP");
//digitalWrite(ledPin, LOW);
}
void setup()
{
Serial.begin(9600);
servoRight.attach(servoRightPin);
servoLeft.attach(servoLeftPin);
//pinMode(ledPin, OUTPUT);
//pinMode(button, INPUT);
irrecv.enableIRIn(); // Start the ir receiver
/*long irKeyCodes[numberOfKeys] = {
839727, // forward 0 key
803007, // stop 1 key
831567, // turnLeft 2 key
815247, //turnRight 3 key
798927, //moveBack 4 key
};
*/
//stopMoving();
Serial.println("IRbonito. V3 (c) 2020");
Serial.println("IRbonito. Listo para empezar....");
stopMoving();

}

void loop()
{
  moveForward();
delay (5000);
stopMoving();
turnLeft();
delay (1000);
moveForward();
delay (5000);
turnRight();
delay (1000);
stopMoving();
delay(1000);
moveBack();
delay (5000);
stopMoving();


 if (irrecv.decode(&results)) {
   Serial.println(results.value, DEC);
if(results.value == 839727)  // Benq Projector Remote codes
  moveForward();   // IRObonito va adelante
    irrecv.resume(); // Receive the next value
     if(results.value == 803007)
     stopMoving(); // Para a IRobonito
          
    // irrecv.resume(); // Receive the next value

   if(results.value == 831567)
     turnLeft();   // IRObonito gira a la izquierda
      //irrecv.resume(); // Receive the next value

   if(results.value == 815247)
     turnRight();   // IRObonito gira a la Derecha
        //irrecv.resume(); // Receive the next value
   
   if(results.value == 798927)
     moveBack();   // IRObonito va hacia atrás

   if(results.value == 839727)
     moveForward();   // IRObonito va adelante
  
   if(results.value == 847887)
     stopMoving();   // IRObonito stop
 


 }
}
