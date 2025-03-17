#pragma once

#include <Subject.h>

#include <vector>

enum class EntityType { Friend, Foe };

class IFF : public IObserver<std::vector<unsigned int>>,
            public Subject<EntityType> {
public:
  void notify(const std::vector<unsigned int> &message) override;

private:
  static bool isOdd(unsigned int value);
};
