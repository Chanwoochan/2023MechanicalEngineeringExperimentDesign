#include "master.h"

LiquidCrystal_I2C lcd(0x27,16,2);

void LCDSetup(){
  lcd.init(); 
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("Team A!");
  delay(1000);
  lcd.clear();
}

void timeParsing(String inputStr){
  int index_start = inputStr.indexOf(':');
  int index_end = inputStr.indexOf(',');
  String result = inputStr.substring(index_start+1, index_end);
  lcd.setCursor(0,0);
  lcd.print("Time:");
  lcd.setCursor(6,0);
  lcd.print(result);
  lcd.setCursor(5+index_end-index_start,0);
  lcd.print(" sec");
}

void accParsing(String inputStr) {
  int index_start = inputStr.indexOf(',',2);
  int index_end = inputStr.indexOf('\n');
  String result = inputStr.substring(index_start+1,inputStr.length()-1);
  lcd.setCursor(0,1);
  lcd.print("acc:");
  if(inputStr.substring(index_start+1,index_start+2) == String("-")){
    lcd.setCursor(5,1); 
  } else {
    lcd.setCursor(5,1); 
    lcd.print(" ");
    lcd.setCursor(6,1);
  }
  lcd.print(result);
  lcd.setCursor(11,1);
  lcd.print("m/s^2");
}
