#include "logger.hpp"
#include "logger_file.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <filesystem>


int main()
{
    namespace fs = std::filesystem;
    try {

        logger_file file{ fs::current_path() };
        logger::get().configure(logger::level::trace, file.get_source());
        logger::get().information("Logger test ! %", 1);
        logger::get().debug("Sum of % and % equal %", 1, 2, 3);
    
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
