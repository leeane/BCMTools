/*
###################################################################################
#
# BCMTools
#
# Copyright (c) 2011-2014 Institute of Industrial Science, The University of Tokyo.
# All rights reserved.
#
# Copyright (c) 2012-2016 Advanced Institute for Computational Science (AICS), RIKEN.
# All rights reserved.
#
# Copyright (c) 2017 Research Institute for Information Technology (RIIT), Kyushu University.
# All rights reserved.
#
###################################################################################
*/

///
/// @file  BitVoxel.h
/// @brief ビットボクセル圧縮/展開ライブラリ
///

#ifndef __BCMTOOLS_BITVOXEL_H__
#define __BCMTOOLS_BITVOXEL_H__

#include <cstdlib>


namespace BCMFileIO {

	/// ビットボクセル型の定義
	typedef unsigned int bitVoxelCell;

	/// ボクセルをビットボクセル化した場合のビットボクセルサイズを出力
	///
	/// @param[in]  sourceSize ボクセル数
	/// @param[in]  bitWidth   ビット幅
	/// @return ビットボクセルサイズ
	///
	/// @note ビットボクセルサイズはバイト単位ではない．
	///
	size_t GetBitVoxelSize(const size_t sourceSize, const unsigned char bitWidth);

	/// ビットボクセル圧縮
	///
	/// @param[out] bitVoxelSize 出力ビットボクセルサイズ
	/// @param[in]  boxelSize    入力ボクセルサイズ
	/// @param[in]  voxel        入力ボクセルの先頭ポインタ
	/// @param[in]  bitWidth     ビット幅
	/// @return ビットボクセルの先頭ポインタ
	///
	/// @note returnされたポインタは適宜解放(delete)してください．
	///
	bitVoxelCell* CompressBitVoxel( size_t* bitVoxelSize, const size_t voxelSize, const unsigned char* voxel, const unsigned char  bitWidth);

	/// ビットボクセル展開
	///
	/// @param[in] bitVoxelSize ボクセルサイズ (展開後のボクセル数)
	/// @param[in] bitVoxel     入力ビットボクセル
	/// @param[in] bitWidth     ビット幅
	/// @return 展開されたボクセルの先頭ポインタ
	///
	/// @note returnされたポインタは適宜解放(delete)してください．
	///
	unsigned char* DecompressBitVoxel( const size_t voxelSize, const bitVoxelCell* bitVoxel, const unsigned char  bitWidth);


} // namespace BCMFileIO




#endif // __BCMTOOLS_BITVOXEL_H__
