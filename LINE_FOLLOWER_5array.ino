#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define enA 9
#define enB 6


 int M1_Speed = 190;//speed of motor 1
 int M2_Speed = 190;//speed of motor 2
 int LeftRotationSpeed = 240;  // Left Rotation Speed
 int RightRotationSpeed = 240; // Right Rotation Speed
 int LeftRotationSpeed1 = 240;  // Left Rotation Speed
 int RightRotationSpeed1 = 240; // Right Rotation Speed

 void setup() {

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

    pinMode(enA,OUTPUT);
    pinMode(enB,OUTPUT);

  Serial.begin(9600);

      pinMode(A0, INPUT); // initialize Left sensor as an input
      pinMode(A1, INPUT); // initialize Right sensor as an input
      pinMode(A2, INPUT); // initialize Left sensor as an input
      pinMode(A3, INPUT); // initialize Right sensor as an input
      pinMode(A4, INPUT); // initialize Left sensor as an input
       
      

}

void loop() {
  int maxleft=digitalRead(A0);
  int LEFT_SENSOR = digitalRead(A1);
  int center = digitalRead(A2);
  int RIGHT_SENSOR = digitalRead(A3);
  int maxright=digitalRead(A4);
  
  Serial.print(maxleft);
  Serial.print(", ");
  Serial.print(LEFT_SENSOR);
  Serial.print(", ");
  Serial.print(center);
  Serial.print(", ");
  Serial.print(RIGHT_SENSOR);
  Serial.print(", ");
  Serial.println(maxright);

if(maxleft==0 && LEFT_SENSOR==0 && center==0 && RIGHT_SENSOR==0 && maxright==0 )           // 0,0,0,0,0
 {
    left();
}

if(maxleft==0 && LEFT_SENSOR==0 && center==1 && RIGHT_SENSOR==0 && maxright==0   )         //0,0,1,0,0 
{
    forward(); //FORWARD
}

else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1&& maxright==0 && maxleft==0 && center==1)  //01110
 {
    forward();  
 }


 else if( maxleft==0 && LEFT_SENSOR==1  && center==1 && RIGHT_SENSOR==0 && maxright==0  ) //0,1,1,0,0
 {
    
    right1(); }

  else if(maxright==0 && RIGHT_SENSOR==1 && center==1 && LEFT_SENSOR==0 &&  maxleft==0 ) //01100
  {   
    left1();
}

 else if(maxright==0 && RIGHT_SENSOR==1 &&  center==1 && LEFT_SENSOR==1&& maxleft==1 ) {//01111
    right();  
 }

  else if(maxright==1 && RIGHT_SENSOR==1 &&  center==1 && LEFT_SENSOR==1&& maxleft==0 ) {//11110
    left();  
 }
 
  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1&& maxright==0 && maxleft==1 && center==1) {//00111
    right();  
 }

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0&& maxright==1 && maxleft==0 && center==1) {//11100
    left(); 
 }

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1&& maxright==1 && maxleft==1) {//11011
    forward();  
 }

if(RIGHT_SENSOR==0 && LEFT_SENSOR==0 && maxright==1&& maxleft==0 && center==1) {//10100
    left(); 
}

if(RIGHT_SENSOR==0 && LEFT_SENSOR==0 && maxright==0 && maxleft==1 && center==1) {//00101
    right();
}

if(RIGHT_SENSOR==0 && LEFT_SENSOR==0 && maxright==1&& maxleft==0 && center==0) {//10000
    left();
}

if(RIGHT_SENSOR==0 && LEFT_SENSOR==0 && maxright==0 && maxleft==1 && center==0) {//00001
    right(); 
}

if(RIGHT_SENSOR==1&& LEFT_SENSOR==0 && maxright==0&& maxleft==0 && center==0)   {//01000
    left(); 
}

if(RIGHT_SENSOR==0 && LEFT_SENSOR==1 && maxright==0 && maxleft==0 && center==0) {//00010
    right(); 
}

}




void forward()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}


void right()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void left()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void right1()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);

                analogWrite(enA, LeftRotationSpeed1);
                analogWrite(enB, RightRotationSpeed1);
}

void left1()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

                analogWrite(enA, LeftRotationSpeed1);
                analogWrite(enB, RightRotationSpeed1);
}

void Stop()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}