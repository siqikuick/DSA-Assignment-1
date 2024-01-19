def add_path(graph, from_node, to_node, cost):
    if from_node not in graph:
        graph[from_node] = []
    graph[from_node].append((to_node, cost))

def create_bidirectional_graph(path_list):
    graph = {}
    for from_node, to_node, cost in path_list:
        add_path(graph, from_node, to_node, cost)
        add_path(graph, to_node, from_node, cost)  # Add the reverse path
    return graph

def find_paths(graph, start, end, visited=None, path=None, paths=None):
    if visited is None:
        visited = set()
    if path is None:
        path = []
    if paths is None:
        paths = []

    visited.add(start)
    path.append(start)

    if start == end:
        total_cost = calculate_total_cost(graph, path)
        paths.append((list(path), total_cost))
    else:
        for neighbor, _ in graph.get(start, []):
            if neighbor not in visited:
                find_paths(graph, neighbor, end, visited, path, paths)

    path.pop()
    visited.remove(start)
    return paths

def calculate_total_cost(graph, path):
    total_cost = 0
    for i in range(len(path) - 1):
        for neighbor, cost in graph[path[i]]:
            if neighbor == path[i + 1]:
                total_cost += cost
                break
    return total_cost

def find_path_interactively(graph):
    print("Possible locations:")
    print(", ".join(graph.keys()))

    start_location = input("Enter the starting location: ").capitalize()
    while start_location not in graph:
        print("Invalid starting location. Please choose from the list.")
        start_location = input("Enter the starting location: ").capitalize()

    # Determine possible ending locations (ignoring the starting location)
    possible_end_locations = set(graph.keys()) - {start_location}
    print("\nPossible ending locations:")
    print(", ".join(possible_end_locations))

    end_location = input("Enter the ending location: ").capitalize()
    while end_location not in possible_end_locations:
        print("Invalid ending location. Please choose from the list.")
        end_location = input("Enter the ending location: ").capitalize()

    paths = find_paths(graph, start_location, end_location)
    if not paths:
        print(f"No paths found from {start_location} to {end_location}.")
        return

    # Sort paths first by total path length, then by cost
    paths.sort(key=lambda x: (len(x[0]), x[1]))

    print(f"\nOptions for paths from {start_location} to {end_location}:")
    for idx, (path, total_cost) in enumerate(paths, start=1):
        print(f"Option {idx}: {' -> '.join(path)} (Total Cost: {total_cost})")

    choice = input("\nEnter the number of the path to choose, or 'stop' to end: ").strip().lower()
    if choice == 'stop' or not choice.isdigit() or int(choice) < 1 or int(choice) > len(paths):
        print("Invalid choice or operation stopped.")
    else:
        choice = int(choice) - 1
        chosen_path, total_cost = paths[choice]
        print(f"\nChosen Path: {' -> '.join(chosen_path)}. Total cost: {total_cost}")

# Path list
path_list = [
    ('A', 'B', 5), ('A', 'C', 3), ('B', 'D', 2), ('B', 'C', 1),
    ('B', 'F', 7), ('C', 'E', 8), ('E', 'Z', 3), ('Z', 'F', 6), ('F', 'E', 4)
]

# Create a bidirectional graph
graph = create_bidirectional_graph(path_list)

# Start the interactive session
find_path_interactively(graph)

