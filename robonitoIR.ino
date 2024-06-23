/*
 * IRobonito V2
 * IR remote controlled Robot
 * (c) 2020 Hernan Moya
 *
 * This sketch controls a robot using an IR remote. It defines actions such as
 * moving forward, moving backward, turning left, turning right, and stopping.
 * It listens for specific IR remote codes to trigger these actions.
 */

#include <Servo.h>
#include <IRremote.h>

// Pin definitions
int RECV_PIN = 4;
int servoRightPin = 8;
int servoLeftPin = 9;

// Servo objects
Servo servoRight;
Servo servoLeft;

// IR receiver object
IRrecv irrecv(RECV_PIN);
decode_results results;

/*
 * Function declarations for robot actions
 */
void moveForward();
void moveBack();
void turnRight();
void turnLeft();
void stopMoving();

void setup()
{
  Serial.begin(9600);
  servoRight.attach(servoRightPin);
  servoLeft.attach(servoLeftPin);
  irrecv.enableIRIn(); // Start the IR receiver

  Serial.println("IRbonito V2 (c) 2020");
  Serial.println("IRbonito: Ready to start...");
  stopMoving(); // Ensure robot starts stopped
}

void loop()
{
  moveForward();
  delay(5000);
  stopMoving();
  turnLeft();
  delay(1000);
  moveForward();
  delay(5000);
  turnRight();
  delay(1000);
  stopMoving();
  delay(1000);
  moveBack();
  delay(5000);
  stopMoving();

  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);

    // Check IR remote codes and perform actions accordingly
    if (results.value == 839727) // Forward
      moveForward();
    else if (results.value == 803007) // Stop
      stopMoving();
    else if (results.value == 831567) // Turn left
      turnLeft();
    else if (results.value == 815247) // Turn right
      turnRight();
    else if (results.value == 798927) // Move back
      moveBack();

    irrecv.resume(); // Receive the next value
  }
}

void moveForward()
{
  servoLeft.write(180);
  servoRight.write(0);
  Serial.println("IRbonito: FORWARD");
}

void moveBack()
{
  servoLeft.write(0);
  servoRight.write(180);
  Serial.println("IRbonito: BACK");
}

void turnRight()
{
  servoLeft.write(180);
  servoRight.write(180);
  Serial.println("IRbonito: RIGHT");
}

void turnLeft()
{
  servoLeft.write(0);
  servoRight.write(0);
  Serial.println("IRbonito: LEFT");
}

void stopMoving()
{
  servoLeft.write(90);
  servoRight.write(90);
  Serial.println("IRbonito: STOP");
}
