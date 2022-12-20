#include "TJobStream.h"

TJobStream::TJobStream(double intens)
{
  if (intens < 0 || intens > 1) {
    throw "Expected value: 0 <= x <= 1";
  }

  jobIntens = intens;
  jobCount = 1;
}

int TJobStream::GetNewJob()
{
  double q1 = double(rand()) / double(RAND_MAX);

  if (q1 <= jobIntens) {
    return jobCount++;
  }
  else {
    return 0;
  }
}
