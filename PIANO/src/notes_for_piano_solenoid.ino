// Right hand

// X_call to bring stepper back is its initial position .
void X_call() {

  up_keysR();
  analogWrite(A0, 200); // Stepper R
  analogWrite(A1, 200);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  stepperR.step(stepPerKeyR * (stepInitR - 0));
  analogWrite(A0, 0); // Stepper R
  analogWrite(A1, 0);
  digitalWrite(A2,LOW);
  digitalWrite(A3, LOW);

}
/* Now for each key a solenoid has to be pressed according to the position of stepper . Whichever key has to be pressed is given 1 as current flag.
  In each call ,first stepper position is checked if it is not in position then StepperpositionR is called and the stepper is being sent to it's required position .
  Then newNoteR is called to press that particular key .
*/
void CR_1() {

  if (stepInitR != step_CR) {
    up_keysR();
    StepperpositionR(stepInitR, step_CR);
  }

  currFlag6 = 1;
  currFlag7 = 0;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 0;

  newNoteR();

}
void DR_1() {

  if (stepInitR != step_DR) {
    up_keysR();
    StepperpositionR(stepInitR, step_DR);
  }

  currFlag6 = 0;
  currFlag7 = 1;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 0;

  newNoteR();

}
void ER_1() {

  if (stepInitR != step_ER) {
    up_keysR();
    StepperpositionR(stepInitR, step_ER);
  }



  currFlag6 = 1;
  currFlag7 = 0;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 0;

  newNoteR();

}
void FR_1() {

  if (stepInitR != step_FR) {
    up_keysR();
    StepperpositionR(stepInitR, step_FR);
  }


  currFlag6 = 0;
  currFlag7 = 1;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 0;

  newNoteR();

}
void GR_1() {

  if (stepInitR != step_GR) {
    up_keysR();
    StepperpositionR(stepInitR, step_GR);
  }

  currFlag6 = 0;
  currFlag7 = 0;
  currFlag8 = 1;
  currFlag9 = 0;
  currFlag10 = 0;

  newNoteR();

}
void AR_1() {

  if (stepInitR != step_AR) {
    up_keysR();
    StepperpositionR(stepInitR, step_AR);
  }
  currFlag6 = 1;
  currFlag7 = 0;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 0;

  newNoteR();

}
void BR_1() {

  if (stepInitR != step_BR) {
    up_keysR();
    StepperpositionR(stepInitR, step_BR);
  }

  currFlag6 = 1;
  currFlag7 = 0;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 0;

  newNoteR();

}

void CR_2() {

  if (stepInitR != step_cR) {
    up_keysR();
    StepperpositionR(stepInitR, step_cR);
  }

  currFlag6 = 0;
  currFlag7 = 0;
  currFlag8 = 1;
  currFlag9 = 0;
  currFlag10 = 0;
  newNoteR();

}
void DR_2() {

  if (stepInitR != step_dR) {
    up_keysR();
    StepperpositionR(stepInitR, step_dR);
  }

  currFlag6 = 0;
  currFlag7 = 0;
  currFlag8 = 1;
  currFlag9 = 0;
  currFlag10 = 0;
  newNoteR();

}
void ER_2() {
  if (stepInitR == step_fR) {
    currFlag6 = 0;
    currFlag7 = 0;
    currFlag8 = 0;
    currFlag9 = 0;
    currFlag10 = 1;
  }
  else {
    if (stepInitR != step_eR) {
      up_keysR();
      StepperpositionR(stepInitR, step_eR);
    }

    currFlag6 = 0;
    currFlag7 = 0;
    currFlag8 = 0;
    currFlag9 = 0;
    currFlag10 = 1;
  }
  newNoteR();

}

void FR_2() {

  if (stepInitR != step_fR) {
    up_keysR();
    StepperpositionR(stepInitR, step_fR);
  }


  currFlag6 = 0;
  currFlag7 = 0;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 1;
  newNoteR();

}
void GR_2() {

  if (stepInitR != step_gR) {
    up_keysR();
    StepperpositionR(stepInitR, step_gR);
  }

  currFlag6 = 0;
  currFlag7 = 0;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 1;
  newNoteR();

}
void AR_2() {

  if (stepInitR != step_aR) {
    up_keysR();
    StepperpositionR(stepInitR, step_aR);
  }

  currFlag6 = 0;
  currFlag7 = 0;
  currFlag8 = 0;
  currFlag9 = 1;
  currFlag10 = 0;
  newNoteR();

}
void BR_2() {

  if (stepInitR != step_bR) {
    up_keysR();
    StepperpositionR(stepInitR, step_bR);
  }


  currFlag6 = 0;
  currFlag7 = 0;
  currFlag8 = 0;
  currFlag9 = 0;
  currFlag10 = 1;
  newNoteR();

}
