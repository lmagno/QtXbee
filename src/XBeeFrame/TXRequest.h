#ifndef TXREQUEST_H
#define TXREQUEST_H

#include <QByteArray>

#include "typedef.h"
#include "XBeeFrame.h"

class TXRequest : public XBeeFrame
{
	byte			   frameID;
	QByteArray		   destinationAddress;
	byte			   broadcastRadius;
	byte			   transmitOptions;
	QByteArray		   rfData;

public:
	TXRequest();

	virtual byte	   getFrameType() const { return pTXRequest; }
	byte			   getFrameID();
	QByteArray		   getDestinationAddress();
	byte			   getBroadcastRadius();
	byte			   getTransmitOptions();
	QByteArray		   getTransmitingData();
	virtual QByteArray getFrameData();

	void			   setFrameID(byte);
	void			   setDestinationAddress(QByteArray);
	void			   setBroadcastRadius(byte);
	void			   setTransmitOptions(byte);
	void			   setTransmitingData(QByteArray d);
	virtual void	   setFrameData(QByteArray);
};

#endif // TXREQUEST_H