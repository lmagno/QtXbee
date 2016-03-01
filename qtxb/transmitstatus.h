#ifndef TRANSMITSTATUS_H
#define TRANSMITSTATUS_H
#include "digimeshpacket.h"
#include <QByteArray>

class TransmitStatus : public DigiMeshPacket
{
	QByteArray reserved;
	unsigned deliveryStatus;
	unsigned transmitRetryCount;
	unsigned discoveryStatus;
public:
	TransmitStatus();
	void readPacket(QByteArray rx);
	void setDeliveryStatus(unsigned ds);
	void setTransmitRetryCount(unsigned trc);
	void setDiscoveryStatus(unsigned ds);
	unsigned getDeliveryStatus();
	unsigned getTransmitRetryCount();
	unsigned getDiscoveryStatus();
	QByteArray getReserved();
	void assemblePacket();
};

#endif // TRANSMITSTATUS_H
