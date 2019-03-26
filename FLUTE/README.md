# Flute
Flute Playing Bot is a robot which replicates the mechanism by which a human being plays the flute. In this bot, the motion of the wooden sticks is equivalent to the motion of the fingers of human being and the pressure control which is done by the lungs in a human being while playing different chords with different frequencies is substituted by the vacuum cleaner and rack and pinion system combined.
## Pre-requisites
### Software:
1. FL-Studio:Basic knowledge of FL studio and midi file is required in order to get the information of chords and duration of playing of chords.
2. Arduino:Knowledge is required to verify working of different components as well as giving instructions for running the complete setup.
### Components used:
#### Mechanical:-
 1. 2 Wooden Boards- For setting the base for Flute and Rack and Pinion System.
 2. 1 Stand- To make a stand for Flute.
 3. 1 Rack and Pinion System- For controlling the air pressure of Vacuum Cleaner.
 4. 7 wooden sticks- They control the air from the holes of flute.
 5. 4 mm Screws
 6. Drill Machine with 4 mm Drill bit
 7. Hammer, Saw etc.
 8. A few small wooden pieces- For atttaching servo motors to the wooden block
 9. A few Nails
#### Electronics:-
 1. 7 Servo Motors (6V output)
 2. 1 Stepper Motor
 3. 1 Arduino MEGA 2560
 4. IC 786 Transistors- For converting 12V input into 6V output.
 5. Capacitors
 6. ULN 2003- For controlling Stepper Motor.
 7. 1 Vacuum Cleaner- For blowing air in the Flute System.
 8. 12 V/5A Adapter- For power supply.
 9. Heat Sink
 10. Male to Female Jumper wires - for wiring purposes.
## Importance of various components
#### 1. Servo Motors:
A servo motor is a rotary actuator or linear actuator that allows for precise control of angular or linear position, velocity and acceleration. It consists of a suitable motor coupled to a sensor for position feedback. In Flute, the servo motors are used to rotate the sticks in order to open and close the holes for different chords.
#### 2. Stepper Motor:
A stepper motor is a brushless electric DC motor that divides a full rotation into a number of equal steps. The motor's position can then be commanded to move and hold at one of these steps without any feedback sensor, as long as the motor is carefully sized to the application in respect to torque and speed. It is used to control the pressure of air coming from vacuum cleaner blown into the flute.
#### 3. Vacuum Cleaner:
It is used to blow the air into flute in controlled amount with the help of rack and pinion system and stepper motor.
#### 4. Arduino:
Arduino is an open source, computer hardware and software company, project, and user community that designs and manufactures single-board microcontrollers and microcontroller kits for building digital devices and interactive objects that can sense and control objects in the physical world.
## Design and Control
Servo motors and stepper motors are controlled using Arduino-MEGA 2560. The information of the different chords playing for different duration as well as which holes are to be opened to produce different chords or equivalently which servo motor is to be at which angle for particular duration is feed to Arduino.
The vacuum cleaner supplies air to the flute with the help of two pipes with one pipe going to flute and another going to rack and pinion system. The pressure control information is taken manually by varying the scale mounted on rack and pinion system and the length of the scale at different chords (the steps required by stepper motor to reach that length) is also programmed. 
The wooden sticks with thermocol are mounted on servo motor such that the hole is completely covered. When power is supplied, the arduino, with the help of the programmed code decides the position of servo motors as well as the stepper motor for different time intervals and produces the appropriate sound at appropriate time, thus playing the tone of a song with perfection. 
**Software related details can be found in Readme.md file in the parent folder.**
