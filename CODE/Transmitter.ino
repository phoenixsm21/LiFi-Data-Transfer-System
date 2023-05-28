#define LED_PIN 13
#define BUTTON_PIN A0
#define PERIOD 15

char* string = "hello123#";
char* receivedString[500];  // Buffer to store received string
int stringIndex = 0;  // Index for receivedString
int string_length = 0;

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  //pinMode(BUTTON_PIN, INPUT_PULLUP);
  string_length = strlen(string);
}

void loop() 
{
  for(int i = 0; i < string_length; i ++)
  {
    send_byte(string[i]);
  }
  delay(1000);
}

void send_byte(char my_byte)
{
  digitalWrite(LED_PIN, LOW);
  delay(PERIOD);

  //transmission of bits
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(LED_PIN, (my_byte&(0x01 << i))!=0 );
    delay(PERIOD);
  }

  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);

}