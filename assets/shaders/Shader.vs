#version 330 core


layout (location = 0) in vec2 pos;  
layout (location = 1) in vec2 texC;
layout (location = 2) in vec4 col; 
uniform mat4 projMatrix;

out vec2 texCoord;
out vec4 color;

void main() {
  
    gl_Position = projMatrix * vec4(pos,0 ,1);
    
	texCoord = texC;
	color = col;

}