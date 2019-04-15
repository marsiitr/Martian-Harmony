// if the stepper has to move first we have to assure that all the keys are up otherwise we will be having mechanical error.
void up_keysR() {

  digitalWrite(solenoidPin6, LOW);
  digitalWrite(solenoidPin7, LOW);
  digitalWrite(solenoidPin8, LOW);
  digitalWrite(solenoidPin9, LOW);
  digitalWrite(solenoidPin10, LOW);
  prevFlag6 = 0;
  prevFlag7 = 0;
  prevFlag8 = 0;
  prevFlag9 = 0;
  prevFlag10 = 0;
  delay(50);
}
// for stepper to go in right position according to the note which has to be played.
void StepperpositionR(int &stepInitR, int stepFinalR)
{
  analogWrite(A0, 200); // Stepper R
  analogWrite(A1, 200);
  
  digitalWrite(A2, LOW); // Stepper R
  digitalWrite(A3, LOW);
  int x = stepFinalR;
  stepperR.step(stepPerKeyR * (stepInitR - x));
  analogWrite(A0, 0); // Stepper R
  analogWrite(A1, 0);
  digitalWrite(A3, LOW);
  digitalWrite(A2, LOW);
  stepInitR = x;

}

// now if previous flag was 0 and current is 1 , the has to be pressed .
// and if we have to press the same key again that is done too.
void newNoteR() {

  if (prevFlag6 == currFlag6 && currFlag6 == 1)        {
    digitalWrite(solenoidPin6, LOW);
    prevFlag6 = 0;
    delay(30);
  }

  if (prevFlag7 == currFlag7 && currFlag7 == 1)         {
    digitalWrite(solenoidPin7, LOW);
    prevFlag7 = 0;
    delay(30);
  }

  if (prevFlag8 == currFlag8 && currFlag8 == 1)         {
    digitalWrite(solenoidPin8, LOW);
    prevFlag8 = 0;
    delay(30);
  }

  if (prevFlag9 == currFlag9 && currFlag9 == 1)         {
    digitalWrite(solenoidPin9, LOW);
    prevFlag9 = 0;
    delay(30);
  }

  if (prevFlag10 == currFlag10 && currFlag10 == 1)       {
    digitalWrite(solenoidPin10, LOW);
    prevFlag10 = 0;
    delay(30);
  }



  if (prevFlag6 > currFlag6)          digitalWrite(solenoidPin6, LOW);
  else if (prevFlag6 < currFlag6)     digitalWrite(solenoidPin6, HIGH);
  if (prevFlag7 > currFlag7)          digitalWrite(solenoidPin7, LOW);
  else if (prevFlag7 < currFlag7)   digitalWrite(solenoidPin7, HIGH);
  if (prevFlag8 > currFlag8)      digitalWrite(solenoidPin8, LOW);
  else if (prevFlag8 < currFlag8)   digitalWrite(solenoidPin8, HIGH);
  if (prevFlag9 > currFlag9)          digitalWrite(solenoidPin9, LOW);
  else if (prevFlag9 < currFlag9)   digitalWrite(solenoidPin9, HIGH);
  if (prevFlag10 > currFlag10)        digitalWrite(solenoidPin10, LOW);
  else if (prevFlag10 < currFlag10)   digitalWrite(solenoidPin10, HIGH);



  prevFlag6 = currFlag6;
  prevFlag7 = currFlag7;
  prevFlag8 = currFlag8;
  prevFlag9 = currFlag9;
  prevFlag10 = currFlag10;
}
