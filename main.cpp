#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"

void render() {
    const int width = 1024;
    const int height = 768;
    std::vector<Vec3f> framebuffer(width*height);

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            framebuffer[col + row * width] = Vec3f(row / float(height), col / float(width), 0);
        }
    }

    std::ofstream ofs; // save the framebuffer to file
    ofs.open("./out.ppm", std::ios::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height*width; ++i) {
        for (size_t j = 0; j<3; j++) {
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

int main() {
    render();
    return 0;
}
