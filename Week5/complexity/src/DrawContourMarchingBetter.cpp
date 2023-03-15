//==============================================================
// Filename    : 
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "../include/DrawContourMarchingBetter.h"
#include <queue>

// draw contour
void DrawContourMarchingBetter::drawContour(float threshold) {
    // Initialize the worklist and visited list
    std::queue<Point> worklist = findFirstPoints(threshold);
    std::vector<std::vector<bool>> visitedMatrix(ui->sizeX, std::vector<bool>(ui->sizeY, false));

    // Marching squares algorithm
    while (!worklist.empty()) {
        // Take a pixel p from the worklist
        Point p = worklist.front();
        worklist.pop();

        // Check if p is already visited or out of bounds
        if (p.x < 0 || p.y < 0 || p.x >= ui->sizeX || p.y >= ui->sizeY || visitedMatrix[p.x][p.y]) {
            continue;
        }

        // Mark p as visited
        visitedMatrix[p.x][p.y] = true;

        // Calculate the potential values at the corners of p
        float p1 = blob->potential(p.x - ui->sizeX/2 - 0.5, p.y - ui->sizeY/2 - 0.5);
        float p2 = blob->potential(p.x - ui->sizeX/2 - 0.5, p.y - ui->sizeY/2 + 0.5);
        float p3 = blob->potential(p.x - ui->sizeX/2 + 0.5, p.y - ui->sizeY/2 - 0.5);
        float p4 = blob->potential(p.x - ui->sizeX/2 + 0.5, p.y - ui->sizeY/2 + 0.5);

        // Check which line segments the contour crosses and draw pixels if necessary
        if (p1 > threshold && p2 <= threshold) {
            ui->drawPixel(p.x - ui->sizeX/2 - 1, p.y - ui->sizeY/2);
            worklist.push(Point(p.x - 1, p.y));
            worklist.push(Point(p.x + 1, p.y));
            worklist.push(Point(p.x, p.y - 1));
            worklist.push(Point(p.x, p.y + 1));
            worklist.push(Point(p.x - 1, p.y - 1));
            worklist.push(Point(p.x - 1, p.y + 1));
            worklist.push(Point(p.x + 1, p.y - 1));
            worklist.push(Point(p.x + 1, p.y + 1));
        }
        if (p2 > threshold && p4 <= threshold) {
            ui->drawPixel(p.x - ui->sizeX/2, p.y - ui->sizeY/2 + 1);
            worklist.push(Point(p.x - 1, p.y));
            worklist.push(Point(p.x + 1, p.y));
            worklist.push(Point(p.x, p.y - 1));
            worklist.push(Point(p.x, p.y + 1));
            worklist.push(Point(p.x - 1, p.y - 1));
            worklist.push(Point(p.x - 1, p.y + 1));
            worklist.push(Point(p.x + 1, p.y - 1));
            worklist.push(Point(p.x + 1, p.y + 1));
        }
        if (p4 > threshold && p3 <= threshold) {
            ui->drawPixel(p.x - ui->sizeX/2 + 1, p.y - ui->sizeY/2);
            worklist.push(Point(p.x - 1, p.y));
            worklist.push(Point(p.x + 1, p.y));
            worklist.push(Point(p.x, p.y - 1));
            worklist.push(Point(p.x, p.y + 1));
            worklist.push(Point(p.x - 1, p.y - 1));
            worklist.push(Point(p.x - 1, p.y + 1));
            worklist.push(Point(p.x + 1, p.y - 1));
            worklist.push(Point(p.x + 1, p.y + 1));
        }
        if (p3 > threshold && p1 <= threshold) {
            ui->drawPixel(p.x - ui->sizeX/2, p.y - ui->sizeY/2 - 1);
            worklist.push(Point(p.x - 1, p.y));
            worklist.push(Point(p.x + 1, p.y));
            worklist.push(Point(p.x, p.y - 1));
            worklist.push(Point(p.x, p.y + 1));
            worklist.push(Point(p.x - 1, p.y - 1));
            worklist.push(Point(p.x - 1, p.y + 1));
            worklist.push(Point(p.x + 1, p.y - 1));
            worklist.push(Point(p.x + 1, p.y + 1));
        }
    }
}

// Helper function to find the first point on the contour
std::queue<Point> DrawContourMarchingBetter::findFirstPoints(float threshold) {
    // Scan the potential field to find the first point on the contour
    std::queue<Point> worklist;
    bool prevPotential = false; // Keep track of whether the previous pixel was inside the contour region or not
    for(int x = 0; x < ui->sizeX; x+=5){
        for(int y = 0; y < ui->sizeY; y+=5) {
            // Check if the current pixel potential value crosses the threshold value
            if (prevPotential != blob->potential(x - ui->sizeX/2, y - ui->sizeY/2) > threshold){
                worklist.push(Point(x, y));
            }
            prevPotential = blob->potential(x - ui->sizeX/2, y - ui->sizeY/2) > threshold; // Update prevPotential based on the current pixel potential value
        }
    }
    return worklist;
}
