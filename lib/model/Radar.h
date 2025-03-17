#pragma once

#include <SimulationDriver.h>
#include <Subject.h>

#include <fstream>
#include <string>

class Radar : public SimulationDriver,
              public Subject<std::vector<unsigned int>> {
  static constexpr std::chrono::milliseconds simulationInterval() {
    return std::chrono::milliseconds(1000);
  }

public:
  Radar(const std::string &inputFile);
  void executeSimulationStep() override;

private:
  static std::vector<std::string> split(const std::string &input);
  static std::vector<unsigned int>
  toIntValues(const std::vector<std::string> &input);
  static void printScan(const std::vector<unsigned int> &values);
  std::ifstream inputStream_;
};
