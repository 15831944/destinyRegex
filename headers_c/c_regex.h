/*******************************************************
 *	c_regex.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):�ַ���
 ******************************************************/
#pragma once
 /*C������ʽ*/
#ifndef DESTINY_REGEX
#define DESTINY_REGEX

#include "c_regex_auto_machine.h"


//����������ʽ
bool compile(struct regex *reg) {
	int len = 0;
	while (reg->str[len] != '\0') {
		len++;
	}
	reg->str_len = len;
	reg->match_strs = NULL;
	reg->token_strs = NULL;
	reg->conditions = NULL;
	return init(reg, 0, len - 1, -1);
}

//������ʽƥ��list_char
bool char_list_match(const char* str, int start_index, int end_index, struct list_char* list) {
	for (int i = start_index; i <= end_index; i++) {
		struct list_char* li = list;
		bool b = false;
		while (li) {
			if (li->value == str[i]) {
				b = true;
				break;
			}
			li = li->next;
		}
		if (!b) {
			return false;
		}
	}
	return true;
}

/*������ʽƥ��single_condition*/
bool s_condition_match(const char* str, int start_index, int end_index, struct single_condition* s_con) {
	for (int i = s_con->least_match_time; i <= (int)s_con->max_match_time; i++) {
		if (start_index + i - 1 > end_index) {
			return false;
		}
		if (char_list_match(str, start_index, start_index + i - 1, s_con->match_letters)) {
			if (s_con->next == NULL) {
				if (start_index + i - 1 == end_index) {
					return true;
				}
				continue;
			}
			if (s_condition_match(str, start_index + i, end_index, s_con->next)) {
				return true;
			}
		}
	}
	return false;
}

//������ʽƥ��condition
inline bool condition_match(const char* str, int start_index, int end_index, struct condition* con) {
	return s_condition_match(str, start_index, end_index, con->single_conditions);
}

//TODO:������ʽ�и��ַ���
bool regex_splite(const char* str, struct regex* reg) {
	return false;
}

//������ʽƥ��
bool regex_match(const char* str, struct regex* reg) {
	if (!reg || strlen(reg->str) < 1) {
		error_str = "������ʽ����Ϊ��!";
		return false;
	}
	if (!compile(reg)) {
		return false;
	}
	struct condition* con = reg->conditions;
	while (con) {
		if (condition_match(str, 0, strlen(str) - 1, con)) {
			return true;
		}
		con = con->next;
	}
	return false;
}

/*�õ�������ʽ���ƥ�䳤��*/
int get_regex_least_length(struct regex* reg) {
	int least_len = MAX_INT_VAL;
	int len;
	struct condition* con = reg->conditions;
	while (con) {
		len = 0;
		struct single_condition* s_con = con->single_conditions;
		while (s_con) {
			len += s_con->least_match_time;
			s_con = s_con->next;
		}
		if (len < least_len) {
			least_len = len;
		}
		con = con->next;
	}
	return least_len;
}

/*�õ�������ʽ�ƥ�䳤��*/
int get_regex_max_length(struct regex* reg) {
	int max_len = 0;
	int len;
	struct condition* con = reg->conditions;
	while (con) {
		len = 0;
		struct single_condition* s_con = con->single_conditions;
		while (s_con) {
			len += s_con->max_match_time;
			s_con = s_con->next;
		}
		if (len > max_len) {
			max_len = len;
		}
		con = con->next;
	}
	return max_len;
}

//������ʽ��Ѱƥ��
bool regex_search(const char* str, struct regex *reg) {
	if (!reg || strlen(reg->str) < 1) {
		error_str = "������ʽ����Ϊ��!";
		return false;
	}
	if (!compile(reg)) {
		return false;
	}
	int len = strlen(str);
	int least = get_regex_least_length(reg);
	int max = get_regex_max_length(reg);
	for (int start_index = 0; start_index < len; start_index++) {
		int least_index = start_index + least - 1;
		int max_index = start_index + max;
		for (int end_index = least_index; end_index < len && end_index < max_index; end_index++) {
			struct condition* con = reg->conditions;
			while (con) {
				if (condition_match(str, start_index, end_index, con)) {
					return true;
				}
				con = con->next;
			}
		}
	}
	return false;
}

#endif