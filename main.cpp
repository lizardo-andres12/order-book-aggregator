#include <iostream>
#include <map>


/**
 * Entry point of the program. This program expects no command line arguments and was designed for
 * inputs to be redirected from an input file. The program executes an aggregation of all matching prices
 * to their total volume in the orderbook, simulating a real-time data stream coming from exchanges.
 */
int main() {
    // Only consider the C++ buffering and disable the C synchronization
    std::ios::sync_with_stdio(false);
    // Disable automatic flushing of std::cout before reading from std::cin.
    std::cin.tie(nullptr);

    // Use std::map for the ordering benefit, and accept the cost of O log(n) lookups and potential tree rebalancing.
    std::map<double, int> priceToVolumeMap {};
    double orderPrice;
    int orderVolume;

    // Only considers pairs
    while (std::cin >> orderPrice && std::cin >> orderVolume) {
	priceToVolumeMap[orderPrice] += orderVolume;
    }

    for (const auto& [price, volume] : priceToVolumeMap) {
	std::cout << price << ' ' << volume << std::endl;
    }
    return 0;
}
