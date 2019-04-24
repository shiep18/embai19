#include <Microduino_AudioPro.h>
#include <SD.h>
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
  Serial.print(F("Playing:"));
  if (!musicPlayer.playMP3(_name)) {
    Serial.println(F("ERROR"));
  }
  else {
    Serial.print(F("OK \t File: "));
    Serial.println(_name);
  }
}
void setup() {
  Serial.begin(115200);
  Serial.println(F("Controlled music station"));
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



  musicPlayer.setVolume(96);  //left & right 0-127

  //or

  //musicPlayer.setVolume(96, 96);  //left right 0-127



  // If DREQ is on an interrupt pin, we can do background

  musicPlayer.useInterrupt(VS1053_PIN_DREQ);  // DREQ int



  help();

}



void loop() {

  if (Serial.available()) {

    char c = Serial.read();

    if ((0x20 <= c) && (c <= 0x126)) {  // strip off non-ASCII, such as CR or LF

      if (c >= '0' && c <= '9') {

        int num = c - 48;

        playNum(num);

      }

      else if (c == 'a') {             //控制运放开关

        if (! musicPlayer.getAmplifier()) {

          Serial.println(F("Amplifier On"));

          musicPlayer.setAmplifier(true);

        } else {

          Serial.println(F("Amplifier Off"));

          musicPlayer.setAmplifier(false);

        }

      }

      else if (c == 's') {    //停止播放音乐

        Serial.println(F("Stopping"));

        musicPlayer.stopPlaying();

      }

      // if we get an 'p' on the serial console, pause/unpause!

      else if (c == 'p') {    //暂停播放音乐

        if (musicPlayer.stopped()) {

          Serial.println(F("Player is Stopping."));

        }

        else if (! musicPlayer.paused()) {

          Serial.println(F("Paused"));

          musicPlayer.pausePlaying(true);

        } else {

          Serial.println(F("Resumed"));

          musicPlayer.pausePlaying(false);

        }

      }

      else if ((c == '-') || (c == '+')) {  //调整音量

        int _volume;

        if (c == '-') { // note dB is negative

          _volume  = musicPlayer.volumeDown();

        }

        else {

          _volume = musicPlayer.volumeUp();

        }

        Serial.print(F("Volume changed to "));

        Serial.println(_volume);

      }

      else if (c == 'i') {          //显示系统常见信息

        Serial.print(F("getVolume:"));

        Serial.println(musicPlayer.getVolume());

        Serial.print(F("getAmplifier:"));

        Serial.println(musicPlayer.getAmplifier());

        Serial.print(F("getPlaySpeed:"));

        Serial.println(musicPlayer.getPlaySpeed());

        Serial.print(F("decodeTime:"));

        Serial.println(musicPlayer.decodeTime());

      }

      else if (c == 'l') {          //列出音乐文件清单

        if (musicPlayer.paused() || musicPlayer.stopped()) {

          Serial.println(F("Enter Index of File to play"));

          fileNum = musicPlayer.getMusicNum();    //可以获取SD卡中曲目列表以及数量

          Serial.print(F("Music Files : "));

          Serial.println(fileNum);

          for (uint8_t a = 0; a < fileNum; a++) {

            Serial.print(F("\t File["));

            Serial.print(a);

            Serial.print(F("]: "));

            Serial.println(musicPlayer.getMusicName(a));

          }

        }

        else {

          Serial.println(F("Busy Playing Files, try again later."));

        }



      }

      else if (c == 'h') {          //显示帮助

        help();

      }



    }

  }



  delay(100);

}



void help() {

  Serial.println(F("COMMANDS:"));

  Serial.println(F(" [0-9] to play a track"));

  Serial.println(F(" [a] to Set Amplifier"));

  Serial.println(F(" [s] to stop playing"));

  Serial.println(F(" [p] to pause or unpause"));

  Serial.println(F(" [s] to stop playing"));

  Serial.println(F(" [+ or -] to change volume"));

  Serial.println(F(" [i] retrieve current audio information (partial list)"));

  Serial.println(F(" [l] Display list of music files"));

  Serial.println(F(" [h] this help"));

}

