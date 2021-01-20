# Modern Logger
Modern logger in C++

Build steps.

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

Run unit tests.

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

Doxygen documentation:
- `cd docs/`
- `doxygen Doxyfile`
- `Open with browser ./html/index.html file.`
