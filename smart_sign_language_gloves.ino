#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

int thumb=A0;
int indexf=A1;
int middlef=A2;
int ringf=A3;
int littlef=A4;

int speaker=8;
int ledPin=9;

// thresholds (center values)
#define T_TH 400
#define I_TH 385
#define M_TH 425
#define R_TH 580
#define L_TH 585   // adjusted slightly lower for stability

void setup()
{
  lcd.begin(16,2);
  lcd.print("Sign Language");
  delay(2000);
  lcd.clear();

  pinMode(speaker,OUTPUT);
  pinMode(ledPin,OUTPUT);
}

void niceBeep()
{
  tone(speaker,1200);
  delay(120);
  noTone(speaker);
}

void loop()
{
  int t=analogRead(thumb);
  int i=analogRead(indexf);
  int m=analogRead(middlef);
  int r=analogRead(ringf);
  int l=analogRead(littlef);

  bool gesture=false;

  // NORMAL fingers
  bool tStraight = t >= T_TH;
  bool tBent = t < T_TH;

  bool iStraight = i >= I_TH;
  bool iBent = i < I_TH;

  bool mStraight = m >= M_TH;
  bool mBent = m < M_TH;

  bool rStraight = r >= R_TH;
  bool rBent = r < R_TH;

  // ⚠ LITTLE FINGER (special handling)
  bool lStraight = l >= (L_TH + 2);   // stricter
  bool lBent = l < L_TH;

  lcd.setCursor(0,0);

  // HELLO
  if(tBent && iBent && mBent && rBent && lBent)
  {
    lcd.print("HELLO        ");
    niceBeep();
    gesture=true;
  }

  // YES
  else if(tStraight && iBent && mBent && rBent && lBent)
  {
    lcd.print("YES          ");
    niceBeep();
    gesture=true;
  }

  // NO
  else if(tBent && iStraight && mStraight && rStraight && lStraight)
  {
    lcd.print("NO           ");
    niceBeep();
    gesture=true;
  }

  // WATER
  else if(tBent && iStraight && mStraight && rBent && lBent)
  {
    lcd.print("WATER        ");
    niceBeep();
    gesture=true;
  }

  // FOOD
  else if(tStraight && iStraight && mStraight && rBent && lBent)
  {
    lcd.print("FOOD         ");
    niceBeep();
    gesture=true;
  }

  // HELP
  else if(tStraight && iBent && mStraight && rBent && lStraight)
  {
    lcd.print("HELP         ");
    niceBeep();
    gesture=true;
  }

  // EMERGENCY
  else if(tStraight && iStraight && mStraight && rStraight && lBent)
  {
    lcd.print("EMERGENCY    ");
    tone(speaker,800);
    delay(150);
    tone(speaker,1400);
    delay(150);
    noTone(speaker);
    gesture=true;
  }

  else
  {
    lcd.print("UNKNOWN      ");
  }

  digitalWrite(ledPin,gesture?HIGH:LOW);

  delay(300);
}