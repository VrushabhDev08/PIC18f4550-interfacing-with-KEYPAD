#include<PIC18F4550.h>
#define RS RC0
#define EN RC1
#define R0 RC2
#define R1 RC4
#define R2 RC5
#define R3 RC6
#define C0 RB4
#define C1 RB5
#define C2 RB6
#define C3 RB7
#define DATABUS PORTD
void delay()
{
int i,j;
for(i=0;i<10000;i++);
}
 
void cmd(char a)
{
RC0 = 0;
DATABUS = a;
RC1=1;
delay();
RC1=0;
}
void data(char a)
{
RC0=1;
DATABUS=a;
RC1=1;
delay();
RC1=0;
}
 
void main()
{
TRISD=0x00;
TRISC=0x00;
TRISBbits.RB5=1;
TRISBbits.RB6=1;
TRISBbits.RB7=1;
TRISBbits.RB4=1;
cmd(0x32);
cmd(0x0e);
cmd(0x06);
while(1)
{
R0=0;
R1=0;
R2=0;
R3=0;
delay();
if(C0==0||C1==0||C2==0||C3==0)
{
R0=0;
R1=1;
R2=1;
R3=1;
if(C0==0)
{
data('7');
delay();
}
if(C1==0)
{
data('8');
delay();
}
if(C2==0)
{
data('9');
delay();
}
if(C3==0)
{
data('/');
delay();
}
R0=1;
R1=0;
R2=1;
R3=1;
if(C0==0)
{
data('4');
delay();
}
if(C1==0)
{
data('5');
delay();
}
if(C2==0)
{
data('6');
delay();
}
if(C3==0)
{
data('*');
delay();
}
R0=1;
R1=1;
R2=0;
R3=1;
if(C0==0)
{
data('1');
delay();
}
if(C1==0)
{
data('2');
delay();
}
if(C2==0)
{
data('3');
delay();
}
if(C3==0)
{
data('-');
delay();
}
R0=1;
R1=1;
R2=1;
R3=0;
if(C0==0)
{
data('.');
delay();
}
if(C1==0)
{
data('0');
delay();
}
if(C2==0)
{
data('=');
delay();
}
if(C3==0)
{
data('+');
delay();
}
}

}
}
}
