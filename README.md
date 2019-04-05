# Martian-Harmony
Srishti 2019 <br/>
The idea was to build a robot that can play musical instruments in the same fashion as humans. It consists of various instruments like Flute, Keyboard, Guitar, etc. All these instruments are being played using different mechanisms.
![alt text](https://github.com/visvash/Martian-Harmony/blob/master/Images%20and%20Videos/Flute/flute%20setup.jpg "Flute playing bot")
<br/>
To read about the working of Flute Playing Bot, click [here.](https://github.com/visvash/Martian-Harmony/blob/master/Src/Flute/README.md "Martian-Harmony Flute Playing Bot")
<br/>
![alt text](https://github.com/visvash/Martian-Harmony/blob/master/Images%20and%20Videos/Piano/piano_setup.jpg "Piano playing bot")
<br/>
To read about working of Piano Playing Bot, click [here.](https://github.com/visvash/Martian-Harmony/blob/master/Src/Piano/README.md "Martian-Harmony Piano Playing Bot")
<br/>
## Motivation:
This is a really good combination of robotics and music. There are many people who don't know how to play instruments but appreciate good music, this band could help those people live their dreams. It could also be used for teaching puposes. It could even be used for fun purposes.
## Software Information Basics:
* For the mechanical model, designing of the complete setup is done on solidworks and some of the parts are 3D printed using Ultimaker 3D printer.
* We primarily needed to supply all the notes to the respective instruments and also the time at which they needed to be played. Initially we used Image processing to extract the notes using music sheet. The notes extraction was successful but we were not able to locate the time at which a note was to be played/stopped. So we dropped the idea of using a music sheet. 
* Then we used MIDI files which are basically digital music files and have the information of all the notes of different instruments and the time at which a particular note is to be played. To extract all this information from the MIDI file we used the java codes given in notes, ON/OFF and the time files.
* We did this for a few songs as only a good MIDI file was available for these much songs and for other songs either the MIDI was not available or a lot of noise was present in the MIDI file. Through MIDI files proper node times were given to the particular instruments.We have to code the instruments using arduino for those particular nodes.Check individual codes for this purpose.
## Cost structure:
### Flute:
|   Item used   | Quantity | Cost |
|---------------|----------|------|
| Stepper motor |  700 x1  | 700  |
|  Servo motor  |  120 x7  | 840  |
| Arduino Mega  |  885 x1  | 885  |
|BD786Transistor|    5 x1  |  5   |
|Vacuum Cleaner | 1650 x1  | 1650 |
|12V/5A Adapter |  400 x1  | 400  |
|   Heat Sink   |   50 x1  |  50  |
| Jumper Wires  |    3 x45 | 135  |
| Rack & Pinion |  280 x1  | 280  |
| Nuts-Bolts 4mm|  0.5 x100|  50  |
|    Screws     |  0.5 x20 |  10  |
|     Nails     | 0.25 x20 |   5  |
|  Rubber Pipe  |  200 x1  | 200  |
|    T-valve    |  200 x1  | 200  |
| Miscellaneous |   350    | 150  |
|     TOTAL PRICE (inr)   || 5860 |

### Piano:

|   Item used   | Quantity | Cost |
|---------------|----------|------|
|Solenoidal Motors| 534 x10| 5340 |
| Stepper Motor | 1345 x2  | 2690 |
| Wooden Board  |  300 x1  |  300 |
| Linear Rails  | 2750 X2  | 5500 |
| Linear Guides |  140 x4  |  560 |
| Nuts-Bolts 4mm|  0.5 x150|  75  |
| Rack & Pinion |  280 x2  |  560 |
|  Al Channels  |   50 x1  |  50  |
| Relay Switches|   20 x10 |  200 |
|   Heat Sink   |   50 x1  |  50  |
|12V/5A Adapter |  400 x1  | 400  |
| Arduino Mega  |  885 x1  | 885  |
| Jumper Wires  |    3 x150| 450  |
| Miscellaneous |   1500   | 1500 |
|     TOTAL PRICE (inr)   || 18560 |

## Team Members:
1. Aniket Kumar <br/>
2. Debaditya Barman <br/>
3. Nehal Tembhurne <br/>
4. Rishiraj Gupta <br/>
5. Shivansh Mathur <br/>
6. Shukshi Raj <br/>
7. Visvash Attri <br/>
## Team Mentors:
1. Abhimanyu Bhambaniya <br/>
2. Avdesh Ranwa <br/>
3. Pradhyuman Mathur <br/>
4. Pratikesh Thakur <br/>
5. Sarthak Gupta <br/>
