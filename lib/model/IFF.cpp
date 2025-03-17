
#include "IFF.h"
#include <iostream>

void IFF::notify(const std::vector<unsigned int> &message) {
  unsigned int oddCount = 0;

  for (auto number : message) {
    if (isOdd(number)) {
      oddCount++;
    }
  }

  std::cout << "IFF: Counted " << oddCount << " odd numbers and "
            << (message.size() - oddCount) << " even numbers" << std::endl;

  if (oddCount > (message.size() / 2)) {
    std::cout << "IFF: Foe detected" << std::endl;
    doNotify(EntityType::Foe);
  } else {
    std::cout << "IFF: Friend detected" << std::endl;
    doNotify(EntityType::Friend);
  }
}

bool IFF::isOdd(unsigned int value) { return (value & 1) == 1; }
