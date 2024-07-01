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

  if (mlx.readObjectTempC() >= 30) {
  analogWrite(11,150);
  }
  else (mlx.readObjectTempC() <= 20) ; {
  analogWrite(11,0);
  } 
  delay(10000);
}



