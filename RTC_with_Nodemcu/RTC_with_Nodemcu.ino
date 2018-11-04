#include <Wire.h>       //I2C library
#include <RtcDS3231.h>  //RTC library
 

RtcDS3231<TwoWire> rtcObject(Wire); //Uncomment for version 2.0.0 of the rtc library
 
void setup() {
 
  Serial.begin(115200);  //Starts serial connection
  rtcObject.Begin();     //Starts I2C
 
  RtcDateTime currentTime = RtcDateTime(18, 10, 21, 07, 21, 0); //define date and time object
  rtcObject.SetDateTime(currentTime); //configure the RTC with object
 
}
 
void loop() {
 
  RtcDateTime currentTime = rtcObject.GetDateTime();    //get the time from the RTC
 
  char str1[20],str2[20];   //declare a string as an array of chars
 
  sprintf(str1, "%d/%d/%d ",     //%d allows to print an integer to the string
          currentTime.Year(),   //get year method
          currentTime.Month(),  //get month method
          currentTime.Day()    //get day method
         );
         
  sprintf(str2, "%d:%d:%d",     //%d allows to print an integer to the string
          currentTime.Hour(),   //get hour method
          currentTime.Minute(), //get minute method
          currentTime.Second()  //get second method
         );

  Serial.println(str1); //print the string to the serial port
  Serial.println(str2);
 
  delay(5000); //5 seconds delay
 
}

