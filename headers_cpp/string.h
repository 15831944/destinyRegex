/*******************************************************
 *	string.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):�ַ���
 ******************************************************/
#pragma once
#ifndef STRING_H
#define STRING_H

#include "includes.h"

class String {
public:
    char *str;
    int length;

    explicit String(int size) {
        this->length = size;
        this->str = new char[size + 1];
    }

public:
    String() {
        this->length = 0;
        this->str = new char[1];
        this->str[0] = '\0';
    }

    String(const String &js) {
        this->length = js.length;
        this->str = new char[js.length + 1];
        for (int i = 0; i < js.length; i++) {
            this->str[i] = js.str[i];
        }
        this->str[length] = '\0';
    }

    String &operator=(const String &js) {
        if (this == &js) {
            return *this;
        }
        this->length = js.length;
        if (this->str) {
            delete[] this->str;
        }
        this->str = new char[js.length + 1];
        for (int i = 0; i < js.length; i++) {
            this->str[i] = js.str[i];
        }
        this->str[length] = '\0';
        return *this;
    }

    //String(const string &js) {
    //    this->length = (int) js.size();
    //    this->str = new char[this->length + 1];
    //    for (int i = 0; i < this->length; i++) {
    //        this->str[i] = js[i];
    //    }
    //    this->str[length] = '\0';
    //}

    String(const char *js) {
        int size = 0;
        while (js[size] != '\0') {
            size++;
        }
        this->length = size;
        this->str = new char[this->length + 1];
        for (int i = 0; i < this->length; i++) {
            this->str[i] = js[i];
        }
        this->str[length] = '\0';
    }

    String(const char *js, int size) {
        this->length = size;
        this->str = new char[this->length + 1];
        for (int i = 0; i < this->length; i++) {
            this->str[i] = js[i];
        }
        this->str[length] = '\0';
    }

    ~String() {
        if (this->str) {
            delete[] this->str;
        }
    }

    inline char operator[](int index) const {
        return this->str[index];
    }

    inline char &operator[](int index) {
        return this->str[index];
    }

    /*���س���*/
    inline int size() const {
        return this->length;
    }

    /*���س���*/
    inline int get_length() const {
        return this->length;
    }

    /*�ַ�������*/
    String operator+(const String &j) const {
        String result(this->length + j.length);
        for (int i = 0; i < this->length; i++) {
            result.str[i] = this->str[i];
        }
        for (int k = 0; k < j.length; k++) {
            result.str[k + this->length] = j.str[k];
        }
        result.str[this->length + j.length] = '\0';
        return result;
    }

    ///*�ַ�������*/
    //String operator+(const string &j) const {
    //    int size = (int) j.size();
    //    String result(this->length + size);
    //    for (int i = 0; i < this->length; i++) {
    //        result.str[i] = this->str[i];
    //    }
    //    for (int k = 0; k < size; k++) {
    //        result.str[k + this->length] = j[k];
    //    }
    //    result.str[this->length + size] = '\0';
    //    return result;
    //}

    /*��β��׷���ַ�*/
    String operator+(const char &c) const {
        String result(this->length + 1);
        for (int i = 0; i < this->length; i++) {
            result.str[i] = this->str[i];
        }
        result.str[this->length] = c;
        result.str[this->length + 1] = '\0';
        return result;
    }

    /*�Ƿ�����*/
    bool is_num()const {
        int dot_num = 0;
        for (int i = 0; i < this->length; i++) {
            if (str[i] < 48 || str[i] > 57) {
                if (str[i] == '.') {
                    dot_num++;
                }
                else {
                    return false;
                }
            }
        }
        return dot_num <= 1;
    }

    /*�ַ�������*/
    void appand(const String &j) {
        String temp = *this;
        if (this->str) {
            delete[] this->str;
        }
        this->str = new char[this->length + j.length + 1];
        for (int i = 0; i < this->length; i++) {
            this->str[i] = temp.str[i];
        }
        for (int k = 0; k < j.length; k++) {
            this->str[k + this->length] = j.str[k];
        }
        this->str[this->length + j.length] = '\0';
        this->length = this->length + j.length;
    }

    /*��β������ַ�*/
    void appand(const char &c) {
        String temp = *this;
        if (this->str) {
            delete[] this->str;
        }
        this->str = new char[this->length + 2];
        for (int i = 0; i < this->length; i++) {
            this->str[i] = temp.str[i];
        }
        this->str[this->length] = c;
        this->str[this->length + 1] = '\0';
        this->length = this->length + 1;
    }

    /*��β������ַ�*/
    void operator+=(const char &c) {
        String temp = *this;
        if (this->str) {
            delete[] this->str;
        }
        this->str = new char[this->length + 2];
        for (int i = 0; i < this->length; i++) {
            this->str[i] = temp.str[i];
        }
        this->str[this->length] = c;
        this->str[this->length + 1] = '\0';
        this->length = this->length + 1;
    }

    /*�ַ�������*/
    void operator+=(const String &j) {
        String temp = *this;
        if (this->str) {
            delete[] this->str;
        }
        this->str = new char[this->length + j.length + 1];
        for (int i = 0; i < this->length; i++) {
            this->str[i] = temp.str[i];
        }
        for (int k = 0; k < j.length; k++) {
            this->str[k + this->length] = j.str[k];
        }
        this->str[this->length + j.length] = '\0';
        this->length = this->length + j.length;
    }

    ///*�ַ�������*/
    //void operator+=(const string &j) {
    //    int size = (int) j.size();
    //    String temp = *this;
    //    if (this->str) {
    //        delete[] this->str;
    //    }
    //    this->str = new char[this->length + size + 1];
    //    for (int i = 0; i < this->length; i++) {
    //        this->str[i] = temp.str[i];
    //    }
    //    for (int k = 0; k < size; k++) {
    //        this->str[k + this->length] = j[k];
    //    }
    //    this->str[this->length + size] = '\0';
    //    this->length = this->length + size;
    //}

    /*�ַ�����ȱȽ�*/
    bool operator==(const String &j) const {
        if (this->length != j.length) {
            return false;
        }
        for (int i = 0; i < this->length; i++) {
            if (this->str[i] != j.str[i]) {
                return false;
            }
        }
        return true;
    }

    /*�ַ������ȱȽ�*/
    inline bool operator!=(const String &j) const {
        return !this->operator==(j);
    }

    bool operator>(const String &str2) const {
        if (this->is_num() && str2.is_num()) {
            return atof(this->str) > atof(str2.str);
        }
        for (int i = 0; i < this->length; i++) {
            if (i < str2.length) {
                if (this->str[i] > str2.str[i]) {
                    return true;
                }
                else if (this->str[i] < str2.str[i]) {
                    return false;
                }
            }
            else {
                return true;
            }
        }
        return false;
    }

    inline bool operator>=(const String &str2) const {
        return this->operator==(str2) || this->operator>(str2);
    }

    inline bool operator<=(const String &str2) const {
        return !this->operator>(str2);
    }

    inline bool operator<(const String &str2) const {
        return !this->operator>=(str2);
    }

    /*������(��0����)pos����ȡ����Ϊlen���Ӵ�(����pos)*/
    String sub_str(int pos, int len) const {
        if (pos < 0 || pos + len > this->length || len < 0) {
            String result(0);
            result.str[0] = '\0';
            return result;
        }
        else {
            String result(len);
            for (int i = 0; i < len; i++) {
                result.str[i] = this->str[pos + i];
            }
            result.str[len] = '\0';
            return result;
        }
    }

    /*�����ַ�����*/
    const char *const c_str() const {
        return this->str;
    }

    /*���*/
    inline friend ostream &operator<<(ostream &os, const String &js) {
        return os << js.str;
    }

    inline int begin() const {
        return 0;
    }

    inline int end() const {
        return this->length - 1;
    }

    ///*�ַ�������*/
    //inline friend String operator+(const string &s, const String &js) {
    //    return String(s) + js;
    //}

    /*�����ַ�����λ��*/
    int index_of(const char &c) const {
        for (int i = 0; i < this->length; i++) {
            if (this->str[i] == c) {
                return i;
            }
        }
        return -1;
    }

    /*�Ƿ�����ַ�*/
    inline bool contains(const char &c) const {
        return this->index_of(c) > -1;
    }

    /*�Ƿ�����ַ���*/
    inline bool contains(const String &s) const {
        return this->index_of_KMP(s) > -1;
    }

    ///*�Ƿ�����ַ���*/
    //inline bool contains(const string &s) const {
    //    return this->index_of_KMP(s) > -1;
    //}

    /*����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ�������(��0��ʼ����)*/
    int index_of(const String &s) const {
        int size = s.size();
        for (int pos = 0; pos < this->length; pos++) {
            for (int i = 0; i < size; i++) {
                if (this->str[pos + i] != s[i]) {
                    continue;
                }
            }
            return pos;
        }
        return -1;
    }

protected:
    /*KMPʧ�ܺ���*/
    void function_fail_KMP(int *&next) const {
        int j = 0;
        int k = -1;
        next[0] = -1;
        while (j < this->length - 1) {
            if (k == -1 || this->str[k] == this->str[j]) {
                j++;
                k++;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
    }

public:
    /*�ַ���ƥ��KMP�㷨*/
    /*���������pos����ַ������� p,�򷵻�p��һ���ַ��ڴ��ַ����е�λ��*/
    int index_of_KMP(const String &p, const int pos = 0) const {
        if (p.length == 0 && pos < this->length) {
            return 0;
        }
        int *next = new int[p.length];
        p.function_fail_KMP(next);
        int i, j;
        for (i = pos, j = 0; i < this->length && j < p.length;) {
            if (this->str[i] == p.str[j]) {
                i++, j++;
            }
            else {
                if (next[j] == -1) {
                    i++, j = 0;
                }
                else {
                    j = next[j];
                }
            }
        }
        delete[] next;
        return p.str[j] == '\0' ? i - j : -1;
    }

    /*�ַ������滻*/
    void replace(char c, char newChar) {
        for (int i = 0; i < this->length; i++) {
            if (this->str[i] == c) {
                this->str[i] = newChar;
            }
        }
    }

    /*��ָ��λ��(index(��0��ʼ����))�Ƴ�ָ������(off)���ַ�*/
    String &remove_at(int index, int off = 1) {
        if (index < 0 || off < 0 || index + off > length) {
            return *this;
        }
        String temp(*this);
        if (this->str) {
            delete[] this->str;
        }
        this->str = new char[this->length - off + 1];
        for (int i = 0; i < index; i++) {
            this->str[i] = temp.str[i];
        }
        for (int j = index + off; j < length; j++) {
            this->str[j - off] = temp.str[j];
        }
        this->str[this->length - off] = '\0';
        this->length = this->length - off;
        return *this;
    }

    /*�Ƴ�ָ���ַ�*/
    String &remove(const char &c) {
        int index = this->index_of(c);
        if (index < 0) {
            return *this;
        }
        String temp(*this);
        if (this->str) {
            delete[] this->str;
        }
        this->str = new char[this->length];
        this->length--;
        for (int i = 0, j = 0; i <= this->length; i++) {
            if (i != index) {
                this->str[j++] = temp.str[i];
            }
        }
        this->str[this->length] = '\0';
        return *this;
    }
};
typedef String string;
#endif