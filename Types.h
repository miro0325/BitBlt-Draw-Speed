#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;

using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

class Vector;
class VectorInt;

using Pos = Vector;
using Vec2 = Vector;
using Vec2Int = VectorInt;

struct STAT
{
	int32 HP = 0;
	int32 MaxHP = 0;
	float Speed = 0;
};