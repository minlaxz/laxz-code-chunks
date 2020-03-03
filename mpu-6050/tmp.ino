#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char ssid[] = WiFi_SSID;
char pass[] = WiFi_PASSWORD;

int ledPower = 12; //firebase_control
int ledPower_2 = 13; //firebase_control

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  WiFi.begin(WiFi_SSID,WiFi_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);

  Serial.println();
  Serial.print("connected");
  Serial.println(WiFi.localIP());

  pinMode(ledPower,OUTPUT);
  pinMode(ledPower_2, OUTPUT);
}
}

void loop(){
  delay(10);
  int ledStatus = Firebase.getInt("ledStatus_1");
  int ledStatus_2 = Firebase.getInt("ledStatus_2");
  Serial.println("Light ONE" + String(ledStatus));
  Serial.println("Light TWO" + String(ledStatus_2));
  if(ledStatus == 1){
    Blynk.virtualWrite(V1, 255);
    digitalWrite(ledPower,HIGH);
  } else{
    digitalWrite(ledPower,LOW);
    Blynk.virtualWrite(V1, 0);
  }
  if(ledStatus_2 == 1){
    Blynk.virtualWrite(V2, 255);
    digitalWrite(ledPower_2,HIGH);
  }
  if(ledStatus_2 == 0){
    Blynk.virtualWrite(V2, 0);
    digitalWrite(ledPower_2,LOW);
  }
Blynk.run();
}



#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include "SH1106.h"
#include "DHT.h"
#include <BlynkSimpleEsp8266.h>

//#define TRIGGER 3
//#define ECHO    1

#define OLED_RESET  D1   // RESET
#define OLED_DC     D2   // Data/Command
#define OLED_CS     D8   // Chip select

#define DHTPIN 2         // DHT11 OUT
#define DHTTYPE DHT11   // DHT 11

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

#define WiFi_SSID "laxz10xx"
#define WiFi_PASSWORD "52886736"

#define FIREBASE_HOST "laxz-fired-project.firebaseio.com"
#define FIREBASE_AUTH "bI3lgcpzAuV6oJ5Hlhn661xWt8vOcbaRtJK3s64E"

//char auth[] = "2ce5add8c0ff45de9dbde6dec6fe4785";
char auth[] = "fca626d6b46f4c179a5fc1d5b2f93831"; //mgmglatt
char ssid[] = "laxz10xx";
char pass[] = "52886736";

int ledPower = 12; //firebase_control
SH1106 display(true, OLED_RESET, OLED_DC, OLED_CS);
DHT dht(DHTPIN, DHTTYPE);

void setup(){

  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  WiFi.begin(WiFi_SSID,WiFi_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  
  Serial.println();
  Serial.print("connected");
  Serial.println(WiFi.localIP());

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  
  

  pinMode(ledPower,OUTPUT);
  //pinMode(TRIGGER, OUTPUT);
  //pinMode(ECHO, INPUT);
  //pinMode(BUILTIN_LED, OUTPUT);
}

void displayTempHumid(){
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)){
    display.clear(); // clearing the display
    display.drawString("Failed DHT");
    delay(100);
    return;
  }
  display.clear();
  display.drawString(0, 0, "Humidity: " + String(h) + "%"); 
  display.drawString(0, 16, "Temp: " + String(t) + "C"); 
  if (t > 35.0){
    display.drawString(0,32, "Warning Temp! Alarm Active.");
  } else{
    display.drawString(0,32, "Good Temp.No Alarm.");
  }
  display.drawString(0, 48, "Made By Min Min Latt"); 
}

/*void dist(){
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;

   if (distance <= 100) {
    Blynk.virtualWrite(V0, 255);
}
  else {
    Blynk.virtualWrite(V0, 0);
  }

 if (distance <= 80) {
    Blynk.virtualWrite(V1, 255);
}
  else {
    Blynk.virtualWrite(V1, 0);
  }

   if (distance <= 60) {
    Blynk.virtualWrite(V2, 255);
}
  else {
    Blynk.virtualWrite(V2, 0);
  }

   if (distance <= 40) {
    Blynk.virtualWrite(V3, 255);
}
  else {
    Blynk.virtualWrite(V3, 0);
  }

   if (distance <= 20) {
    Blynk.virtualWrite(V4, 255);
}
  else {
    Blynk.virtualWrite(V4, 0);
  }
  if (distance > 150){
    Blynk.virtualWrite(V5, 0);
  }
  else{
    Blynk.virtualWrite(V5, distance);
  }
  delay(100);
  Blynk.run();
}
*/

void loop(){
  displayTempHumid();
  display.display();
  delay(500);
  int ledStatus = Firebase.getInt("ledStatus");
  Serial.println(ledStatus);
  if(ledStatus == 1){
    digitalWrite(ledPower,HIGH);
  } else{
    digitalWrite(ledPower,LOW);
  }
}

