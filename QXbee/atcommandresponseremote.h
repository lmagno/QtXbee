#ifndef ATCOMMANDRESPONSEREMOTE_H
#define ATCOMMANDRESPONSEREMOTE_H

#include "atcommandresponse.h"
#include <QObject>
#include <QByteArray>

class ATCommandResponseRemote : public ATCommandResponse
{
	QByteArray remoteAddress;
protected:
	void setRemoteAddress(QByteArray);
public:
	ATCommandResponseRemote();
	virtual unsigned char getApiID() const;
	QByteArray getRemoteAddress();
	QByteArray getFrameData();
	void setFrameData(QByteArray);
};

#endif // ATCOMMANDRESPONSEREMOTE_H
