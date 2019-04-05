#include <Servo.h>
#include <Stepper.h>
#define SIZE 200
#define OPEN 0
#define HALF 1
#define FULL 2

#define STEPSPR 150

Servo myservo1,myservo2,myservo3,myservo4,myservo5,myservo6,myservo7;  // create servo objects to control a servo. Twelve servo objects can be created on most boards

Stepper stepper(STEPSPR, A0,A1,A2,A3 );
int pos=0;
int posInit1=45,posInit2=45,posInit3=45,posInit4=45,posInit5=45,posInit6=45;   // variable to store the servo initial positions
int stepInit=0;                                         
boolean offFlag = false;
int stepC=19,stepC_High=37,stepD=12,stepD_High=9,stepE=5,stepE_High=28,stepF=10,stepF_High=8,stepG=14,stepG_sharp=0,stepA=17,stepA_High=23,stepB=24;//stepB=24,stepC=19
int Open1=30,Open2=0,Open3=0,Open4=30,Open5=0,Open6=30;
int Half1=40,Half2=40,Half3=40,Half4=40,Half5=40,Half6=40;
int Full1=0,Full2=30,Full3=30,Full4=0,Full5=30,Full6=0;
int prevFlag1=0,prevFlag2=0,prevFlag3=0,prevFlag4=0,prevFlag5=0,prevFlag6=0; 
int currFlag1=0,currFlag2=0,currFlag3=0,currFlag4=0,currFlag5=0,currFlag6=0;
int iFlute=0;

int t1,t2;
//flag = 0 for open
//flag = 1 for close
//Data for kal ho na ho
char noteFlute[SIZE]={'C','B','C','B','C','B','C','E','D','C','B','A','B','A','B','C','B','C','B','C','B','C','E','D','C','B','A','B','A','B','B','G','A','C','A','F','G','A','G','G','A','C','A','G','F','F','A','A','G'};
int timeFlute[SIZE]={0,642,857,1500,1714,2357,2571,2785,3000,3214,3428,4071,4285,4928,5142,6857,7500,7714,8357,8571,9214,9428,9643,9857,10071,10285,10928,11142,11785,12000,13714,14571,15000,15428,15642,18000,18428,18857,19072,21428,21857,22285,22500,24214,24428,24857,25285,25714,25928};
byte onOffFlute[SIZE]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

//Data for harry potter
//char noteFlute[SIZE]={'B','E','G','F','E','B','A','F','E','G','F','D','F','B','B','E','G','F','E','B','D','C','C','G','C','B','A','F','G','E','G','B','G','B','G','C','B','A','F','G','B','A','A','B','B','G','B','G','B','G','D','C','C','G','C','B','A','F','G','E'};
//int timeFlute[SIZE]={1500,1800,2250,2400,2700,3300,3600,4500,5400,5850,6000,6300,6900,7200,8700,9000,9450,9600,9900,10500,10800,11400,11700,12300,12600,13050,13200,13500,14100,14400,15900,16200,16800,17100,17700,18000,18600,18900,19500,19800,20250,20400,20700,21300,21600,23100,23400,24000,24300,24900,25200,25800,26100,26700,27000,27450,27600,27900,28500,28800};
//byte onOffFlute[SIZE]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

//data for baazigar
//char noteFlute[SIZE]={'D','D','C','D','A','D','D','D','C','D','A','D','D','C','D','A','D','D','D','C','D','A','D','D','C','D','A','D','D','D','C','D','A','D','D','C','D','A','D','D','D','C','D','A','D','D','C','D','A','D','D','D','C','D','A','D','D','C','D','A','D','D','D','C','D','A'};
//int timeFlute[SIZE]={1920,2640,2880,3120,3360,3840,4200,4560,4800,5040,5280,5760,6480,6720,6960,7200,7680,8040,8400,8640,8880,9120,9600,10320,10560,10800,11040,11520,11880,12240,12480,12720,12960,13440,14160,14400,14640,14880,15360,15720,16080,16320,16560,16800,17280,18000,18240,18480,18720,19200,19560,19920,20160,20400,20640,21120,21840,22080,22320,22560,23040,23400,23760,24000,24240,24480};
//byte onOffFlute[SIZE]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

//Data for ek ladki ko dekha
//char noteFlute[SIZE]={'G','C','C','B','C','D','B','C','D','B','C','D','B','C','C','D','B','C','D','B','B','C','D','D','B','C','D','B','C','C','C','C','B','C','C','G','B','A','B','C','C','B','G','B','A','B','C','C','B','G','B','A','A','A','A','G','G','E','F','A','G','G','G','G','F','F','E','F','A','G','G','G','A','A','F','A','C','A','G','G','G','G','G','B','C','E','D','D','D','B','B','G','B','C','E','D','C','D','D','B','C','D','B','C','D','B','C','E','B','C','C','G','B','C','D','C','G','B','C','D','C','G','C','C','C','G','A','E','F','A','G','G','B','C','D','C','G','B','C','D','C','G','C','C','C','G','A','E','F','A','G'};
//int timeFlute[SIZE]={0,8571,11125,11526,11964,12625,13241,13669,14334,14995,15370,16062,16250,16700,17120,21450,21861,22267,22964,23584,23959,24607,24674,25303,25620,25691,26370,26441,26973,27428,28316,28683,28928,29580,29843,30071,30285,30651,30879,31803,32089,32625,33017,33718,34080,34321,35227,35571,35959,36428,37098,37473,37709,38464,38575,38674,39392,39504,39852,40165,40513,40816,41107,41843,42004,42839,42892,43303,43665,43915,44303,44589,45410,45812,46120,46781,46973,47383,47785,47991,48687,48892,49285,50142,50464,50785,51174,51424,52330,52714,53165,53250,53589,53870,54241,54558,54857,60040,63049,63392,63468,64071,64660,65133,65816,66433,66830,67495,67696,68200,68647,70482,81000,81424,81803,81901,82285,84428,84852,85232,85330,85714,87857,88281,88583,88660,88758,89142,91285,91709,92089,92571,94714,95138,95517,95616,96000,98142,98566,98946,99044,99428,101571,101995,102271,102375,102473,102857,105000,105424,105803,106285};
//byte onOffFlute[SIZE]={0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1};

//Data for vande mataram
//char noteFlute[SIZE]={'C','D','F','G','F','G','F','G','B','C','B','C','C','C','D','A','B','A','G','G','G','A','F','E','D','D','D','D','D','G','F','E','D','E','D','C','C','C','D','F','G','F','G','G','G','B','A','A','A','G','F','G','B','C','B','C','F','G','B','B','B','B','B','B','B','C','B','C','B','C','B','B','B','B','B','C','B','C','B','C','D','C','B','A','B','A','A','A','G','D','D','D','F','F','F','E','D','D','D','D','D','A','B','A','G','A','G','F','G','B','B','B','B','B','B','B','B','B','C','B','C','F','G','B','C','B','C','F','G','B','C','B','C','G'};
//int timeFlute[SIZE]={0,666,1666,2000,2333,2666,5333,6000,7000,7333,7666,8000,10616,10666,11000,11340,11833,12333,12666,13283,13333,13666,14006,15000,15333,15950,16000,16283,16333,16666,17000,17333,18000,18333,18666,19000,21283,21333,22000,22333,22666,23000,23333,24283,24333,24666,25000,25283,25333,25666,26666,27333,28333,28666,29000,29333,32000,32666,33333,33950,34000,34616,34666,34950,35000,35333,35666,36000,37000,37333,38666,39283,39333,39616,39666,40000,40333,40666,41333,41666,42000,42333,42666,43000,43333,43666,43950,44000,44333,45333,45616,45666,46000,46283,46333,46666,47000,47950,48000,48283,48333,48666,49006,49333,49666,50333,50666,52000,52333,52666,53283,53333,53616,53666,53950,54000,54950,55000,55333,55666,56000,57333,58000,59000,59333,59666,60000,62666,63333,64333,64666,65000,65333,65500};
//byte onOffFlute[SIZE]={1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,O};

//Data For Are re re ye kya hua song :P
//char noteFlute[SIZE]={'A','B','C','A','E','D','C','B','A','B','C','A','F','E','A','B','C','A','E','D','C','B','C','D','E','B','C','B','A','G'};
//int timeFlute[SIZE]={5615,5824,6032,6263,6699,7166,7870,8050,9203,9435,9638,9842,10287,10708,12745,12953,13166,13388,13828,14287,14953,15162,16032,16287,16439,16685,16888,17379,17800,17900};
//byte onOffFlute[SIZE]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};

//Data for raghupati raghav
//char noteFlute[SIZE]={'D','D','D','G','G','G','G','F','G','A','G','F','E','F','A','A','A','C','B','C','A','A','A','G','A','G','F','E','F','A','G','G','G','B','B','B','B','B','A','G','A','C','C','C','B','C','A','A','A','C','C','C','D','D','D','C','A','A','G'};
//int timeFlute[SIZE]={72,190,552,796,1036,1194,1516,1996,2232,2472,2712,2956,3436,3916,4872,5570,5832,6316,6796,7276,7752,8236,9196,9672,10152,10392,10632,11116,11596,12552,13032,13226,13516,15432,16074,16396,17098,17356,18316,18796,19272,19756,19974,20232,20712,21196,23116,23350,23592,24076,24438,24556,25036,25996,26476,26956,27916,28392,28876};
//byte onOffFlute[SIZE]={1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1};

void setup() {
  Serial.begin(9600);
  myservo1.attach(8);
  myservo2.attach(9);
  myservo3.attach(7);
  myservo4.attach(6);
  myservo5.attach(5);
  myservo6.attach(12);
  myservo7.attach(11);
  stepper.setSpeed(200);
  myservo1.write(45);
  myservo2.write(45);
  myservo3.write(45);
  myservo4.write(45);
  myservo5.write(45);
  myservo6.write(45);
  myservo7.write(5);
  t1=millis();
  
}

void loop() 
{
  if(1){
    t1=millis();
    while(1){
      t2=millis();
      Serial.println(t1);
      Serial.println(t2);
      if (abs((t2-t1) - timeFlute[iFlute])<140) fluteCall(); 
      //if (abs((t2-t1) - timeFlute[iFlute])<=0) fluteCall(); 
      else if((t2-t1)>timeFlute[iFlute]) {
        //iFlute++;
        Serial.print("Timer Flute Overflow : ");
        Serial.println(t2-t1); 
      }
    }
  }
  else Serial.println("pinOff");
}

void C(){
pressure(stepInit,stepC);
  currFlag1 = 1;//close
  currFlag2 = 1;
  currFlag3 = 1;
  currFlag4 = 0;
  currFlag5 = 0;//open
  currFlag6 = 0;
  newNote();
  posInit1=45;
  posInit2=45;
  posInit3=45;
  posInit4=75;
  posInit5=15;
  posInit6=75;
}

void C_High(){
  pressure(stepInit,stepC_High);
  currFlag1 = 1;
  currFlag2 = 1;
  currFlag3 = 1;
  currFlag4 = 0;
  currFlag5 = 0;
  currFlag6 = 0;
  newNote();
  posInit1=3;
  posInit2=63;
  posInit3=63;
  posInit4=32;
  posInit5=32;
  posInit6=32;
}

void D(){
  pressure(stepInit,stepD);
  currFlag1 = 1;
  currFlag2 = 1;
  currFlag3 = 1;
  currFlag4 = 0;
  currFlag5 = 0;
  currFlag6 = 0;
  newNote();
  posInit1=45;
  posInit2=45;
  posInit3=45;
  posInit4=75;
  posInit5=15;
  posInit6=75;
}

void D_High(){
  pressure(stepInit,stepD_High);
  currFlag1 = 1;
  currFlag2 = 1;
  currFlag3 = 0;
  currFlag4 = 0;
  currFlag5 = 0;
  currFlag6 = 0;
  newNote();
  posInit1=3;
  posInit2=63;
  posInit3=39;
  posInit4=32;
  posInit5=32;
  posInit6=32;
}

void E(){
  pressure(stepInit,stepE);
  currFlag1 = 1;
  currFlag2 = 0;
  currFlag3 = 0;
  currFlag4 = 0;
  currFlag5 = 0;
  currFlag6 = 0;
  newNote();
  posInit1=45;
  posInit2=15;
  posInit3=15;
  posInit4=75;
  posInit5=15;
  posInit6=75;
}

void F_note(){
  pressure(stepInit,stepF);
  currFlag1 = 0;
  currFlag2 = 0;
  currFlag3 = 0;
  currFlag4 = 0;
  currFlag5 = 0;
  currFlag6 = 0;
  newNote();
  posInit1=75;
  posInit2=15;
  posInit3=15;
  posInit4=75;
  posInit5=15;
  posInit6=75;
}

void F_High(){
  pressure(stepInit,stepF_High);
  currFlag1 = 0;
  currFlag2 = 0;
  currFlag3 = 0;
  currFlag4 = 0;
  currFlag5 = 0;
  currFlag6 = 0;
  newNote();
  posInit1=32;
  posInit2=39;
  posInit3=39;
  posInit4=32;
  posInit5=32;
  posInit6=32;}

void G(){
  pressure(stepInit,stepG);
  currFlag1 = 1;
  currFlag2 = 1;
  currFlag3 = 1;
  currFlag4 = 0;
  currFlag5 = 0;
  currFlag6 = 0;
  newNote();
  posInit1=45;
  posInit2=45;
  posInit3=45;
  posInit4=75;
  posInit5=15;
  posInit6=75;}

void G_High(){
  pressure(stepInit,stepG_sharp);
  currFlag1 = 1;
  currFlag2 = 1;
  currFlag3 = 1;
  currFlag4 = 1;
  currFlag5 = 1;
  currFlag6 = 1;
  newNote();
  posInit1=3;
  posInit2=63;
  posInit3=63;
  posInit4=3;
  posInit5=3;
  posInit6=3;}

void A(){
  pressure(stepInit,stepA);
  currFlag1 = 0;
  currFlag2 = 1;
  currFlag3 = 0;
  currFlag4 = 0;
  currFlag5 = 0;
  currFlag6 = 0;
  newNote();
  posInit1=75;
  posInit2=45;
  posInit3=15;
  posInit4=75;
  posInit5=15;
  posInit6=75;
}

void A_High(){
  pressure(stepInit,stepA_High);
 
  currFlag1 = 1;
  currFlag2 = 1;
  currFlag3 = 1;
  currFlag4 = 1;
  currFlag5 = 1;
  currFlag6 = 0;
  newNote();
  posInit1=3;
  posInit2=63;
  posInit3=63;
  posInit4=3;
  posInit5=3;
  posInit6=32;
}

void B(){
  pressure(stepInit,stepB);
  currFlag1 = 1;
  currFlag2 = 1;
  currFlag3 = 1;
  currFlag4 = 1;
  currFlag5 = 1;
  currFlag6 = 1;
  newNote();
  posInit1=45;
  posInit2=45;
  posInit3=45;
  posInit4=45;
  posInit5=45;
  posInit6=45;
}


void fluteCall(){
  Serial.print("Timer : ");
  Serial.print(t2-t1);
  Serial.print(" Flute : ");
  Serial.print(timeFlute[iFlute]);
  Serial.print("  "); //Serial.println(noteFlute[iFlute]);
  //Serial.print(flute);
  //Serial.print("  ");  
  if(onOffFlute[iFlute]==0) {
        if(offFlag==false){
              for (pos = 5; pos <=35 ; pos += 1) 
              { 
                myservo7.write(pos);
                delay(10);
                offFlag = true;
              }
            }
            Serial.println(noteFlute[iFlute]);
    iFlute++;
  }
  else if(onOffFlute[iFlute]==1){
      switch(noteFlute[iFlute]){
      case 'A':
            if(offFlag==true){
              for (pos = 35; pos >=5 ; pos -= 1) 
              { 
                myservo7.write(pos);
                delay(10);
              }
              offFlag = false;
            }
            Serial.println(noteFlute[iFlute]);
            A();
            break;
      case 'B':
            if(offFlag==true){
              for (pos = 35; pos >=5 ; pos -= 1) 
              { 
                myservo7.write(pos);
                delay(10);
              }
              offFlag = false;
            }
            Serial.println(noteFlute[iFlute]);
            B();
        break;
      case 'C':
            if(offFlag==true){
              for (pos = 35; pos >=5 ; pos -= 1) 
              { 
                myservo7.write(pos);
                delay(10);
              }
              offFlag = false;
            }
            Serial.println(noteFlute[iFlute]);
            C();
        break;
     case 'D':
            if(offFlag==true){
              for (pos = 35; pos >=5 ; pos -= 1) 
              { 
                myservo7.write(pos);
                delay(10);
              }
              offFlag = false;
            }
            Serial.println(noteFlute[iFlute]);
            D();
            break;
     case 'E':
            if(offFlag==true){
              for (pos = 35; pos >=5 ; pos -= 1) 
              { 
                myservo7.write(pos);
                delay(10);
              }
              offFlag = false;
            }
            Serial.println(noteFlute[iFlute]);
            E();
        break;
     case 'F':
            if(offFlag==true){
              for (pos = 35; pos >=5 ; pos -= 1) 
              { 
                myservo7.write(pos);
                delay(10);
              }
              offFlag = false;
            }
            Serial.println(noteFlute[iFlute]);
            F_note();
        break;
     case 'G':
            if(offFlag==true){
              for (pos = 30; pos >=0 ; pos -= 1) 
              { 
                myservo7.write(pos);
                delay(10);
              }
              offFlag = false;
            }
            Serial.println(noteFlute[iFlute]);
            G();
        break;
      default:
             if(offFlag==false){
            for (pos = 5; pos <=35 ; pos += 1) 
            { 
              myservo7.write(pos);
              delay(10);
              offFlag = true;
            }
         }
    }
    iFlute++;
  }
  return;
}
void pressure(int &stepInit, int stepFinal)
{
  stepper.step(stepInit - stepFinal);  
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
