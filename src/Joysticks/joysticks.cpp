#include <ResponsiveAnalogRead.h>

// Library Docs
// https://github.com/dxinteractive/ResponsiveAnalogRead?utm_source=platformio&utm_medium=piohome

// Joystick 1
  const int Joystick_1X_PIN = 34;
  const int Joystick_1Y_PIN = 35;

// Joystick 2
  const int Joystick_2Y_PIN = 39;

// ADC Configuration for ESP32
  static constexpr int ADC_BITS = 12;    // ESP32: 12-bit (0..4095)
  static constexpr int ADC_RES  = 4096;  // 2^12

// Create a ResponsiveAnalogRead Objects
  ResponsiveAnalogRead Joystick_1X(Joystick_1X_PIN, true);
  ResponsiveAnalogRead Joystick_1Y(Joystick_1Y_PIN, true);
  ResponsiveAnalogRead Joystick_2Y(Joystick_2Y_PIN, true);

// Global Variables to Store Joystick Values
  int Joystick_1X_Value = 0;
  int Joystick_1X_RawValue = 0;

  int Joystick_1Y_Value = 0;
  int Joystick_1Y_RawValue = 0;

  int Joystick_2Y_Value = 0;
  int Joystick_2Y_RawValue = 0;



// Setup Joysticks:
// ----------------------------------------------------------------------------------------------
void Joystick_Setup() {

  // Configure ADC Resolution
  analogReadResolution(ADC_BITS);

  // Ajuste importante: a biblioteca assume 10-bit por padrão.
  // Como aqui é 12-bit, informe a resolução correta:
  Joystick_1X.setAnalogResolution(ADC_RES);
  Joystick_1Y.setAnalogResolution(ADC_RES);
  Joystick_2Y.setAnalogResolution(ADC_RES);

  // Opcional (mas recomendado para 12-bit):
  // threshold padrão é 4.0 (pensado para 10-bit); em 12-bit, um valor maior evita micro-jitter.
  // 16 é um bom ponto inicial.
  Joystick_1X.setActivityThreshold(16.0f);
  Joystick_1Y.setActivityThreshold(16.0f);
  Joystick_2Y.setActivityThreshold(16.0f);

  // Ajuda a chegar fácil em 0 e no máximo quando o "sleep" está habilitado
  Joystick_1X.enableEdgeSnap();
  Joystick_1Y.enableEdgeSnap();
  Joystick_2Y.enableEdgeSnap();

}



// Update Readings:
void Joysticks_Update() {

  Joystick_1X.update();
  Joystick_1X_RawValue = Joystick_1X.getRawValue();
  Joystick_1X_Value    = Joystick_1X.getValue();

  Joystick_1Y.update();
  Joystick_1Y_RawValue = Joystick_1Y.getRawValue();
  Joystick_1Y_Value    = Joystick_1Y.getValue();

  Joystick_2Y.update();
  Joystick_2Y_RawValue = Joystick_2Y.getRawValue();
  Joystick_2Y_Value    = Joystick_2Y.getValue();

}

  

// Print Joystick Values:
  void Joysticks_Print() {

  Serial.print(Joystick_1X.getRawValue());
  Serial.print("\t");
  Serial.print(Joystick_1X.getValue());

}