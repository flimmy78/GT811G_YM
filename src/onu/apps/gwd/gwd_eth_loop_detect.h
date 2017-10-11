#ifndef __GWD_LOOP_DETECT_H__
#define __GWD_LOOP_DETECT_H__

#include "gwd_eth_loop_cfg.h"

#if 1
//�ⲿ�ɼ�

#ifndef GWD_IN
#define GWD_IN
#endif

#ifndef GWD_OUT
#define GWD_OUT
#endif

#ifndef GWD_IN_OUT
#define GWD_IN_OUT
#endif

typedef enum {
    GWD_E_OK               = 0,
    GWD_E_RESOURCE         = 1,
    GWD_E_PARAM            = 2,
    GWD_E_NOT_FOUND        = 3,
    GWD_E_CONFLICT         = 4,
    GWD_E_TIMEOUT          = 5,
    GWD_E_NOT_SUPPORT      = 6,
    GWD_E_ERROR            = 0xffffffff
} gwd_status;

typedef struct
{
	gw_uint8	enable;
	gw_uint16	vid;
	gw_uint8	smac[GWD_MACADDR_LEN];
	gw_uint16	interval;
	gw_uint16	policy;
	gw_uint16	waitforwakeup;
	gw_uint16	maxwakeup;
	gw_uint16	alarm_interval;			//�˿ڻ�·��ĸ澯���
	gw_uint16	clear_interval;			//ָ��������δ���ֻ�·�������·��Ϣ
	gw_uint16	opposite_aging_time;	//������·�Զ˵���Ϣ���ϻ�ʱ��
}__attribute__((packed))loop_control_config_t;

typedef enum {
    GWD_DOWN_STREAM     = 0x00,
    GWD_UP_STREAM       = 0x01,
} gwd_direction_t;

typedef enum {
    GWD_DST_FE   = 0,
    GWD_DST_DROP,
    GWD_DST_CPU,
} gwd_sdl_pkt_dst_t;

typedef gw_uint8 (*gwd_pkt_handler_t)(gw_uint8 *, gw_uint16, gwd_port_id_t);

typedef gwd_status (*gwd_pkt_parser_t)(gw_uint8 *, gw_uint16, gwd_port_id_t);

typedef struct
{
	gw_uint8	port_id;		//�˿ں�
	gw_uint8	slot_id;		//��λ��
	gw_uint8	onu_slot;		//onu ��λ��: onuע����olt�ϵ�pon���slot(based 1)
	gw_uint8	onu_pon;		//onu pon�ں�: onuע����olt�ϵ�pon���PON�˿ں�(based 1)
	gw_uint8	onu_llid;		//onu �߼���·��ʶ: onu ID��(based 1)
	gw_uint8	onu_type;		//ONU���ͣ���ʾ��·ONU�Ĳ�Ʒ����
	gw_uint8	onu_mac[GWD_MACADDR_LEN];		//ONU MAC����ʾ��·ONU��ϵͳMAC��ַ
	gw_uint8	olt_type;		//OLT���ͣ���ʾ��·ONU���ڵ�OLT���ͣ�1������GFA6100��2������GFA6700���Ժ������µ�OLT���Ϳ����������ӣ���Ϊ��չ
	gw_uint8	olt_mac[GWD_MACADDR_LEN];		//OLT MAC����ʾ��·ONU���ڵ�OLT MAC��ַ
}__attribute__((packed))loop_back_port_info_t;

//onu ��·��������
typedef struct
{
	gw_uint8	dest_mac[GWD_MACADDR_LEN];	//Ŀ��mac
	gw_uint8	src_mac[GWD_MACADDR_LEN];	//Դmac
	gw_uint16	tpid;						//tpid
	gw_uint16	vid;						//vlan id
	gw_uint16	eth_type;					//��̫������
	gw_uint16	loop_flag;					//��·��־
	gw_uint8	olt_type;					//olt ����
	gw_uint8	onu_type;					//onu ����
	gw_uint8	onu_location[4];			//
	gw_uint8	onu_mac[GWD_MACADDR_LEN];	//onu mac
	gw_uint16	onu_vid;					//onu vlan id
	gw_uint32	onu_if_index;				//
} __attribute__ ((packed)) gwd_loop_detect_frame_t;

typedef struct {
    gw_uint8       addr[GWD_MACADDR_LEN];
}__attribute__((packed)) gwd_mac_t;

typedef enum {
    GWD_SDL_PORT_ADMIN_DOWN = 0,  /* Admin down */
    GWD_SDL_PORT_ADMIN_UP   = 1,  /* Admin up   */
} gwd_sdl_port_admin_t;

typedef enum
{
	GWD_LOOP_OCCUR = 0,		/*������·*/
	GWD_LOOP_CNACEL,		/*�����·*/
}gwd_loop_status_t;

#endif	/*end of externally visible */

/*��·���Ʊ��ĸ�ʽ*/
/*begin:
added by wangxiaoyu 2008-05-05
���ز���OAM ��
*/
typedef struct Oam_Onu_Lpb_Detect_Frame{
	gw_uint8	type;		//�������ͣ�4��ʾΪ���ؼ��
	gw_uint8	result;		//���Խ������ONU�����
	gw_uint8	enable;		//�Ƿ�ʹ�ܹ��ܣ���OLT�����
	gw_uint16	vid;			//���в��Ե�VLAN, 0:ONU��������VLAN
	gw_uint8	smac[GWD_MACADDR_LEN];	//�����õ�ԴMAC
	gw_uint16	interval;		//OLT������֡�ļ��ʱ��s
	gw_uint16	policy;		//���򣬼��Ƿ�رն˿�
	/*added by wangxiaoyu 2009-03-11*/
	gw_uint16  waitforwakeup; //�ȴ����ѵ����ڣ�Ϊ��ѯ���ڵı���
	gw_uint16  maxwakeup;		//����������Դ���
}__attribute__((packed))OAM_ONU_LPB_DETECT_FRAME;
/*end*/

/*added by wangxiaoyu 2009-03-11*/
#define LPB_OLD_VER_LEN	(sizeof(OAM_ONU_LPB_DETECT_FRAME)-4)


/*��·��ⱨ�ĸ�ʽ*/
typedef struct
{
	gw_uint16	eth_type;					//��̫������
	gw_uint16	loop_flag;					//��·��־
	gw_uint8	olt_type;					//olt ����
	gw_uint8	onu_type;					//onu ����
	gw_uint8	onu_location[4];			//
	gw_uint8	onu_mac[GWD_MACADDR_LEN];	//onu mac
	gw_uint16	onu_vid;					//onu vlan id
	gw_uint32	onu_if_index;
}__attribute__ ((packed)) gwd_loop_detect_frame_data_t;

typedef union
{
    struct
    {
#if VOS_LITTLE_ENDIAN
        unsigned subif:12;
        unsigned port:6;
        unsigned slot:5;
        unsigned subcard:3;
        unsigned type:6;
#else
        unsigned type:6;
        unsigned subcard:3;
        unsigned slot:5;
        unsigned port:6;
        unsigned subif:12;
#endif
    }phy_slot_port;
    gw_uint32 ulPhyIfIndex;
} onu_if_index_t;


typedef enum
{
    GWD_SDL_VLAN_MODE_TRANSPARENT = 0,		/* transparent mode */
    GWD_SDL_VLAN_MODE_TAG,			        /* tag mode */
    GWD_SDL_VLAN_MODE_TRANSLATION,			/* translation mode, VLAN A <-> VLAN B */
    GWD_SDL_VLAN_MODE_AGGREGATION,			/* 1:N aggregation mode */
    GWD_SDL_VLAN_MODE_TRUNK,			    /* trunk mode */
    GWD_SDL_VLAN_MODE_STACKING,             /* zte stacking mode */
    GWD_SDL_VLAN_MODE_END
}gwd_sdl_vlan_mode_t;


#if 1
/*�����ṩ�Ľӿ�*/
void
loop_back_detect_init(
	void
	);
gwd_status
loop_back_control_pkt_proc(
	GWD_IN	gw_uint8	*pkt,
	GWD_IN	gw_uint16	len
	);

//���û�·����Ƿ�ʹ��
gwd_status
loop_back_detect_config_enable(
	GWD_IN	loop_control_config_t *config
	);

gwd_status
	loop_back_detect_config_get(
	GWD_OUT	loop_control_config_t *config
	);
#endif



#if 1
/*��Ҫʵ�ֵĽӿ�*/

//��·��ⱨ�ķ����Ŀ������
gwd_status
gwd_loop_detect_pkt_dst_set(
	GWD_IN	gwd_direction_t		gwd_direction,
	GWD_IN	gwd_sdl_pkt_dst_t	gwd_dst
);

//ע�ỷ·��ⱨ�Ĵ�����
gwd_status
gwd_loop_detect_pkt_handler_reg(
	GWD_IN	gwd_pkt_handler_t handler
);

//ע�ỷ·��ⱨ�Ľ�������
gwd_status
gwd_loop_detect_pkt_parser_reg(
	GWD_IN	gwd_pkt_parser_t parser
);


//��·�澯
gwd_status
gwd_loop_back_alarm(
	GWD_IN	gw_uint16				vlan_id,
	GWD_IN	loop_back_port_info_t	*port_infor,
	GWD_IN	loop_back_port_info_t	*extern_port_infor,
	GWD_IN	gwd_loop_status_t		loop_status
	);

//������·����߳�
gwd_status
gwd_loop_detect_thread_create(
	GWD_IN	void *gwd_loop_detect_task
);

//ɾ����·����߳�
gwd_status
gwd_loop_detect_thread_delete(
	void
);

//�߳���ʱ���Ժ���Ϊ��λ
gwd_status
gwd_thread_delay(
	GWD_IN	gw_uint32	milli_second
);

//��ȡ�˿ڵ�����vlan ������default vlan
gwd_status
gwd_onu_port_vlan_get(
	GWD_IN	gwd_port_id_t		port_id,
	GWD_OUT	gwd_sdl_vlan_mode_t *vlan_mode,
	GWD_OUT	gw_uint16			*vlan_def,
	GWD_OUT	gw_uint16			*vlan,
	GWD_OUT	gw_uint16			*vlan_num
);

//��ȡ�˿�����
gwd_status gwd_uni_port_num_get(
	GWD_IN	int		*num
	);

//���ͻ�·���Ա���
gwd_status
loop_back_detect_pkt_send(
	GWD_IN	gwd_port_id_t				port_id,
	GWD_IN	gwd_loop_detect_frame_t		*frame
	);

//��ȡfdb ����ָ���˿�ѧϰ���ض�mac ��vlan
gwd_status
gwd_fdb_port_mac_get_vlan(
	GWD_IN	gwd_port_id_t	port_id,
	GWD_IN	gwd_mac_t		mac,
	GWD_OUT	gw_uint16		*vlan,
	GWD_OUT	gw_uint16		*vlan_num
);

//�����ڴ�
void *
gwd_malloc(
	GWD_IN	gw_uint32	size
	);

//�ͷ��ڴ�
void
gwd_free(
	GWD_IN	void 	*ptr
	);

//���ö˿ڵ�ʹ��״̬
gwd_status
gwd_port_admin_set(
	GWD_IN	gwd_port_id_t			port_id,
	GWD_IN	gwd_sdl_port_admin_t	admin
	);

//��ȡ�˿ڵ�ʹ��״̬
gwd_status
gwd_port_admin_get(
	GWD_IN	gwd_port_id_t			port_id,
	GWD_OUT	gwd_sdl_port_admin_t	*admin
	);

//��ȡonu mac
gwd_status
gwd_onu_mac_get(
	GWD_OUT	gwd_mac_t	*onu_mac
);

//��ȡ�߼���·��ʶ
gwd_status
gwd_mpcp_llid_get(
	GWD_OUT	gw_uint16 *gwd_llid
);

//��ȡolt mac
gwd_status
gwd_olt_mac_get(
	GWD_OUT	gwd_mac_t *olt_mac
	);

//��ȡolt ����
gwd_status
gwd_olt_type_get(
	GWD_OUT	gwd_olt_type_t	*olt_type
	);

//��ȡpon ���ڵĲ�λ�źͶ˿ں�
gwd_status
gwd_pon_slot_port_get(
	GWD_OUT	gw_uint32	*pon_slot,
	GWD_OUT	gw_uint32	*pon_port
	);

//��ȡonu ��Ʒid
gw_uint8
gwd_onu_product_id_get(
	void
	);

gwd_status
loop_back_led_proc(
	GWD_IN	gwd_loop_status_t	loop_status
	);

void
loop_back_status_list_lock_init(
	void
	);

void
loop_back_status_list_lock(
	void
	);

void
loop_back_status_list_unlock(
	void
	);

extern void gw_lst_init(gw_list * pLst , gw_int32 (*compare)(void * , gw_uint32));

extern void gw_lst_insert(gw_list * pLst, gw_node * pPrevious, gw_node * pNode);

extern void gw_lst_add(gw_list * pLst, gw_node * pNode);

gw_node *gw_lst_remove(gw_list * pLst , gw_uint32 key);

extern void gw_lst_delete(gw_list * pLst, gw_node * pNode);

extern gw_node * gw_lst_first(gw_list * pLst);

extern gw_node * gw_lst_last(gw_list * pLst);

extern gw_node * gw_lst_get(gw_list * pLst);

extern gw_node * gw_lst_nth(gw_list * pLst, int nodeNum);

gw_node *gw_lst_find(gw_list *pLst , gw_uint32 key);

extern gw_node * gw_lst_prev(gw_node * pNode);

extern gw_node * gw_lst_next(gw_node * pNode);

extern gw_uint32 gw_lst_count(gw_list * pLst);

extern gw_list *gw_lst_concat(gw_list *pDst , gw_list *pSrc);

#define gw_lst_scan(pList , pNode , type) for(pNode=(type)gw_lst_first(pList);pNode;pNode=(type)gw_lst_next((gw_node *)pNode))

#endif

#endif /*end of file*/

