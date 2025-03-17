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
  radar->run();
  return 0;
}
