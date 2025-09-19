#pragma once

#include <cmath>
#include <array>

#include <glw/utils/math/constants.hpp>

#include <glw/utils/math/types/Segment.hpp>
#include <glw/utils/math/types/Circunference.hpp>

namespace glw::math {
    // if x or y is std::numeric_limits<T>::infinity, the lines are the same or just parallel
    inline std::array<float, 2> FindLineIntersection(const glw::math::Segment::Equation& line1, const glw::math::Segment::Equation& line2) {
        float kx1 = line1.x.k;
        float nx1 = line1.x.n;

        float ky1 = line1.y.k;
        float ny1 = line1.y.n;

        float kx2 = line2.x.k;
        float nx2 = line2.x.n;

        float ky2 = line2.y.k;
        float ny2 = line2.y.n;

        float u = (ky1 * (nx2 - nx1) + kx1 * (ny1 - ny2)) / (kx1 * ky2 - ky1 * kx2);
        
        float x = kx2 * u + nx2;
        float y = ky2 * u + ny2;

        return std::array<float, 2> { x, y };
    }

    inline std::array<float, 2> FindLineIntersectionFromSegment(const glw::math::Segment& segment1, const glw::math::Segment& segment2) {
        return FindLineIntersection(segment1.equation, segment2.equation);
    }

    inline std::array<float, 4> FindLineToCircunferenceIntersection(const glw::math::Segment& segment, const glw::math::Circunference& circunference) {
        float kx = segment.equation.x.k;
        float nx = segment.equation.x.n;

        float ky = segment.equation.y.k;
        float ny = segment.equation.y.n;

        std::array<float, 3> circ = circunference.equation;

        float a = circ[0];
        float b = circ[1];
        float rSqrd = circ[2];

        float A = kx * kx + ky * ky;
        float B = 2 * kx * nx + 2 * ky * ny -2 * a * kx - 2 * b * ky;
        float C = nx * nx + ny * ny - 2 * a * nx - 2 * b * ny + a * a + b * b - rSqrd;

        float delta = B * B - 4 * A * C;

        if (delta < 0) {
            return std::array<float, 4> { glw::math::NaN, glw::math::NaN, glw::math::NaN, glw::math::NaN };
        }

        float t1 = (-B + std::sqrt(delta)) / (2 * A);
        float t2 = (-B - std::sqrt(delta)) / (2 * A);

        float x1 = kx * t1 + nx;
        float x2 = kx * t2 + nx;

        float y1 = ky * t1 + ny;
        float y2 = ky * t2 + ny;

        return std::array<float, 4> { x1, y1, x2, y2 };
    }
    
    inline std::array<float, 4> FindCircunferenceIntersection(const glw::math::Circunference& circunference1, const glw::math::Circunference& circunference2) {
        std::array<float, 3> equation1 = circunference1.equation;
        std::array<float, 3> equation2 = circunference2.equation;
        
        float a1 = equation1[0];
        float b1 = equation1[1];
        float rSqrd1 = equation1[2]; // r¹^2
        
        float a2 = equation2[0];
        float b2 = equation2[1];
        float rSqrd2 = equation2[2]; // r²^2
        
        float A = -2 * a1 + 2 * a2;
        float B = -2 * b1 + 2 * b2;
        float C = a1 * a1 - a2 * a2 + b1 * b1 - b2 * b2 - rSqrd1 + rSqrd2;
        
        float oX, oY;
        
        if (B != 0.0f) {
            oY = -C/B;
            oX = 0.0f;
        } else {
            oX = -C/A;
            oY = 0.0f;
        }
        
        glw::math::Segment segment;
        
        segment.equation.x.k = B;
        segment.equation.x.n = oX;
        segment.equation.y.k = -A;
        segment.equation.y.n = oY;
        
        return FindLineToCircunferenceIntersection(segment, circunference1);
    }
}
