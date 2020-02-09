#define centerTrigPin 2
#define centerEchoPin 3
#define leftTrigPin 4
#define leftEchoPin 5
#define rightTrigPin 6
#define rightEchoPin 7
#define leftEnable 10
#define leftpin1 11
#define leftpin2 12
#define rightpin1 13
#define rightpin2 14
#define rightEnable 15
unsigned long time ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rightpin1,OUTPUT);
  pinMode(rightpin2,OUTPUT);
  pinMode(leftpin1,OUTPUT);
  pinMode(leftpin2,OUTPUT);
  pinMode(rightEnable,OUTPUT);
  pinMode(leftEnable,OUTPUT);
  pinMode(17,INPUT);
  digitalWrite(rightEnable,HIGH);
  digitalWrite(leftEnable,HIGH);
}
int first = 0,second=0;
int i = 0,left=0,right=0;
void loop() {
  // put your main code here, to run repeatedly:
  /*gostraight();
  TurnLeft();
  TurnRight();*/
  //analogReadResolution(10);
  first = digitalRead(16);
  second = digitalRead(17);// read the input pin
  //Serial.println(val);
  //time = millis();
  if(first==1&&second==1){
    if(i<255)i++;
    analogWrite(rightpin1,i);
    analogWrite(rightpin2,0);
    analogWrite(leftpin1,0);
    analogWrite(leftpin2,i);
    //Serial.println(i);
  }else if(first==1&&second==0){
    if(left<255)left++;
    analogWrite(rightpin1,left);
    analogWrite(rightpin2,0);
    analogWrite(leftpin1,0);
    analogWrite(leftpin2,0);
  }else if(first==0&&second==1){
    if(right<255)right++;
    analogWrite(rightpin1,0);
    analogWrite(rightpin2,0);
    analogWrite(leftpin1,0);
    analogWrite(leftpin2,right);
  }
  else{
    i=0;
    right=0;
    left=0;
    analogWrite(rightpin1,0);
    analogWrite(rightpin2,0);
    analogWrite(leftpin1,0);
    analogWrite(leftpin2,0);
  }
  delay(10);
}
void TurnLeft(){ 
  digitalWrite(rightpin1,HIGH);
  digitalWrite(rightpin2,LOW);
  digitalWrite(leftpin1,HIGH);
  digitalWrite(leftpin2,LOW);
  delay(500);
  digitalWrite(rightpin1,LOW);
  digitalWrite(rightpin2,LOW);
  digitalWrite(leftpin1,LOW);
  digitalWrite(leftpin2,LOW);
  delay(1000);
}
void TurnRight(){ 
  digitalWrite(rightpin1,LOW);
  digitalWrite(rightpin2,HIGH);
  digitalWrite(leftpin1,LOW);
  digitalWrite(leftpin2,HIGH);
  delay(500);
  digitalWrite(rightpin1,LOW);
  digitalWrite(rightpin2,LOW);
  digitalWrite(leftpin1,LOW);
  digitalWrite(leftpin2,LOW);
  delay(1000);   
}
void gostraight(){
  digitalWrite(rightpin1,HIGH);
  digitalWrite(rightpin2,LOW);
  digitalWrite(leftpin1,LOW);
  digitalWrite(leftpin2,HIGH);
  delay(500); 
  digitalWrite(rightpin1,LOW);
  digitalWrite(rightpin2,LOW);
  digitalWrite(leftpin1,LOW);
  digitalWrite(leftpin2,LOW);
  delay(1000); 
}
