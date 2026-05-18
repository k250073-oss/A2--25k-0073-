#ifndef ABSTRACT_MESSAGE_H
#define ABSTRACT_MESSAGE_H

#include <string>
using namespace std;

class AbstractMessage {
protected:
    int msgId;
    string senderName;
    string receiverName;
    string content;
    string timestamp;
    bool isRead;

public:
    AbstractMessage(int id, string s, string r, string c, string t)
        : msgId(id), senderName(s), receiverName(r), content(c), timestamp(t), isRead(false) {}
    
    virtual ~AbstractMessage() {}
    
    virtual void displayMessage() const = 0; 
    
    void markAsRead() { isRead = true; }
};

#endif