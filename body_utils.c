#include "body_utils.h"
#include "math.h"

VertexCoordinates
getSpikeCoordinates (float x_center,
                  float z_center,
                  float radius,
                  int n,
                  int i)
{
    VertexCoordinates coordinates;
    float angle = M_PI * 2 / n;
    coordinates.x = x_center + radius * sin(i * angle);
    coordinates.z = z_center + radius * cos(i * angle);
    return coordinates;
}
