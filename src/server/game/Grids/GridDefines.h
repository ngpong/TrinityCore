/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_GRIDDEFINES_H
#define TRINITY_GRIDDEFINES_H

#include "Common.h"
#include "ObjectGuid.h"
#include "NGrid.h"
#include <cmath>

// Forward class definitions
class Corpse;
class Creature;
class DynamicObject;
class GameObject;
class Pet;
class Player;

// 一张地图由 64x64 个 Grid 构成
//
// 每个 Grid 里面由 8x8 个 Cell 构成
//
// 一个 GRID 的边长为 533.3333f，一张地图的大小（面积）则为 64 * 64 * 533.3333f
//
// 一个 CELL 的边长为 533.3333f / 8
//
// 下面的宏大多数描述的是一维的情况

#define MAX_NUMBER_OF_CELLS     8

#define MAX_NUMBER_OF_GRIDS      64

#define SIZE_OF_GRIDS            533.3333f
#define CENTER_GRID_ID           (MAX_NUMBER_OF_GRIDS/2)

#define CENTER_GRID_OFFSET      (SIZE_OF_GRIDS/2)

#define MIN_GRID_DELAY          (MINUTE*IN_MILLISECONDS)
#define MIN_MAP_UPDATE_DELAY    1

#define SIZE_OF_GRID_CELL       (SIZE_OF_GRIDS/MAX_NUMBER_OF_CELLS)

#define CENTER_GRID_CELL_ID     (MAX_NUMBER_OF_CELLS*MAX_NUMBER_OF_GRIDS/2)
#define CENTER_GRID_CELL_OFFSET (SIZE_OF_GRID_CELL/2)

#define TOTAL_NUMBER_OF_CELLS_PER_MAP    (MAX_NUMBER_OF_GRIDS*MAX_NUMBER_OF_CELLS)

#define MAP_RESOLUTION 128

#define MAP_SIZE                (SIZE_OF_GRIDS*MAX_NUMBER_OF_GRIDS)
#define MAP_HALFSIZE            (MAP_SIZE/2)

// AllWorldObjectTypes:
//   Player -> Creature -> Corpse -> DynamicObject -> TypeNull
// AllWorldObjectTypes     = TypeList<Player, TypeList<Creature, TypeList<Corpse, TypeList<DynamicObject, TypeNull>>>>
//
// AllGridObjectTypes:
//   GameObject -> Creature -> DynamicObject -> Corpse -> TypeNull
// AllGridObjectTypes      = TypeList<GameObject, TypeList<Creature, TypeList<DynamicObject, TypeList<Corpse, TypeNull>>>>
//
// AllMapStoredObjectTypes:
//   Creature -> GameObject -> DynamicObject -> Pet -> Corpse -> TypeNull
// AllMapStoredObjectTypes = TypeList<Creature, TypeList<GameObject, TypeList<DynamicObject, TypeList<Pet, TypeList<Corpse, TypeNull>>>>>

// Creature used instead pet to simplify *::Visit templates (not required duplicate code for Creature->Pet case)
typedef TYPELIST_4(Player, Creature/*pets*/, Corpse/*resurrectable*/, DynamicObject/*farsight target*/) AllWorldObjectTypes;
typedef TYPELIST_4(GameObject, Creature/*except pets*/, DynamicObject, Corpse/*Bones*/) AllGridObjectTypes;
typedef TYPELIST_5(Creature, GameObject, DynamicObject, Pet, Corpse) AllMapStoredObjectTypes;

typedef GridRefManager<Corpse>          CorpseMapType;
typedef GridRefManager<Creature>        CreatureMapType;
typedef GridRefManager<DynamicObject>   DynamicObjectMapType;
typedef GridRefManager<GameObject>      GameObjectMapType;
typedef GridRefManager<Player>          PlayerMapType;

enum GridMapTypeMask
{
    GRID_MAP_TYPE_MASK_CORPSE           = 0x01,
    GRID_MAP_TYPE_MASK_CREATURE         = 0x02,
    GRID_MAP_TYPE_MASK_DYNAMICOBJECT    = 0x04,
    GRID_MAP_TYPE_MASK_GAMEOBJECT       = 0x08,
    GRID_MAP_TYPE_MASK_PLAYER           = 0x10,
    GRID_MAP_TYPE_MASK_ALL              = 0x1F
};

// 下面的代码属于是显式模板实例化声明，为了增快编译速度；但是他们会导致 clangd 出错；
// extern template class Grid<Player, AllWorldObjectTypes, AllGridObjectTypes>;
// extern template class NGrid<MAX_NUMBER_OF_CELLS, Player, AllWorldObjectTypes, AllGridObjectTypes>;

// 下面的代码属于是显式模板实例化声明，为了增快编译速度；但是他们会导致 clangd 出错；
// extern template class TypeMapContainer<AllGridObjectTypes>;
// extern template class TypeMapContainer<AllWorldObjectTypes>;

typedef Grid<Player, AllWorldObjectTypes, AllGridObjectTypes> GridType;
typedef NGrid<MAX_NUMBER_OF_CELLS, Player, AllWorldObjectTypes, AllGridObjectTypes> NGridType;

typedef TypeMapContainer<AllGridObjectTypes> GridTypeMapContainer;
typedef TypeMapContainer<AllWorldObjectTypes> WorldTypeMapContainer;

template<uint32 LIMIT>
struct CoordPair
{
    CoordPair(uint32 x=0, uint32 y=0)
        : x_coord(x), y_coord(y)
    { }

    CoordPair(const CoordPair<LIMIT> &obj)
        : x_coord(obj.x_coord), y_coord(obj.y_coord)
    { }

    CoordPair<LIMIT> & operator=(const CoordPair<LIMIT> &obj)
    {
        x_coord = obj.x_coord;
        y_coord = obj.y_coord;
        return *this;
    }

    void dec_x(uint32 val)
    {
        if (x_coord > val)
            x_coord -= val;
        else
            x_coord = 0;
    }

    void inc_x(uint32 val)
    {
        if (x_coord + val < LIMIT)
            x_coord += val;
        else
            x_coord = LIMIT - 1;
    }

    void dec_y(uint32 val)
    {
        if (y_coord > val)
            y_coord -= val;
        else
            y_coord = 0;
    }

    void inc_y(uint32 val)
    {
        if (y_coord + val < LIMIT)
            y_coord += val;
        else
            y_coord = LIMIT - 1;
    }

    bool IsCoordValid() const
    {
        return x_coord < LIMIT && y_coord < LIMIT;
    }

    CoordPair& normalize()
    {
        x_coord = std::min(x_coord, LIMIT - 1);
        y_coord = std::min(y_coord, LIMIT - 1);
        return *this;
    }

    uint32 GetId() const
    {
        return y_coord * LIMIT + x_coord;
    }

    friend bool operator==(CoordPair const& p1, CoordPair const& p2) = default;

    uint32 x_coord;
    uint32 y_coord;
};

typedef CoordPair<MAX_NUMBER_OF_GRIDS> GridCoord;
typedef CoordPair<TOTAL_NUMBER_OF_CELLS_PER_MAP> CellCoord;

namespace Trinity
{
    template<class RET_TYPE, int CENTER_VAL>
    inline RET_TYPE Compute(float x, float y, float center_offset, float size)
    {
        // "x - center_offset" 的目的在于：以什么作为 cell 的分界线；
        // 这里所做的处理，是让 cell 的中心点对齐坐标，而非 cell 的边界对齐坐标；
        //
        // calculate and store temporary values in double format for having same result as same mySQL calculations
        double x_offset = (double(x) - center_offset)/size;
        double y_offset = (double(y) - center_offset)/size;

        // 我们期望把坐标轴的原点中心定义为0，那么它应当是左右正负等均分割的；
        // 这里假设我们要计算的空间坐标是 cell，那么它在一个轴上共有 512 个单位；
        // 这 512 个单位在坐标系上应该分割为 [-256...0...256]；
        // 如果我们不做 "+ CENTER_VAL" 的处理，在输入坐标为负数的情况下我们得到的也是负数的离散编号。因此我们加上了一半坐标轴的长度
        // 使得范围整体右移，此时我们就能够得到一个正数的编号，这符合数组亲和性的处理；
        int x_val = int(x_offset + CENTER_VAL + 0.5);
        int y_val = int(y_offset + CENTER_VAL + 0.5);
        return RET_TYPE(x_val, y_val);
    }

    // 世界坐标 → 空间分区索引（grid的编号，一张地图有 64x64 个 grid）
    inline GridCoord ComputeGridCoord(float x, float y)
    {
        return Compute<GridCoord, CENTER_GRID_ID>(x, y, CENTER_GRID_OFFSET, SIZE_OF_GRIDS);
    }

    inline GridCoord ComputeGridCoordSimple(float x, float y)
    {
        int gx = (int)(CENTER_GRID_ID - x / SIZE_OF_GRIDS);
        int gy = (int)(CENTER_GRID_ID - y / SIZE_OF_GRIDS);
        return GridCoord((MAX_NUMBER_OF_GRIDS - 1) - gx, (MAX_NUMBER_OF_GRIDS - 1) - gy);
    }

    // 世界坐标 → 空间分区索引（cell的编号，一张地图有 512x512 个 cell）
    inline CellCoord ComputeCellCoord(float x, float y)
    {
        return Compute<CellCoord, CENTER_GRID_CELL_ID>(x, y, CENTER_GRID_CELL_OFFSET, SIZE_OF_GRID_CELL);
    }

    // 世界坐标 → 空间分区索引（cell的编号，一张地图有 512x512 个 cell）；
    // 此外，还计算了 x_off 和 y_off，他们分别代表的是，x 和 y 的位置相对于目前所在 cell 的中心点的偏移量；
    // 即：
    //  x_off = 0 表示正好在 cell 中心
    //  x_off > 0 表示在中心右边
    //  x_off < 0 表示在中心左边
    inline CellCoord ComputeCellCoord(float x, float y, float &x_off, float &y_off)
    {
        double x_offset = (double(x) - CENTER_GRID_CELL_OFFSET)/SIZE_OF_GRID_CELL;
        double y_offset = (double(y) - CENTER_GRID_CELL_OFFSET)/SIZE_OF_GRID_CELL;

        int x_val = int(x_offset + CENTER_GRID_CELL_ID + 0.5f);
        int y_val = int(y_offset + CENTER_GRID_CELL_ID + 0.5f);
        x_off = (float(x_offset) - float(x_val) + CENTER_GRID_CELL_ID) * SIZE_OF_GRID_CELL;
        y_off = (float(y_offset) - float(y_val) + CENTER_GRID_CELL_ID) * SIZE_OF_GRID_CELL;
        return CellCoord(x_val, y_val);
    }

    inline void NormalizeMapCoord(float &c)
    {
        if (c > MAP_HALFSIZE - 0.5f)
            c = MAP_HALFSIZE - 0.5f;
        else if (c < -(MAP_HALFSIZE - 0.5f))
            c = -(MAP_HALFSIZE - 0.5f);
    }

    inline bool IsValidMapCoord(float c)
    {
        return std::isfinite(c) && (std::fabs(c) <= MAP_HALFSIZE - 0.5f);
    }

    inline bool IsValidMapCoord(float x, float y)
    {
        return IsValidMapCoord(x) && IsValidMapCoord(y);
    }

    inline bool IsValidMapCoord(float x, float y, float z)
    {
        return IsValidMapCoord(x, y) && IsValidMapCoord(z);
    }

    inline bool IsValidMapCoord(float x, float y, float z, float o)
    {
        return IsValidMapCoord(x, y, z) && std::isfinite(o);
    }
}
#endif
