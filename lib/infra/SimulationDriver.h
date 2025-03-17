#pragma once

#include <chrono>

class SimulationDriver {
public:
  virtual ~SimulationDriver() = default;
  SimulationDriver(std::chrono::milliseconds simulationInterval);
  void run();
  void stop();
  virtual void executeSimulationStep() = 0;

private:
  std::chrono::milliseconds simulationInterval_;
  bool isRunning_;
};
