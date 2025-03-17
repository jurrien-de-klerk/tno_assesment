#include <FiringUnit.h>
#include <IFF.h>
#include <Radar.h>

#include <csignal>
#include <memory>

std::unique_ptr<Radar> radar;

void signalHandler(int signum) {
  if (radar) {
    radar->stop();
  }

  exit(signum);
}

int main(int, char **) {
  signal(SIGINT, signalHandler);

  radar = std::make_unique<Radar>("resources/radar_data.csv");
  auto iff = std::make_shared<IFF>();
  auto firingUnit = std::make_shared<FiringUnit>();

  radar->attach(iff);
  iff->attach(firingUnit);

  radar->run();
  return 0;
}
