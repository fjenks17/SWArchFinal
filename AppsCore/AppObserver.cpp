#include "AppsCore.h"
#include <iostream>
#include "..\AppPartOps\DelMeBadPattern.h"

int AppObserver::static_number_ = 0;

AppObserver::AppObserver(AppSession& appSession, EventTypes eventType) : appSession_(appSession), m_eventType(eventType), Observer(appSession_, eventType) {
    this->appSession_.Attach(this);
    std::cout << "Hi, I'm the AppObserver \"" << ++AppObserver::static_number_ << "\".\n";
    this->number_ = AppObserver::static_number_;
}
AppObserver::~AppObserver() {
    std::cout << "Goodbye, I was the AppObserver \"" << this->number_ << "\".\n";
}

void AppObserver::Update(const std::string& message_from_subject) {
    message_from_subject_ = message_from_subject;
    PrintInfo();
}
void AppObserver::Update(const std::string& message_from_subject, void* data) {
    message_from_subject_ = message_from_subject;
    PrintInfo(data);
}


void AppObserver::RemoveMeFromTheList() {
    appSession_.Detach(this);
    std::cout << "AppObserver \"" << number_ << "\" removed from the list.\n";
}
void AppObserver::PrintInfo()
{
    std::cout << "AppObserver \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";

}

void AppObserver::PrintInfo(void* data)
{
    PartOpsNotifierData* partData = (PartOpsNotifierData*)data;

    std::cout << "AppObserver \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    std::cout << "Part Data \n" << "Part FilePath " << partData->partName << "\nPart GUID " << partData->guid << std::endl;

}

bool AppObserver::UpdateOnEventType(EventTypes eventType)
{
    if (eventType == m_eventType)
    {
        return true;
    }
    else
    {
        return false;
    }
}
