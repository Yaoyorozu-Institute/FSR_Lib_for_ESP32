#include "FSR_Lib.h"

FSR::FSR(double R_kOhm, double V_milliVolt, uint8_t DIN)
{
  _R = R_kOhm;
  _V_milliVolt = V_milliVolt;
  _DIN = DIN;

  pinMode(_DIN, INPUT);
}

void FSR::Calibration(void)
{
  calibration_val = analogReadMilliVolts(_DIN);
}

double FSR::Force(void)
{
  val = analogReadMilliVolts(_DIN) - calibration_val;
  F_Resist = (_R * val / (_V_milliVolt - val));
  F = 2757 * pow(F_Resist, -1.135);
  return F;
}
