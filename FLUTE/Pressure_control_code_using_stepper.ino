void pressure(int &stepInit, int stepFinal){
  stepper.step((stepInit - stepFinal));  
  stepInit = stepFinal;
 }
void newNote(){
  for(int i=0;i<=30;i++)
  {
    if (prevFlag1>currFlag1) myservo1.write(posInit1+i);
      else if(prevFlag1<currFlag1) myservo1.write(posInit1-i);
    if (prevFlag2>currFlag2) myservo2.write(posInit2-i);
      else if(prevFlag2<currFlag2) myservo2.write(posInit2+i);
    if (prevFlag3>currFlag3) myservo3.write(posInit3-i);
      else if(prevFlag3<currFlag3) myservo3.write(posInit3+i);
    if (prevFlag4>currFlag4) myservo4.write(posInit4+i);
      else if(prevFlag4<currFlag4) myservo4.write(posInit4-i);
    if (prevFlag5>currFlag5) myservo5.write(posInit5-i);
      else if(prevFlag5<currFlag5) myservo5.write(posInit5+i);
    if (prevFlag6>currFlag6) myservo6.write(posInit6+i);
      else if(prevFlag6<currFlag6) myservo6.write(posInit6-i);  
      
        delay(5);
  }
  prevFlag1=currFlag1;
  prevFlag2=currFlag2;
  prevFlag3=currFlag3;
  prevFlag4=currFlag4;
  prevFlag5=currFlag5;
  prevFlag6=currFlag6;
}

