
void StringHandler() {
  Serial.print ("Input was: ");
  Serial.println(inputString);
  StringNum = inputString.toInt();

  //Next
  if (inputString == "+" || inputString == "") {
    Serial.print("Move to Next LED: ");

    currentpixel++;

    Serial.println(currentpixel);
    pixAllBlack();
    strip.setPixelColor(currentpixel, strip.Color(0, 0, 120));
      strip.show(); // This sends the updated pixel color to the hardware.
  }

  //Previous
  else if (inputString == "-") {
    Serial.print("Move to Previous LED: ");



    currentpixel--;
    Serial.println(currentpixel);
    pixAllBlack();
    strip.setPixelColor(currentpixel, strip.Color(0, 120, 0));
      strip.show(); // This sends the updated pixel color to the hardware.
  }
  else if (inputString == "b") {
    //all black
    pixAllBlack();
  }

  else if (inputString == "i") {
    //all inside
    pixOnlyInside();
  }
  else if (inputString == "o") {
    //all inside
    pixOnlyOutside();
  }
  else if (inputString == "allblue") {
    //all
    pixAllSameColor(0, 0, 150);
  }

  else if (inputString == "allgreen") {
    //all
    pixAllSameColor(0, 150, 0);
  }
  else if (inputString == "allred") {
    //all
    pixAllSameColor(150, 0, 0);
  }
  else if (inputString == "allpurple") {
    //all
    pixAllSameColor(150, 0, 150);
  }
  else if (inputString == "freakout") {
    //run freakout
    theaterChaseRainbow(5);

  }

  else if (inputString == "map") {
   areasoftheBrain();

  }
   else if (inputString == "maprand") {
   areasoftheBrainAnimated();

  }

  //Check numbers and gotoLED
  else {
    Serial.print("Inputted Num was: ");
    Serial.print(StringNum);

    if (StringNum > 0 && StringNum < MAXLED)
    {
      Serial.print("  Target LED turn on : ");
      Serial.println(StringNum);
      currentpixel = StringNum;

      pixAllBlack();
      strip.setPixelColor(currentpixel, strip.Color(0, 120, 0));
      strip.show(); // This sends the updated pixel color to the hardware.

    }

  }

//  strip.show(); // This sends the updated pixel color to the hardware.
//  strip2.show(); // This sends the updated pixel color to the hardware.

  //End loop
  //Clear the string
  inputString = "";

  stringComplete = false;
}







/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX.  This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response.  Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:

    if (inChar == '\n') {
      stringComplete = true;
    }
    else {
      // add it to the inputString:
      inputString += inChar;
    }

  }
}


