#ifndef RXINDICATOR_H
#define RXINDICATOR_H

#include <QByteArray>

#include "XBeePacket.h"

class RXIndicator : public XBeePacket
{
	QByteArray		   sourceAddress64;
	QByteArray		   sourceAddress16;
	byte			   receiveOptions;
	QByteArray		   receivedData;

protected:
	void			   setSourceAddress64(QByteArray);
	void			   setSourceAddress16(QByteArray);
	void			   setReceiveOptions(byte);
	void			   setReceivedData(QByteArray);

public:
	RXIndicator();

	virtual byte	   getFrameType() const { return pRXIndicator; }
	QByteArray		   getSourceAddress64();
	QByteArray		   getSourceAddress16();
	byte			   getReceiveOptions();
	QByteArray		   getReceivedData();
	virtual QByteArray getFrameData();

	virtual void	   setFrameData(QByteArray);
	virtual			   ~RXIndicator();
};

#endif // RXINDICATOR_H
