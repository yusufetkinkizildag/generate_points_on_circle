#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>

constexpr static auto PI = 3.141592653589793;

namespace utility
{
    auto const generate_points_on_the_circle{[](auto const &origin, auto const radius, auto const number_of_points) noexcept
    {
        std::vector<std::pair<double, double>> output_points(number_of_points);
        std::vector<double> angles(number_of_points);
        std::iota(std::begin(angles), std::end(angles), 0.0);
        std::transform(std::begin(angles), std::end(angles), std::begin(angles), [angle_step{2 * PI / number_of_points}](auto const angle) noexcept
        {
            return angle * angle_step;
        });
        std::transform(std::cbegin(angles), std::cend(angles), std::begin(output_points), [&origin, &radius](auto const angle) noexcept
        {
            return std::make_pair(origin.first + radius * std::cos(angle), origin.second + radius * std::sin(angle));
        });
        return output_points;
    }};

    auto const print_points{[](auto const &points) noexcept 
    {
        std::for_each(std::cbegin(points), std::cend(points), [](auto const &point) noexcept
        {
            std::cout << "(" << point.first << ", " << point.second << ")\n";
        });
    }};
} // namespace utility

int main(int argc, char const *argv[])
{
    std::vector<std::pair<double, double>> const center_points{std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(1, 1)};
    std::vector<double> const radii{1, 2, 3, 4};
    std::vector<int> const num_points{10, 20, 30, 40};

    std::for_each(std::cbegin(center_points), std::cend(center_points), [&](auto const &origin)
    {
        std::for_each(std::cbegin(radii), std::cend(radii), [&](auto const radius)
        {
            std::for_each(std::cbegin(num_points), std::cend(num_points), [&](auto const number_of_points)
            {
                std::cout << "origin: (" << origin.first << ", " << origin.second << "), radius: " << radius << ", number_of_points: " << number_of_points << "\n";
                utility::print_points(utility::generate_points_on_the_circle(origin, radius, number_of_points));
            });
        });
    });
    return 0;
}
