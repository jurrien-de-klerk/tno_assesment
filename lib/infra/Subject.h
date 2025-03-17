#pragma once

#include <memory>
#include <vector>

template <typename MSG_T> class IObserver {
public:
  virtual ~IObserver() = default;
  virtual void notify(const MSG_T &message) = 0;
};

template <typename MSG_T> class Subject {
public:
  using ObserverT = IObserver<MSG_T>;
  using ObserverPtr = std::shared_ptr<ObserverT>;

  virtual ~Subject() = default;

  void attach(const ObserverPtr &observer) {
    observers_.emplace_back(observer);
  }

  void doNotify(const MSG_T &message) {
    for (const auto &observer : observers_) {
      observer->notify(message);
    }
  }

private:
  std::vector<std::shared_ptr<IObserver<MSG_T>>> observers_;
};
