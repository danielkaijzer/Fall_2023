/**
 * @file LC836_Rect_Overlap.cpp
 * @author Daniel Kaijzer
 * @brief 
 * An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], 
 * where (x1, y1) is the coordinate of its bottom-left corner, 
 * and (x2, y2) is the coordinate of its top-right corner. 
 *  so then (x1, y2) is top left corner
 *  so then (x2, y1) is bottom right corner
 * 
 * Its top and bottom edges are parallel to the X-axis, 
 * and its left and right edges are parallel to the Y-axis.
 * 
 * Two rectangles overlap if the area of their intersection is positive. 
 * To be clear, two rectangles that only touch at the corner or edges do not overlap.
 * Given two axis-aligned rectangles rec1 and rec2, 
 * return true if they overlap, otherwise return false.

 * @version 1
 * @date 2023-11-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>


bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
    // if any of the four corners of rec1 make a positive area 
    // with any of the four corners of rec2, return true

    // format for rec = [x1,y1,x2,y2]

    if (rec1[2] - rec2[0] < 1){
        return false;
    }
    if (rec1[3] - rec2[1] < 1){
        return false;
    }
    if (rec2[2] - rec1[0] < 1){
        return false;
    }
    if (rec2[3] - rec1[1] < 1){
        return false;
    }

    return true;

    // rec1_bl = [0,0]
    // rec1_tr = [2,2]

    // rec2_bl = [1,1]
    // rec2_tr = [3,3]

    // rec3_bl = 0,0
    // rec3_tr = 1,1

    // rec4_bl = 2,2
    // rec4_tr = 3,3

    // idea: subtract tr - bl, if positive there's overlap, do it both ways for recs
}

int main(){
    std::vector<int> rect1{0,0,2,2};
    std::vector<int> rect2{1,1,3,3};

    return 0;
}