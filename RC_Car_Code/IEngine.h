#pragma once 
class IEngine
{
  public:
  virtual void RunForward()=0;
  virtual void RunBackward()=0;
  virtual void RunLeft()=0;
  virtual void RunRight()=0;
  virtual void RunForwardRight()=0;
  virtual void RunForwardLeft()=0;
  virtual void RunBackwardRight()=0;
  virtual void RunBackwardLeft()=0;
  virtual void Stop()=0;
};