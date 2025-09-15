#include <glw/game/ecs/components/collider/hitbox-intersection.hpp>

#include <glw/utils/math/math.hpp>

std::vector<glw::math::Vec2f> glw::game::ecs::FindHitboxIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    if (hitbox1->Type == glw::game::ecs::HitboxType::RECTANGLE && hitbox2->Type == glw::game::ecs::HitboxType::RECTANGLE) {
        return glw::game::ecs::FindRectangleToRectangleIntersection(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE && hitbox2->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE) {
        return FindCircunferenceToCircunferenceIntersection(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::RECTANGLE && hitbox2->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE) {
        return FindRectangleToCircunferenceIntersection(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE && hitbox2->Type == glw::game::ecs::HitboxType::RECTANGLE) {
        return FindRectangleToCircunferenceIntersection(hitbox2, hitbox1);
    }

    return std::vector<glw::math::Vec2f>();
}

std::vector<glw::math::Vec2f> glw::game::ecs::FindRectangleToRectangleIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    const glw::game::ecs::OOB* oob1 = static_cast<glw::game::ecs::OOB*>(hitbox1->algorithm);
    const glw::game::ecs::OOB* oob2 = static_cast<glw::game::ecs::OOB*>(hitbox2->algorithm);

    static std::array<glw::math::Segment, 4> segments1, segments2;

    for (int i = 0; i < 4; ++i) {
        const std::array<float, 2> origin1 = oob1->vertices[i];
        const std::array<float, 2> destination1 = oob1->vertices[(i == 3)? 0 : i + 1];

        const std::array<float, 2> origin2 = oob2->vertices[i];
        const std::array<float, 2> destination2 = oob2->vertices[(i == 3)? 0 : i + 1];

        segments1[i] = glw::math::Segment(origin1, destination1);
        segments2[i] = glw::math::Segment(origin2, destination2);
    }

    std::vector<glw::math::Vec2f> intersections;
    intersections.reserve(16);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            const std::array<float, 2> intersection = glw::math::FindLineIntersectionFromSegment(segments1[i], segments2[j]);

            if (std::isnan(intersection[0]) || std::isnan(intersection[1]) || std::isinf(intersection[0]) || std::isinf(intersection[1])) {
                continue;
            }

            if (segments1[i].CheckSegmentPoint(intersection) && segments2[j].CheckSegmentPoint(intersection)) {
                intersections.emplace_back(intersection);
            }
        }
    }

    return intersections;
}

std::vector<glw::math::Vec2f> glw::game::ecs::FindCircunferenceToCircunferenceIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    const glw::game::ecs::Circunference* circ1 = static_cast<glw::game::ecs::Circunference*>(hitbox1->algorithm);
    const glw::game::ecs::Circunference* circ2 = static_cast<glw::game::ecs::Circunference*>(hitbox2->algorithm);

    const glw::math::Circunference circunference1 = glw::math::Circunference(std::array<float, 2> { circ1->x, circ1->y }, circ1->diameter);
    const glw::math::Circunference circunference2 = glw::math::Circunference(std::array<float, 2> { circ2->x, circ2->y }, circ2->diameter);

    const std::array<float, 4> points = glw::math::FindCircunferenceIntersection(circunference1, circunference2);

    std::vector<glw::math::Vec2f> intersections;
    intersections.reserve(2);

    for (int i = 0; i < 4; i += 2) {
        std::array<float, 2> point { points[i], points[i + 1] };

        if (std::isnan(point[0]) || std::isnan(point[1]) || std::isinf(point[0]) || std::isinf(point[1])) {
            continue;
        }

        if (circunference1.CheckCircunferencePoint(point) && circunference2.CheckCircunferencePoint(point)) {
            intersections.emplace_back(point);
        }
    }

    return intersections;
}

std::vector<glw::math::Vec2f> glw::game::ecs::FindRectangleToCircunferenceIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    const glw::game::ecs::OOB* oob = static_cast<glw::game::ecs::OOB*>(hitbox1->algorithm);
    const glw::game::ecs::Circunference* circ = static_cast<glw::game::ecs::Circunference*>(hitbox2->algorithm);

    std::vector<glw::math::Vec2f> intersections;
    intersections.reserve(8);

    const glw::math::Circunference circunference = glw::math::Circunference(std::array<float, 2> { circ->x, circ->y }, circ->diameter);
    
    for (int i = 0; i < 4; ++i) {
        const std::array<float, 2> origin = oob->vertices[i];
        const std::array<float, 2> destination = oob->vertices[(i == 3)? 0 : i + 1];

        const glw::math::Segment segment = glw::math::Segment(origin, destination);

        const std::array<float, 4> points = glw::math::FindLineToCircunferenceIntersection(segment, circunference);

        for (int i = 0; i < 4; i += 2) {
            std::array<float, 2> point { points[i], points[i + 1] };

            if (std::isnan(point[0]) || std::isnan(point[1]) || std::isinf(point[0]) || std::isinf(point[1])) {
                continue;
            }

            if (segment.CheckSegmentPoint(point) && circunference.CheckCircunferencePoint(point)) {
                intersections.emplace_back(point);
            }
        }
    }

    return intersections;
}
