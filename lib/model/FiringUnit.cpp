#include "FiringUnit.h"

#include <ctime>
#include <iostream>

bool FiringUnit::isInitialized_ = false;

FiringUnit::FiringUnit() {
  if (!isInitialized_) {
    std::srand(std::time({}));
    isInitialized_ = true;
  }
}

void FiringUnit::notify(const EntityType &entityType) {
  if (EntityType::Friend == entityType) {
    std::cout << "Firing Unit: Detected Friend, no missile launched!"
              << std::endl;
  } else {
    std::cout << "Firing Unit: Detected Foe, lauching missile!" << std::endl;
    launchMissile();
  }
}

void FiringUnit::launchMissile() const {
  auto randomValue = std::rand();
  if ((RAND_MAX * probabilityOfKill()) > randomValue) {
    std::cout << "Firing Unit: Kill hit, target killed." << std::endl;
  } else {
    std::cout << "Firing Unit: No kill hit, target isn't killed." << std::endl;
  }
}
