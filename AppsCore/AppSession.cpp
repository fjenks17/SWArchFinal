#include "AppsCore.h"
#include "..\AppPartOps\DelMeBadPattern.h"
#include <iostream>


AppSession::AppSession() : m_observerForSavePart(nullptr), m_observerForClosePart(nullptr), m_observerForOpenPart(nullptr)
{

}

AppSession& AppSession::GetInstance()
{
    static AppSession instance;

    return instance;
}

void AppSession::SetupDefaultObservers()
{
    m_observerForSavePart = new AppObserver(AppSession::GetInstance(), AppObserver::SavePart);
    m_observerForClosePart = new AppObserver(AppSession::GetInstance(), AppObserver::ClosePart);
    m_observerForOpenPart = new AppObserver(AppSession::GetInstance(), AppObserver::OpenPart);

}


AppSession::~AppSession() {
    std::cout << "Goodbye, I was the AppSession.\n";
}

/**
 * The subscription management methods.
 */
void AppSession::Attach(IObserver* observer) {
    m_listObserver.push_back(observer);
}
void AppSession::Detach(IObserver* observer) {
    m_listObserver.remove(observer);
}
void AppSession::NotifyAll() {
    std::list<IObserver*>::iterator iterator = m_listObserver.begin();
    HowManyObserver();
    while (iterator != m_listObserver.end()) {
        (*iterator)->Update(m_message);
        ++iterator;
    }
}

static std::string  GenerateMessageFromEvent(AppObserver::EventTypes eventType)
{
    std::string retVal;
    if (eventType == AppObserver::ClosePart)
    {
        retVal = "Close Part was Called";
    }
    else if (eventType == AppObserver::OpenPart)
    {
        retVal = "Open Part was Called";
    }
    else if (eventType == AppObserver::SavePart)
    {
        retVal = "Save Part was Called";
    }
    else if (eventType == AppObserver::CreatePart)
    {
        retVal = "Create Part was Called";
    }
    else
    {
        retVal = "Unknown Event Type";
    }

    return retVal;
}



void AppSession::Notify(AppObserver::EventTypes eventType)
{
    std::string generateMessage = GenerateMessageFromEvent(eventType);

    std::list<IObserver*>::iterator iterator = m_listObserver.begin();
    HowManyObserver();
    while (iterator != m_listObserver.end())
    {
        AppObserver* observer = dynamic_cast<AppObserver*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            observer->Update(generateMessage);
        }
        ++iterator;
    }
}

void AppSession::Notify(AppObserver::EventTypes eventType, void* data)
{
    std::string generateMessage = GenerateMessageFromEvent(eventType);

    std::list<IObserver*>::iterator iterator = m_listObserver.begin();
    HowManyObserver();
    while (iterator != m_listObserver.end())
    {
        AppObserver* observer = dynamic_cast<AppObserver*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            observer->Update(generateMessage, data);
        }
        ++iterator;
    }
}

void AppSession::CreateMessage(AppObserver::EventTypes eventType)
{
    Notify(eventType);

}

void AppSession::CreateMessage(AppObserver::EventTypes eventType, void* data)
{
    Notify(eventType, data);

}



void AppSession::CreateMessage(std::string message) {
    this->m_message = message;
    NotifyAll();
}
void AppSession::HowManyObserver() {
    std::cout << "There are " << m_listObserver.size() << " observers in the list.\n";
}


void AppSession::ClearObservers()
{

}
