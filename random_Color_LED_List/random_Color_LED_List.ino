// 상수, 변수 설정
const int redPin = 11;    //Red 핀
const int greenPin = 10;  //Green 핀
const int bluePin = 9;    //Blue 핀
const int dtime = 1000;   //delay 타임 설정
const int startPin = 2;   //랜덤 칼라 시작
const int checkPin = 3;   //랜덤 칼라 확인

bool gameStatus = true;
long randNumber;
int colorArr[5];
const int r[3] = {255, 255, 0};
const int g[3] = {255, 0, 255};
const int b[3] = {0, 255, 255};
const int w[3] = {0, 0, 0};
const char color[4] = "rgbw";
int colorLength=5;
char randColor[5];

// 초기화
void setup() {
  Serial.begin(9600);
  setColor(0, 0, 0);
  pinMode(startPin, INPUT);
  pinMode(checkPin, INPUT);
  randomSeed(analogRead(0));
}

// 반복파트
void loop() {
  if (digitalRead(startPin) == HIGH) {
    Serial.println("entered StartPin HIGH");
    blink(2);
    for (int i = 0; i < colorLength; i += 1) {
      makeRandomColor(i);
    }
  } else {
    Serial.println("entered StartPin LOW");
    if (digitalRead(checkPin) == HIGH) {
      for (int i = 0; i < colorLength; i += 1) {
        Serial.print("랜덤 칼라 읽기");
        Serial.println(i);
      }
    }
  }
}

// 랜던칼라 생성
void makeRandomColor(int i) {
  randNumber = random(4);             //랜덤값 추출
  randColor[i] = color[randNumber];   //칼라리스트에서 선택
  
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

