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
  eegReading = analogRead(eegPin);
  //eegPWR = map(eegPWR,0,500,0,200);

 //Serial.println(eegPWR);
   //unsigned long currentMillis = millis();

 //brainWave(currentMillis);

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
  fadeInterval =   (1000/(waveFreq*2)) /(255/fadeIncrement);

  
  
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
    //analogWrite(breathLED, breathPWR);  
                //    pixAllSameColor(0, 0, breathPWR*.7);

 
    // reset millis for the next iteration (fade timer only)
    previousFadeMillis = thisMillis;
  }
}

//brainwave
void brainWave(unsigned long thisMillis) {

//convert frequency to period


 /// total length/ step size = number of steps to take       1000/freq = time for a period  (double freq since it's up and douwn)
 //interval  = time for a period  / number of steps to take   
  fadeInterval =   (1000/(waveFreq*2)) /(255/fadeIncrement);

  
  // is it time to update yet?
  // if not, nothing happens
  if (thisMillis - previousFadeMillis >= fadeInterval) {
    // yup, it's time!
    if (fadeDirection == UP) {
      eegPWR = eegPWR + fadeIncrement;  
      if (eegPWR >= maxPWM) {
        // At max, limit and change direction
        eegPWR = maxPWM;
        fadeDirection = DOWN;
      }
    } else {
      //if we aren't going up, we're going down
      eegPWR = eegPWR - fadeIncrement;
      if (eegPWR <= minPWM) {
        // At min, limit and change direction
        eegPWR = minPWM;
        fadeDirection = UP;
      }
    }
    // Only need to update when it changes
   // analogWrite(eegLED, eegPWR);  
                //   pixAllSameColor(0, 0, eegPWR*.7);

 
    // reset millis for the next iteration (fade timer only)
    previousFadeMillis = thisMillis;
  }
}





