#include <U8glib.h>
#include <Servo.h>
#include <Microduino_AudioPro.h>
#include <SD.h>
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
#define setFont_L u8g.setFont(u8g_font_unifont)
#define setFont_S u8g.setFont(u8g_font_fixed_v0r)
#define setFont_M u8g.setFont(u8g_font_9x15)
#define BuzzerPin4 4
Servo servo_10;
AudioPro_FilePlayer musicPlayer =  AudioPro_FilePlayer(SD);
uint8_t fileNum = 0;  //文件数量
void playNum(uint8_t num) {
  if (num > musicPlayer.getMusicNum() - 1) {
    return;
  }
  if (!musicPlayer.stopped()) {
    musicPlayer.stopPlaying();  //必要，否则SD类得不到关闭，内存溢出
  }
  musicPlayer.flushCancel(both);  //清缓存，播放MIDI等格式文件时必要
  String _name = musicPlayer.getMusicName(num);
}
//初始化串口
void setup()

{
  pinMode(2, OUTPUT);   //指示灯
  pinMode(4, OUTPUT);   //蜂鸣器
  pinMode(6, INPUT);    //室内控制按键
  pinMode(8, INPUT);    //门铃按键
  servo_10.attach(10);  //舵机接口
  pinMode(SD_PIN_SEL, OUTPUT);    //先初始化AudioPro，所以先使能SD卡
  digitalWrite(SD_PIN_SEL, HIGH);
  delay(500);
    if (! musicPlayer.begin()) { // initialise the music player
    Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
    while (1);
  }
  Serial.println(F("Player found"));
  if (!SD.begin(SD_PIN_SEL)) {
    Serial.println(F("initialization failed!"));
    return;
  }
  Serial.println(F("initialization done."));
  musicPlayer.setVolume(96);
  musicPlayer.useInterrupt(VS1053_PIN_DREQ);
}

void loop()
{
  //程序执行
  while(1)	

  {
   u8g.undoRotation();
   u8g.firstPage();
   do {
       setFont_S;
       u8g.setPrintPos(0, 20);
       u8g.print("Welcome to Team6");
      } while( u8g.nextPage() );
    while(!digitalRead(8))
    {
      //初始化各硬件单元
      digitalWrite(2,LOW); //熄灭指示灯
      noTone(BuzzerPin4);  //关闭蜂鸣器
      //初始化OLED显示“Welcome to Team6”
        if(digitalRead(6))
        {
          //蜂鸣器报警
          while(1){
          for (int i = 200; i <= 800; i = i + (1))   tone(BuzzerPin4,i); 
          for (int i = 800; i >= 200; i = i + (-1))  tone(BuzzerPin4,i);
          break;
          }
        }
        //室内控制按键按下，警报解除，LED指示灯亮
        else 
        {
          noTone(BuzzerPin4);
          u8g.undoRotation();
          u8g.firstPage();
          do {
             setFont_S;
             u8g.setPrintPos(0, 20);
             u8g.print("The Door is Open!");
             } while( u8g.nextPage() );
          digitalWrite(2,HIGH);
          delay(2000);
          digitalWrite(2,LOW);
		  for (int i = 0; i <= 90; i = i + (1)) {
            servo_10.write(i);
            delay(15);
          }
          delay(3000);
		  for (int i = 90; i >= 0; i = i + (-1)) {
          servo_10.write(i);
          delay(15);
          }
		  playNum(6);
          break;
        }
      break;
    }
  }



















































  



}