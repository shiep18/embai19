#include <Servo.h>
#include <IRremote.h>

long flag1;
long flag2;
Servo servo_10;
long ir_item;
IRrecv irrecv_8(8);
decode_results results_8;

void setup()
{
  flag1 = 0;
  flag2 = 0;
  Serial.begin(9600);
  servo_10.attach(10);
  irrecv_8.enableIRIn();
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  if (Serial.readString() == "1") {
    servo_10.write(90);
    delay(10000);
    servo_10.write(0);
    delay(10000);

  }
  if (irrecv_8.decode(&results_8)) {
    ir_item=results_8.value;
    String type="UNKNOWN";
    String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUBISHI", "SAMSUNG", "LG", "WHYNTER"};
    if(results_8.decode_type>=1&&results_8.decode_type<=13){
      type=typelist[results_8.decode_type];
    }
    Serial.print("IR TYPE:"+type+"  ");
    delay(100);
    if (irrecv_8.decode(&results_8)) {
      ir_item=results_8.value;
      String type="UNKNOWN";
      String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUBISHI", "SAMSUNG", "LG", "WHYNTER"};
      if(results_8.decode_type>=1&&results_8.decode_type<=13){
        type=typelist[results_8.decode_type];
      }
      Serial.print("IR TYPE:"+type+"  ");
      if (ir_item == 0x1FE807F) {
        flag1 = 1;

      } else if (ir_item == 0x1FE40BF) {
        flag1 = 0;
      } else if (ir_item == 0x1FE10EF) {
        flag2 = 1;
      } else if (ir_item == 0x1FE906F) {
        flag2 = 0;
      }
      irrecv_8.resume();
    } else {
    }
    irrecv_8.resume();
  } else {
  }
  if (flag1 == 1) {
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(2,LOW);
    delay(500);
    digitalWrite(4,LOW);
    delay(500);
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(6,HIGH);

  }
  if (flag1 == 0) {
    digitalWrite(4,LOW);
    digitalWrite(2,LOW);
    digitalWrite(6,LOW);

  }
  if (flag2 == 1) {
    Serial.println('3');

  } else if (flag2 == 0) {
    Serial.println('2');
  }

}