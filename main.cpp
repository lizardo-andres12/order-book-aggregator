#include <iostream>
#include <map>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Use std::map for the ordering benefit, and accept the cost of O log(n) lookups and potential tree rebalancing.
    std::map<double, int> priceToVolumeMap {};
    double orderPrice;
    int orderVolume;

    while (std::cin >> orderPrice && std::cin >> orderVolume) {
	priceToVolumeMap[orderPrice] += orderVolume;
    }

    for (const auto& [price, volume] : priceToVolumeMap) {
	std::cout << price << ' ' << volume << '\n';
    }
    return 0;
}
