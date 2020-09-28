#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/global.h"

extern char** environ;

/*
* ���ý�������ء�
*/

//  �������������
void init_proctitle() {
	int i;

	// ������������Ĵ�С
	for (i = 0; environ[i] != NULL; i++) {
		g_envmemlen += strlen(environ[i]) + 1;
	}

	// ��������������ռ�
	g_envmem = malloc(sizeof(char) * g_envmemlen);
	memset(g_envmem, 0x00, g_envmemlen);

	char* tmp = g_envmem;
	for (i = 0; environ[i] != NULL; i++) {
		int len = strlen(environ[i]) + 1;
		strcpy(tmp, environ[i]);
		environ[i] = tmp; // ���������ᵽ�µ�λ�ã�environҲҪ���µ���λ��
		tmp += len;
	}
}

// ���ý��̱���
void set_proctitle(const char* name) {
	// ���ⳤ��
	int title_len = strlen(name);
	int arg_len = 0;
	int i;

	// ��������в����ռ�Ĵ�С
	for (i = 0; g_os_argv[i] != NULL; i++) {
		arg_len += strlen(g_os_argv[i]) + 1;
	}

	// ����̫�����Ų���
	if (arg_len + g_envmemlen < title_len)
		return;

	g_os_argv[1] = NULL;
	char* tmp = g_os_argv[0];

	// �����±���
	strcpy(tmp, name);

	// ��������е�λ������
	tmp += title_len;
	memset(tmp, 0x00, (arg_len + g_envmemlen) - title_len);
}
