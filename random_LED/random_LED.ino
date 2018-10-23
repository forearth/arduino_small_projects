// 변수, 상수 설정
long randNumber;        //random 변수
const int led_1 = 2;    //첫번째 LED
const int led_2 = 3;    //두번째 LED
const int led_3 = 4;    //세번째 LED
const int btn=8;        //입력버튼

void setup() {
  Serial.begin(9600);       //serial 통신 9600속도로 시작
  randomSeed(analogRead(0)); //analog 0번핀에 노이즈로 랜덤초기값 설정   
  pinMode(btn, INPUT);        //입력버튼 INPUT 모드로 설정
}

void loop() {
// 입력버튼 상태에 따라 제어, 
// 만약 버튼이 눌러진 상태라면 랜덤하게 선택된 LED만 켜지고, 
// 그렇지 않으면 빠른속도 반복

  if (digitalRead(btn) == HIGH) {
    Serial.println("HIGH");
    Serial.println(randNumber);
    CtrlLED(randNumber);
  } else {
    Serial.println("LOW");
    randNumber = random(2, 5);
    Serial.println(randNumber);
    CtrlLED(randNumber);
    delay(10);
  }
}

// LED 제어함수, 모든 LED를 껐다가, 특정 LED만 켬
void CtrlLED(int pinNum) {
  TurnOffLED();
  digitalWrite(pinNum, HIGH);
}

// 모든 LED 끄기
void TurnOffLED() {
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
}

