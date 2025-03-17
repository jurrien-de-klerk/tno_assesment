#include "Radar.h"

#include <algorithm>
#include <iostream>
#include <sstream>

Radar::Radar(const std::string &inputFile)
    : SimulationDriver(simulationInterval()), inputStream_(inputFile) {
  if (!inputStream_) {
    std::cout << "ERROR: failed to read input file." << std::endl;
    exit(1);
  }
}

void Radar::executeSimulationStep() {
  std::string line;
  getline(inputStream_, line);

  auto dataStringValues = split(line);
  auto dataNumbers = toIntValues(dataStringValues);
  printScan(dataNumbers);
  doNotify(dataNumbers);

  if (inputStream_.eof()) {
    stop();
  }
}

std::vector<std::string> Radar::split(const std::string &input) {
  std::vector<std::string> result;
  std::istringstream inStream(input);
  std::string value;

  while (getline(inStream, value, ';')) {
    result.push_back(value);
  }

  return result;
}

std::vector<unsigned int>
Radar::toIntValues(const std::vector<std::string> &input) {
  std::vector<unsigned int> result;

  std::transform(input.begin(), input.end(), std::back_inserter(result),
                 [](const auto &value) {
                   return static_cast<unsigned int>(
                       std::stoi(value, nullptr, 2));
                 });

  return result;
}

void Radar::printScan(const std::vector<unsigned int> &values) {
  std::cout << std::endl << "Radar: scan complete: [";

  for (auto iter = values.begin(); iter != values.end(); ++iter) {
    if ((iter + 1) == values.end()) {
      std::cout << *iter << "]" << std::endl;
    } else {
      std::cout << *iter << ", ";
    }
  }
}
