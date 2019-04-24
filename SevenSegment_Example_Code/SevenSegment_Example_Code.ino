//Example code for a shift register driven chainable seven segment display module. 
//Daniel de Waard 12/11/16

int dataPin = 2;
int latchPin = 3;
int clockPin = 4;

int numberOfDisplays = 1;

void setup() {
pinMode(dataPin, OUTPUT);
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);

}

void loop() {

for(int x = 0; x<=9; x++){

  sevensegment(x);
  delay(500);
  
  }
}

void sevensegment(int decimal){
  
  int ones, tens, hundreds, thousands, onesB, tensB, hundredsB, thousandsB;
  
  ones = (decimal%10);
  onesB = decimalToSevenSegmentEncoding(ones);
  shiftToDisplay(onesB);
  
  if(numberOfDisplays > 1){
    tens = ((decimal/10)%10);
    tensB = decimalToSevenSegmentEncoding(tens);
    shiftToDisplay(tensB);
  }
  
  if(numberOfDisplays > 2){
    hundreds = ((decimal/100)%10);
    hundredsB = decimalToSevenSegmentEncoding(hundreds);
    shiftToDisplay(hundredsB);
  }
  
  if(numberOfDisplays > 3){
    thousands = (decimal/1000);
    thousandsB = decimalToSevenSegmentEncoding(thousands);
    shiftToDisplay(thousandsB);
  }
  
}

int decimalToSevenSegmentEncoding(int decimal){

  int binary;
  
  switch(decimal){
    default: binary = B11111111;
      break;
    case 0:  binary = B11000000;
      break;    
    case 1:  binary = B11111001;
      break;    
    case 2:  binary = B10100100;
      break;
    case 3:  binary = B10110000;
      break;
    case 4:  binary = B10011001;
      break;
    case 5:  binary = B10010010;
      break;
    case 6:  binary = B10000010;
      break;
    case 7:  binary = B11111000;
      break;
    case 8:  binary = B10000000;
      break;
    case 9:  binary = B10011000;
      break;
  }

  return binary;
  
} 

void shiftToDisplay(int binary){

   digitalWrite(latchPin, LOW);
  // Send the value as a binary sequence to the module
  shiftOut(dataPin, clockPin, MSBFIRST, binary);
  // Enable the latch again to set the output states
  digitalWrite(latchPin, HIGH);
  
  }
