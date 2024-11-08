﻿#pragma once

#include "NtlSharedDef.h"
#include "NtlSharedType.h"
#include "NtlVector.h"
#include "NtlItem.h"

enum eNTL_INVITATION_RESPONSE
{
	NTL_INVITATION_RESPONSE_ACCEPT = 0,		// accept party invite
	NTL_INVITATION_RESPONSE_DECLINE,		// decline party invite
	NTL_INVITATION_RESPONSE_EXPIRE,			// party invite time-out

	NTL_INVITATION_RESPONSE_COUNT,

	NTL_INVITATION_RESPONSE_FIRST = NTL_INVITATION_RESPONSE_ACCEPT,
	NTL_INVITATION_RESPONSE_LAST = NTL_INVITATION_RESPONSE_EXPIRE
};

enum eNTL_PARTY_ZENNY_LOOTING
{
	NTL_PARTY_ZENNY_LOOTING_GREEDILY = 0,		// Looter receive everything
	NTL_PARTY_ZENNY_LOOTING_SHARED,				// Zeni shared in party

	NTL_PARTY_ZENNY_LOOTING_COUNT,

	NTL_PARTY_ZENNY_LOOTING_UNKNOWN = 0xFF,

	NTL_PARTY_ZENNY_LOOTING_FIRST = NTL_PARTY_ZENNY_LOOTING_GREEDILY,
	NTL_PARTY_ZENNY_LOOTING_LAST = NTL_PARTY_ZENNY_LOOTING_SHARED
};

enum eNTL_PARTY_ITEM_LOOTING
{
	NTL_PARTY_ITEM_LOOTING_GREEDILY = 0,			// looter receives the item
	NTL_PARTY_ITEM_LOOTING_IN_ORDER,				// distribution in order
	NTL_PARTY_ITEM_LOOTING_IN_ORDER_SEPERATELY,		// Treat distribution orders of Normal and Excellent grades separately.
	
	NTL_PARTY_ITEM_LOOTING_IN_LEADER,				// Leader randomly distributed
	NTL_PARTY_ITEM_LOOTING_BY_ZENNY,				// Register Zeni and accept and distribute
	NTL_PARTY_ITEM_LOOTING_DICE,					// Dice distribution
	NTL_PARTY_ITEM_LOOTING_DICE_BY_EQUIPED,			// Only allow user to dice if he can equip the item

	NTL_PARTY_ITEM_LOOTING_COUNT,

	NTL_PARTY_ITEM_LOOTING_UNKNOWN = 0xFF,

	NTL_PARTY_ITEM_LOOTING_FIRST = NTL_PARTY_ITEM_LOOTING_GREEDILY,
	NTL_PARTY_ITEM_LOOTING_LAST = NTL_PARTY_ITEM_LOOTING_COUNT - 1
};

enum eDBO_ITEM_DICE
{
	DBO_ITEM_DICE_DICE = 1,
	DBO_ITEM_DICE_RESERVE,
	DBO_ITEM_DICE_CANCELED
};

enum eDBO_PARTY_OPTION
{
	DBO_PARTY_OPTION_CANT_INVITE = 0,
	DBO_PARTY_OPTION_CANT_LEAVE,
	DBO_PARTY_OPTION_CANT_KICK_OUT,
	DBO_PARTY_OPTION_CANT_APPOINT_LEADER
};

enum eDBO_PARTY_OPTION_FLAG
{
	DBO_PARTY_OPTION_FLAG_CANT_INVITE = 1 << DBO_PARTY_OPTION_CANT_INVITE,
	DBO_PARTY_OPTION_FLAG_CANT_LEAVE = 1 << DBO_PARTY_OPTION_CANT_LEAVE,
	DBO_PARTY_OPTION_FLAG_CANT_KICK_OUT = 1 << DBO_PARTY_OPTION_CANT_KICK_OUT,
	DBO_PARTY_OPTION_FLAG_CANT_APPOINT_LEADER = 1 << DBO_PARTY_OPTION_CANT_APPOINT_LEADER
};

enum eNTL_PARTY_SELECT_TYPE
{
  NTL_PARTY_SELECT_TYPE_NONE = 0,

  NTL_PARTY_SELECT_TYPE_CCBD_START,
  NTL_PARTY_SELECT_TYPE_CCBD_REWARD,

  NTL_PARTY_SELECT_TYPE_COUNT,

  NTL_PARTY_SELECT_TYPE_FIRST = NTL_PARTY_SELECT_TYPE_NONE,
  NTL_PARTY_SELECT_TYPE_LAST = NTL_PARTY_SELECT_TYPE_COUNT - 1
};

//-----------------------------------------------------------------------------------
//	ÆÄÆ¼ °ü·Ã »ó¼ö Á¤ÀÇ
//-----------------------------------------------------------------------------------
// Basic Values
const DWORD NTL_MAX_PARTY_COUNT = 2000; //max party per channel

const DWORD NTL_MAX_MEMBER_IN_PARTY = 5;
const float NTL_VALID_DISTANCE_FOR_EXP_FROM_VICTIM = 100.0f;
const float DBO_VALID_DISTANCE_TO_GET_ZENNY_IN_PARTY = 100.0f;
const float DBO_VALID_DISTANCE_TO_GET_ITEM_IN_PARTY = 100.0f;
const DWORD	NTL_PARTY_MAX_AGGRO = 7;

const DWORD DBO_MAX_TIME_PARTY_DICE_ITEM = 60000;		//60sec 

// Contribution Point
//const DWORD NTL_PARTY_MAX_CONTRIBUTION_POINT = 200;

//Party matchin
const DWORD NTL_PARTY_MATCHING_PARTY_LIST_COUNT = 8;


// Party Option
const DWORD DBO_PARTY_OPTION_FLAG_DEFAULT = 0;
const DWORD DBO_PARTY_OPTION_FLAG_TMQ =
			DBO_PARTY_OPTION_FLAG_CANT_INVITE |
			DBO_PARTY_OPTION_FLAG_CANT_LEAVE |
			DBO_PARTY_OPTION_FLAG_CANT_KICK_OUT |
			DBO_PARTY_OPTION_FLAG_CANT_APPOINT_LEADER;
const DWORD DBO_PARTY_OPTION_FLAG_RANK_BATTLE =
			DBO_PARTY_OPTION_FLAG_CANT_INVITE |
			DBO_PARTY_OPTION_FLAG_CANT_LEAVE |
			DBO_PARTY_OPTION_FLAG_CANT_KICK_OUT |
			DBO_PARTY_OPTION_FLAG_CANT_APPOINT_LEADER;

const DWORD DBO_PARTY_OPTION_FLAG_BUDOKAI = 
			DBO_PARTY_OPTION_FLAG_CANT_INVITE |
			DBO_PARTY_OPTION_FLAG_CANT_LEAVE |
			DBO_PARTY_OPTION_FLAG_CANT_KICK_OUT |
			DBO_PARTY_OPTION_FLAG_CANT_APPOINT_LEADER;
			

const DWORD NTL_MAX_SHARETARGET_COUNT = 5;// °øÀ¯Å¸°Ù ½½·Ô ÃÖ´ë °³¼ö[3/28/2008 SGpro]
//-----------------------------------------------------------------------------------

enum eROLEPLAY_TYPE
{
	ROLEPLAY_TYPE_DEFENCE,
	ROLEPLAY_TYPE_HEAL,
	ROLEPLAY_TYPE_ATTACK,

	ROLEPLAY_TYPE_COUNT,
	ROLEPLAY_TYPE_INVALID = 0xFF,
};

enum ePARTY_MATCHING_DUNGEON_TYPE
{
	ePARTY_MATCHING_DUNGEON_TYPE_ULTIMATE_DUNGEON,
	ePARTY_MATCHING_DUNGEON_TYPE_TIMEMACHINE_QUEST,
	ePARTY_MATCHING_DUNGEON_TYPE_CC_BATTLE_DUNGEON,
	ePARTY_MATCHING_DUNGEON_TYPE_RANK_BATTLE,

	ePARTY_MATCHING_DUNGEON_TYPE_COUNT,
	ePARTY_MATCHING_DUNGEON_TYPE_INVALID = 0xFF,
};

#pragma pack(1)

struct sPARTY_MEMBER_INFO
{
	HOBJECT hHandle;
	WCHAR awchMemberName[NTL_MAX_SIZE_CHAR_NAME + 1];
	BYTE byRace;
	BYTE byClass;
	BYTE byLevel;
	int curLp;
	int maxLp;
	WORD wCurEP;
	WORD wMaxEP;
	DWORD dwZenny;
	TBLIDX worldTblidx;
	WORLDID worldId;
	sVECTOR3 vCurLoc;
};

struct sDBO_ZENNY_DATA
{
	CHARACTERID		memberCharId;
	DWORD			dwZenny;
};

struct sINVEST_ZENNY_INFO
{
	HOBJECT hMember;
	DWORD dwZenny;
};

struct sZENNY_INFO
{
	CHARACTERID charId;
	DWORD dwZenny; //È¹µæÇÑ ÃÑ Á¦´Ï( dwOrgZenny + dwBonusZenny )
	DWORD dwOrgZenny; //¿ø·¡ È¹µæÇÒ Á¦´Ï
	DWORD dwBonusZenny; //Ãß°¡ È¹µæ Á¦´Ï
};

// °øÀ¯Å¸°Ù µ¥ÀÌÅ¸ [3/28/2008 SGpro]
struct sSHARETARGET_INFO
{
	HOBJECT hTarget;
};

struct sPARTY_SELECT
{
  HOBJECT hPc;
  CHARACTERID charId;
  BYTE bySelectState;
};

struct sPARTY_SELECT_DATA
{
	sPARTY_SELECT aMameber[NTL_MAX_MEMBER_IN_PARTY];
};

struct SPartyMatchingList
{
	PARTYID			partyId;
	WCHAR			wszPartyName[NTL_MAX_SIZE_PARTY_NAME + 1];
	BYTE			byDifficulty;
	BYTE			byDungeonType;
	BYTE			byRegionType;
	BYTE			byCurMemberCount;
};

struct SPartyMatchingMemberInfo
{
	BYTE			byRoleplay;
	BYTE			byLevel;
	WCHAR			awchCharName[NTL_MAX_SIZE_CHAR_NAME + 1];
	SERVERCHANNELID	byServerChannelIndex;
	bool			bPartyLeader;
};


#pragma pack()