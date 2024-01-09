int m1a=2;
int m1b=4;

int m2a=6;
int m2b=8;
// int ir =14 ;

int buzzer = 20 ;
 
const int triger = 16 ;
const int echo = 14 ;
long duration ;
int  distance ;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
}

void loop() {

  // Clear the trigPin
 digitalWrite(triger, LOW);
 delayMicroseconds(2);

 // Set the trigPin high for 10 microseconds
 digitalWrite(triger, HIGH);
 delayMicroseconds(10);
  digitalWrite(triger, LOW);

//  // Measure the echoPin duration
  duration = pulseIn(echo, HIGH);
      
//  // Calculate the distance
  distance = duration * 0.034 / 2;

//   Print the distance to the serial monitor
 Serial.print("Distance: ");
  Serial.print(distance);  Serial.println(" cm");
  

if (distance<=20){
  Serial.print("Obstacle dectected-");
Serial.println(distance);
//    digitalWrite(buzzer , 1);
   
        
    digitalWrite(m1a, LOW);    // Stop
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);    
    digitalWrite(m2b, LOW);
    delay(500);
    digitalWrite(buzzer , 0);
    

    digitalWrite(m1a, LOW);    // Backward
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);   
    digitalWrite(m2b, HIGH);
    delay(800);
    
    digitalWrite(m1a, HIGH);    // LEFT
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);   
    digitalWrite(m2b, LOW);
    delay(500);

}
else{
  Serial.print("Obstacle not dectected-");
Serial.println(distance);

 digitalWrite(m1a, HIGH);    // motor 1 forward
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);    // motor 2 forward
    digitalWrite(m2b, LOW);
    delay(200);
}
  
}
