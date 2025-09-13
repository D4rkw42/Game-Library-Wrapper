#pragma once

#include <cmath>
#include <array>

#include <limits>

#include <glw/utils/math/types/Segment.hpp>
#include <glw/utils/math/types/Circunference.hpp>

namespace glw::math {
    // if x or y is std::numeric_limits<T>::infinity, the lines are the same or just parallel
    inline std::array<float, 2> FindLineIntersection(const std::array<float, 2>& equation1, const std::array<float, 2>& equation2) {
        float a1 = equation1[0];
        float b1 = equation1[1];

        float a2 = equation2[0];
        float b2 = equation2[1];

        float x = (b2 - b1) / (a1 - a2);
        float y = a1 * x + b1;

        return std::array<float, 2> { x, y };
    }

    inline std::array<float, 2> FindLineIntersectionFromSegment(const glw::math::Segment& segment1, const glw::math::Segment& segment2) {
        std::array<float, 2> equation1 = segment1.GetEquation();
        std::array<float, 2> equation2 = segment2.GetEquation();

        return FindLineIntersection(equation1, equation2);
    }

    inline std::array<float, 4> FindCircunferenceIntersection(const glw::math::Circunference& circunference1, const glw::math::Circunference& circunference2) {
        std::array<float, 3> equation1 = circunference1.GetEquation();
        std::array<float, 3> equation2 = circunference2.GetEquation();

        float a1 = equation1[0];
        float b1 = equation1[1];
        float rSqrd1 = equation1[2]; // r¹^2

        float a2 = equation2[0];
        float b2 = equation2[1];
        float rSqrd2 = equation2[2]; // r²^2

        float k = -2 * b1 + 2 + b2;

        // y = ax + b
        float As = (2 * a1 - 2 * a2) / k;
        float Bs = (-(a1 * a1) + a2 * a2 -(b1 * b1) + b2 * b2 + rSqrd1 - rSqrd2) / k;

        float A = 1 + As * As;
        float B = -2 * a2 + 2 * As * b2;
        float C = -(rSqrd2) + a2 * a2 + Bs * Bs;

        float delta = B * B - 4 * A * C;

        if (delta < 0) {
            return std::array<float, 4> {
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity()
            };
        }

        float x1 = (-B + std::sqrt(delta)) / (2 * A);
        float x2 = (-B - std::sqrt(delta)) / (2 * A);

        float y1 = As * x1 + Bs;
        float y2 = As * x2 + Bs;

        return std::array<float, 4> { x1, y1, x2, y2 };
    }

    inline std::array<float, 4> FindLineToCircunferenceIntersection(const glw::math::Segment& segment, const glw::math::Circunference& circunference) {
        std::array<float, 2> equation1 = segment.GetEquation();
        std::array<float, 3> equation2 = circunference.GetEquation();

        float a1 = equation1[0];
        float b1 = equation1[1];

        float a2 = equation2[0];
        float b2 = equation2[1];
        float rSqrd = equation2[2];

        float A = 1 + a1 * a1;
        float B = -2 * a2 + 2 * a1 * b2;
        float C = -(rSqrd) + a2 * a2 + b1 * b1;

        float delta = B * B - 4 * A * C;

        if (delta < 0) {
            return std::array<float, 4> {
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity()
            };
        }

        float x1 = (-B + std::sqrt(delta)) / (2 * A);
        float x2 = (-B - std::sqrt(delta)) / (2 * A);

        float y1 = a1 * x1 + b1;
        float y2 = a1 * x2 + b1;

        return std::array<float, 4> { x1, y1, x2, y2 };
    }
}
