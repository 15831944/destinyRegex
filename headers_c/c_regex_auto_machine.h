/*******************************************************
 *	c_regex_auto_machine.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):�ַ���
 ******************************************************/
#pragma once
/*�Զ���*/
#ifndef C_REGEX_AUTO_MACHINE
#define C_REGEX_AUTO_MACHINE
#include "c_defines.h"

/*�Զ�����ʼ״̬*/
/*NOTICE:��ʹ��type����*/
bool init(struct regex* reg, int begin, int end, int type/*��ʹ�ô˲���*/) {
	for (int i = begin; i <= end; i++) {
		//TODO
		switch (reg->str[i]) {
			case '\0':
				return true;
			default:
				break;
		}
	}
	return true;
}

#endif