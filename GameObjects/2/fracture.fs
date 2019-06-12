#version 330

out vec4 FragColor;
precision highp float;
uniform float time;
uniform vec2 resolution;
varying vec3 fPosition;
varying vec3 fNormal;

void main()
{
  FragColor = vec4(fNormal, 1.0);
}
