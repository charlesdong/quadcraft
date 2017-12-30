#include "vec2.h"

Mat4f ortho(int width, int height)
{
	return Mat4f(
		2.0f / width, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f / height, 0.0f, 0.0f,
		0.0f, 0.0f, -1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f, 1.0f
	);
}

Mat4f translate(Mat4fr m, Vec2fr v)
{
	return Mat4f(
		m.v00, m.v01, m.v02, m.v03 + v.x,
		m.v10, m.v11, m.v12, m.v13 + v.y,
		m.v20, m.v21, m.v22, m.v23,
		m.v30, m.v31, m.v32, m.v33
	);
}

Mat4f scale(Mat4fr m, Vec2fr v)
{
	return Mat4f(
		m.v00 * v.x, m.v01, m.v02, m.v03,
		m.v10, m.v11 * v.y, m.v12, m.v13,
		m.v20, m.v21, m.v22, m.v23,
		m.v30, m.v31, m.v32, m.v33
	);
}