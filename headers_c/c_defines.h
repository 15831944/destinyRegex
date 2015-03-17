/*******************************************************
 *	c_defines.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):�ַ���
 ******************************************************/
#pragma once
/*���ݽṹ����*/
#ifndef C_DESTINY_REGEX
#define C_DESTINY_REGEX

#define NULL 0
#define MAX_INT_VAL 0x7FFFFFFF

#ifndef _Bool
#define true 1
#define false 0
#define bool int
#endif

#define OR_CHAR '|'

#include <stdlib.h>
#include <stdio.h>

#define LEFT_LARGE_BRACE '{'
#define RIGHT_LARGE_BRACE '}'
#define LEFT_MID_BRACKET '['
#define RIGHT_MID_BRACKET ']'
#define LEFT_BRACKET '('
#define RIGHT_BRACKET ')'
#define CHANGE_LETTER '\\' //˫б��ת��
#define TAB 't' //��Ҫת��
#define RETURN 'r' //��Ҫת��
#define NEW_LINE 'n' //��Ҫת��
#define BLANK ' ' //�ո�
#define COMMA ',' //����
#define DOT '.' //ͨ���
#define MULTI_MATCH_LETTER '*' //���ƥ���
#define QUES '?' //0��1��
#define PLUS '+' //һ������
#define DECIMAL 'd' //һ��ʮ��������,��Ҫת��
#define LOWER_LETTER 'l' //һ��Сд��ĸ,��Ҫת��
#define SPACE 's' //һ���հ׷����ո�����Ʊ���ȣ�,��Ҫת��
#define UPER_LETTER 'u'//һ����д��ĸ,��Ҫת��
#define SIMPLE_LETTER 'w' //һ����ĸ��a��z��A��Z�������֣�0��9�����»��ߣ�_��,��Ҫת��
#define NOT_DECIMAL 'D' //����\d֮����ַ�,��Ҫת��
#define NOT_LOWER_LETTER 'L' //����\l֮����ַ�,��Ҫת��
#define NOT_SPACE 'S' //����\s֮����ַ�,��Ҫת��
#define NOT_UPER_LETTER 'U' //����\u֮����ַ�,��Ҫת��
#define NOT_SIMPLE_LETTER 'W' //����\w֮����ַ�,��Ҫת��
#define RANGE_LETTER '-' //��Χ��ʾ��

/*list for chars*/
struct list_char {
	char value;
	struct list_char *next;
};

/*������ʽ��һƥ�䵥Ԫ*/
struct single_condition {
	struct list_char *match_letters;
	unsigned int least_match_time;//����ƥ�����
	unsigned int max_match_time;//���ƥ�����
};

/*ƥ�����*/
struct list_condition {
	struct single_condition value;
	struct list_condition* next;
};

/*ƥ���ַ���*/
struct match_iterator {
	struct match_iterator* next;
	char* value;
};

/*δƥ���ַ���������ַ���*/
struct regex_token_iterator {
	struct regex_token_iterator* next;
	char* value;
};

/*������ʽ*/
/*ƥ��֮ǰ����compiler*/
struct regex {
	const char* str;
	int length_str;
	struct list_condition* con;
	struct match_iterator* match_strs;
	struct regex_token_iterator* token_strs;
};

#endif