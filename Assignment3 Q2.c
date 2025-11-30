#include <stdio.h>

void calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets) {
    if (fuel <= 0 || planet > totalPlanets) {
        printf("Mission ended.\n");
        return;
    }
    fuel = fuel - consumption;

    fuel = fuel + recharge;

    if (planet % 4 == 0) {
        fuel = fuel + solarBonus;
    }

    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);

    calculateFuel(fuel, consumption, recharge, solarBonus, planet + 1, totalPlanets);
}

int main() {
    int fuel, consumption, recharge, solarBonus, totalPlanets;

    printf("Enter starting fuel: ");
    scanf("%d", &fuel);

    printf("Enter fuel consumption per planet: ");
    scanf("%d", &consumption);

    printf("Enter gravitational recharge: ");
    scanf("%d", &recharge);

    printf("Enter solar bonus (every 4th planet): ");
    scanf("%d", &solarBonus);

    printf("Enter total number of planets: ");
    scanf("%d", &totalPlanets);

    printf("\n--- Journey Begins ---\n");
    calculateFuel(fuel, consumption, recharge, solarBonus, 1, totalPlanets);

    return 0;
}

