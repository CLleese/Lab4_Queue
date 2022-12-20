#pragma once
#include <stdlib.h>
#include "TQueue.h"

class TProc {
private:
  TQueue<int> jobs;
  double procRate; 
  int jobIdComplete; 
  int timeTact;
  int procIdle;


public:
  TProc(double rate);
  int IsProcBusy();
  bool IsProcFull();
  int RunNewJob(int _jobId);
  int Work();
  //double GetProcRate();
  //int GetProcIdle();
  //int GetJobsDone();
  //int GetTimeTacts();
};