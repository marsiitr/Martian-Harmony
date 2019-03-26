# Martian-Harmony-4.0
The idea was to build a robot that can play musical instruments in the same fashion as humans. It consists of various instruments like Flute, Keyboard, Guitar, etc. All these instruments are being played using different mechanisms.
## Team Members:
1. Visvash Attri <br/>
2. Nehal Tembhurne <br/>
3. Debaditya Barman <br/>
4. Aniket Kumar <br/>
5. Shukshi Raj <br/>
6. Aniket Kumar <br/>
7. Shivansh Mathur <br/>
8. Rishiraj Gupta <br/>
## Team Mentors:
1. Pratikesh Thakur <br/>
2. Avdesh Ranwa <br/>
3. Sarthak Gupta <br/>
4. Abhimanyu Bambhaniya <br/>
5. Pradhyuman Mathur <br/>
## Software Information Basics:
For the mechanical model, designing of the complete setup is done on solidworks and some of the parts are 3D printed using Ultimaker 3D printer.
We primarily needed to supply all the notes to the respective instruments and also the time at which they needed to be played.Initially we used Image processing to extract the notes using music sheet. The notes extraction was successful but we were not able to locate the time at which a note was to be played/stopped. So we dropped the idea of using a music sheet .Then we used MIDI files which are basically digital music files and have the information of all the notes of different instruments and the time at which a particular note is to be played. To extract all this information from the MIDI file we used the java codes given in notes,ON/OFF and the time files. We did this for a few songs as only a good MIDI file was available for these much songs and for other songs either the MIDI was not available or a lot of noise was present in the MIDI file. Through MIDI files proper node times were given to the particular instruments.We have to code the instruments using arduino for those particular nodes.Check individual codes for this purpose.
## Inference:
This is a really good combination of robotics and music. There are many people who don't know how to play instruments but appreciate good music, this band could help those people live their dreams. It could also be used for teaching puposes. It could even be used for fun purposes.
