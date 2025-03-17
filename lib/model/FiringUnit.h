#pragma once

#include "IFF.h"

class FiringUnit : public IObserver<EntityType> {
  static constexpr double probabilityOfKill() { return 0.8; }

public:
  FiringUnit();
  void notify(const EntityType &entityType) override;

private:
  void launchMissile() const;
  static bool isInitialized_;
};
