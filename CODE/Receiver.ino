#include <LiquidCrystal.h>
#define LED_PIN 13
#define LDR_PIN A0
#define THRESHOLD 100
#define PERIOD 15

bool previous_state;
bool current_state;
String output;  // Accumulated output string

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Adjust the pin numbers according to your LCD configuration

void setup()
{
  lcd.begin(16, 2);  // Adjust the column and row numbers according to your LCD configuration
  lcd.print("Initializing");
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  current_state = get_ldr();
  if (!current_state && previous_state)
  {
    output += get_byte();  // Accumulate byte values
  }
  previous_state = current_state;

  // Add any other code or conditions here

  // Example: Print the accumulated output on the LCD when the loop finishes
 if (output.length() >= 9) {
   print_output();
}
}

bool get_ldr()
{
  int voltage = analogRead(LDR_PIN);
  return voltage > THRESHOLD ? true : false;
}

char get_byte()
{
  char ret = 0;
  delay(PERIOD * 1.5);
  for (int i = 0; i < 8; i++)
  {
    ret = ret | get_ldr() << i;
    delay(PERIOD);
  }
  return ret;
}

void print_output()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Output: ");
  lcd.setCursor(0, 1);
  lcd.print(output);
  Serial.println(output);
  output = "";  // Clear the accumulated output
  
}