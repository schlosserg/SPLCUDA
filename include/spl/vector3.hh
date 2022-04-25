#ifndef _spl_vector3_hh_
#define _spl_vector3_hh_

#ifdef __DEBUG__
#include <cstdio>
#endif

#include <spl/typesbase.hh>

#define __CUDACC__
#ifdef __CUDACC__
#define CUDA_CALLABLE_MEMBER __host__ __device__
#else
#define CUDA_CALLABLE_MEMBER
#endif

#ifdef __DEBUG__
# include <cstdio>
#endif

template <class T> class SPLVector3;
template <class T> class SPLVector4;
template <class T> class SPLMatrix3;
template <class T> class SPLMatrix4;

typedef SPLVector3<SPLint32> SPLVector3i;	//!< Vector type with SPLint32 (32bit) resolution for each vector component!
typedef SPLVector3<SPLieee32> SPLVector3f;	//!< Vector type with SPLieee32 (32bit) resolution for each vector component!
typedef SPLVector3<SPLieee64> SPLVector3d;	//!< Vector type with SPLieee64 (64bit) resolution for each vector component!

/*! \file vector3.hh  
 * */ 

/*! \class SPLVector3
 * \brief A \f$ 3 \f$ dimensional vector class.
 * 
 * This class defines variables and 
 * implements methods for usual 3 dimensional vectors, i.e. for 
 * \f$ {\bf V} \in \mathbb{R}^{3} \f$.
 * 
 * However, in total a vector contains 3 elements and can be addressed as
 * \f[
 * {\bf V} = 
 * \left(
 * \begin{array}{r}
 * {\bf V}_{x} \\
 * {\bf V}_{y} \\
 * {\bf V}_{z}
 * \end{array}
 * \right) =
 * \left(
 * \begin{array}{r}
 * {\bf V}.{x} \\
 * {\bf V}.{y} \\
 * {\bf V}.{z}
 * \end{array}
 * \right) =  
 * \left(
 * \begin{array}{r}
 * {\bf V}[0] \\
 * {\bf V}[1] \\
 * {\bf V}[2]
 * \end{array}
 * \right) 
 * \f]
 * 
 * \sa SPLMatrix3 SPLVector4
*/
template <class T>
class SPLVector3
{
public:
	/*! \brief Constructor!
	 * 
	 * Initializes the class variables to default values.
	 * That means, as
	 * \f[
	 * {\bf V} = 
 	 * \left(
	 * \begin{array}{r}
	 * 0 \\
	 * 0 \\
	 * 0
	 * \end{array}
	 * \right)
	 * \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V;
	 * 
	 * \endcode
	 */
	CUDA_CALLABLE_MEMBER SPLVector3(void) throw();

	/*! \brief Constructor!
	 * 
	 * Initializes the class variables to specified values.
	 * That means, as
	 * \f[
	 * {\bf V} = 
 	 * \left(
	 * \begin{array}{r}
	 * x \\
	 * y \\
	 * z
	 * \end{array}
	 * \right)
	 * \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V(2.0f, -2.0f, 2.1f);
	 * 
	 * \endcode
	 * 
	 * \param x 1st vector element (i.e. \c v.x = \c x).
	 * \param y 2nd vector element (i.e. \c v.y = \c y).
	 * \param z 3rd vector element (i.e. \c v.z = \c z).
	 */
	CUDA_CALLABLE_MEMBER SPLVector3(const T x, const T y, const T z) throw();
 
 	/*! \brief Constructor!
	 * 
	 * Initializes the class variables to specified values.
	 * That means, as
	 * \f[
	 * {\bf V} = 
 	 * \left(
	 * \begin{array}{r}
	 * {\bf v}_x \\
	 * {\bf v}_y \\
	 * {\bf v}_z
	 * \end{array}
	 * \right)
	 * \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f v(2.0f, -2.0f, 2.1f);
	 * SPLVector3f V(v);
	 * 
	 * \endcode
	 * 
	 * \param v Another vector with type \c T.
	 */
	CUDA_CALLABLE_MEMBER SPLVector3(const SPLVector3<T> &v) throw();

 	/*! \brief Constructor!
	 * 
	 * Initializes the class variables to specified values. The last value v.w is discard!
	 * That means, as
	 * \f[
	 * {\bf V} = 
 	 * \left(
	 * \begin{array}{r}
	 * {\bf v}_x \\
	 * {\bf v}_y \\
	 * {\bf v}_z
	 * \end{array}
	 * \right)
	 * \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector4f v(2.0f, -2.0f, 2.1f, 3f);
	 * SPLVector3f V(v);
	 * 
	 * \endcode
	 * 
	 * \param v Another vector with type \c T.
	 */
	CUDA_CALLABLE_MEMBER SPLVector3(const SPLVector4<T> &v) throw();

	/*! \brief Destructor!
	 *
	 * Frees all previously alloced space.
	 */
	CUDA_CALLABLE_MEMBER ~SPLVector3(void) throw() {};
	
	//operator SPLVector3<T> () const throw();
	
	/*! \brief Comparison operator!
	 * 
	 * Verifies if this vector \f$ {\bf V} \f$ 
	 * is the same as the other vector \f$ {\bf v} \f$. 
	 * That means, returns \c true if,
	 * \f[ {\bf V} == {\bf v}, \f]
	 * where each component is checked individually.
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V,v;
	 * 
	 * if (V == v)
	 * {
	 * 	cout << "equal vectors!" << endl;
	 * }
	 * else
	 * {
	 * 	cout << "non equal vectors!" << endl;
	 * }
	 * 
	 * \endcode
	 * 
	 * \param v Another vector.
	 * 
	 * \return \c true on equality and \c false ontherwise.
	 */	
	CUDA_CALLABLE_MEMBER bool operator == (const SPLVector3<T> &v) const throw();

	/*! \brief Comparison operator!
	 * 
	 * Verifies if this vector \f$ {\bf V} \f$ 
	 * is not the same as the other vector \f$ {\bf v} \f$. 
	 * That means, returns \c true if,
	 * \f[ {\bf V} \ne {\bf v}, \f]
	 * where each component is checked individually.
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V,v;
	 * 
	 * if (V != v)
	 * {
	 * 	cout << "non equal vectors!" << endl;
	 * }
	 * else
	 * {
	 * 	cout << "equal vectors!" << endl;
	 * }
	 * 
	 * \endcode
	 * 
	 * \param v Another vector.
	 * 
	 * \return \c true on inequality and \c false ontherwise.
	 */	
	CUDA_CALLABLE_MEMBER bool operator != (const SPLVector3<T> &v) const throw();

	/*! \brief Assigment operator!
	 * 
	 * \param v Another vector.
	 * 
	 * \return Reference of this vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T>& operator = (const SPLVector3<T> &v) throw();

	/*! \brief Assigment operator!
	 * 
	 * \param v Another vector.
	 * 
	 * \return Reference of this vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T>& operator = (const SPLVector4<SPLieee64> &v) throw();


	/*! \brief Access operator!
	 * 
	 * Accesses the elements of that current vector \f$ {\bf V} \f$.
	 * That means, as
	 * \f[ {\bf V}[i], \f]
	 * such that a for-loop can be applied, for example, as
	 * \code
	 * SPLVector3f V;
	 * SPLieee32 help;
	 * for (SPLindex i = 0 ; i < 3 ; i++)
	 * {
	 * 	help = V[i];
	 * }
	 * \endcode
	 * 
	 * \param i Index into the vector elements.
	 * 
	 * \return Reference of an element.
	 */
	CUDA_CALLABLE_MEMBER T& operator [] (const SPLindex i) throw();

	/*! \brief Access operator!
	 * 
	 * Accesses the elements of that current vector \f$ {\bf V} \f$.
	 * That means, as
	 * \f[ {\bf V}[i], \f]
	 * such that a for-loop can be applied, for example, as
	 * \code
	 * const SPLVector3f V;
	 * const SPLieee32 help;
	 * for (SPLindex i = 0 ; i < 3 ; i++)
	 * {
	 * 	help = V[i];
	 * }
	 * \endcode
	 * 
	 * \param i Index into the vector elements.
	 * 
	 * \return Reference of an element.
	 */
	CUDA_CALLABLE_MEMBER const T& operator [] (const SPLindex i) const throw();

	/*! \brief Unary minus!
	 * 
	 * Returns a new negative vector  \f$ {\bf n} \f$ 
	 * of the current vector  \f$ {\bf V} \f$.
	 * That means, as
	 * \f[ {\bf n} = -{\bf V} \f]
	 * 
	 * Example
	 * \code
	 * const SPLVector3f V(1.0f, 2.0f, 3.0f);
	 * SPLVector3f n;
	 * 
	 * n = -V;
	 * 
	 * \endcode
	 * 
	 * \return New vector.
	 */
	CUDA_CALLABLE_MEMBER SPLVector3<T> operator - (void) const throw();

	/*! \brief Multiplication operator!
	 * 
	 * Multiplication of the other vector \f$ {\bf v} \f$ 
	 * to this vector \f$ {\bf V} \f$ where the scalar 
	 * product is returned.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ s = {\bf V} * {\bf v} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V(1.0f, 2.3f, 4.2f), v(-1.0f, -0.3f, 2.2f);
	 * SPLieee32 s
	 * 
	 * s = V * v;
	 * 
	 * \endcode
	 * 
	 * \param v Another vector.
	 * 
	 * \return Scalar value (vector product).
	 */	
	CUDA_CALLABLE_MEMBER T operator * (const SPLVector3<T> &v) const throw();

	/*! \brief Addition operator!
	 * 
	 * Element-wise addition of the other vector \f$ {\bf v} \f$ 
	 * to this vector \f$ {\bf V} \f$.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ {\bf V} = {\bf V} + {\bf v} \f]
	 *
	 * Example 
	 * \code
	 * SPLVector3f V,v;
	 * 
	 * V += v;
	 * 
	 * \endcode
	 * 
	 * \param v Another vector.
	 * 
	 * \return Reference of this vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T>& operator += (const SPLVector3<T> &v) throw();

	/*! \brief Subtraction operator!
	 * 
	 * Element-wise subtraction of the other vector \f$ {\bf v} \f$ 
	 * to this vector \f$ {\bf V} \f$.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ {\bf V} = {\bf V} - {\bf v} \f]
	 *
	 * Example 
	 * \code
	 * SPLVector3f V,v;
	 * 
	 * V -= v;
	 * 
	 * \endcode
	 * 
	 * \param v Another vector.
	 * 
	 * \return Reference of this vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T>& operator -= (const SPLVector3<T> &v) throw();

	/*! \brief Multiplication operator!
	 * 
	 * Element-wise multiplication of the scalar value \f$ s \f$ 
	 * to this vector \f$ {\bf V} \f$.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ {\bf V} = s*{\bf V} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V;
	 * SPLieee32 s;
	 * 
	 * V *= s;
	 * 
	 * \endcode
	 * 
	 * \param s A scalar value.
	 * 
	 * \return Reference of this vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T>& operator *= (const T s) throw();

	/*! \brief Division operator!
	 * 
	 * Element-wise division of the scalar value \f$ s \f$ 
	 * to this vector \f$ {\bf V} \f$.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ {\bf V} = {1 \over s} * {\bf V} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V;
	 * SPLieee32 s;
	 * 
	 * V /= s;
	 * 
	 * \endcode
	 * 
	 * \param s A scalar value.
	 * 
	 * \return Reference of this vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T>& operator /= (const T s) throw();

	/*! \brief Addition operator!
	 * 
	 * Element-wise addition of the other vector \f$ {\bf v} \f$ 
	 * to this vector \f$ {\bf V} \f$ where a new vector \f$ {\bf n} \f$
	 * is returned.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ {\bf n} = {\bf V} + {\bf v} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V,v,n;
	 * 
	 * n = V + v;
	 * 
	 * \endcode
	 * 
	 * \param v Another vector.
	 * 
	 * \return New vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T> operator + (const SPLVector3<T> &v) const throw();

	/*! \brief Subtraction operator!
	 * 
	 * Element-wise subtraction of the other vector \f$ {\bf v} \f$ 
	 * to this vector \f$ {\bf V} \f$ where a new vector \f$ {\bf n} \f$
	 * is returned.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ {\bf n} = {\bf V} - {\bf v} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V,v,n;
	 * 
	 * n = V - v;
	 * 
	 * \endcode
	 * 
	 * \param v Another vector.
	 * 
	 * \return New vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T> operator - (const SPLVector3<T> &v) const throw();

	/*! \brief Multiplication operator!
	 * 
	 * Element-wise multiplication of the scalar value \f$ s \f$ 
	 * to this vector \f$ {\bf V} \f$ where a new vector \f$ {\bf n} \f$
	 * is returned.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ {\bf n} = s * {\bf V} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V,n;
	 * SPLieee32 s
	 * 
	 * n = V * s;
	 * 
	 * \endcode
	 * 
	 * \param s A scalar value.
	 * 
	 * \return New vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T> operator * (const T s) const throw();

	/*! \brief Division operator!
	 * 
	 * Element-wise division of the scalar value \f$ s \f$ 
	 * to this vector \f$ {\bf V} \f$ where a new vector \f$ {\bf n} \f$
	 * is returned.
	 * As defined in every math book on linear algebra, i.e.
	 * \f[ {\bf n} = {1 \over s} * {\bf V} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V,n;
	 * SPLieee32 s
	 * 
	 * n = V / s;
	 * 
	 * \endcode
	 * 
	 * \param s A scalar value.
	 * 
	 * \return New vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T> operator / (const T s) const throw();

	/*! \brief Print the elements to standard output!
	 * 
	 * The elements (data values) are printed only in debugging mode,
	 * i.e. when the library has been compiled with the flag -D__DEBUG__.
	 * Otherwise a call of this function has no effect.
	 */	
	CUDA_CALLABLE_MEMBER void print(void) const throw();

	/*! \brief Returns the square value of the vector!
	 * 
	 * Computes and returns the scalar square value \f$ s \f$ of this vector \f$ {\bf V} \f$.
	 * That means, as
	 * \f[ s = {\| {\bf V} \|}^2 = {\bf V}_x*{\bf V}_x + {\bf V}_y*{\bf V}_y + {\bf V}_z*{\bf V}_z \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V(1.0f, 2.0f, 3.0f);
	 * SPLieee64 s
	 * 
	 * s = V.square(); // s == 14.0
	 * 
	 * \endcode
	 * 
	 * \return The scalar square value of this vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLieee64 square(void) const throw();

	/*! \brief Returns the length value of the vector!
	 * 
	 * Computes and returns the scalar length value \f$ s \f$ of this vector \f$ {\bf V} \f$.
	 * That means, as
	 * \f[ s = {\| {\bf V} \|} = \sqrt{ {\bf V}_x*{\bf V}_x + {\bf V}_y*{\bf V}_y + {\bf V}_z*{\bf V}_z } \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V(1.0f, 2.0f, 3.0f);
	 * SPLieee64 s
	 * 
	 * s = V.length(); // s == 3.74
	 * 
	 * \endcode
	 * 
	 * \return The scalar length of this vector.
	 */	
	CUDA_CALLABLE_MEMBER SPLieee64 length(void) const throw();

	/*! \brief Returns the normalized vector (inplace)!
	 * 
	 * Normalizes this vector \f$ {\bf V} \f$.
	 * That means, as
	 * \f[ {\bf V} = l * {\bf V} / {\| {\bf V} \|} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V(1.0f, 2.0f, 3.0f);
	 *  
	 * V.normalize(); // V.length() == 1.0
	 * V.normalize(2.5); // V.length() == 2.5
	 * 
	 * \endcode
	 * 
	 * \param l The length of the resulting vector.
	 * 
	 * \return Reference of this normalized vector to a certain length.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T>& normalize(const SPLieee64 l = 1.0) throw();

	/*! \brief Returns the normalized vector!
	 * 
	 * Returns a new normalized vector \f$ {\bf n} \f$ of 
	 * this vector \f$ {\bf V} \f$.
	 * That means, as
	 * \f[ {\bf n} = l * {\bf V} / {\| {\bf V} \|} \f]
	 * 
	 * Example 
	 * \code
	 * SPLVector3f V(1.0f, 2.0f, 3.0f), n;
	 *  
	 * n = V.getNormalized(); // n.length() == 1.0, V.length() == 3.74
	 * n = V.getNormalized(2.5); // n.length() == 2.5, V.length() == 3.74
	 * 
	 * \endcode
	 * 
	 * \param length The length of the resulting vector.
	 * 
	 * \return New normalized vector to a certain length
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T> getNormalized(const SPLieee64 length = 1.0) const throw();

	/*! \brief The cross product of two vectors!
	 * 
	 * Computes the cross product of a vector \f$ {\bf v} \f$ and 
	 * this vector \f$ {\bf V} \f$ which results in
	 * a new perpendicular vector \f$ {\bf n} \f$ to the other ones. 
	 * In general the cross product is defined for 
	 * vectors with 3 elements only, i.e. for \f$ {\bf u} \in \mathbb{R}^3 \f$.
	 * However, the cross product is defined as
	 * \f[
	 * {\bf n} = {\bf V} \times {\bf v} = 
	 * \left(
	 * \begin{array}{r}
	 * {\bf V}_y {\bf v}_z - {\bf v}_y {\bf V}_z \\
	 * {\bf v}_x {\bf V}_z - {\bf V}_x {\bf v}_z \\
	 * {\bf V}_x {\bf v}_y - {\bf v}_x {\bf V}_y \\
	 * \end{array}
	 * \right)
	 * \f]
	 * Note, \f$ \times \f$ denotes the cross product of two vectors.
	 * 
	 * \param v Another vector.
	 * 
	 * \return New vector with the cross product.
	 */	
	CUDA_CALLABLE_MEMBER SPLVector3<T> crossProduct(const SPLVector3<T> &v) const throw();

	/*! \brief The vector with components rounded to the nearest integer values!
	 *
	 * \return New vector of type \ref SPLint32 with rounded values.
	 */
	CUDA_CALLABLE_MEMBER SPLVector3<SPLint32> getROUNDint(void) const throw();

	/*! \brief The vector with components floored to the integer values!
	 *
	 * \return New vector of type \ref SPLint32 with floored values.
	 */
	CUDA_CALLABLE_MEMBER SPLVector3<SPLint32> getFLOORint(void) const throw();

	/*! \brief The vector with components ceiled to the integer values!
	 *
	 * \return New vector of type \ref SPLint32 with ceiled values.
	 */
	CUDA_CALLABLE_MEMBER SPLVector3<SPLint32> getCEILint(void) const throw();

	T x;	//!< 1st component (or element) of the vector.
   	T y;	//!< 2nd component (or element) of the vector.
   	T z;	//!< 3rd component (or element) of the vector.
	private:

};

/************************************************************************************************
 ** Non member functions for SPLVector3 
 ************************************************************************************************/
/*! \fn SPLVector3<T> operator * (const T s, const SPLVector3<T> &v)
 * \brief Multiplication operator!
 * 
 * Element-wise multiplication of the scalar value \f$ s \f$ 
 * to a vector \f$ {\bf v} \f$ where a new vector \f$ {\bf n} \f$
 * is returned.
 * As defined in every math book on linear algebra, i.e.
 * \f[ {\bf n} = s * {\bf v} \f]
 * 
 * Example 
 * \code
 * SPLVector3f v,n;
 * SPLieee32 s
 * 
 * n = s * v;
 * 
 * \endcode
 * 
 * \param s A scalar value.
 * \param v A vector.
 * 
 * \return New vector.
*/
template <class T>
SPLVector3<T> operator * (const T s, const SPLVector3<T> &v)
{
	SPLVector3<T> ret(s*v.x, s*v.y, s*v.z);
	return ret;
}

/*! \fn SPLVector4<T> operator * (const SPLMatrix4<T> &m, const SPLVector3<T> &v)
 * \brief Multiplication operator!
 * 
 * Multiplication of the vector \f$ {\bf v} \f$ 
 * with a matrix \f$ {\bf m} \f$ where a new vector 
 * \f$ {\bf n} \f$ is returned.
 * As defined in every math book on linear algebra, i.e.
 * \f[ n = {\bf m} * {\bf v} \f]
 * 
 * Example 
 * \code
 * SPLMatrix4f m;
 * SPLVector3f v(1.0f, 2.3f, 4.2f), n;
 * 
 * n = m * v;
 * 
 * \endcode
 * 
 * \param m A matrix.
 * \param v A vector.
 * 
 * \return New vector.
*/
template <class T>
SPLVector3<T> operator * (const SPLMatrix4<T> &m, const SPLVector3<T> &v)
{
	SPLVector3<T> ret;
	
	ret.x = m.x.x * v.x + m.y.x * v.y + m.z.x * v.z;
	ret.y = m.x.y * v.x + m.y.y * v.y + m.z.y * v.z;
	ret.z = m.x.z * v.x + m.y.z * v.y + m.z.z * v.z;
	
	return ret;
}

/************************************************************************************************
 ** SPLVector3 class implementation
 ************************************************************************************************/
template <class T>
SPLVector3<T>::SPLVector3(void) throw()
{
	this->x = T(0);
	this->y = T(0);
	this->z = T(0);
}

template <class T>
SPLVector3<T>::SPLVector3(const T x, const T y, const T z) throw()
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template <class T>
SPLVector3<T>::SPLVector3(const SPLVector3<T> &v) throw()
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

template <class T>
SPLVector3<T>::SPLVector3(const SPLVector4<T> &v) throw()
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	//this->w = v.w; discard
}

template <class T>
bool SPLVector3<T>::operator == (const SPLVector3<T> &v) const throw()
{
	return (this->x == v.x && this->y == v.y && this->z == v.z);
}

template <class T>
bool SPLVector3<T>::operator != (const SPLVector3<T> &v) const throw()
{
	return !(this->operator == (v));
}

template <class T>
SPLVector3<T>& SPLVector3<T>::operator = (const SPLVector3<T> &v) throw()
{
	this->x=v.x;
	this->y=v.y;
	this->z=v.z;
	return (*this);
}

template <class T>
SPLVector3<T>& SPLVector3<T>::operator = (const SPLVector4<SPLieee64> &v) throw()
{
	this->x=T(v.x);
	this->y=T(v.y);
	this->z=T(v.z);
	// v.w discard
	return (*this);
}


template <class T>
T& SPLVector3<T>::operator [] (const SPLindex i) throw()
{
	assert (i >= 0 && i <= 2);
	return (&x)[i]; 
}

template <class T>
const T& SPLVector3<T>::operator [] (const SPLindex i) const throw()
{
	assert (i >= 0 && i <= 2);
	return (&x)[i]; 
}

template <class T>
SPLVector3<T> SPLVector3<T>::operator - (void) const throw()
{
	SPLVector3<T> ret(-this->x, -this->y, -this->z);
	return ret;
}

template <class T>
T SPLVector3<T>::operator * (const SPLVector3<T> &v) const throw()
{
	return (this->x*v.x + this->y*v.y + this->z*v.z);
}

template <class T>
SPLVector3<T>& SPLVector3<T>::operator += (const SPLVector3<T> &v) throw()
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
   	return (*this);
}

template <class T>
SPLVector3<T>& SPLVector3<T>::operator -= (const SPLVector3<T> &v) throw()
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
   	return (*this);
}

template <class T>
SPLVector3<T>& SPLVector3<T>::operator *= (T s) throw()
{
	this->x *= s;
	this->y *= s;
	this->z *= s;
   	return (*this);
}

template <class T>
SPLVector3<T>& SPLVector3<T>::operator /= (T s) throw()
{
	assert (s != T(0));
	this->x /= s;
	this->y /= s;
	this->z /= s;
   	return (*this);
}

template <class T>
SPLVector3<T> SPLVector3<T>::operator + (const SPLVector3<T> &v) const throw()
{
	SPLVector3<T> ret(*this);
	ret += v;
	return ret;
}

template <class T>
SPLVector3<T> SPLVector3<T>::operator - (const SPLVector3<T> &v) const throw()
{
	SPLVector3<T> ret(*this);
	ret -= v;
	return ret;
}

template <class T>
SPLVector3<T> SPLVector3<T>::operator * (T s) const throw()
{
	SPLVector3<T> ret(*this);
	ret *= s;
	return ret;
}

template <class T>
SPLVector3<T> SPLVector3<T>::operator / (T s) const throw()
{
	SPLVector3<T> ret(*this);
	ret /= s;
	return ret;
}

template <class T>
void SPLVector3<T>::print(void) const throw()
{
#ifdef __DEBUG__
	printf("SPLVector3:\n");
    printf("%10.9f %10.9f %10.9f\n", x, y, z);
#endif
}

template <class T>
SPLVector3<T> SPLVector3<T>::crossProduct(const SPLVector3<T> &v) const throw()
{
	SPLVector3<T> ret;
	
	ret.x = this->y * v.z - this->z * v.y;
	ret.y = this->z * v.x - this->x * v.z;
	ret.z = this->x * v.y - this->y * v.x;
	return ret;
}

template<class T>
SPLieee64 SPLVector3<T>::square(void) const throw()
{
	double xx = POW2(this->x);
	double yy = POW2(this->y);
	double zz = POW2(this->z);
	return SPLieee64(xx + yy + zz);
}

template<class T>
SPLieee64 SPLVector3<T>::length(void) const throw()
{
	double help;
	help = double(this->square());
	assert(help >= double(0));
	help = SQRT(help);
	assert(help >= double(0));
	return SPLieee64(help);
}

template<class T>
SPLVector3<T>& SPLVector3<T>::normalize(const SPLieee64 length) throw()
{
	assert(length > SPLieee64(0));
	SPLieee64 len;
	len = this->length();
	if (len == SPLieee64(0))
	{
		return *this;
	}
	this->x = SPLieee32(SPLieee64(this->x) * length / len);
	this->y = SPLieee32(SPLieee64(this->y) * length / len);
	this->z = SPLieee32(SPLieee64(this->z) * length / len);
	assert(ABS(this->length() - length) < SPLieee64(EPS));
	return *this;
}

template<class T>
SPLVector3<T> SPLVector3<T>::getNormalized(const SPLieee64 length) const throw()
{
	SPLVector3<T> ret(*this);
	ret.normalize(length);
	return ret;
}

template<class T>
SPLVector3<SPLint32> SPLVector3<T>::getROUNDint(void) const throw()
{
	return SPLVector3<SPLint32>(SPLint32(RINT(this->x)), SPLint32(RINT(this->y)), SPLint32(RINT(this->z)));
}

template<class T>
SPLVector3<SPLint32> SPLVector3<T>::getFLOORint(void) const throw()
{
	return SPLVector3<SPLint32>(SPLint32(FLOOR(this->x)), SPLint32(FLOOR(this->y)), SPLint32(FLOOR(this->z)));
}

template<class T>
SPLVector3<SPLint32> SPLVector3<T>::getCEILint(void) const throw()
{
	return SPLVector3<SPLint32>(SPLint32(CEIL(this->x)), SPLint32(CEIL(this->y)), SPLint32(CEIL(this->z)));
}

#endif /*_spl_vector3_hh_*/
