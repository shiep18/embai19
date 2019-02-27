#程序代码

#include <U8glib.h>\
#include <Microduino_AudioPro.h>\
#include <SD.h>

AudioPro_FilePlayer musicPlayer =  AudioPro_FilePlayer(SD);
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

uint8_t fileNum = 0;  

int pushButton = 6;
int pushmusic = 4;
int buttonState = 0;


void playNum(uint8_t num) {
  if (num > musicPlayer.getMusicNum() - 1) {
    return;
  }

  if (!musicPlayer.stopped()) {
    musicPlayer.stopPlaying();  
  musicPlayer.flushCancel(both);  

  String _name = musicPlayer.getMusicName(num);
  Serial.print(F("Playing:"));
  if (!musicPlayer.playMP3(_name)) {
    Serial.println(F("ERROR"));
  }
  else {
    Serial.print(F("OK \t File: "));
    Serial.println(_name);
  }
}




void setup(void) {

  pinMode(SD_PIN_SEL, OUTPUT);    
  digitalWrite(SD_PIN_SEL, HIGH);
  delay(500);

  if (! musicPlayer.begin()) { // initialise the music player
    while (1);
  }

  if (!SD.begin(SD_PIN_SEL)) {
    return;
  }

  musicPlayer.setVolume(126);  //left & right 0-127
  // If DREQ is on an interrupt pin, we can do background
  musicPlayer.useInterrupt(VS1053_PIN_DREQ);  // DREQ int
  
  
  u8g.setColorIndex(1);        
  pinMode(pushButton, INPUT);
  pinMode(pushmusic, INPUT);
  u8g.firstPage();  
  do {
  u8g.setFont(u8g_font_9x15);
  u8g.drawStr( 0, 30, "OPEN A334");
  } while( u8g.nextPage() );
}

void loop(void) {
  
  if(!digitalRead(pushButton))
  {
    buttonState++;
    switch(buttonState)
    {
      case 1:  u8g.firstPage();  
              do {
              u8g.setFont(u8g_font_9x15);
              u8g.drawStr( 0, 30, "Zhuang Xuecheng!");//5
              } while( u8g.nextPage() );
              delay(100); 
              break;
      case 2:  u8g.firstPage();  
              do {
              u8g.setFont(u8g_font_9x15);
              u8g.drawStr( 0, 30, "Zhang yue!");//3
              } while( u8g.nextPage() ); 
              delay(100); 
              break;     
      case 3:  u8g.firstPage();  
              do {
              u8g.setFont(u8g_font_9x15);
              u8g.drawStr( 0, 30, "Zhuang Tianxia!");//2
              } while( u8g.nextPage() );
              delay(100); 
              break;
      case 4:  u8g.firstPage();  
              do {
              u8g.setFont(u8g_font_9x15);
              u8g.drawStr( 0, 30, "Rudy-SH!");//4
              } while( u8g.nextPage() ); 
              delay(100); 
              buttonState=0;
              break;                   
      }
    }


    
    if(!digitalRead(pushmusic))
  {
    switch(buttonState)
    {
      case 0: playNum(4);
              delay(3000); 
              playNum(4);
              delay(3000); 
              playNum(4);
              delay(3000); 
              break;
      case 1: playNum(5);
              delay(3000); 
              playNum(5);
              delay(3000); 
              playNum(5);
              delay(3000); 
              break;    
      case 2: playNum(3);
              delay(3000); 
              playNum(3);
              delay(3000); 
              playNum(3);
              delay(3000); 
              break;
      case 3: playNum(2);
              delay(3000); 
              playNum(2);
              delay(3000); 
              playNum(2);
              delay(3000); 
              break;                   
      }

   }
  
}

