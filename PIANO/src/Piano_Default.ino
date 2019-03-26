#include<Stepper.h>
#define SIZE 200  // array size
#define STEPPOS 300// max steps
int stepInitR = 0; // stepper initial position .
int solenoidPin6 = 35, solenoidPin7 = 32  , solenoidPin8 = 31 ,   solenoidPin9 =  33 ,  solenoidPin10 = 34;
int stepPerKeyR = 54; //57 // As the Name specifys how many steps should be taken to reach the very next key.


//Data For Are re re ye kya hua song :P
char notePianoR[SIZE] = {'A', 'B', 'c', 'A', 'e', 'd', 'c', 'B', 'A', 'B', 'c', 'A', 'f', 'e', 'A', 'B', 'c', 'A', 'e', 'd', 'c', 'B', 'c', 'd', 'e', 'B', 'c', 'B', 'A', 'X'}; // Note array
int timePianoR[SIZE] = {5615, 5615, 5824, 6032, 6263, 6699, 7166, 7870, 8050, 9203, 9435, 9638, 9842, 10287, 10708, 12745, 12953, 13166, 13388, 13828, 14287, 14953, 15162, 16032, 16287, 16439, 16685, 16888, 17379, 17800, 18000}; // time array
//char notePianoR[SIZE]={'


int step_CR = 3, step_DR = 2, step_ER = 1, step_GR = -1, step_AR = 9, step_BR = 8, step_FR = 0, step_cmajor=0,step_bmajor=1, step_amojor=2; //int step_CR=0,step_DR=0,step_ER=2,step_FR=2,step_GR=2,step_AR=5,step_BR=5,stepC_mazor=00;
int step_cR = 10, step_dR = 9, step_eR = 10, step_fR = 9, step_gR = 6, step_aR = 12, step_bR = 11; //int step_cR=5,step_dR=5,step_eR=5,step_fR=6,step_gR=7,step_aR=9,step_bR=9;//int step_CR = 3, step_DR = 2, step_ER = 1, step_GR = -1, step_AR = 5, step_BR = 4, step_FR = 0, step_cmajor=0,step_bmajor=1, step_amojor=2; //int step_CR=0,step_DR=0,step_ER=2,step_FR=2,step_GR=2,step_AR=5,step_BR=5,stepC_mazor=00;
//int step_cR = 10, step_dR = 9, step_eR = 8, step_fR = 7, step_gR = 6, step_aR = 12, step_bR = 11; //int step_cR=5,step_dR=5,step_eR=5,step_fR=6,step_gR=7,step_aR=9,step_bR=9;


int Y = sizeof(notePianoR);
int iPianoR = 0;
// initializing steppers
Stepper stepperR(STEPPOS, 11, 7);
Stepper stepperL(STEPPOS, 9,10);
int prevFlag6 = 0, prevFlag7 = 0, prevFlag8 = 0, prevFlag9 = 0, prevFlag10 = 0;
int currFlag6 = 0, currFlag7 = 0, currFlag8 = 0, currFlag9 = 0, currFlag10 = 0;
//int iPiano=0;
int t1, t2;
//flag = 0  for open
//flag = 1 for close
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // 5 solenoid in one hand , connected as output pins.
  stepperR.setSpeed(80);// stepper speed is set to 100.

  pinMode(solenoidPin6, OUTPUT);
  pinMode(solenoidPin7, OUTPUT);
  pinMode(solenoidPin8, OUTPUT);
  pinMode(solenoidPin9, OUTPUT);
  pinMode(solenoidPin10, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3,OUTPUT);


  //digitalWrite(A0,HIGH);// Stepper R
  //digitalWrite(A1,HIGH);
}

void loop() {
  
  for(int i=0;i<Y;i++) {

  callPianoR();
    Serial.println(stepInitR);
   
  
   
   delay(timePianoR[iPianoR+1]-timePianoR[iPianoR]); // for how much time the key has to be pressed 
  Serial.println(timePianoR[iPianoR+1]-timePianoR[iPianoR]); 
      }
       
//AR_1();
//delay(1000);
//
//BR_1();
//while(1);
  //digitalWrite(A0,HIGH);// Stepper R
  //digitalWrite(A1,HIGH);
  //   int x=stepFinalR;
  // stepperR.step(stepPerKeyR*(stepInitR-x));

  //  digitalWrite(A0,HIGH);// Stepper R
  //  digitalWrite(A1,HIGH);
  //  stepperR.step(40);
  //    delay(300);
  //  digitalWrite(A0,LOW);// Stepper R
  //  digitalWrite(A1,LOW);
  //  digitalWrite(A0,HIGH);// Stepper R
  //  digitalWrite(A1,HIGH);
  //  stepperR.step(-40);
  //  delay(300);
  //  digitalWrite(A0,LOW);// Stepper R
  //  digitalWrite(A1,LOW);
}
/* callPianoR is a function which will check which note is to be pressed . and accordingly  note is called . At the end of notearray there is a note named 'X'
  which is made to bring the stepper to it's initial position after the execution of complete code.*/
void callPianoR()
{

  switch (notePianoR[iPianoR]) // FOR right hand
  {
    //  case '0' :      zero(); break;
    case 'A' :      AR_1(); break;
    case 'B' :      BR_1(); break;
    case 'C' :      CR_1(); break;
    case 'D' :      DR_1(); break;
    case 'E' :      ER_1(); break;
    case 'F' :      FR_1(); break;
    case 'G' :      GR_1(); break;
    case 'a' :      AR_2(); break;
    case 'b' :      BR_2(); break;
    case 'c' :      CR_2(); break;
    case 'd' :      DR_2(); break;
    case 'e' :      ER_2(); break;
    case 'f' :      FR_2(); break;
    case 'g' :      GR_2(); break;
    //case 'X' :      X_call(); break;

  }
  iPianoR++; // for next note.
}
