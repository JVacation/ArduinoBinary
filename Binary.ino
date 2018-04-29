int arr[50], num = 50, i; // Declaring the variables
int l1 = 2;
int l2 = 3;
int l3 = 4;
int l4 = 5;
int l5 = 6;
int l6 = 7;
int l7 = 8;
int l8 = 9;
String maxString = "";
String minString = "";

void setup() {                 // Starting the Serial Monitor and making sure that the pins are declared.
  Serial.begin(9600);
  Serial.flush();
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);
}

void loop() {
  randomGen();                 // Runs the random number generator so that the 
  sort(arr, 50);               // Runs the bubble sort against the array

  Serial.print("Sorted Array: ");
  for (int i = 0; i < 50; i++) {
    Serial.print(arr[i]);
    Serial.print(",");
  }
  char s1[6];
  char s2[6];
  Serial.println("");
  Serial.print("Max Number: ");
  Serial.print(arr[49]);     // Outputs highest number
  Serial.println("");
  Serial.print("In Binary:");
  int maxNumber = arr[49];  
  getBin (maxNumber, s1);   // Turns to binary
  maxString = s1;
  Serial.print(s1);
  Serial.println("");
  Serial.print("Min Number: ");
  Serial.print(arr[0]);      // Outputs lowest number
  Serial.println("");
  Serial.print("In Binary:");
  int minNumber = arr[0];
  getBin (minNumber, s2);   // Turns to binary
  minString = s2;
  Serial.print(s2);
  Serial.println("");
  Serial.println("");
  Serial.println("Preparing to display Max Number binary on LEDs in:");
  Serial.print("3...");
  delay(1000);
  Serial.print("2...");
  delay(1000);
  Serial.print("1...");
  delay(1000);
  Serial.println("Displaying now!");
  lights();             // Runs the LEDS to turn on and off

  delay(10000);
  digitalWrite(l1, LOW);  // Turns all the lights off.
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
}

void randomGen() {                // Random number generator
  for (i = 0; i < num; i++) {
    arr[i] = 1 + (rand() % 255);
  }
}
 
void sort(int a[], int size) {           // Bubble sort
  for (int i = 0; i < (size - 1); i++) {
    for (int o = 0; o < (size - (i + 1)); o++) {
      if (a[o] > a[o + 1]) {
        int t = a[o];
        a[o] = a[o + 1];
        a[o + 1] = t;
      }
    }
  }
}

void getBin(int value, char* output) // Turns max/min number to binary
{
  int i;
  output[8] = '\0';
  for (i = 7; i >= 0; --i, value >>= 1)
  {
    output[i] = (value & 1) + '0';
  }
}

void lights()          // Reads if the digit from the binary is 0 or 1. If 1 the led is turned on.
{
  String firstchar = maxString.substring(0, 1);  // Splits the max string into a substring. This is each light can be provided a digit. This determines if it is a 1 or a 0
  String secchar = maxString.substring(1, 2);
  String thirdchar = maxString.substring(2, 3);
  String fourthchar = maxString.substring(3, 4);
  String fifthchar = maxString.substring(4, 5);
  String sixthchar = maxString.substring(5, 6);
  String seventhchar = maxString.substring(6, 7);
  String eighthchar = maxString.substring(7, 8);

  if (firstchar.equals("1")) {    // If statement. If the the first substring = 1 then the led turns on
    digitalWrite(l1, HIGH);
  }
  if (secchar.equals("1")) {
    digitalWrite(l2, HIGH);
  }
  if (thirdchar.equals("1")) {
    digitalWrite(l3, HIGH);
  }
  if (fourthchar.equals("1")) {
    digitalWrite(l4, HIGH);
  }
  if (fifthchar.equals("1")) {
    digitalWrite(l5, HIGH);
  }
  if (sixthchar.equals("1")) {
    digitalWrite(l6, HIGH);
  }
  if (seventhchar.equals("1")) {
    digitalWrite(l7, HIGH);
  }
  if (eighthchar.equals("1")) {
    digitalWrite(l8, HIGH);
  }

  delay(10000);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);


  Serial.println("Preparing to display Min Number binary on LEDs in:");  // Delay gives some time for the first binary to be read and gives time for viewer to get ready for the next
  Serial.print("3...");
  delay(1000);
  Serial.print("2...");
  delay(1000);
  Serial.print("1...");
  delay(1000);
  Serial.println("Displaying now!");
  Serial.println("");

  firstchar = minString.substring(0, 1); // Repeats the above but for the minimum string
  secchar = minString.substring(1, 2);
  thirdchar = minString.substring(2, 3);
  fourthchar = minString.substring(3, 4);
  fifthchar = minString.substring(4, 5);
  sixthchar = minString.substring(5, 6);
  seventhchar = minString.substring(6, 7);
  eighthchar = minString.substring(7, 8);

  if (firstchar.equals("1")) {
    digitalWrite(l1, HIGH);
  }
  if (secchar.equals("1")) {
    digitalWrite(l2, HIGH);
  }
  if (thirdchar.equals("1")) {
    digitalWrite(l3, HIGH);
  }
  if (fourthchar.equals("1")) {
    digitalWrite(l4, HIGH);
  }
  if (fifthchar.equals("1")) {
    digitalWrite(l5, HIGH);
  }
  if (sixthchar.equals("1")) {
    digitalWrite(l6, HIGH);
  }
  if (seventhchar.equals("1")) {
    digitalWrite(l7, HIGH);
  }
  if (eighthchar.equals("1")) {
    digitalWrite(l8, HIGH);
  }
}








