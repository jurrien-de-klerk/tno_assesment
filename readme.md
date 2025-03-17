# Build & Run

## prerequisite
- Docker is installed

## Build && run

To build run:
```
./build.sh
```
from the root dir. Note, that the run script will execute the build script as well.

To run the simulation, execute
```
./run.sh
```
from command line.

You can run the unit test by executing
```
./run_tests.sh
```

# IDE setup
The code is developed in VS code, using a devcontainer. Therefore, If you want to browse the code you can install VS code and the devcontainer plugin. Once installed, you can open the folder in code. VS Code will detect the devcontainer setting and ask whether it should restart within the container.

See [this page for more information on devcontainers](https://code.visualstudio.com/docs/devcontainers/containers)

# Considerations
## Language
C++ is probably overkill for this type of simulation. Looking at the assignment Python would probably be a better choice. The reason I choose C++ is that I had a relative complete environment ready and configured (from some other project). Hence, this was easiest for my.

## Infra module
The current module uses a [Subject and Observer](https://refactoring.guru/design-patterns/observer) design pattern. Although this does keep the code clean and the modules decoupled, it would only be a good strategy if the number of modules remain relatively small. In case of a large scale simulation model, it would probably be better to look at a large scale infrastructure and avoid implementing the whole system in one large monolith.
In that case, an event driven architecture might be a strong approach.

## Overal setup
This is clearly a relatively simple simulation model. Hence, you could argue that things like unit tests, code formatters and devcontainers are quite over the top. However, as the assessment explicitly states the code base should be at the level someone else could take over, I assumed that this is something you do want to see. Hence, I have included this in my solution.