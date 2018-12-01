# Spooky Ball Robot <v.0.1.0>

<br>


Repository Contents
==========
* **/README.md** - The main index that you read!
* **/Image** - This is where the image files for this readme file!

Plan with mad thoughts
==========
We are thinking of a round shape robot which can move around by using the same theory as tumbler.
- A bearing in middle for motors to control movement.
There should be a cap on the top which can be lift up by dc motors.
After the cap is risen, two spooky eyes show up. (LCD creen X2).
There should be a speaker for making sounds.
There should be a remote control to control the action of the robot.
<br>

Requirements and Materials
==========
What kind of software and hardware you needed:

Software:
* Circuit Python: https://learn.adafruit.com/welcome-to-circuitpython/what-is-circuitpython

Hardware:
Considerable items to use: 
* a) Circuit Playground Express https://www.adafruit.com/product/3333
* b) Small Alligator Clip Test Lead: https://www.adafruit.com/product/1008
* c) 3 x aaa battery holder with on/off(change it! the suggesting from teacher) : https://www.adafruit.com/product/727
* d) DC motor + stepper featherwing: https://www.adafruit.com/product/2927
* e) Conves glass lens with edge: https://www.adafruit.com/product/3853
    <br>  OLED breakout board: https://www.adafruit.com/product/1431
    <br>  Jumper wire: https://www.adafruit.com/product/793
    <br>  Raspberry Pi accessory: https://www.adafruit.com/product/3356
* f) mini metal speaker: https://www.adafruit.com/product/1890
* g) mini remote control: https://www.adafruit.com/product/389
    <br>  IR (Infrared) Receiver Sensor: https://www.adafruit.com/product/157
  <br>
 
 Already baught materials:
 ===========
 * 1x 1/4oz,0.25oz,Black,Adhesive Stick on Wheel Weights,GM, Ford,Chrysler, Low Profile,Wheel Balance Weights, 60 oz/box, 1.7 kg/box, 3.75   lb/box: https://www.amazon.ca/dp/B06XDG1JJH/ref=pe_3034960_233709270_TE_item 
 * 1x 12 Inch White Acrylic with 5.25 Inch Neckless Opening: https://www.amazon.com/gp/product/B002OM9UM6/ref=od_aui_detailpages00?ie=UTF8&psc=1
 * 2x 1,621 RPM HD Premium Planetary Gear Motor: https://www.servocity.com/1621-rpm-hd-premium-planetary-gear-motor
 * 2x Set Screw Shaft Couplers: https://www.servocity.com/set-screw-shaft-couplers
 * 2x 0.250" (1/4") x 3.00" Stainless Steel D-Shafting: https://www.servocity.com/0-250-1-4-stainless-steel-d-shafting
 * 2x 0.250" (1/4") x 2.75" (2-3/4") Stainless Steel D-Shafting: https://www.servocity.com/0-250-1-4-stainless-steel-d-shafting
 * 2x 0.250" (1/4") x 4.00" Stainless Steel D-Shafting: https://www.servocity.com/0-250-1-4-stainless-steel-d-shafting
 * 2x Aluminum Motor Mount E: https://www.servocity.com/aluminum-motor-mount-e
 * 2x 4.50” Aluminum Channel: https://www.servocity.com/4-50-channel
 * 2x 3.75” Aluminum Channel: https://www.servocity.com/3-75-channel
 * 4x 1/4" Bore Side Tapped Pillow Block: https://www.servocity.com/250-bore-quad-pillow-block
 * 1x 90° Dual Side Mount A (2 pack): https://www.servocity.com/90-dual-side-mount
 * 1x Assembled Actobotics® Dual Motor Controller: https://www.servocity.com/actoboticsr-dual-motor-controller-assembled
 * 1x Matrix 12V 3000mAh NiMH Battery: https://www.servocity.com/matrix-12v-3000mah-nimh-battery
 * 2x D485HW Servo Direction:Clockwise (stock) Rotation:Stock Rotation: https://www.servocity.com/d485hw-servo
 * 4x 2.31" (7 hole) Aluminum Beams (2 pack): https://www.servocity.com/2-31-aluminum-beams
 * 1x Actobotics® Hardware Pack A: https://www.servocity.com/actobotics-hardware-pack-a
 * 2x 0.250" (1/4") x 1.00" Stainless Steel D-Shafting: https://www.servocity.com/0-250-1-4-stainless-steel-d-shafting
 * 2x Pattern Bracket C: https://www.servocity.com/channel-bracket-c
 * 4x Raised Perpendicular X-Rail Mount: https://www.servocity.com/raised-perpendicular-x-rail-mount
 * 1x DFRobot IR Remote Kit for Arduino: https://www.robotshop.com/ca/en/dfrobot-ir-remote-kit-arduino.html
 * 1x 400 Tie Point Interlocking Solderless Breadboard: https://www.robotshop.com/ca/en/400-tie-point-solderless-interlocking-breadboard.html
 * 1x Alligator Clip with Pigtail (10pk): https://www.robotshop.com/ca/en/alligator-clip-with-pigtail-10pk.html
 
 Usable Source
 ===========
- robot recerch link :https://www.instructables.com/id/DIY-Sphere-Robot/   
<br>

Milestones
========
The project will following this time table!

| Milestone   | Date | Information |
|-----------|---------|-------------|
| Milestone 1  | October 20,2018 | All part arrive |
| Milestone 2  | October 30,2018 | Initial assembly |
| Milestone 3  | December 15,2018 | Working in Conveyor |
| Milestone 4  | December 20,2018 | Led system and waring sound system work together |
| Milestone 5  | November 1th,1018 | Remote sensing system online |

<br>

Construction steps
===========

Step one to connect the receiver board and Arduino and put a led to test the board was work or not.

![alt text][pic1]

[pic1]: https://github.com/catssister/Spooky-Ball-Robot/blob/master/Image/Receiver%20board%20test.jpeg "Connect Receiver"

Step two is to complate the motor connection with motion.(We just put on the charger to make sure both of the motor was working, when we saw it working we just take out the charger)

![alt text][pic2]

[pic2]: https://github.com/catssister/Spooky-Ball-Robot/blob/master/Image/Motor.jpeg "Connect motion and two motors"


<br>

Build Instructions
===========
The frame was blocked inside the ball, and the power wheel motor was on the frame. The pulley and surface are connected,gear rotation drivers pulley rolling to let the ball move. On the top of the ball have two LED display. That screen connects to the image processing chip. The video card was put on the side of the frame and block out. In the robot also have a speaker, that speaker was connect to the soundboard. The soundboard was on the frame also. In the middle of the frame have a gravity arm, at the bottom of it have a small metal and a few magnetic susceptibilities of weights.

<br>

Usage
===========

* Step one : Open the power supply cover.

* Step two : Connect the line between Arduino to sound board.
* Step three : Connect the line between Arduino to graphic board.
* Step four : Connect the line between Arduino to signal and information processing board.
* Step five : Connect the line between Arduino to motion board.

* Step six : Upload codes for controlling picture processing.
* Step seven : Upload codes for controlling information processing.
* Step eight : Upload codes for controlling sound.
* Step nine : Upload codes for controlling motion command.
* Step ten : Make sure all the lines are connect at the right place.
* Step Eleven : Close the lid.
* Step twelve : Use remote contral to test each part of function does robot have.

Just play~ Don't forgot to charger the battery!

<br>


Team
===========
The build team consists of:
* @Bennrox Student: Liyi Zhu
* @catssister  Student:  Yunting Shao
<br>

Instructor
===========
Trevor Michael Tomesh ??
