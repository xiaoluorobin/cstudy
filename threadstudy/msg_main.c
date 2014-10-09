#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>
void msg_show_attr(int msg_id,struct msqid_ds msg_info)
{
	int ret = -1;
	sleep(1);
	ret = msgctl(msg_id,IPC_STAT, &msg_info);
	if(-1 == ret)
	{
		printf("get msg fail, error is: %s\n",strerror(errno));
		return;
	}
	printf("\n");
	printf("queue bytes:%d\n",msg_info.msg_cbytes);

	printf("queue msg counts:%d\n",msg_info.msg_qnum);
	printf("queue max bytes:%d\n",msg_info.msg_qbytes);
	printf("last send msg pid:%d\n",msg_info.msg_lspid);
	printf("last rev msg pid:%d\n",msg_info.msg_lrpid);
	printf("last change date:%s\n",ctime(&(msg_info.msg_ctime)));

	printf("msg uid is :%d\n",msg_info.msg_perm.uid);
	printf("msg gid is:%d\n",msg_info.msg_perm.gid);
}

int main(void)
{
	int ret = -1;
	int msg_flags,msg_id;
	key_t key;
	struct msgmbuf{
		int mtype;
		char mtext[10];
	};
	struct msqid_ds msg_info;
	struct msgmbuf msg_mbuf;

	int msg_sflags,msg_rflags;
	char *msgpath = "./";
	key = ftok(msgpath,123);
	if(key != -1)
	{
		printf("key succ created key:%x\n",key);
	}
	else
	{
		printf("create key fail, eror is : %s \n",strerror(errno));
		return -1;
	}
	msg_flags = IPC_CREAT;
	msg_id = msgget(key, msg_flags|0x666);
	if(-1 == msg_id)
	{
		printf("msg create fail,code is %d,error is %s\n",errno,strerror(errno));
		return 0;
	}
	else{
		printf("msg create succ,msg_id is %d\n",msg_id);
		return 0;
	}

	msg_show_attr(msg_id,msg_info);


msg_rflags = IPC_NOWAIT|MSG_NOERROR;
ret = msgrcv(msg_id,&msg_mbuf,10,10,msg_rflags);
if( -1 == ret)
{
	printf("set msg attributes fail\n");
	return 0;
}
msg_show_attr(msg_id,msg_info);
ret = msgctl(msg_id, IPC_RMID,NULL);
if(-1 == ret)
{
	printf("del msg fail\n");
	return 0;
}
return 0;
}
