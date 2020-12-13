#ifndef _LISTEN_MODE_H_
#define _LISTEN_MODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/errno.h>

#define MAX_LISTEN 10

typedef void (* cb_listenEvent)(int epfd, struct epoll_event ev);
typedef struct
{
	int fd;				   //要监听的文件描述符
	cb_listenEvent cbFunc; //事件发生时的回调函数
} FD_EVENT_T;

typedef struct
{
	int epfd;  //epoll文件描述符
	int cnt;   //已添加的监听事件数量
	FD_EVENT_T event[MAX_LISTEN];
} EP_LISTEN_T;

extern int epollCreate(EP_LISTEN_T *fdEvent);
extern void epollDesrory(EP_LISTEN_T *fdEvent);
extern int epollAddEvent(EP_LISTEN_T *fdEvent, int listenFd, cb_listenEvent cbFunc);
extern void epollListenLoop(EP_LISTEN_T *fdEvent);

#endif