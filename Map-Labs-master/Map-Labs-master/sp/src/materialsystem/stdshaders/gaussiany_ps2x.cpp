// Includes
#include "common_ps_fxc.h"

sampler2D	sceneSampler	: register( s0 );
const float	blurSize	: register( c0 );

// Structs
struct VS_OUTPUT
{
   	float4 Position   : POSITION;
	float2 TexCoord0  : TEXCOORD0;
};

// Main
float4 main( VS_OUTPUT IN ) : COLOR0
{
   float4 sum = 0;

   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y - 4.0*blurSize)) * 0.05;
   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y - 3.0*blurSize)) * 0.09;
   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y - 2.0*blurSize)) * 0.12;
   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y - blurSize)) * 0.15;
   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y)) * 0.16;
   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y + blurSize)) * 0.15;
   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y + 2.0*blurSize)) * 0.12;
   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y + 3.0*blurSize)) * 0.09;
   sum += tex2D(sceneSampler, float2(IN.TexCoord0.x, IN.TexCoord0.y + 4.0*blurSize)) * 0.05;

   return sum;
}