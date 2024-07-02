#include <LiquidCrystal_I2C.h>
#include <Adafruit_MLX90614.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup()
{
  lcd.init();
  lcd.backlight();
  mlx.begin();
}

void loop()
{
  lcd.clear();                              
  lcd.setCursor(0, 0);                        
  lcd.print("Temp:");                        
  lcd.print((mlx.readObjectTempC()));         
  lcd.print((char)223);                      
  lcd.print("C");                                                             

  if (mlx.readObjectTempC() >= 31) {
  analogWrite(5,150);
  analogWrite(6,0);
  analogWrite(10,150);
  analogWrite(11,0)
  }
  else (mlx.readObjectTempC() <= 27) ; {
  analogWrite(5,0)
  analogWrite(6,0)
  analogWrite(11,0);
  analogWrite(10,0);
  } 
  delay(10000);
}



