#include "pch.h"
#include "..\Core\StringUtils.h"
#include "..\Core\Observer.h"

TEST(StringUtilsTests, startsWithNegativeTest)
{

	std::string a = "aaaabbbb";
	std::string prefix = "bbbb";
	bool val = startsWith(a, prefix);


	EXPECT_FALSE(val);
	 
}

TEST(StringUtilsTests, startsWithPostiveTest)
{
	std::string a = "aaaabbbb";
	std::string prefix = "aaaa";
	bool val = startsWith(a, prefix);

	EXPECT_TRUE(val);

}

TEST(ObserverTests, createObserverTest) {
	testing::internal::CaptureStdout();
	Observer o = Observer(CoreSession::GetInstance(), IObserver::EventTypes(4));
	std::string output = testing::internal::GetCapturedStdout();
	bool val = startsWith(output, "Hi, I'm the Observer");
}