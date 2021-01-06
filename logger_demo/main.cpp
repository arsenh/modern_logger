#include "logger.hpp"
#include "logger_file.hpp"

#include <filesystem>

// \file

/// \brief  Main function
/// \param  argc An integer argument count of the command line arguments
/// \param  argv An argument vector of the command line arguments
/// \return an integer 0 upon exit success
int main()
{
    namespace fs = std::filesystem;
    
    try {
        
        logger_file file{ fs::current_path() };
        logger::get().configure(logger::level::trace, file.destination());    
    
    } catch (const std::exception& ex) {
    
        std::cout << ex.what() << std::endl;
    
    }
    return 0;
}
