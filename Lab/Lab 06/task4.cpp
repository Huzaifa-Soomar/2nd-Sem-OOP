#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class NotificationHandler
{
public:
    virtual void sendNotification(string userId, string message) = 0;
};

class EmailNotificationHandler : public NotificationHandler
{
    void sendNotification(string userId, string message) override
    {
        cout << "Sending Email to " << userId << endl;
    }
};

class SMSNotificationHandler : public NotificationHandler
{
    void sendNotification(string userId, string message) override
    {
        cout << "Sending SMS to " << userId << endl;
    }
};

class AppNotificationHandler : public NotificationHandler
{
    void sendNotification(string userId, string message) override
    {
        cout << "Pushing App notification to " << userId << endl;
    }
};


// With the help of GPT (class Dispatcher)
class Dispatcher
{
public:
    NotificationHandler *handlers[3];

    void setHandlers(NotificationHandler *h1, NotificationHandler *h2, NotificationHandler *h3)
    {
        handlers[0] = h1;
        handlers[1] = h2;
        handlers[2] = h3;
    }

    void dispatch(string userId, string messages)
    {
        int index = rand() % 3;
        handlers[index]->sendNotification(userId, messages);
    }
};

int main()
{
    srand(time(0));
    EmailNotificationHandler *en = new EmailNotificationHandler();
    SMSNotificationHandler *sn = new SMSNotificationHandler();
    AppNotificationHandler *an = new AppNotificationHandler();

    Dispatcher d;
    d.setHandlers(en, sn, an);
    d.dispatch("Student 69", "Welcome to our University");
    delete en;
    delete sn;
    delete an;
    return 0;
}