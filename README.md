# Modern Logger
Modern logger in C++

#### Build prerequisites
 - C++ 17 compatible compiler.
 - Doxygen (optional).
 
 Note: google test framework will be installed automatically.

<h2>Build steps</h2>

#### GNU/Linux
- `cd modern_logger`
- `mkdir build`
- `cmake .. -G "Unix Makefiles"`
- `make`

#### Windows
- `cd modern_logger`
- `mkdir build`
- `cmake .. -G "Visual Studio 16 2019"`
- `Open modern_logger.sln file from Visual Studio 2019`

<h2>Run unit tests</h2>

#### GNU/Linux
- `cd ./build/bin/`
- `./logger_data_types_tests`
- `./logger_levels_tests`
- `./logger_messages_tests`


#### Windows
- `cd ./build/bin/Debug`
- `logger_data_types_tests.exe`
- `logger_levels_tests.exe`
- `logger_messages_tests.exe`

#### <h2>Doxygen documentation</h2>
- `cd docs/`
- `doxygen Doxyfile`
- `Open with browser ./html/index.html file.`

#### <h2>Usage</h2>
`logger::get().configure(<logger level>, <ostream>)` </br>
`logger::get().debug("Hello %", "World!") // Hello World!` 

More information about API find in documentation.






