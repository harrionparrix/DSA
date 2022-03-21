import random
import copy

import numpy as np
from numpy.linalg import norm


class State:
    def __init__(self, route: [], distance: int = 0):
        self.route = route
        self.distance = distance

    def __eq__(self, other):
        for i in range(len(self.route)):
            if self.route[i] != other.route[i]:
                return False
        return True

    def __lt__(self, other):
        return self.distance < other.distance

    def __repr__(self):
        return "({0},{1})\n".format(self.route, self.distance)

    def copy(self):
        return State(self.route, self.distance)

    def deepcopy(self):
        return State(copy.deepcopy(self.route), copy.deepcopy(self.distance))

    def update_distance(self, matrix, home):
        self.distance = 0
        from_index = home
        for i in range(len(self.route)):
            self.distance += matrix[from_index][self.route[i]]
            from_index = self.route[i]
        self.distance += matrix[from_index][home]


class City:
    def __init__(self, index: int, distance: int):
        self.index = index
        self.distance = distance

    def __lt__(self, other):
        return self.distance < other.distance


def get_random_solution(
    matrix: [], home: int, city_indexes: [], size: int
):
    cities = city_indexes.copy()
    cities.pop(home)
    population = []
    for i in range(size):
        random.shuffle(cities)
        state = State(cities[:])
        state.update_distance(matrix, home)
        population.append(state)
    population.sort()
    return population[0]


def mutate(matrix: [], home: int, state: State, mutation_rate: float = 0.01):
    mutated_state = state.deepcopy()
    for i in range(len(mutated_state.route)):
        if random.random() < mutation_rate:
            j = int(random.random() * len(state.route))
            city_1 = mutated_state.route[i]
            city_2 = mutated_state.route[j]
            mutated_state.route[i] = city_2
            mutated_state.route[j] = city_1
    mutated_state.update_distance(matrix, home)
    return mutated_state


def hill_climbing(
    matrix: [],
    home: int,
    initial_state: State,
    max_iterations: int,
    mutation_rate: float = 0.01,
):
    best_state = initial_state
    iterator = 0
    while True:
        neighbor = mutate(matrix, home, best_state, mutation_rate)
        if neighbor.distance >= best_state.distance:
            iterator += 1
            if iterator > max_iterations:
                break
        if neighbor.distance < best_state.distance:
            best_state = neighbor
    return best_state


def get_euclidean_distance(p, q):
    return round(norm(np.array(p) - np.array(q)))


def main():

    # Extracted from the Western Sahara city coordinates
    # found in http://www.math.uwaterloo.ca/tsp/world/countries.html
    cities_coordinates = {
        1:  (20833.3333, 17100.0000),
        2:  (20900.0000, 17066.6667),
        3:  (21300.0000, 13016.6667),
        4:  (21600.0000, 14150.0000),
        5:  (21600.0000, 14966.6667),
        6:  (21600.0000, 16500.0000),
        7:  (22183.3333, 13133.3333),
        8:  (22583.3333, 14300.0000),
        9:  (22683.3333, 12716.6667),
        10: (23616.6667, 15866.6667),
        11: (23700.0000, 15933.3333),
        12: (23883.3333, 14533.3333),
        13: (24166.6667, 13250.0000),
        14: (25149.1667, 12365.8333),
        15: (26133.3333, 14500.0000),
        16: (26150.0000, 10550.0000),
        17: (26283.3333, 12766.6667),
        18: (26433.3333, 13433.3333),
        19: (26550.0000, 13850.0000),
        20: (26733.3333, 11683.3333),
        21: (27026.1111, 13051.9444),
        22: (27096.1111, 13415.8333),
        23: (27153.6111, 13203.3333),
        24: (27166.6667, 9833.3333),
        25: (27233.3333, 10450.0000),
        26: (27233.3333, 11783.3333),
        27: (27266.6667, 10383.3333),
        28: (27433.3333, 12400.0000),
        29: (27462.5000, 12992.2222),
    }

    D = []
    for _, target_coordinates in cities_coordinates.items():
        distances = []
        for _, coordinates in cities_coordinates.copy().items():
            distances.append(get_euclidean_distance(target_coordinates, coordinates))
        D.append(distances)

    home = 0
    max_iterations = 100000
    cities = list(cities_coordinates.keys())
    city_indexes = [index - 1 for index in cities]

    state = get_random_solution(D, home, city_indexes, 100)
    print("-- Initial state solution --")
    print(cities[home], end="")
    for i in range(0, len(state.route)):
        print(" -> " + str(cities[state.route[i]]), end="")
    print(" -> " + str(cities[home]), end="")
    print("\n\nTotal distance: {0} miles".format(state.distance))
    print()

    state = hill_climbing(D, home, state, max_iterations, 0.1)
    print("-- Hill climbing solution --")
    print(cities[home], end="")
    for i in range(0, len(state.route)):
        print(" -> " + str(cities[state.route[i]]), end="")
    print(" -> " + str(cities[home]), end="")
    print("\n\nTotal distance: {0} miles".format(state.distance))
    print()


if __name__ == "__main__":
    main()