/*********************************************************
 * Copyright (C) 2007-2017 VMware, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation version 2.1 and no later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the Lesser GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA.
 *
 *********************************************************/

/*
 * unicodeTypes.h --
 *
 *      Types used throughout the Unicode library.
 */

#ifndef _UNICODE_TYPES_H_
#define _UNICODE_TYPES_H_

#define INCLUDE_ALLOW_MODULE
#define INCLUDE_ALLOW_USERLEVEL
#define INCLUDE_ALLOW_VMCORE
#define INCLUDE_ALLOW_VMKERNEL
#include "includeCheck.h"


#ifdef __cplusplus
extern "C" {
#endif

#include "vm_basic_types.h"
#include "vm_assert.h"

typedef ssize_t UnicodeIndex;

/*
 * Special UnicodeIndex value returned when a string is not found.
 */
enum {
   UNICODE_INDEX_NOT_FOUND = -1
};


/*
 * Encodings passed to convert encoded byte strings to and from
 * Unicode.
 *
 * Keep this enum synchronized with ICU_ENCODING_LIST in unicodeICU.cc!
 */

typedef enum {
   STRING_ENCODING_FIRST,

   /*
    * Byte string encodings that support all characters in Unicode.
    *
    * If you don't know what to use for bytes in a new system, use
    * STRING_ENCODING_UTF8.
    */

   STRING_ENCODING_UTF8 = STRING_ENCODING_FIRST,

   STRING_ENCODING_UTF16_LE, // Little-endian UTF-16.
   STRING_ENCODING_UTF16_BE, // Big-endian UTF-16.
   STRING_ENCODING_UTF16_XE, // UTF-16 with BOM.

   STRING_ENCODING_UTF32_LE, // Little-endian UTF-32.
   STRING_ENCODING_UTF32_BE, // Big-endian UTF-32.
   STRING_ENCODING_UTF32_XE, // UTF-32 with BOM.

   /*
    * Legacy byte string encodings that only support a subset of Unicode.
    */

   /*
    * Latin encodings
    */

   STRING_ENCODING_US_ASCII,
   STRING_ENCODING_ISO_8859_1,
   STRING_ENCODING_ISO_8859_2,
   STRING_ENCODING_ISO_8859_3,
   STRING_ENCODING_ISO_8859_4,
   STRING_ENCODING_ISO_8859_5,
   STRING_ENCODING_ISO_8859_6,
   STRING_ENCODING_ISO_8859_7,
   STRING_ENCODING_ISO_8859_8,
   STRING_ENCODING_ISO_8859_9,
   STRING_ENCODING_ISO_8859_10,
   // ISO-8859-11 is unused.
   // Oddly, there is no ISO-8859-12.
   STRING_ENCODING_ISO_8859_13,
   STRING_ENCODING_ISO_8859_14,
   STRING_ENCODING_ISO_8859_15,

   /*
    * Chinese encodings
    */

   STRING_ENCODING_GB_18030,
   STRING_ENCODING_BIG_5,
   STRING_ENCODING_BIG_5_HK,
   STRING_ENCODING_GBK,
   STRING_ENCODING_GB_2312,
   STRING_ENCODING_ISO_2022_CN,

   /*
    * Japanese encodings
    */

   STRING_ENCODING_SHIFT_JIS,
   STRING_ENCODING_EUC_JP,
   STRING_ENCODING_ISO_2022_JP,
   STRING_ENCODING_ISO_2022_JP_1,
   STRING_ENCODING_ISO_2022_JP_2,

   /*
    * Korean encodings
    */

   STRING_ENCODING_ISO_2022_KR,

   /*
    * Windows encodings
    */

   STRING_ENCODING_WINDOWS_1250,
   STRING_ENCODING_WINDOWS_1251,
   STRING_ENCODING_WINDOWS_1252,
   STRING_ENCODING_WINDOWS_1253,
   STRING_ENCODING_WINDOWS_1254,
   STRING_ENCODING_WINDOWS_1255,
   STRING_ENCODING_WINDOWS_1256,
   STRING_ENCODING_WINDOWS_1257,
   STRING_ENCODING_WINDOWS_1258,

   STRING_ENCODING_ISO_6937_2_ADD,
   STRING_ENCODING_JIS_X0201,
   STRING_ENCODING_JIS_ENCODING,
   STRING_ENCODING_EXTENDED_UNIX_CODE_FIXED_WIDTH_FOR_JAPANESE,
   STRING_ENCODING_BS_4730,
   STRING_ENCODING_SEN_850200_C,
   STRING_ENCODING_IT,
   STRING_ENCODING_ES,
   STRING_ENCODING_DIN_66003,
   STRING_ENCODING_NS_4551_1,
   STRING_ENCODING_NF_Z_62_010,
   STRING_ENCODING_ISO_10646_UTF_1,
   STRING_ENCODING_ISO_646_BASIC_1983,
   STRING_ENCODING_INVARIANT,
   STRING_ENCODING_ISO_646_IRV_1983,
   STRING_ENCODING_NATS_SEFI,
   STRING_ENCODING_NATS_SEFI_ADD,
   STRING_ENCODING_NATS_DANO,
   STRING_ENCODING_NATS_DANO_ADD,
   STRING_ENCODING_SEN_850200_B,
   STRING_ENCODING_KS_C_5601_1987,
   STRING_ENCODING_JIS_C6220_1969_JP,
   STRING_ENCODING_JIS_C6220_1969_RO,
   STRING_ENCODING_PT,
   STRING_ENCODING_GREEK7_OLD,
   STRING_ENCODING_LATIN_GREEK,
   STRING_ENCODING_NF_Z_62_010__1973_,
   STRING_ENCODING_LATIN_GREEK_1,
   STRING_ENCODING_ISO_5427,
   STRING_ENCODING_JIS_C6226_1978,
   STRING_ENCODING_BS_VIEWDATA,
   STRING_ENCODING_INIS,
   STRING_ENCODING_INIS_8,
   STRING_ENCODING_INIS_CYRILLIC,
   STRING_ENCODING_ISO_5427_1981,
   STRING_ENCODING_ISO_5428_1980,
   STRING_ENCODING_GB_1988_80,
   STRING_ENCODING_GB_2312_80,
   STRING_ENCODING_NS_4551_2,
   STRING_ENCODING_VIDEOTEX_SUPPL,
   STRING_ENCODING_PT2,
   STRING_ENCODING_ES2,
   STRING_ENCODING_MSZ_7795_3,
   STRING_ENCODING_JIS_C6226_1983,
   STRING_ENCODING_GREEK7,
   STRING_ENCODING_ASMO_449,
   STRING_ENCODING_ISO_IR_90,
   STRING_ENCODING_JIS_C6229_1984_A,
   STRING_ENCODING_JIS_C6229_1984_B,
   STRING_ENCODING_JIS_C6229_1984_B_ADD,
   STRING_ENCODING_JIS_C6229_1984_HAND,
   STRING_ENCODING_JIS_C6229_1984_HAND_ADD,
   STRING_ENCODING_JIS_C6229_1984_KANA,
   STRING_ENCODING_ISO_2033_1983,
   STRING_ENCODING_ANSI_X3_110_1983,
   STRING_ENCODING_T_61_7BIT,
   STRING_ENCODING_T_61_8BIT,
   STRING_ENCODING_ECMA_CYRILLIC,
   STRING_ENCODING_CSA_Z243_4_1985_1,
   STRING_ENCODING_CSA_Z243_4_1985_2,
   STRING_ENCODING_CSA_Z243_4_1985_GR,
   STRING_ENCODING_ISO_8859_6_E,
   STRING_ENCODING_ISO_8859_6_I,
   STRING_ENCODING_T_101_G2,
   STRING_ENCODING_ISO_8859_8_E,
   STRING_ENCODING_ISO_8859_8_I,
   STRING_ENCODING_CSN_369103,
   STRING_ENCODING_JUS_I_B1_002,
   STRING_ENCODING_IEC_P27_1,
   STRING_ENCODING_JUS_I_B1_003_SERB,
   STRING_ENCODING_JUS_I_B1_003_MAC,
   STRING_ENCODING_GREEK_CCITT,
   STRING_ENCODING_NC_NC00_10_81,
   STRING_ENCODING_ISO_6937_2_25,
   STRING_ENCODING_GOST_19768_74,
   STRING_ENCODING_ISO_8859_SUPP,
   STRING_ENCODING_ISO_10367_BOX,
   STRING_ENCODING_LATIN_LAP,
   STRING_ENCODING_JIS_X0212_1990,
   STRING_ENCODING_DS_2089,
   STRING_ENCODING_US_DK,
   STRING_ENCODING_DK_US,
   STRING_ENCODING_KSC5636,
   STRING_ENCODING_UNICODE_1_1_UTF_7,
   STRING_ENCODING_ISO_2022_CN_EXT,
   STRING_ENCODING_ISO_8859_16,
   STRING_ENCODING_OSD_EBCDIC_DF04_15,
   STRING_ENCODING_OSD_EBCDIC_DF03_IRV,
   STRING_ENCODING_OSD_EBCDIC_DF04_1,
   STRING_ENCODING_ISO_11548_1,
   STRING_ENCODING_KZ_1048,
   STRING_ENCODING_ISO_10646_UCS_2,
   STRING_ENCODING_ISO_10646_UCS_4,
   STRING_ENCODING_ISO_10646_UCS_BASIC,
   STRING_ENCODING_ISO_10646_UNICODE_LATIN1,
   STRING_ENCODING_ISO_10646_J_1,
   STRING_ENCODING_ISO_UNICODE_IBM_1261,
   STRING_ENCODING_ISO_UNICODE_IBM_1268,
   STRING_ENCODING_ISO_UNICODE_IBM_1276,
   STRING_ENCODING_ISO_UNICODE_IBM_1264,
   STRING_ENCODING_ISO_UNICODE_IBM_1265,
   STRING_ENCODING_UNICODE_1_1,
   STRING_ENCODING_SCSU,
   STRING_ENCODING_UTF_7,
   STRING_ENCODING_CESU_8,
   STRING_ENCODING_BOCU_1,
   STRING_ENCODING_ISO_8859_1_WINDOWS_3_0_LATIN_1,
   STRING_ENCODING_ISO_8859_1_WINDOWS_3_1_LATIN_1,
   STRING_ENCODING_ISO_8859_2_WINDOWS_LATIN_2,
   STRING_ENCODING_ISO_8859_9_WINDOWS_LATIN_5,
   STRING_ENCODING_HP_ROMAN8,
   STRING_ENCODING_ADOBE_STANDARD_ENCODING,
   STRING_ENCODING_VENTURA_US,
   STRING_ENCODING_VENTURA_INTERNATIONAL,
   STRING_ENCODING_DEC_MCS,
   STRING_ENCODING_IBM_850,
   STRING_ENCODING_PC8_DANISH_NORWEGIAN,
   STRING_ENCODING_IBM_862,
   STRING_ENCODING_PC8_TURKISH,
   STRING_ENCODING_IBM_SYMBOLS,
   STRING_ENCODING_IBM_THAI,
   STRING_ENCODING_HP_LEGAL,
   STRING_ENCODING_HP_PI_FONT,
   STRING_ENCODING_HP_MATH8,
   STRING_ENCODING_ADOBE_SYMBOL_ENCODING,
   STRING_ENCODING_HP_DESKTOP,
   STRING_ENCODING_VENTURA_MATH,
   STRING_ENCODING_MICROSOFT_PUBLISHING,
   STRING_ENCODING_WINDOWS_31J,
   STRING_ENCODING_MACINTOSH,
   STRING_ENCODING_IBM_037,
   STRING_ENCODING_IBM_038,
   STRING_ENCODING_IBM_273,
   STRING_ENCODING_IBM_274,
   STRING_ENCODING_IBM_275,
   STRING_ENCODING_IBM_277,
   STRING_ENCODING_IBM_278,
   STRING_ENCODING_IBM_280,
   STRING_ENCODING_IBM_281,
   STRING_ENCODING_IBM_284,
   STRING_ENCODING_IBM_285,
   STRING_ENCODING_IBM_290,
   STRING_ENCODING_IBM_297,
   STRING_ENCODING_IBM_420,
   STRING_ENCODING_IBM_423,
   STRING_ENCODING_IBM_424,
   STRING_ENCODING_IBM_437,
   STRING_ENCODING_IBM_500,
   STRING_ENCODING_IBM_851,
   STRING_ENCODING_IBM_852,
   STRING_ENCODING_IBM_855,
   STRING_ENCODING_IBM_857,
   STRING_ENCODING_IBM_860,
   STRING_ENCODING_IBM_861,
   STRING_ENCODING_IBM_863,
   STRING_ENCODING_IBM_864,
   STRING_ENCODING_IBM_865,
   STRING_ENCODING_IBM_868,
   STRING_ENCODING_IBM_869,
   STRING_ENCODING_IBM_870,
   STRING_ENCODING_IBM_871,
   STRING_ENCODING_IBM_880,
   STRING_ENCODING_IBM_891,
   STRING_ENCODING_IBM_903,
   STRING_ENCODING_IBM_904,
   STRING_ENCODING_IBM_905,
   STRING_ENCODING_IBM_918,
   STRING_ENCODING_IBM_1026,
   STRING_ENCODING_EBCDIC_AT_DE,
   STRING_ENCODING_EBCDIC_AT_DE_A,
   STRING_ENCODING_EBCDIC_CA_FR,
   STRING_ENCODING_EBCDIC_DK_NO,
   STRING_ENCODING_EBCDIC_DK_NO_A,
   STRING_ENCODING_EBCDIC_FI_SE,
   STRING_ENCODING_EBCDIC_FI_SE_A,
   STRING_ENCODING_EBCDIC_FR,
   STRING_ENCODING_EBCDIC_IT,
   STRING_ENCODING_EBCDIC_PT,
   STRING_ENCODING_EBCDIC_ES,
   STRING_ENCODING_EBCDIC_ES_A,
   STRING_ENCODING_EBCDIC_ES_S,
   STRING_ENCODING_EBCDIC_UK,
   STRING_ENCODING_EBCDIC_US,
   STRING_ENCODING_UNKNOWN_8BIT,
   STRING_ENCODING_MNEMONIC,
   STRING_ENCODING_MNEM,
   STRING_ENCODING_VISCII,
   STRING_ENCODING_VIQR,
   STRING_ENCODING_KOI8_R,
   STRING_ENCODING_HZ_GB_2312,
   STRING_ENCODING_IBM_866,
   STRING_ENCODING_IBM_775,
   STRING_ENCODING_KOI8_U,
   STRING_ENCODING_IBM_00858,
   STRING_ENCODING_IBM_00924,
   STRING_ENCODING_IBM_01140,
   STRING_ENCODING_IBM_01141,
   STRING_ENCODING_IBM_01142,
   STRING_ENCODING_IBM_01143,
   STRING_ENCODING_IBM_01144,
   STRING_ENCODING_IBM_01145,
   STRING_ENCODING_IBM_01146,
   STRING_ENCODING_IBM_01147,
   STRING_ENCODING_IBM_01148,
   STRING_ENCODING_IBM_01149,
   STRING_ENCODING_IBM_1047,
   STRING_ENCODING_PTCP154,
   STRING_ENCODING_AMIGA_1251,
   STRING_ENCODING_KOI7_SWITCHED,
   STRING_ENCODING_BRF,
   STRING_ENCODING_TSCII,
   STRING_ENCODING_TIS_620,
   STRING_ENCODING_WINDOWS_709,
   STRING_ENCODING_WINDOWS_710,
   STRING_ENCODING_WINDOWS_720,
   STRING_ENCODING_WINDOWS_737,
   STRING_ENCODING_WINDOWS_875,
   STRING_ENCODING_WINDOWS_1361,
   STRING_ENCODING_WINDOWS_10000,
   STRING_ENCODING_WINDOWS_10001,
   STRING_ENCODING_WINDOWS_10002,
   STRING_ENCODING_WINDOWS_10003,
   STRING_ENCODING_WINDOWS_10004,
   STRING_ENCODING_WINDOWS_10005,
   STRING_ENCODING_WINDOWS_10006,
   STRING_ENCODING_WINDOWS_10007,
   STRING_ENCODING_WINDOWS_10008,
   STRING_ENCODING_WINDOWS_10010,
   STRING_ENCODING_WINDOWS_10017,
   STRING_ENCODING_WINDOWS_10021,
   STRING_ENCODING_WINDOWS_10029,
   STRING_ENCODING_WINDOWS_10079,
   STRING_ENCODING_WINDOWS_10081,
   STRING_ENCODING_WINDOWS_10082,
   STRING_ENCODING_WINDOWS_20000,
   STRING_ENCODING_WINDOWS_20001,
   STRING_ENCODING_WINDOWS_20002,
   STRING_ENCODING_WINDOWS_20003,
   STRING_ENCODING_WINDOWS_20004,
   STRING_ENCODING_WINDOWS_20005,
   STRING_ENCODING_WINDOWS_20105,
   STRING_ENCODING_WINDOWS_20106,
   STRING_ENCODING_WINDOWS_20107,
   STRING_ENCODING_WINDOWS_20108,
   STRING_ENCODING_WINDOWS_20269,
   STRING_ENCODING_WINDOWS_20833,
   STRING_ENCODING_WINDOWS_20949,
   STRING_ENCODING_WINDOWS_21025,
   STRING_ENCODING_WINDOWS_21027,
   STRING_ENCODING_WINDOWS_29001,
   STRING_ENCODING_WINDOWS_38598,
   STRING_ENCODING_WINDOWS_50221,
   STRING_ENCODING_WINDOWS_50222,
   STRING_ENCODING_WINDOWS_50229,
   STRING_ENCODING_WINDOWS_50930,
   STRING_ENCODING_WINDOWS_50931,
   STRING_ENCODING_WINDOWS_50933,
   STRING_ENCODING_WINDOWS_50935,
   STRING_ENCODING_WINDOWS_50936,
   STRING_ENCODING_WINDOWS_50937,
   STRING_ENCODING_WINDOWS_50939,
   STRING_ENCODING_WINDOWS_51936,
   STRING_ENCODING_WINDOWS_51950,
   STRING_ENCODING_WINDOWS_57002,
   STRING_ENCODING_WINDOWS_57003,
   STRING_ENCODING_WINDOWS_57004,
   STRING_ENCODING_WINDOWS_57005,
   STRING_ENCODING_WINDOWS_57006,
   STRING_ENCODING_WINDOWS_57007,
   STRING_ENCODING_WINDOWS_57008,
   STRING_ENCODING_WINDOWS_57009,
   STRING_ENCODING_WINDOWS_57010,
   STRING_ENCODING_WINDOWS_57011,
   STRING_ENCODING_IBM_813,
   STRING_ENCODING_IBM_943_P130_1999,
   STRING_ENCODING_IBM_33722,
   STRING_ENCODING_WINDOWS_949,
   STRING_ENCODING_IBM_1363,
   STRING_ENCODING_IBM_1386,
   STRING_ENCODING_IBM_1373,
   STRING_ENCODING_IBM_5471,
   STRING_ENCODING_IBM_874,

   // Add more encodings here.

   // Sentinel value after the last explicitly specified encoding.
   STRING_ENCODING_MAX_SPECIFIED,

   /*
    * The environment-specified "default" encoding for this process.
    */

   STRING_ENCODING_DEFAULT = -1,
   STRING_ENCODING_UNKNOWN = -2,

   /*
    * UTF-16 and UTF-32 in native byte order.
    */

   STRING_ENCODING_UTF16 = STRING_ENCODING_UTF16_LE,
   STRING_ENCODING_UTF32 = STRING_ENCODING_UTF32_LE,
} StringEncoding;


const char *Unicode_EncodingEnumToName(StringEncoding encoding);
StringEncoding Unicode_EncodingNameToEnum(const char *encodingName);
Bool Unicode_IsEncodingValid(StringEncoding encoding);
void Unicode_Init(int argc, char ***argv, char ***envp);
void Unicode_InitEx(int argc, char ***argv, char ***envp,
                    const char *icuDataDir);
#if defined (_WIN32)
void Unicode_InitW(int argc, utf16_t **wargv, utf16_t **wenvp,
                   char ***argv, char ***envp);
#endif

StringEncoding Unicode_GetCurrentEncoding(void);
StringEncoding Unicode_ResolveEncoding(StringEncoding encoding);

#ifdef __cplusplus
}
#endif

#endif // _UNICODE_TYPES_H_
