def add_path(graph, from_location, to_location, cost):
    if from_location not in graph:
        graph[from_location] = []
    graph[from_location].append((to_location, cost))

def create_graph(path_list, bidirectional=False):
    graph = {}
    for from_location, to_location, cost in path_list:
        add_path(graph, from_location, to_location, cost)
        if bidirectional:
            add_path(graph, to_location, from_location, cost)  # Add the reverse path for bidirectional graph
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

def find_reachable_nodes(graph, start_location):
    reachable = set()
    def dfs(location):
        if location not in reachable:
            reachable.add(location)
            for neighbor, _ in graph.get(location, []):
                dfs(neighbor)
    dfs(start_location)
    return reachable

def ask_graph_type():
    choice = input("Do you want a bidirectional graph? (yes/no): ").strip().lower()
    while choice not in ["yes", "no"]:
        print("Invalid choice. Please type 'yes' or 'no'.")
        choice = input("Do you want a bidirectional graph? (yes/no): ").strip().lower()
    return choice == "yes"

def display_path_list(path_list):
    for idx, (from_location, to_location, cost) in enumerate(path_list, start=1):
        print(f"{idx}. {from_location} to {to_location}, Cost: {cost}")

def modify_path_list(path_list):
    path_list.sort()  # Sort the path list by starting location alphabetically
    print("Current path list:")
    display_path_list(path_list)

    choice = input("Do you want to modify the path list? (yes/no): ").strip().lower()
    while choice not in ["yes", "no"]:
        print("Invalid choice. Please type 'yes' or 'no'.")
        choice = input("Do you want to modify the path list? (yes/no): ").strip().lower()

    while choice == "yes":
        print("\nCurrent path list:")
        display_path_list(path_list)

        action = input("Enter 'add' to add a new path, 'delete' to remove a path, or key the index of the path you want to modify: ").strip().lower()
        if action == 'add':
            from_location = input("Enter the starting location: ").strip().capitalize()
            to_location = input("Enter the ending location: ").strip().capitalize()

            if from_location == to_location:
                print("Starting location cannot be the same as the ending location. Please try again.")
                continue

            while True:
                cost_input = input("Enter the cost: ").strip()
                if cost_input.isdigit():
                    cost = int(cost_input)
                    break
                else:
                    print("Invalid cost. Please enter a numerical value.")

            new_path = (from_location, to_location, cost)
            if any(from_location == path[0] and to_location == path[1] for path in path_list):
                print("This path already exists. Please try again.")
            else:
                path_list.append(new_path)
        elif action == 'delete':
            while True:
                try:
                    idx_to_delete = int(input("Enter the index of the path you want to delete: "))
                    if 1 <= idx_to_delete <= len(path_list):
                        del path_list[idx_to_delete - 1]
                        break
                    else:
                        print("Index out of range. Please try again.")
        
                except:
                    print("Invalid index. Please try again.")
        elif action.isdigit():
            idx = int(action)
            if 1 <= idx <= len(path_list):
                from_location = input("Enter the starting location: ").strip().capitalize()
                to_location = input("Enter the ending location: ").strip().capitalize()

                if from_location == to_location:
                    print("Starting location cannot be the same as the ending location. Please try again.")
                    continue

                while True:
                    cost_input = input("Enter the cost: ").strip()
                    if cost_input.isdigit():
                        cost = int(cost_input)
                        break
                    else:
                        print("Invalid cost. Please enter a numerical value.")

                modified_path = (from_location, to_location, cost)
                if any(from_location == path[0] and to_location == path[1] for path in path_list[:idx - 1] + path_list[idx:]):
                    print("This path modification creates a duplicate. Please try again.")
                    continue
                else:
                    path_list[idx - 1] = modified_path
            else:
                print("Invalid index. Please try again.")
                continue
        else:
            print("Invalid action. Please try again.")
            continue

        path_list.sort()  # Resort the list after modification
        print("\nCurrent path list:")
        display_path_list(path_list)

        choice = input("Do you want to modify another path? (yes/no): ").strip().lower()
        while choice not in ["yes", "no"]:
            print("Invalid choice. Please type 'yes' or 'no'.")
            choice = input("Do you want to modify another path? (yes/no): ").strip().lower()

def setup_graph():
    bidirectional = ask_graph_type()
    modify_path_list(path_list)
    return create_graph(path_list, bidirectional)

def find_path_interactively(graph):
    print("Possible starting locations:")
    print(", ".join(sorted(graph.keys())))  # Sort the keys for display

    start_location = input("Enter the starting location (or type 'exit' to quit): ").capitalize()
    if start_location.lower() == 'exit':
        return
    while start_location not in graph:
        print("Invalid starting location. Please choose from the list.")
        start_location = input("Enter the starting location (or type 'exit' to quit): ").capitalize()
        if start_location.lower() == 'exit':
            return

    reachable_locations = find_reachable_nodes(graph, start_location)
    possible_end_locations = reachable_locations - {start_location}

    if not possible_end_locations:
        print(f"No reachable locations from {start_location}.")
        return

    print("\nPossible ending locations:")
    print(", ".join(sorted(possible_end_locations)))  # Sort the ending locations

    end_location = input("Enter the ending location (or type 'exit' to quit): ").capitalize()
    if end_location.lower() == 'exit':
        return
    while end_location not in possible_end_locations:
        print("Invalid ending location. Please choose from the list.")
        end_location = input("Enter the ending location (or type 'exit' to quit): ").capitalize()
        if end_location.lower() == 'exit':
            return

    paths = find_paths(graph, start_location, end_location)
    if not paths:
        print(f"No paths found from {start_location} to {end_location}.")
        return

    paths.sort(key=lambda x: (len(x[0]), x[1]))

    while True:
        print(f"\nOptions for paths from {start_location} to {end_location}:")
        for idx, (path, total_cost) in enumerate(paths, start=1):
            path_str = ''.join(path)
            print(f"Option {idx}: {path_str} (Total Cost: {total_cost})")

        choice = input("\nEnter the Option number of the path to choose, 'restart' to start over, or 'exit' to quit: ").strip().lower()
        if choice == 'exit':
            break
        if choice == 'restart':
            graph = setup_graph()
            find_path_interactively(graph)
            break
        if not choice.isdigit() or int(choice) < 1 or int(choice) > len(paths):
            print("Invalid choice. Please enter a valid option number, 'restart' to start over, or 'exit' to quit.")
            continue

        choice = int(choice) - 1
        chosen_path, total_cost = paths[choice]
        print(f"\nChosen Path: {''.join(chosen_path)}. Total cost: {total_cost}")
        break

# Path list
path_list = [
    ('A', 'B', 5), ('A', 'C', 3), ('B', 'D', 2), ('B', 'C', 1),
    ('B', 'F', 7), ('C', 'E', 8), ('E', 'Z', 3), ('Z', 'F', 6), ('F', 'E', 4)
]

# Set up the graph
graph = setup_graph()

# Start the interactive session
find_path_interactively(graph)
