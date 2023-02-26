#include<pic.h>
void cmd(int c);
void data(char d);
void data2(char d);
void delay();
void delay1();
void delay2();
void display(const char *p);
char key();
char rec();
void main()
{
int a,i,d=0,g=0,l=0,n,o,p,q,r,s,t;
char b[4],c[4],e[4],f[4],j[4],k[4],m[10];
TRISD=0X0F;
TRISB=0X00;
TRISA=0X00;
TRISC=0XB8;
TXSTA=0X24;
RCSTA=0X90;
SPBRG=129;
cmd(0X38);
cmd(0X01);
cmd(0X80);
cmd(0X06);
cmd(0X0E);
char b[4]="1111";
char e[4]="2222";
char j[4]="3333";
RC0=1;
RC1=1;
RC2=1;
if(RC3==1)
{
display("Two Wheeler");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
c[i]=key();
data(c[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(b[i]==c[i])
{
d++;
}
}
if(d==4)
{
display("APPROVED");

cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
p=rec();
data(p);
q=rec();
data(q);
cmd(0X01);
display("Balance");
o=o-1;
cmd(0XC0);
data(o);
data(p);
data(q);

PORTA=0X01;
delay1();
PORTA=0X00;
delay1();
PORTA=0X02;
delay1();
PORTA=0X00;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
else if(RC4==1)
{
display("Four Wheeler");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
f[i]=key();
data(f[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(e[i]==f[i])
{
g++;
}
}
if(g==4)
{
display("APPROVED");

cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
p=rec();
data(p);
q=rec();
data(q);
cmd(0X01);
display("Balance");
o=o-2;
cmd(0XC0);
data(o);
data(p);
data(q);

PORTA=0X04;
delay1();
PORTA=0X00;
delay1();
PORTA=0X08;
delay1();
PORTA=0X00;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
else if(RC5==1)
{
display("Heavy Vehicle");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
k[i]=key();
data(k[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(j[i]==k[i])
{
l++;
}
}
if(l==4)
{
display("APPROVED");

cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
p=rec();
data(p);
q=rec();
data(q);
cmd(0X01);
display("Balance");
o=o-3;
cmd(0XC0);
data(o);
data(p);
data(q);

PORTA=0X10;
delay1();
PORTA=0X00;
delay1();
PORTA=0X20;
delay1();
PORTA=0X00;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
}
char key()
{
int a;
while(1)
{
PORTD=0X7F;
a=PORTD&0X0F;
switch(a)
{  
case 0X07:return('1');break;
case 0X0B:return('2');break;
case 0X0D:return('3');break;
case 0X0E:return('4');break;
}
PORTD=0XBF;
a=PORTD&0X0F;
switch(a)
{
case 0X07:return('5');break;
case 0X0B:return('6');break;
case 0X0D:return('7');break;
case 0X0E:return('8');break;
}
PORTD=0XDF;
a=PORTD&0X0F;
switch(a)
{
case 0X07:return('9');break;
case 0X0B:return('A');break;
case 0X0D:return('B');break;
case 0X0E:return('C');break;
}
PORTD=0XEF;
a=PORTD&0X0F;
switch(a)
{
case 0X07:return('D');break;
case 0X0B:return('E');break;
case 0X0D:return('F');break;
case 0X0E:return('G');break;
}
}
}
void cmd(int c)
{
PORTB=c;
RC0=0;
RC1=1;
delay();
RC1=0;
}
void delay()
{
int i,j;
for(i=0;i<300;i++)
for(j=0;j<300;j++);
}
void delay1()
{
int i,j;
for(i=0;i<800;i++)
for(j=0;j<800;j++);
}
void delay2()
{
int i,j;
for(i=0;i<150;i++)
for(j=0;j<150;j++);
}
void data(char d)
{
PORTB=d;
RC0=1;
RC1=1;
delay();
RC1=0;
}
void data2(char d)
{
PORTB=d;
RC0=1;
RC1=1;
delay2();
RC1=0;
}
void display(const char *p)
{
while(*p!='\0')
{
data2(*p);
p++;
}
}
char rec()
{
while(RCIF==0);
RCIF=0;
return(RCREG);
}
