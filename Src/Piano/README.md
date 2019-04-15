# Piano
Piano Playing Bot is a robot which replicates the mechanism by which a human being plays piano. In this bot 3D printed hand like structures are used to replicate the motion of human fingers over the keys of piano.Solenoid valves are used for the movement of fingers where as Stepper motors are used for motion of hand.
## Pre-requisites
### Softwares:
1. FL-Studio: Basic knowledge of FL studio and midi file is required in order to get the information of chords and duration of playing of chords.
2. Arduino: Knowledge is required to verify working of different components as well as giving instructions for running the complete setup.
### Components used:
#### Mechanical:-
 1. 1 Wooden Boards- For setting the base for Piano System.
 2. 10 Finger like 3D Printed Structures (They should contain a 4.5 mm hole at the center of them)
 3. 2 3D Printed U- shaped mounts (serves as fulcrum for see-saw mechanism of fingers)
 4. 2 15 cm threaded steel rods of diameter 4 mm each.
 5. 2 Linear Rails and 4 Linear Guides (For linear motion of hand)
 6. 2 12X12 cm Wooden Bases (for base of the hand)
 7. 4 mm nuts and bolts
 8. Drill Machine with 4 mm Drill bit
 9. Hammer, Saw, Electrical Tape, Pliers, Nails, Glue Gun, Double Side Tape etc. 
 10. 2 pairs of Rack and Pinion (atleast 15 inches long rack)
 11. Aluminium Channels (Square and L)
#### Electronics:-
 1. 2 Stepper Motors (10 KG Torque preferred).
 2. 1 Arduino MEGA 2560
 3. 10 Solenoid Valves(12 V DC each) .
 4. 2 Motor Drivers (For running Stepper Motors)
 5. 10 Relay Switches. (For ON and OFF control of Solenoids).
 6. Heat Sink
 7. ULN 2003-For controlling the voltages in Relay Switches.
 8. 12V/5A Adapter- For power supply.
 9. Breadboards and plenty of jumpers.(Male to Male, Male to Female, Female to Female)
 10. Digital Multi Meter
 11. Switches
## Importance of various components
#### 1. Stepper Motor:
A stepper motor is a brushless electric DC motor that divides a full rotation into a number of equal steps. The motor's position can then be commanded to move and hold at one of these steps without any feedback sensor, as long as the motor is carefully sized to the application in respect to torque and speed. It is used to control the pressure of air coming from vacuum cleaner blown into the flute.
#### 2. Arduino: 
Arduino is an open source, computer hardware and software company, project, and user community that designs and manufactures single-board micro-controllers and micro-controller kits for building digital devices and interactive objects that can sense and control objects in the physical world.
#### 3. Solenoid Valves: 
A solenoid valve is an electro-mechanical controlled valve. The valve features a solenoid, which is an electric coil with a movable ferromagnetic core in its center. This core is called the plunger. In rest position, the plunger closes off a small orifice. An electric current through the coil creates a magnetic field. The magnetic field exerts a force on the plunger. As a result, the plunger is pulled toward the center of the coil so that the orifice opens. This is the basic principle that is used to open and close solenoid valves.
#### 4. Relay Switches: 
Relays are switches that open and close circuits electro-mechanically or electronically. Relays control one electrical circuit by opening and closing contacts in another circuit. As relay diagrams show, when a relay contact is normally open (NO), there is an open contact when the relay is not energized. When a relay contact is Normally Closed (NC), there is a closed contact when the relay is not energized. In either case, applying electrical current to the contacts will change their state.
#### 5. Motor Drivers: 
A motor driver is a little current amplifier; the function of motor drivers is to take a low-current control signal and then turn it into a higher-current signal that can drive a motor.
## Design and Control
* First of all mount keyboard on the big wooden board, so that it does not get displaced from its position. Take the measurements of keys and wooden base (mount the U-shaped stand perpendicular to its surface along its one edge) such that it can cover 5 consecutive keys.
* Mount the fingers of the hand as WBWBW where W stands for shorter finger for white keys and B stands for longer finger for black keys. Mounting is done with the help of threaded rod that mates through holes in the clamp, 5 fingers and optimum number of nuts. 
* Now place all keys at an appropriate distance from each other, such that they cover one key each (You can use Tape to create distance or something which doesn't allow them to move from their place, but make sure they are free to rotate). Fix this entire structure on a linear rails fixed parallel on wooden board with the help of linear guides such that it is able to slide along the rails. 
* Stick all the solenoids on the back of the hand base exactly under the fingered structures (with the help of aluminium channels) such that when current is passed through them, they push the fingers and the key is pressed (See-saw mechanism). Attach the pinions to the shafts of Stepper Motors. 
* Attach the rack to the movable part of hands. Mount each stepper on either side of the keyboard and mount the slider using wooden blocks such that the rack and pinion work smoothly and all the keys are pressed properly.
* Make the circuits using relays and ULN such that each relay controls a solenoid. Connect all solenoids to relay so that relay work as a switch.Use motor drivers to drive the steppers.Male all connections to Arduino Mega. Power the circuits using 12V/5A adapters. Upload the files to Arduino and you are ready to rock.
