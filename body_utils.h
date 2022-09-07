#ifndef BODY_UTILS_H_
#define BODY_UTILS_H_

typedef struct VertexCoordinates
{
    float x, z;
} VertexCoordinates ;

VertexCoordinates
getSpikeCoordinates (float x_center,
                     float z_center,
                     float radiux,
                     int n,
                     int i);

#endif
