const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int dtime =1000;

void setup(){
  Serial.begin(9600);
  setColor(0,0,0);
}

void loop(){
  //Before Start
  blink(3);

  //Start Rainbow
  Serial.println("RED");
  setColor(255,255,0);
  delay(dtime);
  Serial.println("ORANGE");
  setColor(240, 20,40);
  delay(dtime);  
  Serial.println("Yellow");
  setColor(240, 0,80);
  delay(dtime);
  Serial.println("Green");
  setColor(255,0,255);
  delay(dtime);
  Serial.println("BLUE");
  setColor(0,255,255);
  delay(dtime);  
  Serial.println("NAVY");
  setColor(100,255,255);
  delay(dtime);  
  Serial.println("PURPLE");
  setColor(50,200,200);
  delay(dtime);
}

void setColor(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void blink(int count){
  for(int i=0; i<count; i+=1){
  setColor(0,0,0);
  delay(dtime);  
  setColor(255,255,255);
  delay(dtime);
  }
}

