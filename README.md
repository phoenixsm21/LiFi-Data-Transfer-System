# LiFi-Data-Transfer-System
This project used two different Arduinos that is connected to two different computers, each are
connected to their own serial monitor. One computer act as a data transmitter, while another
computers act as the data receiver. Data between two pc are transmitted using light that is send by
Arduino's transmitter using an LED and is captured by Arduino's receiver using a photodiode. The data transmitted is string of characters that will be sent from the transmitter computer's serial
monitor into receiver computer's serial monitor. 

Steps
1. The transmitter code will be uploaded into Arduino Transmitter while the receiver code will be uploaded into Arduino Trasnmitter. 
2. Connect Arduino Transmitter with an LASER, with the Anode pin at D13 while cahthode pin at ground.
3. Connect Arduino receiver with the photodiode, the AO pin is connected to A0 pin on Arduino Nano
After the codes have been uploaded, open serial monitor using this combination of keys ctrl + shift + m on both of the computers. Set the Baud rate to be 9600, The data to be transmitted, stored in the transmitter code will start encoding and transferring through the LASER. Meanwhile arduino receiver will read the Intensity of light that it received throught the photodiode and translate it again into binary and then into character before it sent the string of characters into the receiver computer and LCD display.
