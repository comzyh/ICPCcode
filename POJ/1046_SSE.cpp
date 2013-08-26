#include <iostream>
using namespace std;

struct __declspec(align(16)) color
{
	float a, r, g, b;
};

color table[16];
inline float dist(color &a, color &b)
{
	color *p = &a, *q = &b;
	float result, *s = &result;
	__asm
	{
		mov eax, p;
		mov ebx, q;
		mov ecx, s;
		movaps xmm0, [eax];
		movaps xmm1, [ebx];
		subps xmm0, xmm1;
		mulps xmm0, xmm0;
		movaps xmm1, xmm0;
		shufps xmm1, xmm1, 1Bh;
		movaps xmm2, xmm0;
		shufps xmm2, xmm2, 0B1h;
		movaps xmm3, xmm1;
		shufps xmm3, xmm3, 0B1h;
		addps xmm0, xmm1;
		addps xmm0, xmm2;
		addps xmm0, xmm3;
		sqrtss xmm0, xmm0;
		movss [ecx], xmm0;
	}
	return result;
}

int main()
{
	color t;
	float min, d;
	int k;
	for(int i = 0; i < 16; i++) {
		cin >> table[i].r >> table[i].g >> table[i].b;
		table[i].a = 0.0f;
	}
	while(cin >> t.r >> t.g >> t.b) {
		if((int)t.r == -1) break;
		t.a = 0.0f;
		min = 100000.0f;
		for(int i = 0; i < 16; i++) {
			d = dist(t, table[i]);
			if(d < min) {
				min = d;
				k = i;
			}
		}
		cout << "(" << (int)t.r << "," << (int)t.g << "," << (int)t.b << ") maps to (" <<
			(int)table[k].r << "," << (int)table[k].g << "," << (int)table[k].b << ")" << endl;
	}
	return 0;
}
