# AirlineControlSystem
### Description
A C++ project that defines functionality for an airline control system that will handle all flights, crew, and planes that are contained within the airline. This project uses, inheritance, STL, runtime polymorphism via method overriding, and virtual functions. 
This is done by having 3 main classes that contain all attributes for each crew member, plane, and flight. Each has a corresponding collection class called crews, planes, and flights respectively. Crew has 3 child classes: pilot, copilot, and cabcrew. These each use inheritance and runtime polymorphism.

### Execution
A makefile is included to ensure all proper files are compiled. Command `make` will compile all files necessary. `make run` will run the compiled executable. `make clean` will remove binaries generated if necessary.

### Use
When ran the user will be prompted with a list of actions. When an option is selected the user will be prompted with another list of corresponding actions. `.dat` files are included for each collection. These are used to store and load data between uses. In order to store data the `store all data` option must be selected from the menu. Data is loaded from the files upon original execution and when option is selected.
