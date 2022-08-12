// Set-up low-level interrupts for most acurate BPM math.
#define USE_ARDUINO_INTERRUPTS true
    
// Includes the PulseSensorPlayground Library.   
#include <PulseSensorPlayground.h>     

// PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int PulseWire = 0;

// The on-board Arduino LED, close to PIN 13.      
const int LED13 = 13; 

/*Determine which Signal to "count as a beat" and which to ignore.         
 *Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
 *Otherwise leave the default "550" value.
*/
int Threshold = 550;

// To keep track when there isn't any pulse                              
int Timer = 0;

// Creates an instance of the PulseSensorPlayground object called "pulseSensor"                               
PulseSensorPlayground pulseSensor;

void setup() {   
  Serial.begin(9600);
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);     
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
  if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute(); // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now.                                              
  Timer = Timer + 1;                           // Add 1 to "Timer" every second
  delay(1000);  
   
  if (pulseSensor.sawStartOfBeat()) {              // Constantly test to see if "a beat happened". 
    Serial.println("♥  A HeartBeat Happened ! ");  // If test is "true", print a message "a heartbeat happened".
    Serial.print("BPM: ");                         // Print phrase "BPM: " 
    Serial.println(myBPM);                         // Print the value inside of myBPM. 
    Timer = 0;                                     // If there's a beat reset the timer to zero
 }

  // If "Timer" has not been reset, there's no pulse
  if (Timer > 1){
    Serial.println("No pulse");
 }
 
 delay(20);                    
}
