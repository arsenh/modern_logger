#include "logger.hpp"

#include <gtest/gtest.h>

TEST(logger_corner_cases_test, file_not_exist) {
    logger l;
    ASSERT_EQ(1, 1);
}
