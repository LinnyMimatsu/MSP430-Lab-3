
/*
Name: Dominic Pressler
*/
#include <msp430.h>

int getButton() {

//waiting until all the buttons are released
  while(!(P1IN & BIT1 && P1IN & BIT2 && P1IN & BIT4 && P1IN & BIT5 && P1IN & BIT7));

  while(1){

    if(!(P1IN & BIT1)) return 1; //Red Button 1
    if(!(P1IN & BIT2)) return 2; //Brown Button 2
    if(!(P1IN & BIT4)) return 3; //White Button 3
    if(!(P1IN & BIT5)) return 4; //Green Button 4
    if(!(P1IN & BIT7)) return 5; //Gray Button 5

  }

}

int main(void)
{
    //Buttons
    P1DIR &= ~(BIT1 | BIT2 | BIT4 | BIT5 | BIT7); 
    P1OUT |= (BIT1 | BIT2 | BIT4 | BIT5 | BIT7);
    P1REN |= (BIT1 | BIT2 | BIT4 | BIT5 | BIT7);
    //L.E.Ds
    P1DIR |= (BIT0 | BIT6);
    P1OUT &= ~(BIT0 | BIT6);


    int button1, button2, button3, i;
    while(1)
    {
    
    //grabbing values for the buttons
    button1 = getButton();
    button2 = getButton();
    button3 = getButton();

    //checking if the combination is correct
    if(button1 == 2 && button2 == 3 && button3 == 1){
      P1OUT ^= BIT0;
    }else if(button1 == 2 && button2 == 5 && button3 == 4){
      P1OUT ^= BIT6;
    }else{
      for (i = 0; i < 10; i++) {
      
        P1OUT ^= BIT0 | BIT6;
        __delay_cycles(1000000);

      }

      P1OUT &= ~(BIT0 | BIT6);
    }
  }
}
