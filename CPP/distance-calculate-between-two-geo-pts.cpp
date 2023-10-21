#include <iostream>
#include <cmath>

// Function to convert degrees to radians
double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Function to calculate the distance between two coordinates using the Haversine formula
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Radius of the Earth in kilometers
    const double radius = 6371.0;

    // Convert degrees to radians
    lat1 = degreesToRadians(lat1);
    lon1 = degreesToRadians(lon1);
    lat2 = degreesToRadians(lat2);
    lon2 = degreesToRadians(lon2);

    // Haversine formula
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // Calculate the distance
    double distance = radius * c;
    return distance;
}

int main() {
    // Coordinates of two points (latitude and longitude in degrees)
    double lat1, lon1, lat2, lon2;

    std::cout << "Enter the latitude of the first point (in degrees): ";
    std::cin >> lat1;
    std::cout << "Enter the longitude of the first point (in degrees): ";
    std::cin >> lon1;
    std::cout << "Enter the latitude of the second point (in degrees): ";
    std::cin >> lat2;
    std::cout << "Enter the longitude of the second point (in degrees): ";
    std::cin >> lon2;

    double distance = calculateDistance(lat1, lon1, lat2, lon2);

    std::cout << "The distance between the two points is approximately " << distance << " kilometers." << std::endl;

    return 0;
}