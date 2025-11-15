#include <iostream>
#include <unordered_map>


/**
 * Entry point of the program. This program expects no command line arguments and was designed for
 * inputs to be redirected from an input file. The program executes an aggregation of all matching prices
 * to their total volume in the orderbook, simulating a real-time data stream coming from exchanges.
 */
int main(void) {
    // Using unordered_map because this is a constant time insertion. An alternative I considered was to use
    // std::map, which is implemented as a Red-Black Tree, for the ordering guarantee, but since the order would
    // not matter in the real world, and the red-black tree has a longer look-up time (O(log n)), I opted for the
    // unordered_map.
    std::unordered_map<double, int> priceToVolumeMap {};
    double orderPrice;
    unsigned int orderVolume;

    // Only considers pairs
    while (std::cin >> orderPrice && std::cin >> orderVolume) {
	priceToVolumeMap.emplace(orderPrice, orderVolume);
    }

    for (const auto& [price, volume] : priceToVolumeMap) {
	std::cout << price << ' ' << volume << std::endl;
    }
    return 0;
}
