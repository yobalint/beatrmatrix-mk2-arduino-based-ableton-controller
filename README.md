# beatrmatrix mk2 Ableton controller
An open source Arduino based controller for Ableton Live.

# Functions
- 16 step sequencer with velocity control
- adding notes directly to Ableton's piano roll/sequencer
- modifying the loop length (start and end too)
- Ableton session view clip launching
- 3 mapable potentiometer to control anything Ableton
- visual feedback through smd RGB (ws2812b) LEDs, indicating MIDI notes, velocity, step position, loop length and clips in session view

# Communication
The beatrmatrix device is simply a controller for the Max patcher (serial communication). All the "magic" happens within the patcher. The max4live patcher uses the live API to communicate with Ableton Live.

![magic](https://github.com/beatrmatrix/beatrmatrix-mk2-arduino-based-ableton-controller/assets/155435444/d274d9e0-a9db-453c-94d9-ae97a6e90e6b)

# Parts

-Arduino Nano
-the PCB, with the smd soldered ws2812 LEDs
-19x 6x6x5mm tact push button 
-3 10k potentiometers 

 
# Getting started guide

## Connection
1. connect the device to your computer
2. open Ableton
3. drag and drop the max4live patcher to the **first track** (it has to be a midi track)
4. select the right serial port
5. load a drum kit or any instrument after the patcher

## Patcher UI
![ui](https://github.com/beatrmatrix/beatrmatrix-mk2-arduino-based-ableton-controller/assets/155435444/f2dfe761-f025-4703-b84b-ea0fc188b599)

### **MIDI NOTES:** 
You can choose which 8 MIDI notes you want to edit and display on the beatrmatrix device.
### **NOTE VELOCITY:** 
It's a display, but you can also change it from the UI too. For example, if it shows 127, and you place a new note, 
                   it will have a velocity of 127. If you change it, it will only be applied to the new notes you add.

### **SERIAL PORT:** 
Here you have to select the port to which the arduino is connected.

### **MAP CONTROLS:** 
You can map the 3 pots on the beatrmatrix to any Ableton parameter.
Pot "A" is mapped to note velocity by default, but you can change that too.

## Mode selection
There are 3 buttons on the top of the device labeled 'E', 'S' and 'P'. 
They are used to switch between the 3 modes: editing (sequencer), loop length, and clip launching. 
The switching is seamless; it doesn't pause audio or interrupt playback, so you can easily switch between modes during a live act too.

<img src= "https://github.com/beatrmatrix/beatrmatrix-mk2-arduino-based-ableton-controller/assets/155435444/fb8d0412-1bf6-4dd9-a1ff-0b286fec35d8" width="60%" height="60%" >

### Editing/Sequencer
- press button 'E'
- press a button from 1-8 to select the midi note you want to place (For example, if you have set the first note output to 36 in the UI, which triggers a kick drum,
                                                                       selecting the first note output with the first button allows you to place the kick in the sequence.)
- now you can place the midi notes to the Ableton sequencer by pressing the buttons 1-16
- if you want to place other notes you have to press 'E' again then select an other midi note
- before you place a note you can always change it's velocity (by default with the first pot)

### Loop length

- press button 'S'
- there is a yellow LED indicating whether you can modify the beginning or the end of the loop
- the blue leds are showing the loop length, and position
- to change the beginning or the end of the loop press a button from 1 to 16
![IMG_E2874](https://github.com/beatrmatrix/beatrmatrix-mk2-arduino-based-ableton-controller/assets/155435444/5198f308-770e-40fa-b138-5f2f3177bf39)

### Clip launching

- press button 'P'
- now you can launch clips which are in this 4x4 box shown in the picture
- track 1: buttons 1-4
- track 2: buttons 5-6
- track 3: buttons 9-12
- track 4: buttons 13-16
  
![clip launch grid](https://github.com/beatrmatrix/beatrmatrix-mk2-arduino-based-ableton-controller/assets/155435444/a2c619fc-f7ba-46bd-812e-644e9782bfec)


**led color meanings**

- **yellow:** the clip slot has a clip
- **green:** the clip is playing
- **green blinking:** the clip is triggered and it will be played

# If you'd rather not build it yourself, you can order it on Tindie

https://www.tindie.com/products/beatrmatrix/ableton-controller-mk2-beatrmatrix/

- Fully Assembled
- DIY Kit
- Just the PCB board


# Support the project

| Paypal |
| ---- |
| [<img src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" width="100%">](https://www.paypal.com/donate/?hosted_button_id=DY3BFYHC33TGG) |







