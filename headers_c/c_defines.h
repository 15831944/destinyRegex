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
#define RETURN_ 'r' //��Ҫת��
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

enum auto_machine_ident {
	left_large_brace = '{',
	right_large_brace = '}',
	left_mid_bracket = '[',
	right_mid_bracket = ']',
	left_bracket = '(',
	right_bracket = ')',
	change_letter = '\\', //˫б��ת��
	tab = 't',//��Ҫת��
	return_ = 'r',//��Ҫת��
	new_line = 'n', //��Ҫת��
	blank = ' ',//�ո�
	comma = ',', //����
	dot = '.',//ͨ���
	multi_match_letter = '*', //���ƥ���
	ques = '?',//0��1��
	plus = '+',//һ������
	decimal = 'd',//һ��ʮ��������,��Ҫת��
	lower_letter = 'l', //һ��Сд��ĸ,��Ҫת��
	space = 's',//һ���հ׷����ո�����Ʊ���ȣ�,��Ҫת��
	uper_letter = 'u',//һ����д��ĸ,��Ҫת��
	simple_letter = 'w', //һ����ĸ��a��z��A��Z�������֣�0��9�����»��ߣ�_��,��Ҫת��
	not_decimal = 'D',//����\d֮����ַ�,��Ҫת��
	not_lower_letter = 'L', //����\l֮����ַ�,��Ҫת��
	not_space = 'S',//����\s֮����ַ�,��Ҫת��
	not_uper_letter = 'U',//����\u֮����ַ�,��Ҫת��
	not_simple_letter = 'W', //����\w֮����ַ�,��Ҫת��
	range_letter = '-' //��Χ��ʾ��
};

/*list for chars*/
struct list_char {
	char value;
	struct list_char *next;
};

/*����list_char*/
inline struct list_char* construct_char(char c) {
	struct list_char* list = (struct list_char*)malloc(sizeof(struct list_char));
	list->value = c;
	list->next = NULL;
	return list;
}

/*������ʽ��һƥ�䵥Ԫ*/
struct single_condition {
	struct list_char* match_letters;
	struct single_condition* next;
	unsigned int least_match_time;//����ƥ�����
	unsigned int max_match_time;//���ƥ�����
};

/*����single_condition*/
inline struct single_condition* construct_s_condition(struct list_char* list, int l_m_time, int m_m_time) {
	struct single_condition* con = (struct single_condition*)malloc(sizeof(struct single_condition));
	con->match_letters = list;
	con->least_match_time = l_m_time;
	con->max_match_time = m_m_time;
	con->next = NULL;
	return con;
}

/*������ʽƥ�䵥Ԫ*/
struct condition {
	struct single_condition* single_conditions;
	struct condition* next;
};

/*����condition*/
inline struct condition* construct_condition(struct single_condition* s_con) {
	struct condition* con = (struct condition*)malloc(sizeof(struct condition));
	con->single_conditions = s_con;
	con->next = NULL;
	return con;
}

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
	int str_len;
	struct condition* conditions;
	struct match_iterator* match_strs;
	struct regex_token_iterator* token_strs;
};

/*����regex*/
inline struct regex* construct_regex(const char* str) {
	struct regex* reg = (struct regex*)malloc(sizeof(struct regex));
	reg->conditions = NULL;
	reg->str = str;
	reg->str_len = 0;
	reg->match_strs = NULL;
	reg->token_strs = NULL;
	return reg;
}

#endif