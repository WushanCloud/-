#ifndef __MYSIGNAL_H__
#define __MYSIGNAL_H__
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// �źŽṹ��
typedef struct {
	int signo;             // �źŵ�ֵ SIGINT
	char* signame;         // �źŵ�����"SIGINT"
	char* name;            // ���������
	void  (*handler)(int signo, siginfo_t* info, void* ucontext); // �źŴ����� 
}signal_t;


void  sig_handler(int signo, siginfo_t* info, void* ucontext);


int init_signal();
#endif // __MYSIGNAL_H__
