#include "sfwdraw.h"
#include "flops.h"
#include "vec2.h"


void main()
{
	sfw::initContext(800, 800);
	float steps = 100;
	while (sfw::stepContext())
	{
		for (int i = 0; i < steps; i++)
		{
			float x1 = i / steps;
			float x2 = (i + 1) / steps;

			float y1 = quadBezier(.5f, 0, 1, x1);
			float y2 = quadBezier(.5f, 0, 1, x2);

			x1 *= 400;
			x2 *= 400;
			y1 *= 400;
			y2 *= 400;

			sfw::drawLine(x1, y1, x2, y2);
		}
	}
	sfw::termContext();
}
