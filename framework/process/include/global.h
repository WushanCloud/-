#ifndef __GLOBAL_H__
#define __GLOBAL_H__

extern char** g_os_argv; // �����в�������ʼλ��
extern int g_envmemlen;  // ���������Ŀռ��С
extern char* g_envmem;   // ��������

void init_proctitle();
void set_proctitle(const char* name);

#endif // __GLOBAL_H__
