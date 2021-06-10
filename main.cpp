#include <UnitTest++/UnitTest++.h>
#include <../NTP/NTP.cpp>

SUITE(ConstructorTest)
{
	TEST(CorrectAddress) {
		NTP t("185.224.145.68");
		CHECK(true);
	}
	TEST(StringOfNumbers) {
		CHECK_THROW(NTP t(""), ntp_error);
	}
	TEST(StringOfLetters) {
		CHECK_THROW(NTP t("185.2E4.145.68"), ntp_error);
	}
	TEST(EmptyAddress) {
		CHECK_THROW(NTP t("185.145.68"), ntp_error);
	}
	TEST(CharacterString) {
		CHECK_THROW(NTP t("185.300.145.68"), ntp_error);
	}
}

int main(int argc, char **argv) {
	return UnitTest::RunAllTests();
}