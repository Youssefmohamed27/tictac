#include <gtest/gtest.h>
#include "login.h"

TEST(LoginTest, ValidLogin) {
    Login login;
    EXPECT_TRUE(login.authenticate("validUsername", "validPassword"));
}

TEST(LoginTest, InvalidLogin) {
    Login login;
    EXPECT_FALSE(login.authenticate("invalidUsername", "invalidPassword"));
}

TEST(LoginTest, EmptyUsername) {
    Login login;
    EXPECT_FALSE(login.isValidUsername(""));
}

TEST(LoginTest, ValidUsername) {
    Login login;
    EXPECT_TRUE(login.isValidUsername("validUsername"));
}

TEST(LoginTest, EmptyPassword) {
    Login login;
    EXPECT_FALSE(login.isValidPassword(""));
}

TEST(LoginTest, ValidPassword) {
    Login login;
    EXPECT_TRUE(login.isValidPassword("validPassword"));
}
