#include <Servo.h>

#include <LiquidCrystal.h>
#include <Keypad.h>
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal ekran(rs, en, d4, d5, d6, d7);
Servo servo;
int i = 0;
int a = 0;
int x = 0;
char sifre[4]={'2','1','9','5'};
const char sifredegistir[4]={'*','#','3','1'};
char dizidegistir[4];
char dizi[4];
byte sdsayac=0;
byte sayac=0;
const byte bzr = 11;
const byte s= 12;
const byte k= 13;
const byte satir = 4;
const byte sutun = 3;
char tuslar[satir][sutun] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte satirPinleri[satir] = {9, 8, 7,6};
byte sutunPinleri[sutun] = {5,4,3};
Keypad tusTakimi = Keypad( makeKeymap(tuslar), satirPinleri, sutunPinleri, satir, sutun );
void setup (){
  ekran.begin(16,2);
  pinMode(bzr,OUTPUT);
  pinMode(s,OUTPUT);
  pinMode(k,OUTPUT);
  digitalWrite(k,HIGH);
ekran.clear();
ekran.setCursor(0,0);
ekran.print("Sifreyi giriniz=");
ekran.setCursor(0,1);


}
void loop(){
  
  Serial.begin(9600);
char basilanTus = tusTakimi.getKey();
servo.attach(10);
if (basilanTus!=0 )
{
  
digitalWrite(bzr,HIGH);
delay(50);
digitalWrite(bzr,LOW);
dizi[sayac]=basilanTus;
ekran.write("*");
sayac++;
if(sayac==4)
{
sayac=0;
if(sifre[0]==dizi[0] && sifre[1]==dizi[1] && sifre[2]==dizi[2] && sifre[3]==dizi[3])
{
ekran.clear();
ekran.setCursor(0,0);
ekran.print("Sifre Dogru!");
ekran.setCursor(0,1);
ekran.print("Kapi acildi.");
digitalWrite(bzr,HIGH);
digitalWrite(s,HIGH);
digitalWrite(k,LOW);
 for (int i=0;i<=180;i++)
          {
            servo.write(i);
            delay(3);
          }
 for (int i=180;i>=0;i--)
 {
            servo.write(i);
            delay(3);      
 }

digitalWrite(bzr,LOW);
digitalWrite(s,LOW);
digitalWrite(k,HIGH);

                 
a=0;
i=0;

}
else
{
ekran.clear();
ekran.setCursor(0,0);
ekran.print("Sifre Yanlis!");
ekran.setCursor(0,1);
ekran.print("Tekrar Deneyin.");
digitalWrite(bzr,LOW);
                 digitalWrite(k,LOW);
                 delay(200);
                 digitalWrite(bzr,HIGH);
                 digitalWrite(k,HIGH);
                 delay(200);
                 digitalWrite(bzr,LOW);
                 digitalWrite(k,LOW);
                 delay(200);
                 digitalWrite(k,HIGH);
                 digitalWrite(bzr,HIGH);
                 
                 delay(200);
                 digitalWrite(bzr,LOW);
                 digitalWrite(k,LOW);
                  delay(200);
                 digitalWrite(bzr,HIGH);
                 digitalWrite(k,HIGH);
                 delay(200);
                 digitalWrite(bzr,LOW);
                 digitalWrite(k,LOW); 
                  delay(200);
                  digitalWrite(k,HIGH);
delay(1000);
}
ekran.clear();
ekran.setCursor(0,0);
ekran.print("Sifreyi giriniz=");
ekran.setCursor(0,1);
if (basilanTus =='#'){
  ekran.clear();
  ekran.setCursor(0,0);
  ekran.print("YENI SIFRE");
  ekran.setCursor(0,1);
  ekran.print("KODUNU GIRIN");
  delay(1000);
  ekran.clear();
  ekran.setCursor(0,0);
  
  while(i<4){
          char basilanTus = tusTakimi.getKey();
          if (basilanTus!=0 )
            {
              digitalWrite(bzr,HIGH);
              
              digitalWrite(bzr,LOW);
            dizi[sayac]=basilanTus;
            ekran.write("*");
            sayac++;
            i++;
            if(sayac==4)
            {
              sayac=0;
                if(sifredegistir[0]==dizi[0] && sifredegistir[1]==dizi[1] && sifredegistir[2]==dizi[2] && sifredegistir[3]==dizi[3])
              {
                ekran.clear();
                ekran.setCursor(0,0);
                ekran.print("YENI SIFRE");
                ekran.setCursor(0,1);
                ekran.print("KODU ONAYLANDI");
                delay(500);
                ekran.clear();
                ekran.setCursor(0,0);
                ekran.print("YENI SIFRE");
                ekran.setCursor(0,1);
                sdsayac=0;

                dizidegistir[4]=0;
                
                while(a<4){
                  
                  
                      char basilanTus = tusTakimi.getKey();
                      if (basilanTus!=0 )
                      {
                      digitalWrite(bzr,HIGH);
                      delay(50);
                      digitalWrite(bzr,LOW);
                      sifre[sdsayac]=basilanTus;
                      ekran.write("*");
                      sdsayac++;
                      a++;

                      
                    }
                    
                }
                 digitalWrite(s,LOW);
                 delay(300);
                 ekran.clear();
                 ekran.setCursor(0,0);
                 ekran.write("SIFRE DEGISTIRME");
                 ekran.setCursor(0,1);
                 ekran.write("BASARILI OLDU");
                 digitalWrite(k,LOW);
                 digitalWrite(s,HIGH);
                 digitalWrite(bzr,HIGH);
                 delay(2000);
                 digitalWrite(bzr,LOW);
                 digitalWrite(s,LOW);
                 delay(200);
                 digitalWrite(bzr,HIGH);
                 digitalWrite(s,HIGH);
                 delay(200);
                 digitalWrite(bzr,LOW);
                 digitalWrite(s,LOW);
                 delay(200);
                 digitalWrite(bzr,HIGH);
                 digitalWrite(s,HIGH);
                 delay(200);
                 digitalWrite(bzr,LOW);
                 digitalWrite(s,LOW);
                 delay(200);
                 digitalWrite(k,HIGH);
                  
              }
              else{
                ekran.clear();
                ekran.setCursor(0,0);
                ekran.print("YENI SIFRE");
                
                ekran.setCursor(0,1);
                ekran.print("KODU YANLIS");
                delay(1000);
                digitalWrite(bzr,LOW);
                 digitalWrite(k,LOW);
                 delay(200);
                 digitalWrite(bzr,HIGH);
                 digitalWrite(k,HIGH);
                 delay(200);                
                 digitalWrite(bzr,LOW);
                 digitalWrite(k,LOW);
                 delay(200);
                 digitalWrite(k,HIGH);
                }
             }
            }
           }
          }

ekran.clear();
ekran.setCursor(0,0);
ekran.print("Sifreyi giriniz=");
ekran.setCursor(0,1);
sayac=0;
sdsayac=0;
a=0;
i=0;

}
}
}
