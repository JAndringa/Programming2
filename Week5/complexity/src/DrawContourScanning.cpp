//==============================================================
// Filename    : DrawContourScanning.cpp
// Authors     : Jibbe Andringa S2336219
// Group       : 12
// License     : N.A. or open source license like LGPL
// Description : This file contains the implementation for the DrawContourScanning class,
//               which is used to draw a contour line around regions in a 2D grid with a potential value greater than a
//               specified threshold. This implementation uses a scanning algorithm to identify pixels that cross
//               the threshold and draws them to create the contour line.
//==============================================================

#include "../include/DrawContourScanning.h"

// This function draws a contour line for the given threshold value by scanning the 2D grid of size ui->sizeX by ui->sizeY.
void DrawContourScanning::drawContour(float threshold) {
    bool prevPotential = false; // Keep track of whether the previous pixel was inside the contour region or not
    for(int x = 0; x < ui->sizeX; x++){
        for(int y = 0; y < ui->sizeY; y++) {
            // Check if the current pixel potential value crosses the threshold value
            if (prevPotential != blob->potential(x - ui->sizeX/2, y - ui->sizeY/2) > threshold){
                ui->drawPixel(x - ui->sizeX/2, y - ui->sizeY/2); // Draw the pixel at the current coordinate
            }
            prevPotential = blob->potential(x - ui->sizeX/2, y - ui->sizeY/2) > threshold; // Update prevPotential based on the current pixel potential value
        }
    }
}