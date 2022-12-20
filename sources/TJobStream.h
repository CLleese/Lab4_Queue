#pragma once
#include <stdlib.h>


class TJobStream {
private:
  double jobIntens;
  int jobCount;

public:
  TJobStream(double intens);
  int GetNewJob();
};



