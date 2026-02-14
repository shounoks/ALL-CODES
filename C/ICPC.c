#include <stdio.h>
#include <string.h>

// Function to calculate the cost for making 'm' hamburgers
long long calculate_cost(long long m, long long nb, long long ns, long long nc, long long pb, long long ps, long long pc, long long req_b, long long req_s, long long req_c) {
    long long needed_b = 0, needed_s = 0, needed_c = 0;

    // Check if more bread is needed
    if (m * req_b > nb) {
        needed_b = m * req_b - nb;
    } else {
        needed_b = 0;
    }

    // Check if more sausage is needed
    if (m * req_s > ns) {
        needed_s = m * req_s - ns;
    } else {
        needed_s = 0;
    }

    // Check if more cheese is needed
    if (m * req_c > nc) {
        needed_c = m * req_c - nc;
    } else {
        needed_c = 0;
    }

    // Calculate the total cost
    return needed_b * pb + needed_s * ps + needed_c * pc;
}

int main() {
    char recipe[105];
    long long nb, ns, nc, pb, ps, pc, r;
    long long req_b = 0, req_s = 0, req_c = 0;

    // Reading input
    scanf("%s", recipe);
    scanf("%lld %lld %lld", &nb, &ns, &nc);
    scanf("%lld %lld %lld", &pb, &ps, &pc);
    scanf("%lld", &r);

    // Count the number of 'B', 'S', and 'C' in the recipe
    for (int i = 0; recipe[i] != '\0'; i++) {
        if (recipe[i] == 'B') req_b++;
        if (recipe[i] == 'S') req_s++;
        if (recipe[i] == 'C') req_c++;
    }

    // Binary search for the maximum number of hamburgers
    long long left = 0, right = 1e13, mid, max_hamburgers = 0;

    while (left <= right) {
        mid = (left + right) / 2;

        long long needed_b = 0, needed_s = 0, needed_c = 0;
        if (mid * req_b > nb) {
            needed_b = mid * req_b - nb;
        }
        if (mid * req_s > ns) {
            needed_s = mid * req_s - ns;
        }
        if (mid * req_c > nc) {
            needed_c = mid * req_c - nc;
        }

        long long total_cost = needed_b * pb + needed_s * ps + needed_c * pc;

        if (total_cost <= r) {
            max_hamburgers = mid;  // We can afford to make 'mid' hamburgers
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld\n", max_hamburgers);
    return 0;
}
