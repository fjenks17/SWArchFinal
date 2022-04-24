// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the APPSCORE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// APPSCORE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "../Core/Observer.h"
#include "../Core/CoreSession.h"
#ifdef APPSCORE_EXPORTS
#define APPSCORE_API __declspec(dllexport)
#else
#define APPSCORE_API __declspec(dllimport)
#endif
#include <list>

// This class is exported from the dll
class APPSCORE_API CAppsCore {
public:
	CAppsCore(void);
};

class APPSCORE_API AppObserver : public Observer {
public:

    AppObserver(AppSession& appSession, EventTypes eventType);
    ~AppObserver() override;
    void Update(const std::string& message_from_subject) override;
    void Update(const std::string& message_from_subject, void* data) override;
    void RemoveMeFromTheList();
    void PrintInfo();
    void PrintInfo(void* data);
    bool UpdateOnEventType(EventTypes eventType);

private:
    std::string message_from_subject_;
    AppSession& appSession_;
    static int static_number_;
    int number_;
    EventTypes m_eventType;
};

class APPSCORE_API AppSession : CoreSession
{
public:
    static AppSession& GetInstance();

    AppSession(AppSession const&) = delete;
    void operator=(AppSession const&) = delete;


    ~AppSession() override;

    /**
     * The subscription management methods.
     */
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    void NotifyAll() override;
    void Notify(IObserver::EventTypes eventType) override;
    void Notify(IObserver::EventTypes eventType, void* data) override;

    void CreateMessage(IObserver::EventTypes eventType);
    void CreateMessage(IObserver::EventTypes eventType, void* data);
    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();

    void ClearObservers();

    void SetupDefaultObservers();

private:
    std::list<IObserver*> m_listObserver;
    std::string m_message;
    AppSession();
    AppObserver* m_observerForSavePart;
    AppObserver* m_observerForClosePart;
    AppObserver* m_observerForOpenPart;


};

extern APPSCORE_API int nAppsCore;

APPSCORE_API int fnAppsCore(void);
