//Paint the Brain Pixels
//Go through  all the calculations and assign all the colors to the LEDs
void paintBrain (){
  

    //Demo
    //            pixAllSameColor(heartPWR, 0, breathPWR);
    areasoftheBrainAnimated();

}






//Measured Senses

void heartBeat(){
  heartPWRreading = analogRead(heartPin);

//adding some nice ramping to the pulse beats
if(heartPWRreading> 20){
  heartPWR = heartPWR+50;
 heartPWR =  constrain(heartPWR , 0 , 200);
}
else{
  heartPWR = heartPWR-20;
  heartPWR =   constrain(heartPWR , 0 , 200);

}
//Serial.println(heartPWR);

//heartPWR = map(analogRead(heartPin),0,1023,0,200);

}

void auditory(){
  
}

void eegBASIC(){
  eegPWR = analogRead(eegPin);
  //eegPWR = map(eegPWR,0,500,0,200);

 Serial.println(eegPWR);

}



//Simulated Senses
void heartBeatS(float tempo){
    if ((millis() - prevMillis) > (long)(heartBeatArray[hbeatIndex] * tempo)){
        hbeatIndex++;
        if (hbeatIndex > 3) hbeatIndex = 0;

        if ((hbeatIndex % 2) == 0){     // modulo 2 operator will be true on even counts
            digitalWrite(LEDpin, HIGH);
               // pixAllSameColor(180, 0, 0);
                heartPWR= 200;
        }
        else{ 
            digitalWrite(LEDpin, LOW); 
        heartPWR = 0;

        }
        //  Serial.println(hbeatIndex);
        prevMillis = millis();
    }
}
void stopHeatbeat(){
    digitalWrite(LEDpin, LOW); 
}




void breathFade(unsigned long thisMillis) {
  // is it time to update yet?
  // if not, nothing happens
  if (thisMillis - previousFadeMillis >= fadeInterval) {
    // yup, it's time!
    if (fadeDirection == UP) {
      breathPWR = breathPWR + fadeIncrement;  
      if (breathPWR >= maxPWM) {
        // At max, limit and change direction
        breathPWR = maxPWM;
        fadeDirection = DOWN;
      }
    } else {
      //if we aren't going up, we're going down
      breathPWR = breathPWR - fadeIncrement;
      if (breathPWR <= minPWM) {
        // At min, limit and change direction
        breathPWR = minPWM;
        fadeDirection = UP;
      }
    }
    // Only need to update when it changes
    analogWrite(breathLED, breathPWR);  
                   // pixAllSameColor(0, 0, breathPWR*.7);

 
    // reset millis for the next iteration (fade timer only)
    previousFadeMillis = thisMillis;
  }
}





