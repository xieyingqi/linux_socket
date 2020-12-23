#include "cmd_para_analy.h"

/**
 * @brief 解析命令行参数
 * @param cmdList 命令行参数列表
 * @param cmdCnt  命令行参数个数
 */
void analyCmdPara(int argc, char *argv[], CMD_PARA_T *cmdList, int cmdCnt)
{
	int i, c, paraIndex;
	struct option longOpts[cmdCnt + 1];

	/* 长参数列表赋值 */
	for (i = 0; i < cmdCnt; i++)
	{
		longOpts[i].name = cmdList[i].name;
		longOpts[i].has_arg = required_argument;
		longOpts[i].flag = 0;
		longOpts[i].val = 0;
	}
	memset(&longOpts[cmdCnt], 0, sizeof(struct option)); //最后的成员必须全为0

	while (-1 != (c = getopt_long(argc, argv, "", longOpts, &paraIndex)))
	{
		if (optarg != NULL)
		{
			if (cmdList[paraIndex].type == TYPE_INT)
			{
				*(int *)(cmdList[paraIndex].value) = atoi(optarg);
			}
			else
			{
				strcpy(cmdList[paraIndex].value, optarg);
			}
			
			
			//printf("%s value is %s\n", cmdList[paraIndex].name, cmdList[paraIndex].value);
		}
	}
}