#include <gtest/gtest.h>

#include "includes.hpp"
#include "../src/Core/Core.hpp"
#include "../src/Parsing/Parsing.hpp"
#include <cstring>

TEST(BasicHelp, BasicUsage)
{
    testing::internal::CaptureStdout();
    char** arguments = (char**)malloc(sizeof(char*) * 3);
    arguments[0] = (char*)strdup("./filename");
    arguments[1] = (char*)strdup("--help");
    arguments[2] = (char*)NULL;
    EXPECT_EXIT(Plazza::Core(2, arguments), testing::ExitedWithCode(0), ".*") << "Error while running the program with --help";
    free(arguments[0]);
    free(arguments[1]);
    free(arguments);
    std::string sout = testing::internal::GetCapturedStdout();
    EXPECT_EQ(sout, "Usage: ./filename [-h|--help] [MultipierTime] [NbCooks] [RefillTime]\n") << "STDOUT is invalid !";
}

// TEST (BasicParsing, BasicUsage)
// {
//     char** arguments = (char**)malloc(sizeof(char*) * 5);
//     arguments[0] = (char*)strdup("./filename");
//     arguments[1] = (char*)strdup("0.5");
//     arguments[2] = (char*)strdup("8");
//     arguments[3] = (char*)strdup("3");
//     arguments[4] = (char*)NULL;

//     Plazza::Core obj(4, arguments);
//     free(arguments[0]);
//     free(arguments[1]);
//     free(arguments[2]);
//     free(arguments[3]);
//     free(arguments);
//     EXPECT_EQ(Parsing::get().getMultiplierTime(), 0.5) << "Invalid retreived Multiplier Time";
//     EXPECT_EQ(Parsing::get().getNbCooks(), 8) << "Invalid retreived Nb Cooks";
//     EXPECT_EQ(Parsing::get().getRefillTime(), 3) << "Invalid retreived Refill Time";
// }
