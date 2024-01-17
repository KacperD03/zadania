#include "pch.h"
#include "CppUnitTest.h"
#include "../Project4/funkcje.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EbookSystemTests
{
    TEST_CLASS(EbookSystemTests)
    {
    public:
        TEST_METHOD(LoginTest)
        {
            System system;
            system.login();
            Assert::IsTrue(system.userLoggedIn);
        }

        TEST_METHOD(CheckLoginStatusTest)
        {
            System system;
            system.login();

            std::string expectedOutput = "User is logged in.\nEbook List:\nTitle1\nTitle2\nTitle3\nTitle4\nTitle5\n";

            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            system.checkLoginStatus();

            std::cout.rdbuf(sbuf);

            Assert::AreEqual(expectedOutput, buffer.str());
        }


    };
}
