/*
 *  BCMViewer
 *
 *  Copyright 2012 SGI Japan, Ltd.
 *
 */

#ifndef __GRID_BCM_H__
#define __GRID_BCM_H__

#include "BCMOctree.h"
#include "Vec3.h"

#include <string>
#include <vector>

namespace BCMFileIO{
	class PartitionMapper;
} // namespace BCMFileIO

namespace SG {
	struct IndexFormat;
	struct VertexLineFormat;

	template<typename T> class Geometry;
} // namespace SG


namespace Render {
	class SGRender;
} // namespace Render

class SliceFace;
class LeafBlocks;

class GridBCM
{

public:
	enum AXIS {
		AXIS_X = 0x1,
		AXIS_Y = 0x2,
		AXIS_Z = 0x4
	};

	GridBCM( const std::string& filename );
	~GridBCM();

	void AddSlicePlane(const AXIS axis);
	void DeleteSlicePlane(const AXIS axis);
	
	size_t SetSlicePosition( size_t position );

	void SetActiveAxis(const AXIS axis)
	{
		if( axis == AXIS_X || axis == AXIS_Y || axis == AXIS_Z ) m_active = axis;
	}

	const Vec3r& GetGlobalOrigin() const { return m_globalOrigin; }
	const Vec3r& GetGlobalRegion() const { return m_globalRegion; }

	size_t GetCellCount(const AXIS axis){
		if( axis == AXIS_X ){ return m_maxCellCount[0]; }
		if( axis == AXIS_Y ){ return m_maxCellCount[1]; }
		if( axis == AXIS_Z ){ return m_maxCellCount[2]; }

		return 0;
	}

	void Render();

	void ShowGrid(const bool show){ m_showGrid = show; }
	bool IsShowGrid() const { return m_showGrid; }

private:
	bool Init();
	bool Deinit();
	bool LoadFile(const std::string& filename);
	bool LoadFileIndex(const std::string& filename) { }
	bool LoadFileOctree(const std::string& filename);
	bool LoadFileLeafBlock(const std::string& filename) { }

	bool UpdateGeometry();
	bool UpdateGeometry(const AXIS axis );

private:
	// render
	SG::Geometry<SG::VertexLineFormat> *m_bbox;	
	SliceFace *m_slice[3];

	Render::SGRender *m_render;

	// Control
	size_t m_slicePos[3];
	size_t m_maxCellCount[3];

	// Domain
	Vec3r m_globalOrigin;
	Vec3r m_globalRegion;

	// Octree
	BCMFileIO::PartitionMapper *m_pmapper;
	BCMOctree                  *m_octree;
	size_t                      m_maxLevel;
	size_t                      m_rootDims[3];

	// LeafBlock
	LeafBlocks *m_leafBlocks;
	size_t      m_blockSize[3];

	bool m_showGrid;

	AXIS m_active;
};


#endif // __GRID_BCM_H__