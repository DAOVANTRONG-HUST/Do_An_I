#define chanphat 11            // định nghĩa cho chân phát
#define chanthu 10             // định nghĩa cho chân thu
#include <Wire.h>;
#include <LiquidCrystal_I2C.h> // thư viện chuẩn để kết nối với màn hình LCD theo giao thức I2C
LiquidCrystal_I2C lcd(0x27,20,4);
int cambien = A3;              // khai báo chân digital 12 cho cảm biến anh sáng
int thoigian;

unsigned int khoangcach;     // khai báo biến 
int Led = 13;                  //kháo báo chân digital 13 cho đèn LED

void setup ()
{
Serial.begin(9600);
lcd.init();                    //cho phép arduino sử dụng mà hình
lcd.backlight();               //bật đền nền  
pinMode(chanphat , OUTPUT);    // chân phát cao
pinMode(chanthu , INPUT);      // chân thu thấp
pinMode(Led,OUTPUT);           //pinMode xuất tín hiệu đầu ra cho led
pinMode(cambien,INPUT);        //pinMode nhận tín hiệu đầu vào cho cảm biê

}

void loop ()
{
int a = digitalRead(cambien);  //lưu giá trị cảm biến vào biến value
digitalWrite(chanphat,HIGH);   // bật
delayMicroseconds(10);         // thời gian giữa 2 lần phát tần số
digitalWrite(chanphat,LOW);    // tắt
thoigian=pulseIn(chanthu,HIGH);// hàm đến thời gian từ khi chân phát đến khi chân thu nhận được
khoangcach=0.0344*(thoigian/2);
lcd.setCursor(0,1);            //khởi tạo vị trí màn hình sử dụng
lcd.print("TRANG THAI DEN :");
lcd.setCursor(0,2);
lcd.print("KHOANG CACH :");
lcd.setCursor(14,2);
lcd.print("     ");
lcd.setCursor(14,2);
lcd.print(khoangcach);
lcd.setCursor(18,2);
lcd.print("cm");
Serial.print(khoangcach);
Serial.println("cm");
lcd.setCursor(0,0);
lcd.print("XIN CHAO MOI NGUOI!!");
lcd.setCursor(0,3);
lcd.print("Khoangcach<=100");
if(a != 0 &&khoangcach<100) 
{
lcd.setCursor(17,1);
lcd.print("BAT");
digitalWrite(Led,HIGH);       //xuất giá trị ra đèn LED
delay(2000);
}
else
{

lcd.setCursor(17,1);
lcd.print("TAT");
    digitalWrite(Led,LOW);
    delay(200);
}
}

