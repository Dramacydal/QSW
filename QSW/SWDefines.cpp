#include "SWDefines.h"

quint8 Locale = 0;

QString CLIENT_VERSION("5.x.x");
QString QSW_BUILD("8");
QString CLIENT_BUILD = QString("%0").arg(_BUILD);

QString ProcFlagDesc[] =
{
    // 00 0x00000001
    "00 Killed by aggressor that receive experience or honor",
    // 01 0x00000002
    "01 Kill that yields experience or honor",
    // 02 0x00000004
    "02 Successful melee attack",
    // 03 0x00000008
    "03 Taken damage from melee strike hit",
    // 04 0x00000010
    "04 Successful attack by Spell that use melee weapon",
    // 05 0x00000020
    "05 Taken damage by Spell that use melee weapon",
    // 06 0x00000040
    "06 Successful Ranged attack (and wand spell cast)",
    // 07 0x00000080
    "07 Taken damage from ranged attack",
    // 08 0x00000100
    "08 Successful Ranged attack by Spell that use ranged weapon",
    // 09 0x00000200
    "09 Taken damage by Spell that use ranged weapon",
    // 10 0x00000400
    "10 Successful spell hit",
    // 11 0x00000800
    "11 Taken spell hit",
    // 12 0x00001000
    "12 Successful spell cast",
    // 13 0x00002000
    "13 Taken spell hit",
    // 14 0x00004000
    "14 Successful cast positive spell",
    // 15 0x00008000
    "15 Taken positive spell hit",
    // 16 0x00010000
    "16 Successful damage from harmful spell cast",
    // 17 0x00020000
    "17 Taken spell damage",
    // 18 0x00040000
    "18 Deal periodic damage",
    // 19 0x00080000
    "19 Taken periodic damage",
    // 20 0x00100000
    "20 Taken any damage",
    // 21 0x00200000
    "21 On trap activation",
    // 22 0x00400000
    "22 Taken off-hand melee attacks",
    // 23 0x00800000
    "23 Successful off-hand melee attacks",
    // 24 0x01000000
    "24 On death",
    // 25 0x02000000
    "25 On jump",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31"
};
