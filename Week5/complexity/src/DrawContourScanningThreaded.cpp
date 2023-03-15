//==============================================================
// Filename    : 
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "../include/DrawContourScanningThreaded.h"
#include <thread>

// draw contour
void DrawContourScanningThreaded::drawContour(float threshold) {
    for(int i = 0; i < ui->sizeX; i++){
        std::thread t(searchRow(row))
    }
}

void DrawContourScanningThreaded::searchRow(int row) {

}