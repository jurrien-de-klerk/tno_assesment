
#include "SimulationDriver.h"

#include <thread>

SimulationDriver::SimulationDriver(std::chrono::milliseconds simulationInterval)
    : simulationInterval_(simulationInterval), isRunning_(false) {}

void SimulationDriver::run() {
  isRunning_ = true;

  while (isRunning_) {
    std::this_thread::sleep_for(simulationInterval_);
    executeSimulationStep();
  }
}

void SimulationDriver::stop() { isRunning_ = false; }
