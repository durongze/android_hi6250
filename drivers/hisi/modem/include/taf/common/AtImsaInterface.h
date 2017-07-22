

#ifndef  AT_IMSA_INTERFACE_H
#define  AT_IMSA_INTERFACE_H

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "vos.h"
#include "TafTypeDef.h"

#include "TafApsApi.h"
#include "AtMnInterface.h"
#include "MnCallApi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

#define AT_IMSA_IMPU_MAX_LENGTH        (128)
#define AT_IMSA_IMPI_MAX_LENGTH        (128)
#define AT_IMSA_DOMAIN_MAX_LENGTH      (128)


/* equals IMSA_MAX_CALL_NUMBER_LENGTH */
#define AT_IMSA_CALL_ASCII_NUM_MAX_LENGTH     (40)

#define IMSA_PHONECONTEXT_MAX_LENGTH     (128)

#define IMSA_PUBLICEUSERID_MAX_LENGTH    (128)
#define AT_IMSA_IPV4_ADDR_LEN              (4)

#define AT_IMSA_IPV6_ADDR_LEN              (16)


#define IMSA_IMS_STRING_LENGTH           (128)
#define AT_IMSA_MAX_SMSPSI_LEN           (128)

#define IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN      (0x0100)

/* 当前ims注册失败网侧上报最大字符串长度为255 */
#define IMSA_AT_REG_FAIL_CAUSE_STR_MAX_LEN              (256)
/*****************************************************************************
  2 枚举定义
*****************************************************************************/
/*****************************************************************************
枚举名    : AT_IMSA_MSG_TYPE_ENUM
结构说明  : AT 和IMSA的之间的消息

  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 定义AT和IMSA之间的接口消息
*****************************************************************************/
enum AT_IMSA_MSG_TYPE_ENUM
{
    /* AT->IMSA */
    ID_AT_IMSA_CIREG_SET_REQ                = 0x0001,                           /* _H2ASN_MsgChoice AT_IMSA_CIREG_SET_REQ_STRU */
    ID_AT_IMSA_CIREG_QRY_REQ                = 0x0002,                           /* _H2ASN_MsgChoice AT_IMSA_CIREG_QRY_REQ_STRU */
    ID_AT_IMSA_CIREP_SET_REQ                = 0x0003,                           /* _H2ASN_MsgChoice AT_IMSA_CIREP_SET_REQ_STRU */
    ID_AT_IMSA_CIREP_QRY_REQ                = 0x0004,                           /* _H2ASN_MsgChoice AT_IMSA_CIREP_QRY_REQ_STRU */
    ID_AT_IMSA_VOLTEIMPU_QRY_REQ            = 0x0005,                           /* _H2ASN_MsgChoice AT_IMSA_VOLTEIMPU_QRY_REQ_STRU */



    ID_AT_IMSA_IMS_REG_DOMAIN_QRY_REQ       = 0x0006,                           /* _H2ASN_MsgChoice AT_IMSA_IMS_REG_DOMAIN_QRY_REQ_STRU */
    ID_AT_IMSA_IMS_CTRL_MSG                 = 0x0007,                           /* _H2ASN_MsgChoice AT_IMSA_IMS_CTRL_MSG_STRU */

    ID_AT_IMSA_CALL_ENCRYPT_SET_REQ         = 0x0008,                           /* _H2ASN_MsgChoice AT_IMSA_CALL_ENCRYPT_SET_REQ_STRU */

    ID_AT_IMSA_ROAMING_IMS_QRY_REQ          = 0x0009,                           /* _H2ASN_MsgChoice AT_IMSA_ROAMING_IMS_QRY_REQ_STRU */

    ID_AT_IMSA_PCSCF_SET_REQ                = 0x000A,                           /* _H2ASN_MsgChoice AT_IMSA_PCSCF_SET_REQ_STRU */
    ID_AT_IMSA_PCSCF_QRY_REQ                = 0x000B,                           /* _H2ASN_MsgChoice AT_IMSA_PCSCF_QRY_REQ_STRU */
    ID_AT_IMSA_DMDYN_SET_REQ                = 0x000C,                           /* _H2ASN_MsgChoice AT_IMSA_DMDYN_SET_REQ_STRU */
    ID_AT_IMSA_DMDYN_QRY_REQ                = 0x000D,                           /* _H2ASN_MsgChoice AT_IMSA_DMDYN_QRY_REQ_STRU */

    ID_AT_IMSA_IMSTIMER_SET_REQ             = 0x000E,                           /* _H2ASN_MsgChoice AT_IMSA_IMSTIMER_SET_REQ_STRU */
    ID_AT_IMSA_IMSTIMER_QRY_REQ             = 0x000F,                           /* _H2ASN_MsgChoice AT_IMSA_IMSTIMER_QRY_REQ_STRU */
    ID_AT_IMSA_SMSPSI_SET_REQ               = 0x0010,                           /* _H2ASN_MsgChoice AT_IMSA_SMSPSI_SET_REQ_STRU */
    ID_AT_IMSA_SMSPSI_QRY_REQ               = 0x0011,                           /* _H2ASN_MsgChoice AT_IMSA_SMSPSI_QRY_REQ_STRU */
    ID_AT_IMSA_DMUSER_QRY_REQ               = 0x0012,

    ID_AT_IMSA_NICKNAME_SET_REQ             = 0x0013,                           /* _H2ASN_MsgChoice AT_IMSA_NICKNAME_SET_REQ_STRU */
    ID_AT_IMSA_NICKNAME_QRY_REQ             = 0x0014,                           /* _H2ASN_MsgChoice AT_IMSA_NICKNAME_QRY_REQ_STRU */
    ID_AT_IMSA_BATTERYINFO_SET_REQ          = 0x0015,                           /* _H2ASN_MsgChoice AT_IMSA_BATTERY_INFO_SET_REQ_STRU */
    ID_AT_IMSA_VOLTEREG_NTF                 = 0x0016,                           /* _H2ASN_MsgChoice AT_IMSA_VOLTEREG_NTF_STRU */

    ID_AT_IMSA_CANCEL_ADD_VIDEO_REQ         = 0x0017,                           /* _H2ASN_MsgChoice AT_IMSA_CANCEL_ADD_VIDEO_REQ_STRU */

    ID_AT_IMSA_VOLTEIMPI_QRY_REQ            = 0x0018,                                               /* _H2ASN_MsgChoice AT_IMSA_VOLTEIMPI_QRY_REQ_STRU */
    ID_AT_IMSA_VOLTEDOMAIN_QRY_REQ          = 0x0019,                                             /* _H2ASN_MsgChoice AT_IMSA_VOLTEDOMAIN_QRY_REQ_STRU */
    ID_AT_IMSA_REGERR_REPORT_SET_REQ        = 0x001A,                           /* _H2ASN_MsgChoice AT_IMSA_REGERR_REPORT_SET_REQ_STRU*/
    ID_AT_IMSA_REGERR_REPORT_QRY_REQ        = 0x001B,                           /* _H2ASN_MsgChoice AT_IMSA_REGERR_REPORT_QRY_REQ_STRU*/


    /* IMSA->AT */
    ID_IMSA_AT_CIREG_SET_CNF                = 0x1001,                           /* _H2ASN_MsgChoice IMSA_AT_CIREG_SET_CNF_STRU */
    ID_IMSA_AT_CIREG_QRY_CNF                = 0x1002,                           /* _H2ASN_MsgChoice IMSA_AT_CIREG_QRY_CNF_STRU */
    ID_IMSA_AT_CIREP_SET_CNF                = 0x1003,                           /* _H2ASN_MsgChoice IMSA_AT_CIREP_SET_CNF_STRU */
    ID_IMSA_AT_CIREP_QRY_CNF                = 0x1004,                           /* _H2ASN_MsgChoice IMSA_AT_CIREP_QRY_CNF_STRU */

    ID_IMSA_AT_VOLTEIMPU_QRY_CNF            = 0x1005,                           /* _H2ASN_MsgChoice IMSA_AT_VOLTEIMPU_QRY_CNF_STRU */




    ID_IMSA_AT_CIREGU_IND                   = 0x1006,                           /* _H2ASN_MsgChoice IMSA_AT_CIREGU_IND_STRU */
    ID_IMSA_AT_CIREPH_IND                   = 0x1007,                           /* _H2ASN_MsgChoice IMSA_AT_CIREPH_IND_STRU */
    ID_IMSA_AT_CIREPI_IND                   = 0x1008,                           /* _H2ASN_MsgChoice IMSA_AT_CIREPI_IND_STRU */

    ID_IMSA_AT_VT_PDP_ACTIVATE_IND          = 0x1009,                           /* _H2ASN_MsgChoice IMSA_AT_VT_PDP_ACTIVATE_IND_STRU */
    ID_IMSA_AT_VT_PDP_DEACTIVATE_IND        = 0x100A,                           /* _H2ASN_MsgChoice IMSA_AT_VT_PDP_DEACTIVATE_IND_STRU */

    ID_IMSA_AT_MT_STATES_IND                = 0x100B,                           /* _H2ASN_MsgChoice IMSA_AT_MT_STATES_IND_STRU */

    ID_IMSA_AT_IMS_REG_DOMAIN_QRY_CNF       = 0x100C,                           /* _H2ASN_MsgChoice IMSA_AT_IMS_REG_DOMAIN_QRY_CNF_STRU */
    ID_IMSA_AT_IMS_CTRL_MSG                 = 0x100D,                           /* _H2ASN_MsgChoice IMSA_AT_IMS_CTRL_MSG_STRU */

    ID_IMSA_AT_CALL_ENCRYPT_SET_CNF         = 0x100E,                           /* _H2ASN_MsgChoice IMSA_AT_CALL_ENCRYPT_SET_CNF_STRU */

    ID_IMSA_AT_ROAMING_IMS_QRY_CNF          = 0x100F,                           /* _H2ASN_MsgChoice IMSA_AT_ROAMING_IMS_QRY_CNF_STRU */

    ID_IMSA_AT_IMS_RAT_HANDOVER_IND         = 0x1010,                           /* _H2ASN_MsgChoice IMSA_AT_IMS_RAT_HANDOVER_IND_STRU */
    ID_IMSA_AT_IMS_SRV_STATUS_UPDATE_IND    = 0x1011,                           /* _H2ASN_MsgChoice IMSA_AT_IMS_SRV_STATUS_UPDATE_IND_STRU */

    ID_IMSA_AT_PCSCF_SET_CNF                = 0x1012,                           /* _H2ASN_MsgChoice IMSA_AT_PCSCF_SET_CNF_STRU */
    ID_IMSA_AT_PCSCF_QRY_CNF                = 0x1013,                           /* _H2ASN_MsgChoice IMSA_AT_PCSCF_QRY_CNF_STRU */

    ID_IMSA_AT_DMDYN_SET_CNF                = 0x1014,                           /* _H2ASN_MsgChoice IMSA_AT_DMDYN_SET_CNF_STRU */
    ID_IMSA_AT_DMDYN_QRY_CNF                = 0x1015,                           /* _H2ASN_MsgChoice IMSA_AT_DMDYN_QRY_CNF_STRU */

    ID_IMSA_AT_DMCN_IND                     = 0x1016,                           /* _H2ASN_MsgChoice IMSA_AT_DMCN_IND_STRU */

    ID_IMSA_AT_IMSTIMER_SET_CNF             = 0x1017,                           /* _H2ASN_MsgChoice IMSA_AT_IMSTIMER_SET_CNF_STRU*/
    ID_IMSA_AT_IMSTIMER_QRY_CNF             = 0x1018,                           /* _H2ASN_MsgChoice IMSA_AT_IMSTIMER_QRY_CNF_STRU*/
    ID_IMSA_AT_SMSPSI_SET_CNF               = 0x1019,                           /* _H2ASN_MsgChoice IMSA_AT_SMSPSI_SET_CNF_STRU*/
    ID_IMSA_AT_SMSPSI_QRY_CNF               = 0x101A,                           /* _H2ASN_MsgChoice IMSA_AT_SMSPSI_SET_CNF_STRU*/
    ID_IMSA_AT_DMUSER_QRY_CNF               = 0x101B,

    ID_IMSA_AT_NICKNAME_SET_CNF             = 0x101C,                           /* _H2ASN_MsgChoice IMSA_AT_NICKNAME_SET_CNF_STRU */
    ID_IMSA_AT_NICKNAME_QRY_CNF             = 0x101D,                           /* _H2ASN_MsgChoice IMSA_AT_NICKNAME_QRY_CNF_STRU */
    ID_IMSA_AT_REGFAIL_IND                  = 0x101E,                           /* _H2ASN_MsgChoice IMSA_AT_REG_FAIL_IND_STRU */
    ID_IMSA_AT_BATTERYINFO_SET_CNF          = 0x101F,                           /* _H2ASN_MsgChoice IMSA_AT_BATTERY_INFO_SET_CNF_STRU */

    ID_IMSA_AT_CANCEL_ADD_VIDEO_CNF         = 0x1020,                           /* _H2ASN_MsgChoice IMSA_AT_CANCEL_ADD_VIDEO_CNF_STRU */

    ID_IMSA_AT_VOLTEIMPI_QRY_CNF            = 0x1021,                           /* _H2ASN_MsgChoice IMSA_AT_VOLTEIMPI_QRY_CNF_STRU */
    ID_IMSA_AT_VOLTEDOMAIN_QRY_CNF          = 0x1022,                           /* _H2ASN_MsgChoice IMSA_AT_VOLTEDOMAIN_QRY_CNF_STRU */
    ID_IMSA_AT_REGERR_REPORT_SET_CNF        = 0x1023,                           /* _H2ASN_MsgChoice IMSA_AT_REGERR_REPORT_SET_CNF_STRU*/
    ID_IMSA_AT_REGERR_REPORT_QRY_CNF        = 0x1024,                           /* _H2ASN_MsgChoice IMSA_AT_REGERR_REPORT_QRY_CNF_STRU*/
    ID_IMSA_AT_REGERR_REPORT_IND            = 0x1025,                           /* _H2ASN_MsgChoice IMSA_AT_REGERR_REPORT_IND_STRU */

    ID_AT_IMSA_MSG_BUTT
};
typedef  VOS_UINT32  AT_IMSA_MSG_TYPE_ENUM_UINT32;


/*****************************************************************************
枚举名    : AT_IMSA_IMS_REG_STATE_REPORT_ENUM
结构说明  : IMS注册状态上报控制

  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增枚举
*****************************************************************************/
enum AT_IMSA_IMS_REG_STATE_REPORT_ENUM
{
    AT_IMSA_IMS_REG_STATE_DISABLE_REPORT        = 0,
    AT_IMSA_IMS_REG_STATE_ENABLE_REPORT,
    AT_IMSA_IMS_REG_STATE_ENABLE_EXTENDED_REPROT,

    AT_IMSA_IMS_REG_STATE_REPROT_BUTT
};
typedef  VOS_UINT32  AT_IMSA_IMS_REG_STATE_REPORT_ENUM_UINT32;

/*****************************************************************************
枚举名    : AT_IMSA_CCWAI_MODE_ENUM
结构说明  : 网络是否支持IMSVOPS

  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增枚举
*****************************************************************************/
enum AT_IMSA_CCWAI_MODE_ENUM
{
    AT_IMSA_CCWAI_MODE_DISABLE               = 0,
    AT_IMSA_CCWAI_MODE_ENABLE,

    AT_IMSA_CCWAI_MODE_BUTT
};
typedef  VOS_UINT8 AT_IMSA_CCWAI_MODE_ENUM_UINT8;


/*****************************************************************************
枚举名    : AT_IMSA_IMSVOPS_CAPABILITY_ENUM
结构说明  : 网络是否支持IMSVOPS

  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增枚举
*****************************************************************************/
enum AT_IMSA_IMSVOPS_CAPABILITY_ENUM
{
    AT_IMSA_NW_NOT_SUPORT_IMSVOPS               = 0,
    AT_IMSA_NW_SUPORT_IMSVOPS,

    AT_IMSA_IMSVOPS_CAPABILITY_BUTT
};
typedef  VOS_UINT32  AT_IMSA_IMSVOPS_CAPABILITY_ENUM_UINT32;


/*****************************************************************************
枚举名    : AT_IMSA_CIREP_REPORT_ENUM
结构说明  : 是否允许CIREPH和CIREPI主动上报

  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增枚举
*****************************************************************************/
enum AT_IMSA_CIREP_REPORT_ENUM
{
    AT_IMSA_CIREP_REPORT_DISENABLE      = 0,
    AT_IMSA_CIREP_REPORT_ENABLE,

    AT_IMSA_CIREP_REPORT_BUTT
};
typedef  VOS_UINT32  AT_IMSA_CIREP_REPORT_ENUM_UINT32;


/*****************************************************************************
枚举名    : AT_IMSA_SRVCC_HANDVOER_ENUM
结构说明  : SRVCC过程状态

  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增枚举
*****************************************************************************/
enum AT_IMSA_SRVCC_HANDVOER_ENUM
{
    AT_IMSA_SRVCC_HANDOVER_STARTED                = 0,
    AT_IMSA_SRVCC_HANDOVER_SUCCESS,
    AT_IMSA_SRVCC_HANDOVER_CANCEL,
    AT_IMSA_SRVCC_HANDOVER_FAILURE,

    AT_IMSA_SRVCC_HANDOVER_BUTT
};
typedef  VOS_UINT32  AT_IMSA_SRVCC_HANDVOER_ENUM_UINT32;

/*****************************************************************************
枚举名    : AT_IMSA_BATTERY_STATUS_ENUM
结构说明  : 电池电量状态

  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增枚举
*****************************************************************************/
enum AT_IMSA_BATTERY_STATUS_ENUM
{
    AT_IMSA_BATTERY_STATUS_NORMAL                 = 0,                          /* 正常 */
    AT_IMSA_BATTERY_STATUS_LOW,                                                 /* 低电 */
    AT_IMSA_BATTERY_STATUS_EXHAUST,                                             /* 电池耗尽 */

    AT_IMSA_BATTERY_STATUS_BUTT
};
typedef  VOS_UINT8  AT_IMSA_BATTERY_STATUS_ENUM_UINT8;

/*****************************************************************************
枚举名    : IMSA_AT_REG_FAIL_CODE_ENUM
结构说明  : IMS注册失败信息

  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增枚举
*****************************************************************************/
enum IMSA_AT_REG_FAIL_CODE_ENUM
{
    IMSA_AT_REG_FAIL_CODE_PERM                    = 1,

    IMSA_AT_REG_FAIL_CODE_BUTT
};
typedef  VOS_UINT8  IMSA_AT_REG_FAIL_CODE_ENUM_UINT8;

/*****************************************************************************
 枚举名    : IMSA_AT_IMS_RAT_TYPE_ENUM
 枚举说明  : IMS接入类型
 1.日    期   : 2015年10月07日
   作    者   : f00179208
   修改内容   : 创建
*****************************************************************************/
enum IMSA_AT_IMS_RAT_TYPE_ENUM
{
    IMSA_AT_IMS_RAT_TYPE_LTE            = 0x00,
    IMSA_AT_IMS_RAT_TYPE_WIFI           = 0x01,
    IMSA_AT_IMS_RAT_TYPE_BUTT
};
typedef VOS_UINT8 IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8;
/*****************************************************************************
枚举名    : AT_IMSA_ROAMING_IMS_SUPPORT_ENUM
结构说明  : 漫游状态下是否支持IMS服务

  1.日    期   : 2016年1月15日
    作    者   : w00316404
    修改内容   : 新增枚举
*****************************************************************************/
enum AT_IMSA_ROAMING_IMS_SUPPORT_ENUM
{
    AT_IMSA_ROAMING_IMS_SUPPORT         = 1,
    AT_IMSA_ROAMING_IMS_NOT_SUPPORT     = 2,

    AT_IMSA_ROAMING_IMS_BUTT
};
typedef  VOS_UINT32  AT_IMSA_ROAMING_IMS_SUPPORT_ENUM_UINT32;

/*****************************************************************************
 枚举名    : IMSA_AT_IMS_REG_DOMAIN_TYPE_ENUM
 枚举说明  : IMS注册域类型
 1.日    期   : 2015年10月07日
   作    者   : f00179208
   修改内容   : 创建
*****************************************************************************/
enum IMSA_AT_IMS_REG_DOMAIN_TYPE_ENUM
{
    IMSA_AT_IMS_REG_DOMAIN_TYPE_LTE     = 0x00,
    IMSA_AT_IMS_REG_DOMAIN_TYPE_WIFI    = 0x01,
    IMSA_AT_IMS_REG_DOMAIN_TYPE_UNKNOWN = 0x02,
    IMSA_AT_IMS_REG_DOMAIN_TYPE_BUTT
};
typedef VOS_UINT8 IMSA_AT_IMS_REG_DOMAIN_TYPE_ENUM_UINT8;


/*****************************************************************************
 枚举名    : IMSA_AT_IMS_RAT_HO_STATUS_ENUM
 枚举说明  : IMS注册域切换状态
 1.日    期   : 2016年04月07日
   作    者   : f00179208
   修改内容   : 创建
*****************************************************************************/
enum IMSA_AT_IMS_RAT_HO_STATUS_ENUM
{
    IMSA_AT_IMS_RAT_HO_STATUS_SUCCESS               = 0x00,     /* RAT handover was successful */
    IMSA_AT_IMS_RAT_HO_STATUS_FAILURE               = 0x01,     /* RAT handover was failed */
    IMSA_AT_IMS_RAT_HO_STATUS_NOT_TRIGGERED         = 0x02,     /* RAT handover could nut be triggered */
    IMSA_AT_IMS_RAT_HO_STATUS_BUTT
};
typedef VOS_UINT8 IMSA_AT_IMS_RAT_HO_STATUS_ENUM_UINT8;

/*****************************************************************************
 枚举名    : IMSA_AT_IMS_SERVICE_STATUS_ENUM
 枚举说明  : IMS的服务状态
 1.日    期   : 2016年04月07日
   作    者   : f00179208
   修改内容   : 创建
*****************************************************************************/
enum IMSA_AT_IMS_SERVICE_STATUS_ENUM
{
    IMSA_AT_IMS_SERVICE_STATUS_NO_SERVICE           = 0x00,     /* IMS is no service */
    IMSA_AT_IMS_SERVICE_STATUS_LIMITED_SERVICE      = 0x01,     /* IMS is in limited service */
    IMSA_AT_IMS_SERVICE_STATUS_FULL_SERVICE         = 0x02,     /* IMS is in full service */
    IMSA_AT_IMS_SERVICE_STATUS_SOS_PENDING          = 0x08,     /* IMS is in sos pending */
    IMSA_AT_IMS_SERVICE_STATUS_BUTT
};
typedef VOS_UINT8 IMSA_AT_IMS_SERVICE_STATUS_ENUM_UINT8;

/*****************************************************************************
 枚举名    : IMSA_AT_HO_CAUSE_ENUM
 枚举说明  : IMS的HO状态
 1.日    期   : 2016年04月07日
   作    者   :  z00353461
   修改内容   : 创建
*****************************************************************************/

enum IMSA_AT_HO_CAUSE_ENUM
{
    IMSA_AT_HO_CAUSE_SUCCESS                    = 0,       /**< HO命令执行成功 */
    IMSA_AT_HO_CAUSE_FAIL_PARA_ERR              = 1,       /**< HO命令执行失败，由于参数错误 */
    IMSA_AT_HO_CAUSE_FAIL_CN_REJ                = 2,       /**< HO命令执行失败，由于被网侧拒绝 */
    IMSA_AT_HO_CAUSE_FAIL_TIMER_EXP             = 3,       /**< HO命令执行失败，由于定时器超时 */
    IMSA_AT_HO_CAUSE_FAIL_CONN_RELEASING        = 4,       /**< HO命令执行失败，由于正在释放连接 */
    IMSA_AT_HO_CAUSE_FAIL_PDP_ACTIVATE_LIMIT    = 5,       /**< HO命令执行失败，由于激活的承载数限制 */
    IMSA_AT_HO_CAUSE_FAIL_SAME_APN_OPERATING    = 6,       /**< HO命令执行失败，由于APS正在执行操作 */
    IMSA_AT_HO_CAUSE_FAIL_TEMP_FORBIDDEN        = 7,       /**< HO命令执行失败，收到临时被拒原因值或者网侧不响应 */
    IMSA_AT_HO_CAUSE_FAIL_PERM_FORBIDDEN        = 8,       /**< HO命令执行失败，收到永久被拒原因值 */
    IMSA_AT_HO_CAUSE_FAIL_WIFI_READY_IND_TIMEOUT    = 9,   /**< HO命令执行失败，由于WIFI下发送READY IND超时 */

    IMSA_AT_HO_CAUSE_FAIL_OHTERS                    = 11,    /**< HO命令执行失败，由于其他原因 */
	IMSA_AT_HO_CAUSE_FAIL_NO_DSDS_RESOURCE			= 12,    /**< HO命令执行失败，由于DSDS下申请无线资源失败 */

    IMSA_AT_HO_CAUSE_BUTT
};
typedef VOS_UINT32 IMSA_AT_HO_CAUSE_ENUM_UINT32;





enum IMSA_AT_PCSCF_SRC_ENUM
{
    IMSA_AT_PCSCF_SRC_DM_DEFAULT    = 0,    /* P-CSCF地址来源是DM默认配置 */
    IMSA_AT_PCSCF_SRC_DM            = 1,    /* P-CSCF地址来源是DM服务器 */

    IMSA_AT_PCSCF_SRC_BUTT
};
typedef VOS_UINT32 IMSA_AT_PCSCF_SRC_ENUM_UINT32;

enum AT_IMSA_VOICE_DOMAIN_ENUM
{
    AT_IMSA_VOICE_DOMAIN_CS_ONLY                = 0,  /* CS voice only */
    AT_IMSA_VOICE_DOMAIN_IMS_PS_ONLY            = 1,  /* IMS PS voice only */
    AT_IMSA_VOICE_DOMAIN_CS_PREFERRED           = 2,  /* CS voice preferred, IMS PS voice as secondary */
    AT_IMSA_VOICE_DOMAIN_IMS_PS_PREFERRED       = 3,  /* IMS PS voice preferred, CS voice as secondary  */

    AT_IMSA_VOICE_DOMAIN_BUTT
};
typedef VOS_UINT32 AT_IMSA_VOICE_DOMAIN_ENUM_UINT32;
/*****************************************************************************
 枚举名    : IMSA_AT_REG_ERR_TYPE_ENUM_UINT8
 枚举说明  : IMS注册失败类型
 1.日    期   : 2016年11月09日
   作    者   : w00209181
   修改内容   : 创建
*****************************************************************************/
enum IMSA_AT_REG_ERR_TYPE_ENUM
{
    IMSA_AT_REG_ERR_TYPE_PDN_FAIL       = 0x00,
    IMSA_AT_REG_ERR_TYPE_IMS_REG_FAIL   = 0x01,
    IMSA_AT_REG_ERR_TYPE_BUTT
};
typedef VOS_UINT8 IMSA_AT_REG_ERR_TYPE_ENUM_UINT8;
/*****************************************************************************
 枚举名    : IMSA_AT_REG_ERR_TYPE_ENUM_UINT8
 枚举说明  : IMS注册失败类型
 1.日    期   : 2016年11月09日
   作    者   : w00209181
   修改内容   : 创建
*****************************************************************************/
enum IMSA_AT_PDN_FAIL_CAUSE_ENUM
{
    IMSA_AT_PDN_FAIL_CAUSE_PARA_ERR                             = 1,
    /* IMSA_AT_PDN_FAIL_CAUSE_CN_REJ                               = 2,*/
    IMSA_AT_PDN_FAIL_CAUSE_TIMER_EXP                            = 3,
    IMSA_AT_PDN_FAIL_CAUSE_CONN_RELEASING                       = 4,
    IMSA_AT_PDN_FAIL_CAUSE_PDP_ACTIVATE_LIMIT                   = 5,
    IMSA_AT_PDN_FAIL_CAUSE_SAME_APN_OPERATING                   = 6,
    IMSA_AT_PDN_FAIL_CAUSE_TEMP_FORBIDDEN                       = 7,
    IMSA_AT_PDN_FAIL_CAUSE_PERM_FORBIDDEN                       = 8,
    IMSA_AT_PDN_FAIL_CAUSE_WIFI_READY_IND_TIMEOUT               = 9,
    IMSA_AT_PDN_FAIL_CAUSE_HO_NEW_PDN_SETUP_FAIL                = 10,
    IMSA_AT_PDN_FAIL_CAUSE_WIFI_FAIL_TEMP_FORBIDDEN             = 11,
    IMSA_AT_PDN_FAIL_CAUSE_WIFI_FAIL_PERM_FORBIDDEN             = 12,
    IMSA_AT_PDN_FAIL_CAUSE_WIFI_FAIL_TEMP_FORBIDDEN_WITH_TIMERLEN   = 13,
    IMSA_AT_PDN_FAIL_CAUSE_WIFI_FAIL_LINKLOST                   = 14,
    IMSA_AT_PDN_FAIL_CAUSE_OHTERS                               = 15,

    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_OPERATOR_DETERMINED_BARRING          = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 8),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_MBMS_BC_INSUFFICIENT                 = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 24),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_LLC_OR_SNDCP_FAILURE                 = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 25),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_INSUFFICIENT_RESOURCES               = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 26),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_MISSING_OR_UKNOWN_APN                = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 27),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_UNKNOWN_PDP_ADDR_OR_TYPE             = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 28),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_USER_AUTHENTICATION_FAIL             = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 29),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_ACTIVATION_REJECTED_BY_GGSN_SGW_OR_PGW         = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 30),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_ACTIVATION_REJECTED_UNSPECIFIED      = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 31),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SERVICE_OPTION_NOT_SUPPORTED         = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 32),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_REQUESTED_SERVICE_NOT_SUBSCRIBED     = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 33),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SERVICE_OPTION_TEMP_OUT_ORDER        = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 34),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_NSAPI_ALREADY_USED                   = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 35),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_REGULAR_DEACTIVATION                 = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 36),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_QOS_NOT_ACCEPTED                     = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 37),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_NETWORK_FAILURE                      = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 38),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_REACTIVATION_REQUESTED               = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 39),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_FEATURE_NOT_SUPPORT                  = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 40),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SEMANTIC_ERR_IN_TFT                  = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 41),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SYNTACTIC_ERR_IN_TFT                 = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 42),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_UKNOWN_PDP_CONTEXT                   = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 43),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SEMANTIC_ERR_IN_PACKET_FILTER        = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 44),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SYNCTACTIC_ERR_IN_PACKET_FILTER      = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 45),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_PDP_CONTEXT_WITHOUT_TFT_ACTIVATED    = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 46),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_MULTICAST_GROUP_MEMBERHHSHIP_TIMEOUT = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 47),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_REQUEST_REJECTED_BCM_VIOLATION       = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 48),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_LAST_PDN_DISCONN_NOT_ALLOWED         = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 49),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_PDP_TYPE_IPV4_ONLY_ALLOWED           = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 50),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_PDP_TYPE_IPV6_ONLY_ALLOWED           = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 51),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SINGLE_ADDR_BEARERS_ONLY_ALLOWED     = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 52),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_INFORMATION_NOT_RECEIVED             = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 53),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_PDN_CONNECTION_DOES_NOT_EXIST        = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 54),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SAME_APN_MULTI_PDN_CONNECTION_NOT_ALLOWED = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 55),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_COLLISION_WITH_NW_INITIATED_REQUEST  = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 56),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_UNSUPPORTED_QCI_VALUE                = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 59),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_BEARER_HANDLING_NOT_SUPPORTED        = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 60),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_INVALID_TI                           = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 81),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SEMANTICALLY_INCORRECT_MESSAGE       = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 95),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_INVALID_MANDATORY_INFO               = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 96),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_MSG_TYPE_NON_EXISTENT                = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 97),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_MSG_TYPE_NOT_COMPATIBLE              = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 98),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_IE_NON_EXISTENT                      = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 99),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_CONDITIONAL_IE_ERR                   = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 100),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_MSG_NOT_COMPATIBLE                   = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 101),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_PROTOCOL_ERR_UNSPECIFIED             = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 111),
    IMSA_AT_PDN_FAIL_CAUSE_SM_NW_APN_RESTRICTION_INCOMPATIBLE         = (IMSA_AT_PDN_FAIL_CAUSE_SM_NW_SECTION_BEGIN + 112),

    IMSA_AT_PDN_FAIL_CAUSE_BUTT
};
typedef VOS_UINT32 IMSA_AT_PDN_FAIL_CAUSE_ENUM_UINT32;
/*****************************************************************************
 枚举名    : IMSA_AT_REG_FAIL_CAUSE_ENUM
 枚举说明  : IMS注册失败类型
 1.日    期   : 2016年11月09日
   作    者   : w00209181
   修改内容   : 创建
*****************************************************************************/
enum IMSA_AT_REG_FAIL_CAUSE_ENUM
{
    IMSA_AT_REG_FAIL_CAUSE_FAIL                = 1,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_REMOTE         = 2,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_TIMEOUT        = 3,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_TRANSPORT      = 4,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_SA             = 5,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_MT_DEREG       = 6,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_NO_ADDR_PAIR   = 7,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_LACK_PARAM     = 8,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_FORBIDDEN      = 9,
    IMSA_AT_REG_FAIL_CAUSE_FAIL_REREG_FAIL     = 10,

    /* IMS网侧拒绝原因值 300~699,直接填数字，不再一一列举  */

    IMSA_AT_REG_FAIL_CAUSE_BUTT                = 700,
};
typedef VOS_UINT32 IMSA_AT_REG_FAIL_CAUSE_ENUM_UINT32;


/*****************************************************************************
  3 类型定义
*****************************************************************************/
/*****************************************************************************
结构名    : AT_IMSA_MSG_STRU
结构说明  : AT模块与IMSA模块间的消息结构

1.日    期  : 2013年09月12日
  作    者  : Y00213812
  修改内容  : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT8                           aucContent[4];
} AT_IMSA_MSG_STRU;

/*****************************************************************************
结构名    : AT_IMSA_MSG_STRU
结构说明  : IMSA模块与AT模块间CNF的消息结构

1.日    期  : 2016年7月5日
  作    者  : w00316404
  修改内容  : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    AT_APPCTRL_STRU                         stAppCtrl;
    VOS_UINT32                              ulResult;                           /* 成功返回VOS_OK，失败返回VOS_ERR */
} IMSA_AT_CNF_MSG_STRU;

/*****************************************************************************
结构名    : AT_IMSA_CIREG_QRY_REQ_STRU
结构说明  : ID_AT_IMSA_CIREG_QRY_REQ的消息结构

1.日    期  : 2013年09月12日
  作    者  : Y00213812
  修改内容  : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_CIREG_QRY_REQ_STRU;


/*****************************************************************************
结构名    : AT_IMSA_CIREP_QRY_REQ_STRU
结构说明  : ID_AT_IMSA_CIREP_QRY_REQ的消息结构

1.日    期  : 2013年09月12日
  作    者  : Y00213812
  修改内容  : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_CIREP_QRY_REQ_STRU;

/*****************************************************************************
结构名    : AT_IMSA_VOLTEIMPU_QRY_REQ_STRU
结构说明  : ID_AT_IMSA_VOLTEIMPU_QRY_REQ的消息结构

1.日    期  : 2013年12月05日
  作    者  : Y00213812
  修改内容  : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_VOLTEIMPU_QRY_REQ_STRU;


/*****************************************************************************
结构名    : AT_IMSA_VOLTEIMPI_QRY_REQ_STRU
结构说明  : ID_AT_IMSA_VOLTEIMPI_QRY_REQ的消息结构

1.日    期  : 2016年10月27日
  作    者  : W00209181
  修改内容  : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_VOLTEIMPI_QRY_REQ_STRU;


/*****************************************************************************
结构名    : AT_IMSA_VOLTEDOMAIN_QRY_REQ_STRU
结构说明  : ID_AT_IMSA_VOLTEDOMAIN_QRY_REQ的消息结构

1.日    期  : 2016年10月27日
  作    者  : W00209181
  修改内容  : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_VOLTEDOMAIN_QRY_REQ_STRU;


/*****************************************************************************
 结构名  : AT_IMSA_CCWAI_SET_REQ_STRU
 结构说明: ^CCWAI IMS  呼叫等待
 修改历史      :
  1.日    期   : 2014年3月11日
    作    者   : w00209181
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    AT_IMSA_CCWAI_MODE_ENUM_UINT8       enMode;
    VOS_UINT32                          ulSrvClass;
} AT_IMSA_CCWAI_SET_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_CCWAI_SET_CNF_STRU
 结构说明: ^CCWAI IMS  呼叫等待
 修改历史      :
  1.日    期   : 2014年3月11日
    作    者   : w00209181
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           ucReserved;
    VOS_UINT32                          ulResult;
} IMSA_AT_CCWAI_SET_CNF_STRU;


/*****************************************************************************
 结构名  : AT_IMSA_CALL_ENCRYPT_SET_REQ_STRU
 结构说明: ^CALLENCRYPT: 设置语音加密请求
 修改历史      :
  1.日    期   : 2015年10月14日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved1[1];
    VOS_UINT8                           ucEncrypt;                              /* 0:不加密，1:加密 */
    VOS_UINT8                           aucReserved2[3];
} AT_IMSA_CALL_ENCRYPT_SET_REQ_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_CALL_ENCRYPT_SET_CNF_STRU
 结构说明: ^CALLENCRYPT: 设置语音加密回复
 修改历史      :
  1.日    期   : 2015年10月14日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           ucReserved;
    VOS_UINT32                          ulResult;                               /* 成功返回VOS_OK，失败返回VOS_ERR */
} IMSA_AT_CALL_ENCRYPT_SET_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_CIREG_SET_REQ_STRU
 结构说明: +CIREG IMS注册状态主动上报控制设置

 修改历史      :
  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    AT_IMSA_IMS_REG_STATE_REPORT_ENUM_UINT32    enCireg;
} AT_IMSA_CIREG_SET_REQ_STRU;


/*****************************************************************************
 结构名  : IMSA_AT_CIREG_SET_CNF_STRU
 结构说明: +CIREG IMS注册状态主动上报控制

 修改历史      :
  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT32                          ulResult;                               /* 成功返回VOS_OK，失败返回VOS_ERR */
} IMSA_AT_CIREG_SET_CNF_STRU;


/*****************************************************************************
 结构名  : IMSA_AT_CIREG_QRY_CNF_STRU
 结构说明: +CIREG IMS注册状态查询结果

 修改历史      :
  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];

    VOS_UINT32                          bitOpExtInfo    : 1 ;                   /* +CIREG=2时,标志位置1 */
    VOS_UINT32                          bitOpSpare      : 31;

    AT_IMSA_IMS_REG_STATE_REPORT_ENUM_UINT32    enCireg;
    VOS_UINT32                          ulRegInfo;
    VOS_UINT32                          ulExtInfo;                              /* +CIREG=2时 ，扩展信息暂时回复0 */
    VOS_UINT32                          ulResult;                               /* 成功返回VOS_OK，失败返回VOS_ERR */
} IMSA_AT_CIREG_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_CIREGU_IND_STRU
 结构说明: ID_IMSA_AT_CIREGU_IND IMS注册状态主动上报

 修改历史      :
  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;                             /* 主动上报时填0X3FFF */
    VOS_UINT8                           ucOpId;                                 /* 填0 */
    VOS_UINT8                           aucReserved[1];

    VOS_UINT32                          bitOpExtInfo    : 1 ;
    VOS_UINT32                          bitOpSpare      : 31;

    VOS_UINT32                          ulRegInfo;
    VOS_UINT32                          ulExtInfo;
} IMSA_AT_CIREGU_IND_STRU;


/*****************************************************************************
 结构名  : AT_IMSA_CIREP_SET_REQ_STRU
 结构说明: +CIREP SRVCC切换状态主动上报控制

 修改历史      :
  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    AT_IMSA_CIREP_REPORT_ENUM_UINT32    enReport;
} AT_IMSA_CIREP_SET_REQ_STRU;


/*****************************************************************************
 结构名  : IMSA_AT_CIREP_SET_CNF_STRU
 结构说明: +CIREP SRVCC切换状态主动上报控制

 修改历史      :
  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT32                          ulResult;                               /* 成功返回VOS_OK，失败返回VOS_ERR */
} IMSA_AT_CIREP_SET_CNF_STRU;


/*****************************************************************************
 结构名  : IMSA_AT_CIREP_QRY_CNF_STRU
 结构说明: +CIREP IMSVOPS能力查询

 修改历史      :
  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    AT_IMSA_CIREP_REPORT_ENUM_UINT32            enReport;
    AT_IMSA_IMSVOPS_CAPABILITY_ENUM_UINT32      enImsvops;
    VOS_UINT32                          ulResult;                               /* 成功返回VOS_OK，失败返回VOS_ERR */
} IMSA_AT_CIREP_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_VOLTEIMPU_QRY_CNF_STRU
 结构说明: ^VOLTEIMPU IMPU信息查询结果

 修改历史      :
  1.日    期   : 2013年12月05日
    作    者   : Y00213812
    修改内容   : 新增结构

  2.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : LGU+ Project新增虚拟号码查询
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;               /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT32                          ulResult;              /* 成功返回VOS_OK，失败返回VOS_ERR */
    VOS_UINT32                          ulImpuLen;
    VOS_CHAR                            aucImpu[AT_IMSA_IMPU_MAX_LENGTH];
    VOS_UINT32                          ulImpuLenVirtual;
    VOS_CHAR                            aucImpuVirtual[AT_IMSA_IMPU_MAX_LENGTH];
} IMSA_AT_VOLTEIMPU_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_VOLTEIMPI_QRY_CNF_STRU
 结构说明: ^VOLTEIMPI IMPI信息查询结果

 修改历史      :
  1.日    期   : 2016年10月27日
    作    者   : W00209181
    修改内容   : 新增结构

*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;               /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT32                          ulResult;              /* 成功返回VOS_OK，失败返回VOS_ERR */
    VOS_UINT32                          ulImpiLen;
    VOS_CHAR                            aucImpi[AT_IMSA_IMPI_MAX_LENGTH];
} IMSA_AT_VOLTEIMPI_QRY_CNF_STRU;
/*****************************************************************************
 结构名  : IMSA_AT_VOLTEDOMAIN_QRY_CNF_STRU
 结构说明: ^VOLTEDOMAIN DOMAIN信息查询结果

 修改历史      :
  1.日    期   : 2016年10月27日
    作    者   : W00209181
    修改内容   : 新增结构

*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;               /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT32                          ulResult;              /* 成功返回VOS_OK，失败返回VOS_ERR */
    VOS_UINT32                          ulDomainLen;
    VOS_CHAR                            aucDomain[AT_IMSA_DOMAIN_MAX_LENGTH];
} IMSA_AT_VOLTEDOMAIN_QRY_CNF_STRU;


/*****************************************************************************
 结构名  : AT_IMSA_ROAMING_IMS_QRY_REQ_STRU
 结构说明: AT通知IMSA查询漫游是否支持的结构

 修改历史      :
  1.日    期   : 2016年1月15日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_ROAMING_IMS_QRY_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_ROAMING_IMS_QRY_CNF_STRU
 结构说明: ^ROAMIMSSERVICE 漫游状态下IMS服务是否支持查询命令CNF消息

 修改历史      :
  1.日    期   : 2016年1月15日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                              usClientId;
    VOS_UINT8                               ucOpId;
    VOS_UINT8                               aucReserved[1];
    AT_IMSA_ROAMING_IMS_SUPPORT_ENUM_UINT32 enRoamingImsSupportFlag;
    VOS_UINT32                              ulResult;
} IMSA_AT_ROAMING_IMS_QRY_CNF_STRU;


/*****************************************************************************
 结构名  : IMSA_AT_CIREPH_IND_STRU
 结构说明: +CIREPH SRVCC切换状态主动上报

 修改历史      :
  1.日    期   : 2013年9月13日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;                             /* 主动上报时填0X3FFF */
    VOS_UINT8                           ucOpId;                                 /* 填0 */
    VOS_UINT8                           aucReserved[1];
    AT_IMSA_SRVCC_HANDVOER_ENUM_UINT32  enHandover;
} IMSA_AT_CIREPH_IND_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_CIREPI_IND_STRU
 结构说明: +CIREPI IMSVOPS主动上报

 修改历史      :
  1.日    期   : 2013年9月23日
    作    者   : Y00213812
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;                             /* 主动上报时填0X3FFF */
    VOS_UINT8                           ucOpId;                                 /* 填0 */
    VOS_UINT8                           aucReserved[1];
    AT_IMSA_IMSVOPS_CAPABILITY_ENUM_UINT32      enImsvops;
} IMSA_AT_CIREPI_IND_STRU;


/*****************************************************************************
 结构名称: IMSA_AT_VT_PDP_ACTIVATE_IND_STRU
 结构说明: IMSA上报VT承载激活成功结果的结构

 修改历史      :
  1.日    期   : 2014年07月31日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;               /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8     enRatType;                  /* 注册域 */
    TAF_PDP_ADDR_STRU                   stPdpAddr;
    TAF_PDP_DNS_STRU                    stIpv4Dns;
    TAF_PDP_IPV6_DNS_STRU               stIpv6Dns;
} IMSA_AT_VT_PDP_ACTIVATE_IND_STRU;


/*****************************************************************************
 结构名称: IMSA_AT_VT_PDP_DEACTIVATE_IND_STRU
 结构说明: IMSA上报VT承载去激活成功结果的结构

 修改历史      :
  1.日    期   : 2014年07月31日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;               /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    TAF_PDP_TYPE_ENUM_UINT8             enPdpType;
    IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8     enRatType;             /* 注册域 */
    VOS_UINT8                           aucReserved[3];
} IMSA_AT_VT_PDP_DEACTIVATE_IND_STRU;

/*****************************************************************************
 结构名称： IMSA_AT_MT_STATES_IND_STRU
 结构说明:  IMSA上报AT收到被叫事件的结构

 修改历史:
 1.日期: 2015年03月18日
   作者: m00277840
   修改内容:新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT32                          ulCauseCode;
    VOS_UINT8                           ucMtStatus;
    VOS_UINT8                           aucRsv[3];
    VOS_UINT8                           aucAsciiCallNum[AT_IMSA_CALL_ASCII_NUM_MAX_LENGTH];
} IMSA_AT_MT_STATES_IND_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_IMS_REG_DOMAIN_QRY_REQ_STRU
 结构说明: 查询IMS注册域请求
 修改历史      :
  1.日    期   : 2015年10月07日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_IMS_REG_DOMAIN_QRY_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_IMS_REG_DOMAIN_QRY_CNF_STRU
 结构说明: 查询IMS注册域回复
 修改历史      :
  1.日    期   : 2015年10月07日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                              usClientId;
    VOS_UINT8                               ucOpId;
    IMSA_AT_IMS_REG_DOMAIN_TYPE_ENUM_UINT8  enImsRegDomain;
} IMSA_AT_IMS_REG_DOMAIN_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_IMS_CTRL_MSG_STRU
 结构说明: AT转发MAPCON->IMSA的内部消息
 修改历史      :
  1.日    期   : 2015年10月07日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                              usClientId;
    VOS_UINT8                               ucOpId;
    VOS_UINT8                               aucReserved[1];
    VOS_UINT32                              ulWifiMsgLen;
    VOS_UINT8                               aucWifiMsg[4];
} AT_IMSA_IMS_CTRL_MSG_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_IMS_CTRL_MSG_STRU
 结构说明: AT转发IMSA->MAPCON的内部消息
 修改历史      :
  1.日    期   : 2015年10月07日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                              usClientId;
    VOS_UINT8                               ucOpId;
    VOS_UINT8                               aucReserved[1];
    VOS_UINT32                              ulWifiMsgLen;
    VOS_UINT8                               aucWifiMsg[4];
} IMSA_AT_IMS_CTRL_MSG_STRU;


/*****************************************************************************
 结构名  : IMSA_AT_IMS_RAT_HANDOVER_IND_STRU
 结构说明: IMS注册域切换指示

 修改历史      :
  1.日    期   : 2016年04月07日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                              usClientId;                         /* 主动上报时填0X3FFF */
    VOS_UINT8                               ucOpId;                             /* 填0 */
    IMSA_AT_IMS_RAT_HO_STATUS_ENUM_UINT8    enHoStatus;                         /* 切换状态 */
    IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8         enSrcRat;                           /* 原有IMS注册域 */
    IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8         enDstRat;                           /* 目标IMS注册域 */
    VOS_UINT8                               aucReserved[2];
    IMSA_AT_HO_CAUSE_ENUM_UINT32            enCause;                            /* 切换失败原因值 */
} IMSA_AT_IMS_RAT_HANDOVER_IND_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_IMS_SRV_STATUS_UPDATE_IND_STRU
 结构说明: IMS服务状态变化指示

 修改历史      :
  1.日    期   : 2016年04月07日
    作    者   : f00179208
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                              usClientId;                         /* 主动上报时填0X3FFF */
    VOS_UINT8                               ucOpId;                             /* 填0 */
    VOS_UINT8                               aucReserved[1];
    IMSA_AT_IMS_SERVICE_STATUS_ENUM_UINT8   enSmsSrvStatus;                     /* 短信的IMS服务状态 */
    IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8         enSmsSrvRat;                        /* 短信的IMS服务域 */
    IMSA_AT_IMS_SERVICE_STATUS_ENUM_UINT8   enVoIpSrvStatus;                    /* VoIP的IMS服务状态 */
    IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8         enVoIpSrvRat;                       /* VoIP的IMS服务域 */
    IMSA_AT_IMS_SERVICE_STATUS_ENUM_UINT8   enVtSrvStatus;                      /* VT的IMS服务状态 */
    IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8         enVtSrvRat;                         /* VT的IMS服务域 */
    IMSA_AT_IMS_SERVICE_STATUS_ENUM_UINT8   enVsSrvStatus;                      /* VS的IMS服务状态 */
    IMSA_AT_IMS_RAT_TYPE_ENUM_UINT8         enVsSrvRat;                         /* VS的IMS服务域 */
} IMSA_AT_IMS_SRV_STATUS_UPDATE_IND_STRU;

typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    AT_APPCTRL_STRU                         stAppCtrl;
} IMSA_AT_DMCN_IND_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_DMDYN_STRU
 结构说明: DMDYN配置参数结构体

 修改历史      :
  1.日    期   : 2016年6月12日
    作    者   : z00308719
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpAmrWbOctetAcigned       : 1;
    VOS_UINT32                          bitOpAmrWbBandWidthEfficient : 1;
    VOS_UINT32                          bitOpAmrOctetAcigned         : 1;
    VOS_UINT32                          bitOpAmrBandWidthEfficient   : 1;
    VOS_UINT32                          bitOpAmrWbMode               : 1;
    VOS_UINT32                          bitOpDtmfWb                  : 1;
    VOS_UINT32                          bitOpDtmfNb                  : 1;
    VOS_UINT32                          bitOpSpeechStart             : 1;
    VOS_UINT32                          bitOpSpeechEnd               : 1;
    VOS_UINT32                          bitOpVideoStart              : 1;
    VOS_UINT32                          bitOpVideoEnd                : 1;
    VOS_UINT32                          bitOpRetryBaseTime           : 1;
    VOS_UINT32                          bitOpRetryMaxTime            : 1;
    VOS_UINT32                          bitOpPhoneContext            : 1;
    VOS_UINT32                          bitOpPhoneContextImpu        : 1;
    VOS_UINT32                          bitOpSpare                   : 17;

    VOS_UINT32                          ulAmrWbOctetAcigned;
    VOS_UINT32                          ulAmrWbBandWidthEfficient;              /* 接口预留，IMSA不处理 */
    VOS_UINT32                          ulAmrOctetAcigned;
    VOS_UINT32                          ulAmrBandWidthEfficient;                /* 接口预留，IMSA不处理 */
    VOS_UINT32                          ulAmrWbMode;
    VOS_UINT32                          ulDtmfWb;                               /* 接口预留，IMSA不处理 */
    VOS_UINT32                          ulDtmfNb;                               /* 接口预留，IMSA不处理 */
    VOS_UINT32                          ulSpeechStart;
    VOS_UINT32                          ulSpeechEnd;
    VOS_UINT32                          ulVideoStart;
    VOS_UINT32                          ulVideoEnd;
    VOS_UINT32                          ulRetryBaseTime;
    VOS_UINT32                          ulRetryMaxTime;
    VOS_CHAR                            acPhoneContext[IMSA_PHONECONTEXT_MAX_LENGTH + 1];
    VOS_UINT8                           aucReserved1[3];
    VOS_CHAR                            acPhoneContextImpu[IMSA_PUBLICEUSERID_MAX_LENGTH + 1];
    VOS_UINT8                           aucReserved2[3];

} AT_IMSA_DMDYN_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_DMDYN_SET_REQ_STRU
 结构说明: DMDYN参数配置命令

 修改历史      :
  1.日    期   : 2016年6月12日
    作    者   : z00308719
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    AT_APPCTRL_STRU                     stAppCtrl;
    AT_IMSA_DMDYN_STRU                  stDmdyn;
} AT_IMSA_DMDYN_SET_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_DMDYN_SET_CNF_STRU
 结构说明: DMDYN参数查询结果

 修改历史      :
  1.日    期   : 2016年6月12日
    作    者   : z00308719
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    AT_APPCTRL_STRU                     stAppCtrl;
    VOS_UINT32                          ulResult;                               /* 成功返回VOS_OK，失败返回VOS_ERR */
} IMSA_AT_DMDYN_SET_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_DMDYN_QRY_REQ_STRU
 结构说明: DMDYN参数查询请求命令

 修改历史      :
  1.日    期   : 2016年6月12日
    作    者   : z00308719
    修改内容   : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_DMDYN_QRY_REQ_STRU;

typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    AT_APPCTRL_STRU                     stAppCtrl;
    VOS_UINT32                          ulResult;
    AT_IMSA_DMDYN_STRU                  stDmdyn;
} IMSA_AT_DMDYN_QRY_CNF_STRU;


/*****************************************************************************
 结构名称: IMSA_PDP_IPV4_PCSCF_STRU
 结构说明: IPv4 P-CSCF地址结构体
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpPrimPcscfAddr      : 1;
    VOS_UINT32                          bitOpSecPcscfAddr       : 1;
    VOS_UINT32                          bitOpThiPcscfAddr       : 1;
    VOS_UINT32                          bitOpPrimPcscfSipPort   : 1;
    VOS_UINT32                          bitOpSecPcscfSipPort    : 1;
    VOS_UINT32                          bitOpThiPcscfSipPort    : 1;
    VOS_UINT32                          bitOpSpare              : 26;

    VOS_UINT8                           aucPrimPcscfAddr[TAF_IPV4_ADDR_LEN];
    VOS_UINT8                           aucSecPcscfAddr[TAF_IPV4_ADDR_LEN];
    VOS_UINT8                           aucThiPcscfAddr[TAF_IPV4_ADDR_LEN];
    VOS_UINT32                          ulPrimPcscfSipPort;
    VOS_UINT32                          ulSecPcscfSipPort;
    VOS_UINT32                          ulThiPcscfSipPort;
} IMSA_AT_IPV4_PCSCF_STRU;

/*****************************************************************************
 结构名称: IMSA_PDP_IPV6_PCSCF_STRU
 结构说明: IPv6 P-CSCF地址结构体
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpPrimPcscfAddr      : 1;
    VOS_UINT32                          bitOpSecPcscfAddr       : 1;
    VOS_UINT32                          bitOpThiPcscfAddr       : 1;
    VOS_UINT32                          bitOpPrimPcscfSipPort   : 1;
    VOS_UINT32                          bitOpSecPcscfSipPort    : 1;
    VOS_UINT32                          bitOpThiPcscfSipPort    : 1;
    VOS_UINT32                          bitOpSpare              : 26;

    VOS_UINT8                           aucPrimPcscfAddr[TAF_IPV6_ADDR_LEN];
    VOS_UINT8                           aucSecPcscfAddr[TAF_IPV6_ADDR_LEN];
    VOS_UINT8                           aucThiPcscfAddr[TAF_IPV6_ADDR_LEN];
    VOS_UINT32                          ulPrimPcscfSipPort;
    VOS_UINT32                          ulSecPcscfSipPort;
    VOS_UINT32                          ulThiPcscfSipPort;
} IMSA_AT_IPV6_PCSCF_STRU;

typedef struct
{
    IMSA_AT_PCSCF_SRC_ENUM_UINT32         enSrc;                                /* 区分P-CSCF地址来源， */
    IMSA_AT_IPV6_PCSCF_STRU               stIpv6Pcscf;
    IMSA_AT_IPV4_PCSCF_STRU               stIpv4Pcscf;
}IMSA_AT_PCSCF_STRU;

typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    AT_APPCTRL_STRU                     stAppCtrl;
    IMSA_AT_PCSCF_STRU                  stAtPcscf;
} AT_IMSA_PCSCF_SET_REQ_STRU;

typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    AT_APPCTRL_STRU                     stAppCtrl;
    VOS_UINT32                          ulResult;                               /* 成功返回VOS_OK，失败返回VOS_ERR */
} IMSA_AT_PCSCF_SET_CNF_STRU;

typedef AT_IMSA_MSG_STRU AT_IMSA_PCSCF_QRY_REQ_STRU;

typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    AT_APPCTRL_STRU                     stAppCtrl;
    VOS_UINT32                          ulResult;
    IMSA_AT_PCSCF_STRU                  stAtPcscf;
} IMSA_AT_PCSCF_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_IMS_TIMER_STRU
 结构说明: IMS定时器时间信息结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新建
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              bitOpTimerT1Value   : 1;
    VOS_UINT32                              bitOpTimerT2Value   : 1;
    VOS_UINT32                              bitOpTimerT4Value   : 1;
    VOS_UINT32                              bitOpTimerTAValue   : 1;
    VOS_UINT32                              bitOpTimerTBValue   : 1;
    VOS_UINT32                              bitOpTimerTCValue   : 1;
    VOS_UINT32                              bitOpTimerTDValue   : 1;
    VOS_UINT32                              bitOpTimerTEValue   : 1;
    VOS_UINT32                              bitOpTimerTFValue   : 1;
    VOS_UINT32                              bitOpTimerTGValue   : 1;
    VOS_UINT32                              bitOpTimerTHValue   : 1;
    VOS_UINT32                              bitOpTimerTIValue   : 1;
    VOS_UINT32                              bitOpTimerTJValue   : 1;
    VOS_UINT32                              bitOpTimerTKValue   : 1;
    VOS_UINT32                              bitOpSpare          : 18;

    VOS_UINT32                              ulTimerT1Value;
    VOS_UINT32                              ulTimerT2Value;
    VOS_UINT32                              ulTimerT4Value;
    VOS_UINT32                              ulTimerTAValue;
    VOS_UINT32                              ulTimerTBValue;
    VOS_UINT32                              ulTimerTCValue;
    VOS_UINT32                              ulTimerTDValue;
    VOS_UINT32                              ulTimerTEValue;
    VOS_UINT32                              ulTimerTFValue;
    VOS_UINT32                              ulTimerTGValue;
    VOS_UINT32                              ulTimerTHValue;
    VOS_UINT32                              ulTimerTIValue;
    VOS_UINT32                              ulTimerTJValue;
    VOS_UINT32                              ulTimerTKValue;

}IMSA_AT_IMS_TIMER_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_IMSTIMER_SET_REQ_STRU
 结构说明: ID_AT_IMSA_IMSTIMER_SET_REQ消息对应结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    AT_APPCTRL_STRU                         stAppCtrl;
    IMSA_AT_IMS_TIMER_STRU                  stImsTimer;
}AT_IMSA_IMSTIMER_SET_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_IMSTIMER_SET_CNF_STRU
 结构说明: ID_IMSA_AT_IMSTIMER_SET_CNF消息对应结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    AT_APPCTRL_STRU                         stAppCtrl;
    VOS_UINT32                              ulResult;                   /* 成功返回 VOS_OK,失败返回 VOS_ERR*/
}IMSA_AT_IMSTIMER_SET_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_IMSTIMER_QRY_REQ_STRU
 结构说明: ID_AT_IMSA_IMSTIMER_QRY_REQ消息对应结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_IMSTIMER_QRY_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_IMSTIMER_QRY_CNF_STRU
 结构说明: ID_IMSA_AT_IMSTIMER_QRY_CNF消息对应结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    AT_APPCTRL_STRU                         stAppCtrl;
    VOS_UINT32                              ulResult;
    IMSA_AT_IMS_TIMER_STRU                  stImsTimer;
}IMSA_AT_IMSTIMER_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : IMSA_SMS_PSI_STRU
 结构说明: IMS域动态变化参数对应结构体

  1.日    期   : 2016年6月20日
    作    者   : f00367319
    修改内容   : 新建
*****************************************************************************/
typedef struct
{
    VOS_CHAR                                acSmsPsi[AT_IMSA_MAX_SMSPSI_LEN + 1];
    VOS_UINT8                               aucReserved[3];
}IMSA_SMS_PSI_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_SMSPSI_SET_REQ_STRU
 结构说明: ID_AT_IMSA_SMSPSI_SET_REQ消息对应结构体

  1.日    期   : 2016年6月20日
    作    者   : f00367319
    修改内容   : 新建
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    AT_APPCTRL_STRU                         stAppCtrl;
    IMSA_SMS_PSI_STRU                       stSmsPsi;
}AT_IMSA_SMSPSI_SET_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_SMSPSI_SET_CNF_STRU
 结构说明: ID_IMSA_AT_SMSPSI_SET_CNF消息对应结构体

  1.日    期   : 2016年6月20日
    作    者   : f00367319
    修改内容   : 新建
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    AT_APPCTRL_STRU                         stAppCtrl;
    VOS_UINT32                              ulResult;
}IMSA_AT_SMSPSI_SET_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_SMSPSI_QRY_REQ_STRU
 结构说明: ID_AT_IMSA_SMSPSI_QRY_REQ消息对应结构体

 修改历史      :
  1.日    期   : 2016年6月20日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_SMSPSI_QRY_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_SMSPSI_QRY_CNF_STRU
 结构说明: ID_IMSA_AT_SMSPSI_QRY_CNF消息对应结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    AT_APPCTRL_STRU                         stAppCtrl;
    VOS_UINT32                              ulResult;
    IMSA_SMS_PSI_STRU                       stSmsPsi;

}IMSA_AT_SMSPSI_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_DMUSER_QRY_REQ_STRU
 结构说明: ID_IMSA_AT_DMUSER_QRY_REQ消息对应结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_DMUSER_QRY_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_DMUSER_STRU
 结构说明: DM用户信息对应结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef struct
{
    VOS_CHAR                                acImpi[AT_IMSA_IMPI_MAX_LENGTH + 1];
    VOS_CHAR                                acImpu[AT_IMSA_IMPU_MAX_LENGTH + 1];
    VOS_CHAR                                acHomeNetWorkDomain[IMSA_IMS_STRING_LENGTH + 1];
    VOS_UINT8                               aucReserved[1];
    AT_IMSA_VOICE_DOMAIN_ENUM_UINT32        enVoiceDomain;
    VOS_UINT32                              ulIpsecEnable;
}IMSA_AT_DMUSER_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_DMUSER_STRU
 结构说明: DM用户信息对应结构体

 修改历史      :
  1.日    期   : 2016年6月18日
    作    者   : f00367319
    修改内容   : 新增
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    AT_APPCTRL_STRU                         stAppCtrl;
    VOS_UINT32                              ulResult;
    IMSA_AT_DMUSER_STRU                     stDmUser;
}IMSA_AT_DMUSER_QRY_CNF_STRU;


/*****************************************************************************
 结构名  : AT_IMSA_NICKNAME_INFO_STRU
 结构说明: IMS昵称结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucNickNameLen;
    VOS_CHAR                                acNickName[MN_CALL_DISPLAY_NAME_STRING_SZ];
    VOS_UINT8                               aucReserved[2];
} IMSA_AT_NICKNAME_INFO_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_NICKNAME_SET_REQ_STRU
 结构说明: 设置IMS昵称请求结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    AT_APPCTRL_STRU                         stAppCtrl;
    IMSA_AT_NICKNAME_INFO_STRU              stNickName;
} AT_IMSA_NICKNAME_SET_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_NICKNAME_SET_CNF_STRU
 结构说明: 设置IMS昵称返回结果结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef IMSA_AT_CNF_MSG_STRU IMSA_AT_NICKNAME_SET_CNF_STRU;

/*****************************************************************************
结构名    : AT_IMSA_NICKNAME_QRY_REQ_STRU
结构说明  : 查询IMS昵称结构体

1.日    期  : 2016年07月05日
  作    者  : w00316404
  修改内容  : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_NICKNAME_QRY_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_NICKNAME_QRY_CNF_STRU
 结构说明: 查询IMS昵称返回结果结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    AT_APPCTRL_STRU                         stAppCtrl;
    VOS_UINT32                              ulResult;                           /* 成功返回VOS_OK，失败返回VOS_ERR */
    IMSA_AT_NICKNAME_INFO_STRU              stNickName;
} IMSA_AT_NICKNAME_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_BATTERY_STATUS_INFO_STRU
 结构说明: IMS当前电池电量信息结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    AT_IMSA_BATTERY_STATUS_ENUM_UINT8       enBatteryStatus;
    VOS_UINT8                               aucReserved[3];
} AT_IMSA_BATTERY_STATUS_INFO_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_BATTERY_INFO_SET_REQ_STRU
 结构说明: 设置IMS当前电池电量信息请求结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    AT_APPCTRL_STRU                         stAppCtrl;
    AT_IMSA_BATTERY_STATUS_INFO_STRU        stBatteryStatusInfo;
} AT_IMSA_BATTERY_INFO_SET_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_BATTERY_INFO_SET_CNF_STRU
 结构说明: 设置IMS当前电池电量信息返回结果结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef IMSA_AT_CNF_MSG_STRU IMSA_AT_BATTERY_INFO_SET_CNF_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_REG_FAIL_INFO_STRU
 结构说明: IMS注册失败原因值结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    IMSA_AT_REG_FAIL_CODE_ENUM_UINT8        enFailCode;
    VOS_UINT8                               aucReserved[3];
} IMSA_AT_REG_FAIL_INFO_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_REG_FAIL_IND_STRU
 结构说明: 主动上报IMS注册失败原因值结构体

 修改历史      :
  1.日    期   : 2016年07月05日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    AT_APPCTRL_STRU                         stAppCtrl;
    IMSA_AT_REG_FAIL_INFO_STRU              stRegFailInfo;
} IMSA_AT_REG_FAIL_IND_STRU;

/*****************************************************************************
结构名    : AT_IMSA_VOLTEREG_NTF_STRU
结构说明  : 发送VOLTE REG NOTIFY结构体

1.日    期  : 2016年09月06日
  作    者  : w00316404
  修改内容  : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_VOLTEREG_NTF_STRU;

/*****************************************************************************
结构名    : AT_IMSA_CANCEL_ADD_VIDEO_REQ_STRU
结构说明  : 发送IMS VIDEO CALL CANCEL结构体

1.日    期  : 2016年10月13日
  作    者  : w00316404
  修改内容  : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_CANCEL_ADD_VIDEO_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_CANCEL_ADD_VIDEO_CNF_STRU
 结构说明: 设置VOLTE语音到视频过程中取消视频返回结果结构体

 修改历史      :
  1.日    期   : 2016年10月13日
    作    者   : w00316404
    修改内容   : 新增结构
*****************************************************************************/
typedef IMSA_AT_CNF_MSG_STRU IMSA_AT_CANCEL_ADD_VIDEO_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_REGERR_REPORT_SET_REQ_STRU
 结构说明: 设置IMS注册错误是否上报请求结构体

 修改历史      :
  1.日    期   : 2016年11月09日
    作    者   : w00209181
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                            /* _H2ASN_Skip */
    AT_APPCTRL_STRU                     stAppCtrl;
    VOS_UINT8                           ucReportFlag;   /* VOS_TRUE:允许主动上报；VOS_FALSE:不允许上报 */
    VOS_UINT8                           aucReserv[3];
} AT_IMSA_REGERR_REPORT_SET_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_REGERR_REPORT_SET_CNF_STRU
 结构说明: 设置IMS注册错误是否上报回复结构体

 修改历史      :
  1.日    期   : 2016年11月09日
    作    者   : w00209181
    修改内容   : 新增结构
*****************************************************************************/
typedef IMSA_AT_CNF_MSG_STRU IMSA_AT_REGERR_REPORT_SET_CNF_STRU;

/*****************************************************************************
 结构名  : AT_IMSA_REGERR_REPORT_QRY_REQ_STRU
 结构说明: 查询IMS注册错误是否上报请求结构体

 修改历史      :
  1.日    期   : 2016年11月09日
    作    者   : w00209181
    修改内容   : 新增结构
*****************************************************************************/
typedef AT_IMSA_MSG_STRU AT_IMSA_REGERR_REPORT_QRY_REQ_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_REGERR_REPORT_QRY_CNF_STRU
 结构说明: 查询IMS注册错误是否上报回复结构体

 修改历史      :
  1.日    期   : 2016年11月09日
    作    者   : w00209181
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */

    AT_APPCTRL_STRU                     stAppCtrl;
    VOS_UINT32                          ulResult;                               /* 成功返回VOS_OK，失败返回VOS_ERR */

    VOS_UINT8                           ucReportFlag;
    VOS_UINT8                           aucReserved[7];
} IMSA_AT_REGERR_REPORT_QRY_CNF_STRU;

/*****************************************************************************
 结构名  : IMSA_AT_REGERR_REPORT_IND_STRU
 结构说明: 主动上报IMS注册失败原因值结构体

 修改历史      :
  1.日    期   : 2016年11月09日
    作    者   : w00209181
    修改内容   : 新增结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                              ulMsgId;                            /* _H2ASN_Skip */
    AT_APPCTRL_STRU                         stAppCtrl;
    IMSA_AT_IMS_REG_DOMAIN_TYPE_ENUM_UINT8  enImsaRegDomain;
    IMSA_AT_REG_ERR_TYPE_ENUM_UINT8         enImsaRegErrType;
    VOS_UINT8                               aucRsv[2];
    IMSA_AT_PDN_FAIL_CAUSE_ENUM_UINT32      enImsaPdnFailCause;
    IMSA_AT_REG_FAIL_CAUSE_ENUM_UINT32      enImsaRegFailCause;
    VOS_CHAR                                acImsRegFailReasonCtx[IMSA_AT_REG_FAIL_CAUSE_STR_MAX_LEN];         /* 无字符串时全0 */
} IMSA_AT_REGERR_REPORT_IND_STRU;

/*****************************************************************************
  4 宏定义
*****************************************************************************/


/*****************************************************************************
  5 全局变量声明
*****************************************************************************/


/*****************************************************************************
  6 接口函数声明
*****************************************************************************/

/*****************************************************************************
  7 OTHERS定义
*****************************************************************************/

/* ASN解析结构 */
typedef struct
{
    VOS_UINT32                          ulMsgId;                                /*_H2ASN_MsgChoice_Export AT_IMSA_MSG_TYPE_ENUM_UINT32 */
    VOS_UINT8                           aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          AT_IMSA_MSG_TYPE_ENUM_UINT32
    ****************************************************************************/
}AT_IMSA_INTERFACE_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    AT_IMSA_INTERFACE_MSG_DATA           stMsgData;
} AtImsaInterface_MSG;


#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif


