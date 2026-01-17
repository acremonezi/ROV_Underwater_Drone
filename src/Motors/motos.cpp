#include <FS_MX1508.h>

// Library Sources:
//  https://github.com/fanfanlatulipe26/FS_MX1508?utm_source=platformio&utm_medium=piohome
//  https://registry.platformio.org/libraries/fanfanlatulipe26/FS_MX1508


// Motor #1: Right Motor
  #define Motor_Right_Pin1 25
  #define Motor_Right_Pin2 26

// Motor #2: Left Motor
  #define Motor_Left_Pin1 32
  #define Motor_Left_Pin2 33

// Motor #3: Top Motor
  #define Motor_Top_Pin1 13
  #define Motor_Top_Pin2 14

// Motor Control settings
  #define PWM_FREQ_HZ 20000  // PWM frequency in Hertz
  #define PWM_BITS    8     // PWM resolution in bits (8 bits -> 0-255)

// Motor control variables
  int Motor_Right_PWM = 0;
  int Motor_Right_BrakingForce = 0;  

  int Motor_Left_PWM = 0;  
  int Motor_Left_BrakingForce = 0;  

  int Motor_Top_PWM = 0; 
  int Motor_Top_BrakingForce = 0;  



// Create Motors Objects:
// ---------------------------------------------------------------------------------------
MX1508 Motor_Right(Motor_Right_Pin1, Motor_Right_Pin2);
MX1508 Motor_Left(Motor_Left_Pin1, Motor_Left_Pin2);
MX1508 Motor_Top(Motor_Top_Pin1, Motor_Top_Pin2);



// Setup function to initialize motors:
// ---------------------------------------------------------------------------------------
void Motors_Setup() {
  Motor_Right.setFrequency(PWM_FREQ_HZ);
  Motor_Right.setResolution(PWM_BITS);
  Motor_Right.motorStop();

  Motor_Left.setFrequency(PWM_FREQ_HZ);
  Motor_Left.setResolution(PWM_BITS);
  Motor_Left.motorStop();

  Motor_Top.setFrequency(PWM_FREQ_HZ);
  Motor_Top.setResolution(PWM_BITS);
  Motor_Top.motorStop();

}

//  Functions to control the Motors:
// ---------------------------------------------------------------------------------------

// Motors Go:
  void Motor_Right_Go() {
    Serial.println("--- Motor Go ----");
      Motor_Right.motorGo(Motor_Right_PWM);
      delay(50);
    }

  void Motor_Left_Go() {
    Serial.println("--- Motor Go ----");
      Motor_Left.motorGo(Motor_Left_PWM);
      delay(50);
    }

  void Motor_Top_Go() {
    Serial.println("--- Motor Go ----");
      Motor_Top.motorGo(Motor_Top_PWM);
      delay(50);
    }

  

// Motors Stop:
  void Motor_Right_Stop() {
    Serial.println("--- Motor Stop ----");
    Serial.println("Speed decrease slowly (free wheeling)");

    Motor_Right.motorStop();
    delay(5000);
  } 

  void Motor_Left_Stop() {
    Serial.println("--- Motor Stop ----");
    Serial.println("Speed decrease slowly (free wheeling)");

    Motor_Left.motorStop();
    delay(5000);
  }

  void Motor_Top_Stop() {
    Serial.println("--- Motor Stop ----");
    Serial.println("Speed decrease slowly (free wheeling)");

    Motor_Top.motorStop();
    delay(5000);
  }



// Motors Brake:
  void Motor_Right_Break() {
    Serial.println("--- Motor Brake ----");
    Serial.println("Motor brake: speed decrease quickly ");

    Motor_Right.motorBrake(Motor_Right_BrakingForce);
    delay(5000);
  } 

  void Motor_Left_Break() {
    Serial.println("--- Motor Brake ----");
    Serial.println("Motor brake: speed decrease quickly ");

    Motor_Left.motorBrake(Motor_Left_BrakingForce);
    delay(5000);
  }

  void Motor_Top_Break() {
    Serial.println("--- Motor Brake ----");
    Serial.println("Motor brake: speed decrease quickly ");

    Motor_Top.motorBrake(Motor_Top_BrakingForce);
    delay(5000);
  }



// Motors Get PWM Values:
  void Motor_Right_Get_PWM() {
    Serial.print("Right Motor PWM Value: ");
    Serial.println(Motor_Right.getPWM());
    Motor_Right.getPWM();
  }

  void Motor_Left_Get_PWM() {
    Serial.print("Right Motor PWM Value: ");
    Serial.println(Motor_Left.getPWM());
    Motor_Left.getPWM();
  }

  void Motor_Top_Get_PWM() {
    Serial.print("Right Motor PWM Value: ");
    Serial.println(Motor_Top.getPWM());
    Motor_Top.getPWM();
  }



// Motors Test:
void Motor_Right_Test() {

  Serial.println("--- Motor Forward ----");
  Serial.println("Ramp up forward 0 to 200");
  for (int pwm = 0; pwm <= 200; pwm++) { // ramp up forward.
    Motor_Right.motorGo(pwm);
    delay(50);
  }

  Serial.println("--- Motor Stop --- ");
  Motor_Right.motorStop();

  Serial.println("--- Motor Backward ----");
  Serial.println("Ramp up backward 0 to -200");
  for (int pwm = 0; pwm <= 200; pwm++) { // ramp up backward.
    Motor_Right.motorGo(-pwm);
    delay(50);
  }

  Serial.println("--- Motor Stop --- ");
  Motor_Right.motorStop();

}


void Motor_Left_Test() {

  Serial.println("--- Motor Forward ----");
  Serial.println("Ramp up forward 0 to 200");
  for (int pwm = 0; pwm <= 200; pwm++) { // ramp up forward.
    Motor_Left.motorGo(pwm);
    delay(50);
  }

  Serial.println("--- Motor Stop --- ");
  Motor_Left.motorStop();

  Serial.println("--- Motor Backward ----");
  Serial.println("Ramp up backward 0 to -200");
  for (int pwm = 0; pwm <= 200; pwm++) { // ramp up backward.
    Motor_Left.motorGo(-pwm);
    delay(50);
  }

  Serial.println("--- Motor Stop --- ");
  Motor_Left.motorStop();

}


void Motor_Top_Test() {

  Serial.println("--- Motor Forward ----");
  Serial.println("Ramp up forward 0 to 200");
  for (int pwm = 0; pwm <= 200; pwm++) { // ramp up forward.
    Motor_Top.motorGo(pwm);
    delay(50);
  }

  Serial.println("--- Motor Stop --- ");
  Motor_Top.motorStop();

  Serial.println("--- Motor Backward ----");
  Serial.println("Ramp up backward 0 to -200");
  for (int pwm = 0; pwm <= 200; pwm++) { // ramp up backward.
    Motor_Top.motorGo(-pwm);
    delay(50);
  }

  Serial.println("--- Motor Stop --- ");
  Motor_Top.motorStop();

}