#include "TProc.h"


TProc::TProc(double rate)
{
  if (rate < 0 || rate > 1) throw "Expected value: 0 <= x <= 1";
  procRate = rate;
  jobIdComplete = 1;
  timeTact = 0;
  procIdle = 0;
}

int TProc::IsProcBusy()
{
  if (jobs.IsEmpty()) return 0;
  else return 1;
}

bool TProc::IsProcFull()
{
  return jobs.IsFull();
}

int TProc::RunNewJob(int jobId)
{
  if (jobId > 0)
  {
    if (IsProcFull())
    {
      timeTact++;
      return 0;
    }
    else
    {
      jobs.Put(jobId);
      return jobId;
    }
  }
}

int TProc::Work()
{
  if (!IsProcBusy())
  {
    procIdle++;
    return 0;
  }
  double job = (double)rand() / (double)RAND_MAX;
  if (job <= procRate && IsProcBusy())
  {
    int lastJob = jobs.Pop();
    jobIdComplete++;
    return lastJob;
  }
  else {
    return jobs.Low();
  }
}
//
//double TProc::GetProcRate()
//{
//  return procRate;
//}
//
//int TProc::GetProcIdle()
//{
//  return procIdle;
//}
//
//int TProc::GetJobsDone()
//{
//  return jobIdComplete;
//}
//
//int TProc::GetTimeTacts()
//{
//  return timeTact;
//}