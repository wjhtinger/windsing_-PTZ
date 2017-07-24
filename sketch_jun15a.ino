#include <Servo.h>


Servo myservo;
Servo myservo2;
int x = 0; 
int y = 0;
int xa = 90;
int ya = 90;
char x_flag = 0;
char y_flag = 0;

void setup() {

  Serial.begin(115200); //initial the Serial
  myservo.attach(9);  // 该舵机由arduino第九脚控制
  myservo2.attach(8); 
  myservo.write(xa);
  myservo2.write(ya);
}

void loop(){
  
  for(;;){
    if(Serial.available()){
      int data = Serial.read();
      if(data == 'X'){
        x_flag = 1;
        x = 0;
        continue;
      }
      else if(data == 'x'){
        x_flag = -1;
        x = 0;
        continue;
      }
      else if(data == 'Y'){
        y_flag = 1;
        y = 0;
        continue;
      }
      else if(data == 'y'){
        y_flag = -1;
        y = 0;
        continue;
      }
      else if(data == 'E'){
        if(x_flag != 0){
          xa += x * x_flag;
          if(xa < 0)
            xa = 0;
          if(xa > 180)
            xa = 180;
          myservo.write(xa);      
          x_flag = 0;
          //Serial.print(xa);
          //Serial.println("NX");
          //continue;
        }

        if(y_flag != 0){
          ya += y * y_flag;
          if(ya < 0)
            ya = 0;
          if(ya > 100)
            ya = 100;
          myservo2.write(ya);      
          y_flag = 0;
          //Serial.print(ya);
          //Serial.println("NY");
        }
        
        continue;
      }

      if(x_flag != 0){
        x = x * 10 + (data - 48);
      }
      if(y_flag != 0){
        y = y * 10 + (data - 48);
      }
        //Serial.print(x);
        //Serial.print("_");      
        
    }
  }
    
}

