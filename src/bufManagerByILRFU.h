#ifndef BUFMANAGERBYILRFU_H
#define BUFMANAGERBYILRFU_H

#include "../include/global.h"
#include "bufManager.h"
#include <list>
using namespace std;

struct timeval tv;
typedef struct blockInfo{
	unsigned int fileId;
	unsigned int segId;
	float weight;
	int lastTime;
	float lastWeight;
}BlockInfo;

typedef struct qOut{
	unsigned int fileId;
	unsigned int segId;
	float weight;
}QOut;

class bufManagerByILRFU: public bufManager{
	public:
		bufManagerByILRFU(Client*client,unsigned int blockSize,unsigned int totalBufSize):bufManager(client,blockSize,totalBufSize){}
		~bufManagerByILRFU();
	public:
		 int writeFileSegment(unsigned int fileId,unsigned int segId);
		 int readFileSegment(unsigned int fileId,unsigned int segId);
		 int haveSegment(unsigned int fileId,unsigned int segId);
	public:
		 int eliminateBlock();
		 int addBlock(unsigned int fileId,unsigned int segId);
	private:
		 list<BlockInfo> buf;
		 int initial_parameter();
		 float lambda;
		 int MODIFY_TIMES;								// �ı��ʱ��
		 float MODIFY_RATIO;							// �ı�Ŀ���
		 float MODIFY_VALUE;							// �ı���
		 int inTimes;									// ���������к���ҳ����Qout �еĴ���
		 int outTimes;									// ��ҳ�治��Qout �еĴ���
		 int isPreIn;									// �ϴε���ҳ���Ƿ���Qout ��, Ϊ��ͳ���������ֵĴ���
		 int succTimes;									// ��¼��ҳ��������( ����) Qout �г��ֵĴ���
		 int isInQout;									// ��ҳ���Ƿ���Qout �л�����ҳ���Ƿ�����

};

#endif
