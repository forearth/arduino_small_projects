// 상수 설정
const int redPin = 11;    //Red 핀
const int greenPin = 10;  //Green 핀
const int bluePin = 9;    //Blue 핀
const int dtime = 1000;   //delay 타임 설정

// 초기화
void setup() {
  Serial.begin(9600);
  setColor(0, 0, 0);
}

// 반복파트
void loop() {
  //Before Start 시작전 3번 LED 점멸
  blink(2);

  //Start Rainbow 무지개 7색이 1초 단위로 출력
  Serial.println("RED");
  setColor(255, 255, 0);
  delay(dtime);
  Serial.println("ORANGE");
  setColor(240, 20, 40);
  delay(dtime);
  Serial.println("Yellow");
  setColor(240, 0, 80);
  delay(dtime);
  Serial.println("Green");
  setColor(255, 0, 255);
  delay(dtime);
  Serial.println("BLUE");
  setColor(0, 255, 255);
  delay(dtime);
  Serial.println("NAVY");
  setColor(100, 255, 255);
  delay(dtime);
  Serial.println("PURPLE");
  setColor(50, 200, 200);
  delay(dtime);
}

//red, green, blue 값에 따라 0~255로 설정됨,
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

//LED 점멸함수
void blink(int count) {
  for (int i = 0; i < count; i += 1) {
    setColor(0, 0, 0);
    delay(dtime);
    setColor(255, 255, 255);
    delay(dtime);
  }
}

