int LDR1=0;   // Up sensor
int LDR2=0;   // Down sensor
int LDR3=0;   //Right sensor
int LDR4=0;   //Left sensor
int x=0;       //resultion
int y=0;        //resultion


void Motor_up (){              //make the solar panel in the top
do {  LDR1=ADC_Read (0);       // read the LDR1 & LDR2 in every repetition
      LDR2=ADC_Read (1);
      PORTD=0b0001;            //drive the stepper motor in micro step mode
      delay_ms(3);
      PORTD=0b0011;
      delay_ms(3);
      PORTD=0b0010;
      delay_ms(3);
      PORTD=0b0110;
      delay_ms(3);
      PORTD=0b0100;
      delay_ms(3);
      PORTD=0b1100;
      delay_ms(3);
      PORTD=0b1000;
      delay_ms(3);
      PORTD=0b1001;
      delay_ms(3);
      }while (LDR2>LDR1);}

void Motor_down (){          //Make the solar panel in the bottom
do {  LDR1=ADC_Read (0);     // Read the LDR1 & LDR2 in every repetition
      LDR2=ADC_Read (1);
      PORTD=0b1000;          //drive the stepper motor in micro step mode
      delay_ms(3);
      PORTD=0b1100;
      delay_ms(3);
      PORTD=0b0100;
      delay_ms(3);
      PORTD=0b0110;
      delay_ms(3);
      PORTD=0b0010;
      delay_ms(3);
      PORTD=0b0011;
      delay_ms(3);
      PORTD=0b0001;
      delay_ms(3);
      PORTD=0b1001;
      delay_ms(3);
      }while (LDR1>LDR2);}

void Motor_Right (){           //Make the solar panels rotate with the clockwise
 do { LDR3=ADC_Read (2);       // Read the LDR3 & LDR4 in every repetition
      LDR4=ADC_Read (3);
      PORTb=0b1000;            //drive the stepper motor in micro step mode
      delay_ms(3);
      PORTb=0b1100;
      delay_ms(3);
      PORTb=0b0100;
      delay_ms(3);
      PORTb=0b0110;
      delay_ms(3);
      PORTb=0b0010;
      delay_ms(3);
      PORTb=0b0011;
      delay_ms(3);
      PORTb=0b0001;
      delay_ms(3);
      PORTb=0b1001;
      delay_ms(3);
      }while (LDR4>LDR3);}


void Motor_Left(){           //Make the solar panels rotate counter clockwise
do {  LDR3=ADC_Read (2);     // Read the LDR3 & LDR4 in every repetition
      LDR4=ADC_Read (3);
      PORTb=0b0001;           //drive the stepper motor in micro step mode
      delay_ms(3);
      PORTb=0b0011;
      delay_ms(3);
      PORTb=0b0010;
      delay_ms(3);
      PORTb=0b0110;
      delay_ms(3);
      PORTb=0b0100;
      delay_ms(3);
      PORTb=0b1100;
      delay_ms(3);
      PORTb=0b1000;
      delay_ms(3);
      PORTb=0b1001;
      delay_ms(3);
      }while (LDR3>LDR4);}

void main() {
TRISD=0;         //Initializing portD & portB as OUTPUT
TRISB=0;
PORTD=0;         //Make the output 0 in the start
PORTB=0;
ADC_init();
while (1){
LDR1=ADC_Read (0);        //Read the 4 sensors to determine the progrram path in the if statment
LDR2=ADC_Read (1);
LDR3=ADC_Read (2);
LDR4=ADC_Read (3);
x=abs(LDR1-LDR2);
y=abs(LDR3-LDR4);
//delay_ms(50);
if (x>10.0&&y>10.0){
if (LDR1>LDR2){    //the solar panel go to the bottom and left or right
Motor_down();
if (LDR3>LDR4){
Motor_Left();

}
else {
Motor_Right();

}
}

else {         //the solar panel go to the top  and left or right
Motor_up ();
if (LDR3>LDR4){
Motor_Left();
}
else {
Motor_Right();
}
}
//delay_ms(50);
}
}
}