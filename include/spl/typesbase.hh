#ifndef _spl_typesbase_hh_
#define _spl_typesbase_hh_

#include <cassert>   // for assert()

/*! \file typesbase.hh  
 * */ 
 
typedef char           SPLint8;   //!< signed integer with 8 bit
typedef unsigned char  SPLuint8;  //!< unsigned integer with 8 bit
typedef short          SPLint16;  //!< signed integer with 16 bit
typedef unsigned short SPLuint16; //!< unsigned integer with 16 bit
typedef int            SPLint32;  //!< signed integer with 32 bit
typedef unsigned int   SPLuint32; //!< unsigned integer with 32 bit
typedef long           SPLint64;  //!< signed integer with 64 bit
typedef unsigned long  SPLuint64; //!< unsigned integer with 64 bit
typedef float          SPLieee32; //!< IEEE floating point with 32 bit
typedef double         SPLieee64; //!< IEEE floating point with 64 bit
typedef long double    SPLieee128;//!< IEEE floating point with 128 bit
typedef SPLint32       SPLindex;  //!< array index data type
typedef SPLint32       SPLenum;   //!< enumerator values
typedef SPLint32       SPLsizei;  //!< array index data type
typedef void           SPLvoid;   //!< void pointer with 32 bit
typedef void*          SPLvoidp;  //!< void pointer with 32 bit

typedef bool (*SPLFunctionVoid)(void);	//!< Default function pointer
typedef bool (*SPLFunctionVoidp)(void *);	//!< Default function pointer
//typedef bool (TMyClass::*pt2Member)(void);

static const SPLint32 __SPL_ENUM_FIRST = 0x0FFF0000; //!< 1st enum value
static const SPLint32 __SPL_ENUM_RANGE = 0x00002000; //!< range of enum values

/*! \brief Global defined parameters!
 *
 * This global defined parameters are used throughout the different classes.
 */
enum m_SPLenum
{ 
   SPL_TYPE_MIN                          = __SPL_ENUM_FIRST + __SPL_ENUM_RANGE * 0,
   SPL_FILEIO_MIN                        = __SPL_ENUM_FIRST + __SPL_ENUM_RANGE * 1,
   SPL_CAMERA_MIN                  		 = __SPL_ENUM_FIRST + __SPL_ENUM_RANGE * 2,
   SPL_MATERIAL_MIN						 = __SPL_ENUM_FIRST + __SPL_ENUM_RANGE * 3,
   SPL_LIGHT_MIN						 = __SPL_ENUM_FIRST + __SPL_ENUM_RANGE * 4,
   // type identifier constants
   // for scalar types
   SPL_TYPE_UINT8 = SPL_TYPE_MIN + 1, //!< Identification number for storage type \ref SPLuint8 
   SPL_TYPE_INT8,	//!< Identification number for storage type \ref SPLint8 
   SPL_TYPE_UINT16,	//!< Identification number for storage type \ref SPLuint16 
   SPL_TYPE_INT16,	//!< Identification number for storage type \ref SPLint16 
   SPL_TYPE_UINT32,	//!< Identification number for storage type \ref SPLuint32 
   SPL_TYPE_INT32,	//!< Identification number for storage type \ref SPLint32 
   SPL_TYPE_UINT64,	//!< Identification number for storage type \ref SPLuint64 
   SPL_TYPE_INT64,	//!< Identification number for storage type \ref SPLint64 
   SPL_TYPE_IEEE32,	//!< Identification number for storage type \ref SPLieee32 
   SPL_TYPE_IEEE64,	//!< Identification number for storage type \ref SPLieee64
   SPL_TYPE_IEEE128,//!< Identification number for storage type \ref SPLieee128
   SPL_TYPE_VOIDP,	//!< Identification number for storage type \ref SPLvoidp
   // for vector types, e.g. SPLRGBA8, SPLVector4
   SPL_TYPE_RGBA8,	//!< Identification number for storage type \ref SPLRGBA8
   SPL_TYPE_RGBAf,	//!< Identification number for storage type \ref SPLRGBAf
//   SPL_TYPE_VEC4I,	//!< Identification number for storage type \ref SPLRGBA8
   SPL_TYPE_MAX,
   
   SPL_FILEIO_PGM_ID = SPL_FILEIO_MIN + 1,	//!< Identification number for the \b "pgm" file storage type, see \ref SPLFileIO, \ref SPLGrid
   SPL_FILEIO_PPM_ID,		//!< Identification number for the \b "ppm" file storage type, see \ref SPLFileIO, \ref SPLGrid
   SPL_FILEIO_RAW_ID,		//!< Identification number for the \b "raw" file storage type, see \ref SPLFileIO, \ref SPLGrid
   SPL_FILEIO_PNG_ID,		//!< Identification number for the \b "png" file storage type, see \ref SPLFileIO, \ref SPLGrid
   SPL_FILEIO_TIF_ID,		//!< Identification number for the \b "tif" file storage type, see \ref SPLFileIO, \ref SPLGrid
   SPL_FILEIO_NII_ID,		//!< Identification number for the \b "nii" file storage type, see \ref SPLFileIO, \ref SPLGrid
   SPL_FILEIO_VTR_ID,		//!< Identification number for the \b "vtr" file storage type, see \ref SPLFileIO, \ref SPLGrid
   SPL_FILEIO_MAX,
   
   SPL_CAMERA_MATRIX_MODELVIEW = SPL_CAMERA_MIN + 1,	//!< Identification number for the modelview camera matrix, see \ref SPLCamera \ref SPLMatrix4 
   SPL_CAMERA_MATRIX_ORTHO,		//!< Identification number for the projection (orthographic) camera matrix, see \ref SPLCamera \ref SPLMatrix4 
   SPL_CAMERA_MATRIX_FRUSTUM,	//!< Identification number for the projection (perspective) camera matrix, see \ref SPLCamera \ref SPLMatrix4 
   SPL_CAMERA_MATRIX_VIEWPORT,	//!< Identification number for the viewport camera matrix, see \ref SPLCamera \ref SPLMatrix4 
   SPL_CAMERA_MAX,

	SPL_MATERIAL_OPACITY = SPL_MATERIAL_MIN + 1, //!< Identification number for the opacity material channel
	SPL_MATERIAL_EMISSION_RED,	//!< Identification number for the emission material red channel
	SPL_MATERIAL_EMISSION_GREEN,//!< Identification number for the emission material green channel
	SPL_MATERIAL_EMISSION_BLUE,	//!< Identification number for the emission material blue channel
	SPL_MATERIAL_AMBIENT_RED,
	SPL_MATERIAL_AMBIENT_GREEN,
	SPL_MATERIAL_AMBIENT_BLUE,
	SPL_MATERIAL_DIFFUSE_RED,
	SPL_MATERIAL_DIFFUSE_GREEN,
	SPL_MATERIAL_DIFFUSE_BLUE,
	SPL_MATERIAL_SPECULAR_RED,
	SPL_MATERIAL_SPECULAR_GREEN,
	SPL_MATERIAL_SPECULAR_BLUE,
	SPL_MATERIAL_SHININESS,
	SPL_MATERIAL_ISOSURFACE,
	SPL_MATERIAL_GRADIENT,
	SPL_MATERIAL_EXT0,
	SPL_MATERIAL_MAX,

	SPL_MATERIAL_APPROX_MIN,
	SPL_MATERIAL_APPROX_CONSTANT,	//!< Identification number for constant approximation of a material channel 
	SPL_MATERIAL_APPROX_LINEAR,		//!< Identification number for linear approximation of a material channel 
	SPL_MATERIAL_APPROX_QUADRATIC,	//!< Identification number for quadtratic approximation of a material channel 
	SPL_MATERIAL_APPROX_MAX,

	SPL_LIGHT_POIN = SPL_LIGHT_MIN + 1, //!< Identification number for the point light source
	SPL_LIGHT_DIRE,						//!< Identification number for the directional light source
	SPL_LIGHT_SPOT						//!< Identification number for the spot light source
};

#endif /* _spl_typesbase_hh_ */

