#version 330 core

out vec4 FragColor;

void main()
{
    int triangleID = int(gl_PrimitiveID);
    float time = sin(gl_FragCoord.x * 0.1 + gl_FragCoord.y * 0.1);

    if (triangleID == 0) {
        FragColor = vec4(abs(time), 0.0, 0.0, 1.0);
    } else if (triangleID == 1) {
        FragColor = vec4(abs(time), 1.0, 0.0, 1.0);
    } else if (triangleID == 2) {
        FragColor = vec4(abs(time), 0.0, 1.0, 1.0); 
    } else {
        FragColor = vec4(abs(time), 0.0, 0.0, 0.0);
    }
}
