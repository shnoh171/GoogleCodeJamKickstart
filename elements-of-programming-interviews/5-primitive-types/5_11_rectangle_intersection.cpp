#include <tuple>
#include <algorithm>

struct Rect {
    int x, y, width, height;
};

struct Region {
    int min, max;
};

Rect IntersectRectangle(const Rect& R1, const Rect& R2) {
    Rect ret;

    Region R1_x = {R1.x, R1.x + R1.width};
    Region R2_x = {R2.x, R2.x + R2.width};

    if (R1_x.min <= R2_x.min) {
        if (R1_x.max <= R2_x.min) {
            return {0, 0, -1, -1};
        } else {
            ret.x = R2_x.min;
            ret.width = std::min(R1_x.max, R2_x.max) - R2_x.min;
        }   
    } else {
        if (R2_x.max <= R1_x.min) {
            return {0, 0, -1, -1};
        } else {
            ret.x = R1_x.min;
            ret.width = std::min(R2_x.max, R1_x.max) - R1_x.min;
        }   
    }   

    Region R1_y = {R1.y, R1.y + R1.height};
    Region R2_y = {R2.y, R2.y + R2.height};

    if (R1_y.min <= R2_y.min) {
        if (R1_y.max <= R2_y.min) {
            return {0, 0, -1, -1};
        } else {
            ret.y = R2_y.min;
            ret.height= std::min(R1_y.max, R2_y.max) - R2_y.min;
        }   
    } else {
        if (R2_y.max <= R1_y.min) {
            return {0, 0, -1, -1};
        } else {
            ret.y = R1_y.min;
            ret.height= std::min(R2_y.max, R1_y.max) - R1_y.min;
        }
    }

    return ret;
}

/* Solution */

bool IsIntersect(const Rect& R1, const Rect& R2) {
    return R1.x <= R2.x + R2.width && R1.x + R1.width >= R2.x &&
           R1.y <= R2.y + R2.height && R1.y + R1.height >= R2.y;
}

Rect IntersectRectangleSolution(const Rect& R1, const Rect& R2) {
    if (!IsIntersect(R1, R2)) {
        return {0, 0, -1, -1};  // No intersection.
    }
    return {std::max(R1.x, R2.x), std::max(R1.y, R2.y),
            std::min(R1.x + R1.width, R2.x + R2.width) - std::max(R1.x, R2.x),
            std::min(R1.y + R1.height, R2.y + R2.height) - std::max(R1.y, R2.y)};
}