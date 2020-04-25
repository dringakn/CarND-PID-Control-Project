#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, double ILimit = 1)
{
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  i_limit = fabs(ILimit);
  p_error = i_error = d_error = 0;
}

void PID::UpdateError(double cte)
{
  d_error = cte - p_error;
  p_error = cte;
  /**
   * Integral wind-up
   */
  if (fabs(i_error) < i_limit)
    i_error += cte;
}

double PID::TotalError()
{
  return (-(Kp * p_error) - (Ki * i_error) - (Kd * d_error));
}