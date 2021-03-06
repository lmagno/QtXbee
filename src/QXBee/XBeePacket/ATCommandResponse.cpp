#include "ATCommandResponse.h"

ATCommandResponse::ATCommandResponse()
{
}

uint8_t ATCommandResponse::getFrameID() {
	return frameID;
}

QString ATCommandResponse::getATCommand() {
	return atCommand;
}

uint8_t ATCommandResponse::getCommandStatus() {
	return commandStatus;
}

QByteArray ATCommandResponse::getCommandData() {
	return commandData;
}

QByteArray ATCommandResponse::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getATCommand();
	frameData += getCommandStatus();
	frameData += getCommandData();
	return frameData;
}

void ATCommandResponse::setFrameID(uint8_t id) {
	frameID = id;
}
void ATCommandResponse::setATCommand(QString command) {
	atCommand = command.toLocal8Bit();
}
void ATCommandResponse::setCommandStatus(uint8_t status) {
	commandStatus = status;
}
void ATCommandResponse::setCommandData(QByteArray data) {
	commandData = data;
}

void ATCommandResponse::setFrameData(QByteArray data) {
	if ((data.size() < 5) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setATCommand(data.mid(2,2));
	setCommandStatus(data[4]);
	if (data.size() > 5) setCommandData(data.mid(5));
}

ATCommandResponse::~ATCommandResponse() {
}
