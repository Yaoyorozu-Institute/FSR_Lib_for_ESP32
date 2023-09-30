#ifndef FSR_Lib.H
#define FSR_Lib .H

#pragma once

#include <stdint.h>
#include <math.h>

class FSR
{
public:
  FSR(double R_kOhm, double V_milliVolt, uint8_t DIN);
  void Calibration(void);
  double Force(void);

protected:
  double _R;
  double _V_milliVolt;
  uint8_t _DIN;
  double calibration_val;
  double val;
  double F_Resist;
  double F;
};

#endif