/*By: Liyi Zhu Project: cs207 project
//NORMAL -256
//VOL+ -511
//VOL- -2551
//LEFT -1276
//RIGHT -1786
//PLAY -1531
//1 -4336
//2 -4591
//3 -4846
//4 -5356
//5 -5611
//6 -5866
//7 -6376
//8 -6631
//9 -6886
//SOURCE https://www.dfrobot.com/wiki/index.php/IR_Remote_Control_Lesson#Code_Sample
  SOURCE https://gist.github.com/StevenNunez/6786124
*/

#define in1 7
#define in2 6
#define speakerPin  10                        //Connect Buzzer to Digital Pin 10
#define LED_RED 11                        //Connect a Red LED to Digital Pin 11
#define IR_IN   8                         //Connect the Infrared receiver to Digital Pin 8

int length = 70; // the number of notes
String notes[] = {"G4","G4", "G4", "D#4/Eb4", "A#4/Bb4", "G4", "D#4/Eb4","A#4/Bb4", "G4", "D5", "D5", "D5", "D#5/Eb5", "A#4/Bb4", "F#4/Gb4", "D#4/Eb4","A#4/Bb4", "G4", "G5","G4","G4","G5","F#5/Gb5", "F5","E5","D#5/Eb5","E5", "rest", "G4", "rest","C#5/Db5","C5","B4","A#4/Bb4","A4","A#4/Bb4", "rest", "D#4/Eb4", "rest", "F#4/Gb4", "D#4/Eb4","A#4/Bb4", "G4" ,"D#4/Eb4","A#4/Bb4", "G4"}; // a space represents a rest
int beats[] = { 8, 8, 8, 6, 2, 8, 6 , 2 ,16 , 8, 8, 8, 6, 2, 8, 6, 2, 16,8,6,2,8,6,2,2, 2, 2,6,2,2,8,6,2,2,2,2,6,2,2,9,6,2,8,6,2,16  };
int tempo = 50;

int Pulse_Width=0;                       //Pulse width
int  ir_code=0x00;                       //IR command code

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    digitalWrite(LED_RED,HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    digitalWrite(LED_RED,LOW);
    delayMicroseconds(tone);
  }
}

void playNote(String note, int duration) {
  String names[] = { "D#4/Eb4", "E4", "F4", "F#4/Gb4", "G4", "G#4/Ab4", "A4", "A#4/Bb4", "B4", "C5", "C#5/Db5", "D5", "D#5/Eb5", "E5", "F5", "F#5/Gb5", "G5", "G#5/Ab5", "A5", "A#5/Bb5", "B5", "C6", "C#6/Db6", "D6", "D#6/Eb6", "E6", "F6", "F#6/Gb6", "G6" };
  int tones[] = { 1607, 1516, 1431, 1351, 1275, 1203, 1136, 1072, 1012, 955, 901, 851, 803, 758, 715, 675, 637, 601, 568, 536, 506, 477, 450, 425, 401, 379, 357, 337, 318 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 29; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void timer1_init(void){                  //Initilize timer
    TCCR1A = 0X00; 
    TCCR1B = 0X05; 
    TCCR1C = 0X00;
    TCNT1  = 0X00;
    TIMSK1 = 0X00;  
}

void remote_deal(void){                         //Get IR command
  Serial.print("I just read: "); //Print some text
  Serial.println(ir_code);     //Print pot_value and go to next line
    switch(ir_code){
    case 0xff00:                                //Press stop button on the remote controller
        digitalWrite(LED_RED,LOW);              //Turn off red led
        digitalWrite(speakerPin,LOW);               //Silence the buzzer
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        break;
    case -511:                                //Press VOL+ button
        digitalWrite(LED_RED,HIGH);             //Turn off Red LED
        break;
    case -1531:
    {
        for (int i = 0; i < 46; i++) {
        if (notes[i] == "rest") 
        {
        delay(beats[i] * tempo); // rest
        } 
        else 
        {
        playNote(notes[i], beats[i] * tempo);
        Serial.print(i); //Print some text
        delay(100);
        }
    
        // pause between notes
        delay(tempo / 2); 
        }
    }
    case -4591:
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(in1, 250);
      analogWrite(in2, 250);
    }
}
}

char logic_value(){                                         // The function determine the logic value "1" and "0".
    while(!(digitalRead(8)));                               //Wait low 
    Pulse_Width = TCNT1;
    TCNT1 = 0;
    if( Pulse_Width >= 7 && Pulse_Width <= 10 ){               //low level 560us
        while(digitalRead(8));                                //Value is high, then wait.
        Pulse_Width = TCNT1;
        TCNT1=0;
        if( Pulse_Width >= 7 && Pulse_Width <= 10 )            //High level 560us
             return 0;
        else if( Pulse_Width >= 25 && Pulse_Width <= 27 )      //High level 1.7ms
             return 1;
    }
    return -1;
}

void pulse_deal()  {                                 //Receive address code and command code pulse function
    int i;   
    // Run 8 zeros
    for(i=0; i<8; i++) {
      if( logic_value() != 0 )                       //If it isn't 0.
          return; 
    }
    // Run 6 ones
    for(i=0; i<6; i++) {
      if(logic_value()!= 1)                        //If it isn't 1.
          return;
    }
    // Run 1 zero
    if(logic_value()!= 0)                          //If it isn't 0.
        return;
    //Run 1 one
    if(logic_value()!= 1)                          //If it isn't 1.
        return;
  
    //decode the commands of IR remote control codes 
    ir_code = 0x00;                                  //clear
    for(i=0; i<16;i++ )  {
      if(logic_value() == 1)   {
        ir_code |=(1<<i);
      }
    }
}

void remote_decode(void){                          //decode function
    TCNT1 = 0X00;       
    while(digitalRead(8)){                         // Value is high, then wait.
      if(TCNT1>=1563) {                            // High level duration exceeds 100ms,which means "no button pressed".
        ir_code = 0xff00;
        return;
      }  
    }
    
    // High level duration doesn't exceed 100ms.
    TCNT1 = 0X00;
    while(!(digitalRead(8)));                           // wait low
    Pulse_Width=TCNT1;
    TCNT1 = 0;
    if(Pulse_Width>=140&&Pulse_Width<=141) {            // 9ms  
        while(digitalRead(8));                          //Value is high, then wait.
        Pulse_Width=TCNT1;
        TCNT1=0;
        if(Pulse_Width>=68&&Pulse_Width<=72) {          //4.5ms
          pulse_deal();
          return;
        }
        else if(Pulse_Width>=34&&Pulse_Width<=36){     //2.25ms
          while(!(digitalRead(8)));                    //wait low
          Pulse_Width=TCNT1;
          TCNT1=0;
          if(Pulse_Width>=7&&Pulse_Width<=10){         //560us
            return; 
          }
        }
    }
}

void setup(){
  unsigned char i;
  pinMode(LED_RED,OUTPUT);                      //Set red led pin output
  pinMode(speakerPin,OUTPUT);                       //Set buaaer pin output
  pinMode(IR_IN,INPUT);                         //Set ir receiver input
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

void loop(){  
  timer1_init();                                //timer init
  while(1){
    remote_decode();                            //decode
    remote_deal();                              //Run decodeerout
  }  
}
