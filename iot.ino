#include <MakerKit.h>
#include <ESP32Servo.h>

#define BLYNK_TEMPLATE_ID           "TMPL6cdzdcEFt"
#define BLYNK_DEVICE_NAME           "iot"
#define BLYNK_AUTH_TOKEN            "VlrEEyYCebxnAfTxa-ym8ke17zU5p-Mf"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "@cfanafn";
char pass[] = "Hikari31";
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0xff0000);
    pixels.setPixelColor(1, 0xff0000);
    pixels.setPixelColor(2, 0x00cccc);
    pixels.setPixelColor(3, 0xffffff);
    pixels.setPixelColor(4, 0xff0000);
    pixels.show();
    pixels.show();

  } else {
    pixels.setPixelColor(0, 0x000066);
    pixels.setPixelColor(1, 0x000066);
    pixels.setPixelColor(2, 0x000066);
    pixels.setPixelColor(3, 0x000066);
    pixels.setPixelColor(4, 0x000066);
    pixels.show();
    pixels.show();

  }
}

BlynkTimer Timer1;

void Timer1_TimerEvent()
{
  Blynk.virtualWrite(V2, ultrasonic(12,27));
}

BLYNK_WRITE(V4)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,200);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,200);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V5)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,200);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,200);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);

  }
}

Servo servo_23;
BLYNK_WRITE(V8)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    servo_23.write(0);

  } else {
    servo_23.write(90);

  }
}

BLYNK_WRITE(V3)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,50);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,50);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V9)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,50);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,50);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V7)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,30);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,70);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V6)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,30);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,70);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);

  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();

  Timer1.setInterval(1000, Timer1_TimerEvent);

  pinMode(13,OUTPUT);
 pinMode(14,OUTPUT);
 pinMode(25,OUTPUT);
  pinMode(18,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(15,OUTPUT);
  servo_23.attach(23);
}

void loop() {
  Blynk.run();
  Timer1.run();
  // ForWard

  // backward

  // GRABBER

  // ForWard SLOW

  // backward SLOW

  // right

  // LEFY

}