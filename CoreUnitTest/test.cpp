#include "pch.h"
#include "..\Core\StringUtils.h"
#include "..\Core\Observer.h"
#include "../AppPartOps/DelMeBadPattern.h"
#include "../AppsCore/AppObserver.cpp"

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

//core observer tests
TEST(ObserverTests, createObserverTest) {
	testing::internal::CaptureStdout();
	Observer o = Observer(CoreSession::GetInstance(), IObserver::EventTypes(4));
	std::string output = testing::internal::GetCapturedStdout();
	bool val = startsWith(output, "Hi, I'm the Observer");

	EXPECT_TRUE(val);
}

TEST(ObserverTests, updateObserverTest) {
	Observer o = Observer(CoreSession::GetInstance(), IObserver::EventTypes(4));
	testing::internal::CaptureStdout();
	o.Update("This is a new message.");
	std::string output = testing::internal::GetCapturedStdout();
	bool val = endsWith(output, "This is a new message.\n");

	EXPECT_TRUE(val);
}

TEST(ObserverTests, updateObserverWithDataTest) {
	Observer o = Observer(CoreSession::GetInstance(), IObserver::EventTypes(4));
	testing::internal::CaptureStdout();
	PartOpsNotifierData* data = new PartOpsNotifierData();
	data->partName = "Part";
	data->guid = 123;
	o.Update("This is a new message.", data);
	std::string output = testing::internal::GetCapturedStdout();
	bool val = (output.find("Part") && output.find("123"));

	EXPECT_TRUE(val);
}

TEST(ObserverTests, updateOnEventTypeTest) {
	Observer o = Observer(CoreSession::GetInstance(), IObserver::EventTypes(4));
	bool val = o.UpdateOnEventType(IObserver::EventTypes(0));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IObserver::EventTypes(1));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IObserver::EventTypes(2));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IObserver::EventTypes(4));

	EXPECT_TRUE(val);
}
//end core observer tests

// app observer tests


TEST(AppObserverTests, updateOnEventTypeTest) {
	AppObserver o = AppObserver(AppSession::GetInstance(), IObserver::EventTypes(4));
	bool val = o.UpdateOnEventType(IObserver::EventTypes(0));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IObserver::EventTypes(1));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IObserver::EventTypes(2));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IObserver::EventTypes(4));

	EXPECT_TRUE(val);
}


TEST(AppObserverTests, createAppObserverTest) {
	testing::internal::CaptureStdout();
	AppObserver o = AppObserver(AppSession::GetInstance(), IObserver::EventTypes(4));
	std::string output = testing::internal::GetCapturedStdout();
	bool val = startsWith(output, "Hi, I'm the AppObserver");

	EXPECT_TRUE(val);
}

TEST(AppObserverTests, updateAppObserverTest) {
	AppObserver o = AppObserver(AppSession::GetInstance(), IObserver::EventTypes(4));
	testing::internal::CaptureStdout();
	o.Update("This is a new message.");
	std::string output = testing::internal::GetCapturedStdout();
	bool val = endsWith(output, "This is a new message.\n");

	EXPECT_TRUE(val);
}

TEST(AppObserverTests, updateAppObserverWithDataTest) {
	AppObserver o = AppObserver(AppSession::GetInstance(), IObserver::EventTypes(4));
	testing::internal::CaptureStdout();
	PartOpsNotifierData* data = new PartOpsNotifierData();
	data->partName = "Part";
	data->guid = 123;
	o.Update("This is a new message.", data);
	std::string output = testing::internal::GetCapturedStdout();
	bool val = (output.find("Part") && output.find("123"));

	EXPECT_TRUE(val);
}

// end app observer tests
