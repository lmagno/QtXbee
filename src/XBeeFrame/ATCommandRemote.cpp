#include "ATCommandRemote.h"

ATCommandRemote::ATCommandRemote() {
	static const byte broadcast[] = {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF};
	setFrameID(0x01);
	setCommandOptions(0x02);
	setDestinationAddress(QByteArray((char *)broadcast, 8)); // Broadcast by default
}

QByteArray ATCommandRemote::getDestinationAdress() {
	return destinationAddress;
}

byte ATCommandRemote::getCommandOptions() {
	return commandOptions;
}

QByteArray ATCommandRemote::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getDestinationAdress();

	// Reserved bytes
	frameData += (byte)0xFF;
	frameData += (byte)0xFE;

	frameData += getCommandOptions();
	frameData += getATCommand();
	frameData += getATParameter();
	return frameData;
}

void ATCommandRemote::setDestinationAddress(QByteArray address) {
	if (address.length() >= 8) destinationAddress = address.left(8);
}

void ATCommandRemote::setCommandOptions(byte options) {
	commandOptions = options;
}

void ATCommandRemote::setFrameData(QByteArray data) {
	if (data.size() < 15 && data.at(0) != getFrameType()) return;
	setFrameID(data[1]);
	setDestinationAddress(data.mid(2,8));
	setCommandOptions(data[12]);
	setATCommand(data.mid(13,2));
	if (data.size() > 15) setATParameter(data.mid(15));
}