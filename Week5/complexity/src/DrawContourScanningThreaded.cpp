//==============================================================
// Filename    : 
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "../include/DrawContourScanningThreaded.h"
#include <vector>
#include <thread>

// draw contour
void DrawContourScanningThreaded::drawContour(float threshold) {
    std::vector<std::thread> threads;
    for(int row = 0; row < ui->sizeX; row++){
        threads.emplace_back([=](){
            this->searchRow(row, threshold);
        });
    }
    for(auto &thread : threads){
        thread.join();
    }
}

void DrawContourScanningThreaded::searchRow(int row, float threshold) {
    bool prevPotential = false; // Keep track of whether the previous pixel was inside the contour region or not
    for (int column = 0; column < ui->sizeY; column++) {
        // Check if the current pixel potential value crosses the threshold value
        if (prevPotential != blob->potential(row - ui->sizeX / 2, column - ui->sizeY / 2) > threshold) {
            ui->drawPixel(row - ui->sizeX / 2, column - ui->sizeY / 2); // Draw the pixel at the current coordinate
        }
        prevPotential = blob->potential(row - ui->sizeX / 2, column - ui->sizeY / 2) >
                        threshold; // Update prevPotential based on the current pixel potential value
    }
}
