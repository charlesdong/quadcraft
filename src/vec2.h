#ifndef VEC2_H_
#define VEC2_H_

class Vec2d
{
public:
	double x;
	double y;

	Vec2d() : x(0.0), y(0.0)
	{
	}

	Vec2d(double vx, double vy) : x(vx), y(vy)
	{
	}

	Vec2d(float vx, float vy) : x(double(vx)), y(double(vy))
	{
	}

	Vec2d operator+(const Vec2d & v) const
	{
		return Vec2d(x + v.x, y + v.y);
	}

	Vec2d operator-(const Vec2d & v) const
	{
		return Vec2d(x - v.x, y - v.y);
	}

	double * pointer()
	{
		return &x;
	}

	const double * pointer() const
	{
		return &x;
	}
};

class Vec2f
{
public:
	float x;
	float y;

	Vec2f() : x(0.0f), y(0.0f)
	{
	}

	Vec2f(float vx, float vy) : x(vx), y(vy)
	{
	}

	Vec2f operator+(const Vec2f & v) const
	{
		return Vec2f(x + v.x, y + v.y);
	}

	Vec2f operator-(const Vec2f & v) const
	{
		return Vec2f(x - v.x, y - v.y);
	}

	float * pointer()
	{
		return &x;
	}

	const float * pointer() const
	{
		return &x;
	}
};

// May could have a better implementation
class Mat4f
{
public:
	float v00, v01, v02, v03;
	float v10, v11, v12, v13;
	float v20, v21, v22, v23;
	float v30, v31, v32, v33;

	Mat4f() :
		v00(1.0f), v01(0.0f), v02(0.0f), v03(0.0f),
		v10(0.0f), v11(1.0f), v12(0.0f), v13(0.0f),
		v20(0.0f), v21(0.0f), v22(1.0f), v23(0.0f),
		v30(0.0f), v31(0.0f), v32(0.0f), v33(1.0f)
	{
	}

	Mat4f(float vv00, float vv11, float vv22, float vv33)
		:
		v00(vv00), v01(0.0f), v02(0.0f), v03(0.0f),
		v10(0.0f), v11(vv11), v12(0.0f), v13(0.0f),
		v20(0.0f), v21(0.0f), v22(vv22), v23(0.0f),
		v30(0.0f), v31(0.0f), v32(0.0f), v33(vv33)
	{
	}

	Mat4f(
		float vv00, float vv01, float vv02, float vv03,
		float vv10, float vv11, float vv12, float vv13,
		float vv20, float vv21, float vv22, float vv23,
		float vv30, float vv31, float vv32, float vv33
	) :
		v00(vv00), v01(vv01), v02(vv02), v03(vv03),
		v10(vv10), v11(vv11), v12(vv12), v13(vv13),
		v20(vv20), v21(vv21), v22(vv22), v23(vv23),
		v30(vv30), v31(vv31), v32(vv32), v33(vv33)
	{
	}

	float * pointer()
	{
		return &v00;
	}

	const float * pointer() const
	{
		return &v00;
	}
};

// Typedefs to reduce the code.
typedef const Vec2f & Vec2fr;
typedef const Vec2d & Vec2dr;
typedef const Mat4f & Mat4fr;

Mat4f ortho(int width, int height);
Mat4f translate(Mat4fr m, Vec2fr v);
Mat4f scale(Mat4fr m, Vec2fr v);

#endif