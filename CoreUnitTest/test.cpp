#include "pch.h"
#include "..\Core\StringUtils.h"
#include "..\Core\Observer.h"
#include "../AppPartOps/DelMeBadPattern.h"

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

// drawing observer tests

/*
TEST(DrawingObserverTests, updateOnEventTypeTest) {
	DrawingObserver o = DrawingObserver(Session::GetInstance(), IDrawingObserver::EventTypes(4));
	bool val = o.UpdateOnEventType(IDrawingObserver::EventTypes(0));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IDrawingObserver::EventTypes(1));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IDrawingObserver::EventTypes(2));

	EXPECT_FALSE(val);

	val = o.UpdateOnEventType(IDrawingObserver::EventTypes(4));

	EXPECT_TRUE(val);
}

TEST(DrawingObserverTests, createDrawingObserverTest) {
	testing::internal::CaptureStdout();
	DrawingObserver o = DrawingObserver(Session::GetInstance(), IDrawingObserver::EventTypes(4));
	std::string output = testing::internal::GetCapturedStdout();
	bool val = startsWith(output, "Hi, I'm the DrawingObserver");

	EXPECT_TRUE(val);
}

TEST(DrawingObserverTests, updateDrawingObserverTest) {
	DrawingObserver o = DrawingObserver(Session::GetInstance(), IDrawingObserver::EventTypes(4));
	testing::internal::CaptureStdout();
	o.Update("This is a new message.");
	std::string output = testing::internal::GetCapturedStdout();
	bool val = endsWith(output, "This is a new message.\n");

	EXPECT_TRUE(val);
}

TEST(DrawingObserverTests, updateDrawingObserverWithDataTest) {
	DrawingObserver o = DrawingObserver(Session::GetInstance(), IDrawingObserver::EventTypes(4));
	testing::internal::CaptureStdout();
	PartOpsNotifierData* data = new PartOpsNotifierData();
	data->partName = "Part";
	data->guid = 123;
	o.Update("This is a new message.", data);
	std::string output = testing::internal::GetCapturedStdout();
	bool val = (output.find("Part") && output.find("123"));

	EXPECT_TRUE(val);
}

/*

// end drawing observer tests
