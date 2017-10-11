#ifndef __GWD_LOOP_CFG_H__
#define __GWD_LOOP_CFG_H__

#include "app_oam_gwd.h"
#include <string.h>
#include "sdl_vlan.h"
#include "sdl.h"
#include "gwd_types.h"
#if 1
//�ⲿ����
//#define TEST	1	//��ӡ���Կ���

#define	VOS_LITTLE_ENDIAN 1

#define CPU_PKT_TO_SPECIFIC_UNI_PORT	1	// 1:оƬ֧����ָ����uni �ڷ��ͱ���; 0:��֧��

//mac ��ַ����
#define GWD_MACADDR_LEN	CS_MACADDR_LEN

//uni ������
#define GWD_UNI_PORT_NUM	UNI_PORT_MAX

//�����˿ڵ����vlan��(����Ĭ��vlan)
#define PER_PORT_MAX_VLAN	(__VLAN_RULE_PER_PORT_MAX+1)	//�˿ڵ�����vlan ����������default vlan

//��·���Ա��ı�ʶ
#define GWD_ETH_TYPE_LOOP_DETECT (0x0800)
#define GWD_LOOP_DETECT_CHECK (0x0080)

//���Դ�ӡ����
#define gwd_printf cs_printf


typedef int gwd_olt_type_t;

typedef cs_port_id_t gwd_port_id_t;

typedef cs_node gw_node;

typedef cs_list gw_list;



#endif	/*end of extern config*/


#endif	/*end of file*/


